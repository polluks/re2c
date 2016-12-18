#ifndef _RE2C_GLOBALS_
#define _RE2C_GLOBALS_

#include <string>

#include "src/util/c99_stdint.h"

namespace re2c
{

extern bool bUsedYYBitmap;
extern bool bWroteGetState;
extern bool bWroteCondCheck;
extern uint32_t last_fill_index;
extern std::string yySetupRule;

} // end namespace re2c

#endif // _RE2C_GLOBALS_
