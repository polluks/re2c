#ifndef _RE2C_IR_RE_RE_
#define _RE2C_IR_RE_RE_

#include "src/util/c99_stdint.h"

#include "src/conf/opt.h"
#include "src/ir/rule.h"
#include "src/ir/regexp/regexp.h"
#include "src/util/range.h"
#include "src/util/slab_allocator.h"

namespace re2c
{

struct RE
{
	typedef slab_allocator_t<~0u, 4096> alc_t;
	enum type_t {NIL, SYM, ALT, CAT, ITER, REPEAT, TAG} type;
	union {
		const Range *sym;
		struct {
			RE *re1;
			RE *re2;
		} alt;
		struct {
			RE *re1;
			RE *re2;
		} cat;
		RE *iter;
		struct {
			RE *re;
			uint32_t upto;
		} repeat;
		struct {
			size_t idx;
			bool bottom;
		} tag;
	};
};

struct RESpec
{
	RE::alc_t alc;
	std::vector<RE*> res;
	std::vector<Tag> &tags;
	std::valarray<Rule> &rules;

	explicit RESpec(const std::vector<RegExpRule> &ast);
};

void find_fixed_tags(RESpec &spec, const opt_t *opts);
void insert_default_tags(RESpec &spec);

inline RE *re_nil(RE::alc_t &alc)
{
	RE *x = alc.alloct<RE>(1);
	x->type = RE::NIL;
	return x;
}

inline RE *re_sym(RE::alc_t &alc, const Range *r)
{
	RE *x = alc.alloct<RE>(1);
	x->type = RE::SYM;
	x->sym = r;
	return x;
}

inline RE *re_alt(RE::alc_t &alc, RE *x, RE *y)
{
	RE *z = alc.alloct<RE>(1);
	z->type = RE::ALT;
	z->alt.re1 = x;
	z->alt.re2 = y;
	return z;
}

inline RE *re_cat(RE::alc_t &alc, RE *x, RE *y)
{
	RE *z = alc.alloct<RE>(1);
	z->type = RE::CAT;
	z->cat.re1 = x;
	z->cat.re2 = y;
	return z;
}

inline RE *re_iter(RE::alc_t &alc, RE *x)
{
	RE *y = alc.alloct<RE>(1);
	y->type = RE::ITER;
	y->iter = x;
	return y;
}

inline RE *re_repeat(RE::alc_t &alc, RE *x, uint32_t n)
{
	RE *y = alc.alloct<RE>(1);
	y->type = RE::REPEAT;
	y->repeat.re = x;
	y->repeat.upto = n;
	return y;
}

inline RE *re_tag(RE::alc_t &alc, size_t i, bool b)
{
	RE *x = alc.alloct<RE>(1);
	x->type = RE::TAG;
	x->tag.idx = i;
	x->tag.bottom = b;
	return x;
}

} // namespace re2c

#endif // _RE2C_IR_RE_RE_