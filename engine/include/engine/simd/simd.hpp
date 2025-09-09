#pragma once
#include <spdlog/spdlog.h>

#ifndef SIMD_INLINE_IMPL
#define SIMD_INLINE_IMPL
#endif

namespace stmp::simd
{
#if defined(__AVX2__)
#include <immintrin.h>
#elif defined(__ARM_NEON)
#include <arm_neon.h>
#else
#error "You need a computer with support for either AVX2 or NEON in order to compile this program"
#endif

    template <typename T, uint8_t N>
    class VectorLanes
    {
        static_assert(sizeof(T) == 0, "VectorLanes lanes type must be floating point");
    };

    template<uint8_t N>
    class VectorLanes<float, N>
    {
        static_assert(N >= 4, "VectorLanes lanes count must be 4 or more");
        static_assert((N & (N-1)) == 0, "VectorLanes lanes count must be power of 2");
    public:
        VectorLanes();

        void load(float* data);
        void store(float* data);

        bool operator==(const VectorLanes& rhs) const;

        VectorLanes operator+(const VectorLanes& rhs) const;
        VectorLanes operator-(const VectorLanes& rhs) const;
        VectorLanes operator*(const VectorLanes& rhs) const;
        VectorLanes operator/(const VectorLanes& rhs) const;

    private:
#if defined(__AVX2__)
        static constexpr int reg_lanes = 8;
        using reg_t = __m256;
#elif defined(__ARM_NEON__)
        static constexpr int reg_lanes = 4;
        using reg_t = float32x4_t;
#endif
        static constexpr int reg_count = (N + reg_lanes - 1) / reg_lanes;
        reg_t regs[reg_count];
    };

#if defined(__AVX2__)

#elif defined(__ARM_NEON__)
#include "inl/simd_neon.inl"
#endif

} // namespace stmp::simd

#undef SIMD_INLINE_IMPL