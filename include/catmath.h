#pragma once

#include <catsys.h>

#define CAT_MAX  1.e300

#define CAT_MIN -1.e300

#define CAT_SMALL 1e-10

#define CatAbs(a)  (((a) >= 0) ? a : -a)

#define CatMin(a, b) (((a)<(b)) ? (a) : (b))

#define CatMax(a, b) (((a)<(b)) ? (b) : (a))
