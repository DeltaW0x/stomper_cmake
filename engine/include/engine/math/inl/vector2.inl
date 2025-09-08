#pragma once

#ifndef VECTOR2_INLINE_IMPL
#error "Do not include vector2.inl, include engine/math/vector2.hpp instead"
#else

template<typename T>
constexpr Vector2<T> Vector2<T>::Zero = Vector2(0.0f, 0.0f);

template<typename T>
constexpr Vector2<T> Vector2<T>::One = Vector2(1.0f, 1.0f);

template<typename T>
constexpr Vector2<T> Vector2<T>::Up = Vector2(0.0f, 1.0f);

template<typename T>
constexpr Vector2<T> Vector2<T>::Down = Vector2(0.0f, std::is_signed_v<T> ? -1.0f : 0.0f);

template<typename T>
constexpr Vector2<T> Vector2<T>::Left = Vector2(std::is_signed_v<T> ? -1.0f : -0.0f, 0.0f);

template<typename T>
constexpr Vector2<T> Vector2<T>::Right = Vector2(1.0f, 0.0f);

template<typename T>
constexpr bool Vector2<T>::operator==(const Vector2& v) const
{
    return x == v.x && y == v.y;
}

template<typename T>
constexpr Vector2<T> Vector2<T>::operator-() const
{
    static_assert(std::is_signed_v<T>, "You can't negate an unsigned vector");
    return Vector2(-x, -y);
}

template<typename T>
constexpr Vector2<T> Vector2<T>::operator+(const Vector2 &rhs) const
{
    return Vector2(x + rhs.x, y + rhs.y);
}

template<typename T>
constexpr Vector2<T> Vector2<T>::operator-(const Vector2 &rhs) const
{
    return Vector2(x - rhs.x, y - rhs.y);
}

template<typename T>
constexpr Vector2<T> Vector2<T>::operator*(T rhs) const
{
    return Vector2(x * rhs, y * rhs);
}

template<typename T>
constexpr Vector2<T> operator*(T lhs, const Vector2<T> &rhs)
{
    return Vector2(lhs * rhs.x, lhs * rhs.y);
}

template<typename T>
constexpr Vector2<T> Vector2<T>::operator/(T rhs) const
{
    return Vector2(x / rhs, y / rhs);
}

template<typename T>
constexpr Vector2<T>& Vector2<T>::operator+=(const Vector2 &rhs)
{
    x += rhs.x;
    y += rhs.y;
    return *this;
}

template<typename T>
constexpr Vector2<T>& Vector2<T>::operator-=(const Vector2 &rhs)
{
    x -= rhs.x;
    y -= rhs.y;
    return *this;
}

template<typename T>
constexpr Vector2<T>& Vector2<T>::operator*=(T rhs)
{
    x *= rhs.x;
    y *= rhs.y;
    return *this;
}

template<typename T>
constexpr Vector2<T>& Vector2<T>::operator/=(T rhs)
{
    x /= rhs.x;
    y /= rhs.y;
    return *this;
}

template<typename T>
auto Vector2<T>::length() const
{
    return std::sqrt(x * x + y * y);
}

template<typename T>
constexpr T Vector2<T>::sq_length() const
{
    return x * x + y * y;
}

template<typename T>
Vector2<T>& Vector2<T>::normalize()
{
    if (auto len = length(); len > m_epsilon)
    {
        return *this /= len;
    }
    x = 0.0f;
    y = 0.0f;
    return *this;
}

template<typename T>
Vector2<T> Vector2<T>::normalized() const
{
    if (auto len = length(); len > m_epsilon)
    {
        return Vector2(x / len, y / len);
    }
    return Vector2(0.0f, 0.0f);
}

template<typename T>
constexpr T Vector2<T>::dot(const Vector2 &lhs, const Vector2 &rhs)
{
    return lhs.x * rhs.x + lhs.y * rhs.y;
}

#endif