#pragma once

namespace stmp::simd
{
#if defined(__AVX2__)
#include <immintrin.h>
#elif defined(__ARM_NEON)
#include <arm_neon.h>
#else
#error "You need a computer with support for either AVX2 or NEON in order to compile this program"
#endif
} // namespace stmp::simd
