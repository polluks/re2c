#include <stdio.h>
#include <algorithm>
#include <utility>
#include <vector>

#include "lib/regex.h"
#include "lib/regex_impl.h"
#include "src/debug/debug.h"
#include "src/dfa/closure_posix.h"
#include "src/dfa/posix_precedence.h"
#include "src/dfa/tag_history.h"
#include "src/nfa/nfa.h"
#include "src/regexp/rule.h"
#include "src/util/range.h"


namespace re2c {
namespace libre2c {

static void make_one_step(psimctx_t &, uint32_t);
static void make_final_step(psimctx_t &);
static void compute_prectbl_naive(psimctx_t &ctx);

// we *do* want these to be inlined
static inline void closure_posix(psimctx_t &ctx);

int regexec_nfa_posix(const regex_t *preg, const char *string
    , size_t nmatch, regmatch_t pmatch[], int /* eflags */)
{
    psimctx_t &ctx = *static_cast<psimctx_t*>(preg->simctx);
    init(ctx, string);

    // root state can be non-core, so we pass zero as origin to avoid checks
    const conf_t c0(ctx.nfa.root, 0, HROOT);
    ctx.reach.push_back(c0);
    for (;;) {
        closure_posix(ctx);
        const uint32_t sym = static_cast<uint8_t>(*ctx.cursor++);
        if (ctx.state.empty() || sym == 0) break;
        make_one_step(ctx, sym);
    }
    make_final_step(ctx);

    if (ctx.rule == Rule::NONE) {
        return REG_NOMATCH;
    }

    regmatch_t *m = pmatch;
    m->rm_so = 0;
    m->rm_eo = ctx.marker - string - 1;
    const size_t n = std::min(ctx.nsub, 2 * nmatch);
    for (size_t t = 0; t < n; ++t) {
        const regoff_t off = ctx.offsets3[t];
        if (t % 2 == 0) {
            ++m;
            m->rm_so = off;
        }
        else {
            m->rm_eo = off;
        }
    }
    return 0;
}

void closure_posix(psimctx_t &ctx)
{
    ctx.history.init();

    if (ctx.flags & REG_GTOP) {
        closure_posix_gtop(ctx);
    }
    else {
        closure_posix_gor1(ctx);
    }
}

void make_one_step(psimctx_t &ctx, uint32_t sym)
{
    confset_t &state = ctx.state, &reach = ctx.reach;
    uint32_t j = 0;
    reach.clear();

    for (cconfiter_t i = state.begin(), e = state.end(); i != e; ++i) {
        nfa_state_t *s = i->state;

        s->clos = NOCLOS;
        s->arcidx = 0;
        DASSERT(s->status == GOR_NOPASS && s->active == 0);

        if (s->type == nfa_state_t::RAN) {
            for (const Range *r = s->ran.ran; r; r = r->next()) {
                if (r->lower() <= sym && sym < r->upper()) {
                    const conf_t c(s->ran.out, j, HROOT);
                    reach.push_back(c);
                    state[j] = *i;
                    update_offsets(ctx, *i, j);
                    ++j;
                    break;
                }
            }
        }
        else if (s->type == nfa_state_t::FIN) {
            update_offsets(ctx, *i, NONCORE);
        }
    }

    state.resize(j);
    std::swap(ctx.offsets1, ctx.offsets2);

    if (!(ctx.flags & REG_SLOWPREC)) {
        compute_prectable(ctx);
    }
    else {
        compute_prectbl_naive(ctx);
    }
    std::swap(ctx.newprectbl, ctx.oldprectbl);
    ctx.oldprecdim = j;

    ctx.history.init();
    ++ctx.step;
}

void make_final_step(psimctx_t &ctx)
{
    for (cconfiter_t i = ctx.state.begin(), e = ctx.state.end(); i != e; ++i) {
        nfa_state_t *s = i->state;

        s->clos = NOCLOS;
        s->arcidx = 0;
        DASSERT(s->status == GOR_NOPASS && s->active == 0);

        if (s->type == nfa_state_t::FIN) {
            update_offsets(ctx, *i, NONCORE);
        }
    }
}

// Old naive algorithm that has cubic complexity in the size of TNFA.
// Example that exhibits cubic behaviour is ((a?){1,N})*. In this example
// closure has O(N) states, and the compared histories have O(N) length.
void compute_prectbl_naive(psimctx_t &ctx)
{
    const confset_t &state = ctx.state;
    int32_t *newtbl = ctx.newprectbl;
    const size_t newdim = state.size();

    const int32_t p0 = pack(MAX_RHO, 0);

    for (uint32_t i = 0; i < newdim; ++i) {
        newtbl[i * newdim + i] = p0;
        for (uint32_t j = i + 1; j < newdim; ++j) {
            int32_t prec1, prec2;
            int32_t prec = phistory_t::precedence(ctx, state[i], state[j], prec1, prec2);
            newtbl[i * newdim + j] = pack(prec1, prec);
            newtbl[j * newdim + i] = pack(prec2, -prec);
        }
    }
}

} // namespace libre2c
} // namespace re2c

