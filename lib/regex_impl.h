#ifndef _RE2C_LIB_REGEX_IMPL_
#define _RE2C_LIB_REGEX_IMPL_

#include "regex.h"
#include <stddef.h>
#include <map>
#include <vector>
#include <queue>

#include "src/dfa/determinization.h"
#include "src/nfa/nfa.h"


namespace re2c {
namespace libre2c {

typedef std::vector<tag_info_t> tag_path_t;

struct conf_t
{
    nfa_state_t *state;
    uint32_t origin;
    int32_t thist;

    inline conf_t(): state(NULL), origin(0), thist(HROOT) {}
    inline conf_t(nfa_state_t *s, uint32_t o, int32_t h)
        : state(s), origin(o), thist(h) {}
    inline conf_t(const conf_t &c, nfa_state_t *s)
        : state(s), origin(c.origin), thist(c.thist) {}
    inline conf_t(const conf_t &c, nfa_state_t *s, int32_t h)
        : state(s), origin(c.origin), thist(h) {}
};

struct ran_or_fin_t
{
    inline bool operator()(const conf_t &c);
};

typedef std::vector<conf_t> confset_t;
typedef confset_t::iterator confiter_t;
typedef confset_t::const_iterator cconfiter_t;
typedef confset_t::const_reverse_iterator rcconfiter_t;

template<typename history_type_t>
struct simctx_t
{
    typedef libre2c::conf_t conf_t;
    typedef std::vector<conf_t> confset_t;
    typedef confset_t::iterator confiter_t;
    typedef confset_t::const_iterator cconfiter_t;
    typedef confset_t::reverse_iterator rconfiter_t;
    typedef confset_t::const_reverse_iterator rcconfiter_t;
    typedef history_type_t history_t;

    const nfa_t &nfa;
    const nfa_t *nfa0;
    const size_t nsub;
    const int flags;

    history_t history;
    int32_t hidx;

    uint32_t step;

    size_t rule;

    const char *cursor;
    const char *marker;

    regoff_t *offsets1;
    regoff_t *offsets2;
    regoff_t *offsets3;
    bool *done;

    int32_t *newprectbl;
    int32_t *oldprectbl;
    size_t oldprecdim;
    histleaf_t *histlevel;
    std::vector<uint32_t> sortcores;
    std::vector<uint32_t> fincount;
    std::vector<int32_t> worklist;
    std::vector<cconfiter_t> stateiters;

    confset_t reach;
    confset_t state;
    std::vector<nfa_state_t*> gor1_topsort;
    std::vector<nfa_state_t*> gor1_linear;
    std::vector<nfa_state_t*> gtop_heap_storage;
    cmp_gtop_t gtop_cmp;
    gtop_heap_t gtop_heap;
    closure_stats_t dc_clstats;

    simctx_t(const nfa_t &nfa, const nfa_t *nfa0, size_t re_nsub, int flags);
    ~simctx_t();
    FORBID_COPY(simctx_t);
};

// tag history for lazy disambiguation (both POSIX and leftmost greedy)
struct zhistory_t
{
    struct node_t {
        tag_info_t info;
        hidx_t pred;
        uint32_t orig;
        uint32_t step;

        inline node_t(tag_info_t info, hidx_t pred, uint32_t orig, uint32_t step)
            : info(info), pred(pred), orig(orig), step(step) {}
    };

    struct cache_entry_t
    {
        int32_t prec1;
        int32_t prec2;
        int32_t prec;
    };
    typedef std::map<uint64_t, cache_entry_t> cache_t;

    std::vector<node_t> nodes;
    cache_t cache;

    inline zhistory_t(): nodes(), cache() { init(); }
    inline void init();
    inline node_t &node(hidx_t i) { return nodes[static_cast<uint32_t>(i)]; }
    inline const node_t &node(hidx_t i) const { return nodes[static_cast<uint32_t>(i)]; }
    template<typename ctx_t> inline hidx_t link(ctx_t &ctx
        , const typename ctx_t::conf_t &conf);
    template<typename ctx_t> static int32_t precedence(ctx_t &ctx
        , const typename ctx_t::conf_t &x, const typename ctx_t::conf_t &y
        , int32_t &prec1, int32_t &prec2);
    FORBID_COPY(zhistory_t);
};

// tag history for Kuklewicz disambiguation (POSIX semantics)
struct khistory_t
{
    struct node_t {
        tag_info_t info;
        hidx_t pred;

        inline node_t(tag_info_t info, hidx_t pred)
            : info(info), pred(pred) {}
    };

    std::vector<node_t> nodes;
    std::vector<int32_t> path1;
    std::vector<int32_t> path2;

    inline khistory_t(): nodes(), path1(), path2() { init(); }
    inline void init();
    inline node_t &node(hidx_t i) { return nodes[static_cast<uint32_t>(i)]; }
    inline const node_t &node(hidx_t i) const { return nodes[static_cast<uint32_t>(i)]; }
    template<typename ctx_t> inline hidx_t link(ctx_t &ctx
        , const typename ctx_t::conf_t &conf);
    template<typename ctx_t> static int32_t precedence(ctx_t &ctx
        , const typename ctx_t::conf_t &x, const typename ctx_t::conf_t &y
        , int32_t &prec1, int32_t &prec2);
    FORBID_COPY(khistory_t);
};

typedef simctx_t<phistory_t> psimctx_t;
typedef simctx_t<lhistory_t> lsimctx_t;
typedef simctx_t<zhistory_t> pzsimctx_t;
typedef simctx_t<zhistory_t> lzsimctx_t;
typedef simctx_t<khistory_t> ksimctx_t;

int regexec_dfa(const regex_t *preg, const char *string, size_t nmatch, regmatch_t pmatch[], int eflags);
int regexec_nfa_posix(const regex_t *preg, const char *string, size_t nmatch, regmatch_t pmatch[], int eflags);
int regexec_nfa_posix_trie(const regex_t *preg, const char *string, size_t nmatch, regmatch_t pmatch[], int eflags);
int regexec_nfa_posix_backward(const regex_t *preg, const char *string, size_t nmatch, regmatch_t pmatch[], int eflags);
int regexec_nfa_posix_kuklewicz(const regex_t *preg, const char *string, size_t nmatch, regmatch_t pmatch[], int eflags);
int regexec_nfa_leftmost(const regex_t *preg, const char *string, size_t nmatch, regmatch_t pmatch[], int eflags);
int regexec_nfa_leftmost_trie(const regex_t *preg, const char *string, size_t nmatch, regmatch_t pmatch[], int eflags);

template<typename history_t>
simctx_t<history_t>::simctx_t(const nfa_t &nfa, const nfa_t *nfa0, size_t re_nsub, int flags)
    : nfa(nfa)
    , nfa0(nfa0)
    , nsub(2 * (re_nsub - 1))
    , flags(flags)
    , history()
    , hidx(HROOT)
    , step(0)
    , rule(Rule::NONE)
    , cursor(NULL)
    , marker(NULL)
    , offsets1(NULL)
    , offsets2(NULL)
    , offsets3(NULL)
    , done(NULL)
    , newprectbl(NULL)
    , oldprectbl(NULL)
    , oldprecdim(0)
    , histlevel(NULL)
    , sortcores()
    , fincount()
    , worklist()
    , stateiters()
    , reach()
    , state()
    , gor1_topsort()
    , gor1_linear()
    , gtop_heap_storage()
    , gtop_cmp()
    , gtop_heap(gtop_cmp, gtop_heap_storage)
    , dc_clstats()
{
    const size_t
        ntags = nfa.tags.size(),
        nstates = nfa.size,
        ncores = nfa.ncores;

    state.reserve(nstates);
    reach.reserve(nstates);

    done = new bool[nsub];

    if (!(flags & REG_TRIE)) {
        offsets1 = new regoff_t[nsub * ncores];
        offsets2 = new regoff_t[nsub * ncores];
        offsets3 = new regoff_t[nsub];
    }
    if (!(flags & REG_LEFTMOST) && !(flags & REG_TRIE)) {
        const size_t dim = (flags & REG_KUKLEWICZ) ? ntags : ncores;
        newprectbl = new int32_t[ncores * dim];
        oldprectbl = new int32_t[ncores * dim];
        histlevel = new histleaf_t[ncores];
        sortcores.reserve(ncores);
        fincount.resize(ncores + 1);
        worklist.reserve(nstates);
    }
    if (flags & REG_KUKLEWICZ) {
        stateiters.reserve(ncores);
    }

    if (flags & REG_GTOP) {
        gtop_heap_storage.reserve(nstates);
    }
    else {
        gor1_topsort.reserve(nstates);
        gor1_linear.reserve(nstates);
    }
}

template<typename history_t>
simctx_t<history_t>::~simctx_t()
{
    delete[] done;
    if (!(flags & REG_TRIE)) {
        delete[] offsets1;
        delete[] offsets2;
        delete[] offsets3;
    }
    if (!(flags & REG_LEFTMOST) && !(flags & REG_TRIE)) {
        delete[] newprectbl;
        delete[] oldprectbl;
        delete[] histlevel;
    }
    if (flags & REG_BACKWARD) {
        delete &nfa0->charset;
        delete &nfa0->rules;
        delete &nfa0->tags;
        delete nfa0;
    }
}

template<typename history_t>
void init(simctx_t<history_t> &ctx, const char *string)
{
    ctx.reach.clear();
    ctx.state.clear();
    ctx.history.init();
    ctx.hidx = HROOT;
    ctx.step = 0;
    ctx.rule = Rule::NONE;
    ctx.cursor = ctx.marker = string;
    ctx.sortcores.clear();
    DASSERT(ctx.worklist.empty());
    DASSERT(ctx.gor1_topsort.empty());
    DASSERT(ctx.gor1_linear.empty());
    DASSERT(ctx.gtop_heap.empty());
}

static inline regoff_t *offs_addr(regmatch_t pmatch[], size_t t)
{
    regmatch_t *m = &pmatch[t / 2 + 1];
    return t % 2 == 0 ? &m->rm_so : &m->rm_eo;
}

template<typename history_t>
int finalize(const simctx_t<history_t> &ctx, const char *string, size_t nmatch,
    regmatch_t pmatch[])
{
    if (ctx.rule == Rule::NONE) {
        return REG_NOMATCH;
    }

    regmatch_t *m = pmatch;
    m->rm_so = 0;
    m->rm_eo = ctx.marker - string - 1;

    const std::vector<Tag> &tags = ctx.nfa.tags;
    size_t todo = nmatch * 2;
    bool *done = ctx.done;
    memset(done, 0, ctx.nsub * sizeof(bool));

    for (int32_t i = ctx.hidx; todo > 0 && i != HROOT; ) {
        const typename history_t::node_t &n = ctx.history.node(i);
        const Tag &tag = tags[n.info.idx];
        const size_t t = tag.ncap;

        // Set negative tag, together with its sibling and nested tags (if any),
        // unless already set. Fictive tags may have nested non-fictive tags.
        if (n.info.neg && (fictive(tag) || !done[t])) {
            for (size_t l = tag.lnest; l < tag.hnest; ++l) {
                const Tag &ntag = tags[l];
                const size_t nt = ntag.ncap;
                if (!fictive(ntag) && !done[nt] && nt < nmatch * 2) {
                    done[nt] = true;
                    --todo;
                    *offs_addr(pmatch, nt) = -1;
                }
            }
        }

        // Set positive tag (unless already set).
        else if (!fictive(tag) && !done[t] && t < nmatch * 2) {
            done[t] = true;
            --todo;
            *offs_addr(pmatch, t) = static_cast<regoff_t>(n.step);
        }

        i = n.pred;
    }

    return 0;
}

template<typename history_t>
void update_offsets(simctx_t<history_t> &ctx, const conf_t &c, uint32_t id)
{
    const size_t nsub = ctx.nsub;
    regoff_t *o;
    const std::vector<Tag> &tags = ctx.nfa.tags;
    nfa_state_t *s = c.state;
    bool *done = ctx.done;

    if (s->type == nfa_state_t::FIN) {
        ctx.marker = ctx.cursor;
        ctx.rule = 0;
        o = ctx.offsets3;
    }
    else {
        o = ctx.offsets1 + id * nsub;
    }

    memcpy(o, ctx.offsets2 + c.origin * nsub, nsub * sizeof(regoff_t));
    memset(done, 0, nsub * sizeof(bool));

    for (int32_t i = c.thist; i != HROOT; ) {
        const typename history_t::node_t &n = ctx.history.node(i);
        const Tag &tag = tags[n.info.idx];
        const size_t t = tag.ncap;

        // Update negative tag, together with its sibling and nested tags (if any),
        // unless already updated. Fictive tags may have nested non-fictive tags.
        if (n.info.neg && (fictive(tag) || !done[t])) {
            for (size_t l = tag.lnest; l < tag.hnest; ++l) {
                const Tag &ntag = tags[l];
                const size_t nt = ntag.ncap;
                if (!fictive(ntag) && !done[nt]) {
                    done[nt] = true;
                    o[nt] = -1;
                }
            }
        }

        // Update positive tag (unless already updated).
        else if (!fictive(tag) && !done[t]) {
            done[t] = true;
            o[t] = static_cast<regoff_t>(ctx.step);
        }

        i = n.pred;
    }
}

bool ran_or_fin_t::operator()(const conf_t &c)
{
    return c.state->type == nfa_state_t::RAN
        || c.state->type == nfa_state_t::FIN;
}

void zhistory_t::init()
{
    nodes.clear();
    nodes.push_back(node_t(NOINFO, -1, 0, 0));
    cache.clear();
}

void khistory_t::init()
{
    nodes.clear();
    nodes.push_back(node_t(NOINFO, -1));
}

template<typename ctx_t>
hidx_t zhistory_t::link(ctx_t &ctx, const typename ctx_t::conf_t &conf)
{
    const int32_t i = static_cast<int32_t>(nodes.size());
    nodes.push_back(node_t(conf.state->tag.info, conf.thist, conf.origin, ctx.step));
    return i;
}

template<typename ctx_t>
hidx_t khistory_t::link(ctx_t &/* ctx */, const typename ctx_t::conf_t &conf)
{
    const int32_t i = static_cast<int32_t>(nodes.size());
    nodes.push_back(node_t(conf.state->tag.info, conf.thist));
    return i;
}

} // namespace libre2c
} // namespace re2c

#endif // _RE2C_LIB_REGEX_IMPL_
