#pragma once
#include <cmath>
#include "engine/common.hpp"

#ifndef VECTOR2_INLINE_IMPL
#define VECTOR2_INLINE_IMPL
#endif

namespace stmp::math
{
    struct Vector2f
    {
        constexpr Vector2f();
        constexpr Vector2f(float v);
        constexpr Vector2f(float x, float y);

        constexpr FORCE_INLINE bool operator==(const Vector2f &v) const;

        constexpr FORCE_INLINE Vector2f operator-() const;
        constexpr FORCE_INLINE Vector2f operator+(const Vector2f &rhs) const;
        constexpr FORCE_INLINE Vector2f operator-(const Vector2f &rhs) const;
        constexpr FORCE_INLINE Vector2f operator*(float rhs) const;
        constexpr FORCE_INLINE Vector2f operator/(float rhs) const;

        constexpr FORCE_INLINE Vector2f &operator+=(const Vector2f &rhs);
        constexpr FORCE_INLINE Vector2f &operator-=(const Vector2f &rhs);
        constexpr FORCE_INLINE Vector2f &operator*=(float rhs);
        constexpr FORCE_INLINE Vector2f &operator/=(float rhs);

        FORCE_INLINE auto length() const;
        constexpr FORCE_INLINE float sq_length() const;

        Vector2f &normalize();
        Vector2f normalized() const;

        static constexpr FORCE_INLINE float dot(const Vector2f &lhs, const Vector2f &rhs);

        union
        {
            struct
            {
                float x, y;
            };
            struct
            {
                float u, v;
            };
            struct
            {
                float r, g;
            };
            float data[2];
        };

        static const Vector2f Zero, One, Up, Down, Left, Right;

    private:
        static constexpr f32 m_epsilon = 0.00001f;
    };

#include "inl/vector2.inl"
} // namespace stpm::math

#undef VECTOR2_INLINE_IMPL