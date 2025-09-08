#pragma once
#include <cmath>
#include "engine/common.hpp"

#ifndef VECTOR2_INLINE_IMPL
#define VECTOR2_INLINE_IMPL
#endif

namespace stpm::math
{
    template<typename T>
    struct Vector2
    {
        constexpr Vector2() : x(0.0f), y(0.0f) {}
        constexpr Vector2(T v) : x(v), y(v) {}
        constexpr Vector2(T x, T y) : x(x), y(y) {}

        constexpr FORCE_INLINE bool operator==(const Vector2 &v) const;

        constexpr FORCE_INLINE Vector2 operator-() const;
        constexpr FORCE_INLINE Vector2 operator+(const Vector2 &rhs) const;
        constexpr FORCE_INLINE Vector2 operator-(const Vector2 &rhs) const;
        constexpr FORCE_INLINE Vector2 operator*(T rhs) const;
        constexpr FORCE_INLINE Vector2 operator/(T rhs) const;

        constexpr FORCE_INLINE Vector2 &operator+=(const Vector2 &rhs);
        constexpr FORCE_INLINE Vector2 &operator-=(const Vector2 &rhs);
        constexpr FORCE_INLINE Vector2 &operator*=(T rhs);
        constexpr FORCE_INLINE Vector2 &operator/=(T rhs);

        FORCE_INLINE auto length() const;
        constexpr FORCE_INLINE T sq_length() const;

        Vector2 &normalize();
        Vector2 normalized() const;

        static constexpr FORCE_INLINE T dot(const Vector2 &lhs, const Vector2 &rhs);

        union
        {
            struct
            {
                T x, y;
            };
            struct
            {
                T u, v;
            };
            struct
            {
                T r, g;
            };
            T data[2];
        };

        static const Vector2 Zero, One, Up, Down, Left, Right;

    private:
        static constexpr f32 m_epsilon = 0.00001f;
    };

    typedef Vector2<i32> Vector2i;
    typedef Vector2<u32> Vector2u;
    typedef Vector2<f32> Vector2f;
    typedef Vector2<f64> Vector2d;

#include "inl/vector2.inl"
} // namespace stpm::math

#undef VECTOR2_INLINE_IMPL