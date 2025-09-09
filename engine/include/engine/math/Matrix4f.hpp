#pragma once
#include <cmath>
#include "engine/common.hpp"
#include "vector4.hpp"

#ifndef MATRIX4_INLINE_IMPL
#define MATRIX4_INLINE_IMPL
#endif

namespace stmp::math
{
    struct Matrix4f
    {
        constexpr Matrix4f();
        constexpr Matrix4f(float v);
        constexpr Matrix4f(Vector4f row0, Vector4f row1, Vector4f row2, Vector4f row3);
        constexpr Matrix4f(float m00, float m01, float m02, float m03, float m10, float m11, float m12, float m13,
                          float m20, float m21, float m22, float m23, float m30, float m31, float m32, float m33);

        constexpr FORCE_INLINE Matrix4f operator-() const;
        constexpr FORCE_INLINE bool operator==(const Matrix4f &rhs) const;

        constexpr FORCE_INLINE Matrix4f operator+(const Matrix4f &rhs) const;
        constexpr FORCE_INLINE Matrix4f operator-(const Matrix4f &rhs) const;
        constexpr FORCE_INLINE Matrix4f operator*(const Matrix4f &rhs) const;

        constexpr FORCE_INLINE Matrix4f operator+(float rhs) const;
        constexpr FORCE_INLINE Matrix4f operator-(float rhs) const;
        constexpr FORCE_INLINE Matrix4f operator*(float rhs) const;
        constexpr FORCE_INLINE Matrix4f operator/(float rhs) const;

        static FORCE_INLINE Matrix4f perspective_fov(float fov, float aspect, float z_near, float z_far);
        static FORCE_INLINE Matrix4f perspective_offcenter(float left, float right, float bottom, float top, float z_near, float z_far);

        union
        {
            struct
            {
                float m00, m01, m02, m03;
                float m10, m11, m12, m13;
                float m20, m21, m22, m23;
                float m30, m31, m32, m33;
            };
            Vector4f rows[4];
            float data[16];
        };

        static const Matrix4f Zero, Identity;
    };

#include "inl/Matrix4f.inl"
} // namespace stmp::math

#undef MATRIX4_INLINE_IMPL
