#pragma once
#include <cmath>
#include "engine/common.hpp"

#ifndef VECTOR4_INLINE_IMPL
#define VECTOR4_INLINE_IMPL
#endif


namespace stmp::math
{
    struct Vector4f
    {

        constexpr Vector4f();
        constexpr Vector4f(float v);
        constexpr Vector4f(float x, float y, float z, float w);

        constexpr FORCE_INLINE bool operator==(const Vector4f& v) const;

        constexpr FORCE_INLINE Vector4f operator-() const;
        constexpr FORCE_INLINE Vector4f operator+(const Vector4f &rhs) const;
        constexpr FORCE_INLINE Vector4f operator-(const Vector4f &rhs) const;
        constexpr FORCE_INLINE Vector4f operator*(float rhs) const;
        constexpr FORCE_INLINE Vector4f operator/(float rhs) const;

        constexpr FORCE_INLINE Vector4f& operator+=(const Vector4f &rhs);
        constexpr FORCE_INLINE Vector4f& operator-=(const Vector4f &rhs);
        constexpr FORCE_INLINE Vector4f& operator*=(float rhs);
        constexpr FORCE_INLINE Vector4f& operator/=(float rhs);

        FORCE_INLINE auto length() const;
        constexpr FORCE_INLINE float sq_length() const;

        FORCE_INLINE Vector4f& normalize();
        FORCE_INLINE Vector4f normalized() const;

        union
        {
            struct
            {
                float x, y, z, w;
            };
            struct
            {
                float r, g, b, a;
            };
            float data[4];
        };

        static const Vector4f Zero, One, Up, Down, Left, Right, Forward, Backward;

    private:
        static constexpr f32 m_epsilon = 0.00001f;
    };
#include "inl/vector4.inl"
} // namespace stpm::math

#undef VECTOR4_INLINE_IMPL