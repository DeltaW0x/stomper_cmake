#pragma once

#ifndef VECTOR3_INLINE_IMPL
#error "Do not include vector3.inl, include engine/math/vector3.hpp instead"
#else

template<typename T>
constexpr Vector3<T> Vector3<T>::Zero = Vector3(0.0f, 0.0f, 0.0f);

template<typename T>
constexpr Vector3<T> Vector3<T>::One = Vector3(1.0f, 1.0, 1.0f);

template<typename T>
constexpr Vector3<T> Vector3<T>::Up = Vector3(0.0f, 1.0f, 0.0f);

template<typename T>
constexpr Vector3<T> Vector3<T>::Down = Vector3(0.0f, std::is_signed_v<T> ? -1.0f : 0.0f, 0.0f);

template<typename T>
constexpr Vector3<T> Vector3<T>::Left = Vector3(std::is_signed_v<T> ? -1.0f : 0.0f, 0.0f, 0.0f);

template<typename T>
constexpr Vector3<T> Vector3<T>::Right = Vector3(1.0f, 0.0f, 0.0f);

template<typename T>
constexpr Vector3<T> Vector3<T>::Forward = Vector3(0.0f, 0.0f, 1.0f);


template<typename T>
constexpr bool Vector3<T>::operator==(const Vector3 &v) const
{
    return x == v.x && y == v.y && z == v.z;
}

template<typename T>
constexpr Vector3<T> Vector3<T>::operator-() const
{
    static_assert(std::is_signed_v<T>, "You can't negate an unsigned vector");
    return Vector3(-x, -y, -z);
}

template<typename T>
constexpr Vector3<T> Vector3<T>::operator+(const Vector3 &rhs) const
{
    return Vector3(x + rhs.x, y + rhs.y, z + rhs.z);
}

template<typename T>
constexpr Vector3<T> Vector3<T>::operator-(const Vector3 &rhs) const
{
    return Vector3(x - rhs.x, y - rhs.y, z - rhs.z);
}

template<typename T>
constexpr Vector3<T> Vector3<T>::operator*(T rhs) const
{
    return Vector3(x * rhs, y * rhs, z * rhs);
}

template<typename T>
constexpr Vector3<T> operator*(T lhs, const Vector3<T> &rhs)
{
    return Vector3(lhs * rhs.x, lhs * rhs.y, lhs * rhs.z);
}

template<typename T>
constexpr Vector3<T> Vector3<T>::operator/(T rhs) const
{
    return Vector3(x / rhs, y / rhs, z / rhs);
}

template<typename T>
constexpr Vector3<T> &Vector3<T>::operator+=(const Vector3 &rhs)
{
    x += rhs.x;
    y += rhs.y;
    z += rhs.z;
    return *this;
}

template<typename T>
constexpr Vector3<T> &Vector3<T>::operator-=(const Vector3 &rhs)
{
    x -= rhs.x;
    y -= rhs.y;
    z -= rhs.z;
    return *this;
}

template<typename T>
constexpr Vector3<T> &Vector3<T>::operator*=(T rhs)
{
    x *= rhs.x;
    y *= rhs.y;
    z *= rhs.z;
    return *this;
}

template<typename T>
constexpr Vector3<T> &Vector3<T>::operator/=(T rhs)
{
    x /= rhs.x;
    y /= rhs.y;
    z /= rhs.z;
    return *this;
}

template<typename T>
auto Vector3<T>::length() const
{
    return std::sqrt(x * x + y * y + z * z);
}

template<typename T>
constexpr T Vector3<T>::sq_length() const
{
    return x * x + y * y + z * z;
}

template<typename T>
Vector3<T> &Vector3<T>::normalize()
{
    if (auto len = length(); len > m_epsilon)
    {
        auto inv = 1.0f / len;
        return *this *= inv;
    }
    x = 0.0f;
    y = 0.0f;
    z = 0.0f;
    return *this;
}

template<typename T>
Vector3<T> Vector3<T>::normalized() const
{
    if (auto len = length(); len > m_epsilon)
    {
        auto inv = 1.0f / len;
        return Vector3(x * inv, y * inv, z * inv);
    }
    return Vector3(0.0f, 0.0f, 0.0f);
}

template<typename T>
constexpr T Vector3<T>::dot(const Vector3 &lhs, const Vector3 &rhs)
{
    return lhs.x * rhs.x + lhs.y * rhs.y + lhs.z * rhs.z;
}

template<typename T>
constexpr Vector3<T> Vector3<T>::cross(const Vector3 &lhs, const Vector3 &rhs)
{
    return Vector3(lhs.y * rhs.z - lhs.z * rhs.y, lhs.z * rhs.x - lhs.x * rhs.z, lhs.x * rhs.y - lhs.y * rhs.x);
}

#endif
