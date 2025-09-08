#include <engine/math/vector2.hpp>
#include <engine/math/vector3.hpp>
#include <catch2/catch_approx.hpp>
#include <catch2/catch_test_macros.hpp>

namespace stpm::math
{
    TEST_CASE("Vector2<float> math functions")
    {
        using Vector2f = Vector2<float>;

        REQUIRE(Vector2f(10, 10) + Vector2f(20, 30) == Vector2f(30, 40));
        REQUIRE(Vector2f(10, 10) - Vector2f(20, 30) == Vector2f(-10, -20));
        REQUIRE(Vector2f(10, 10) * 0.5f == Vector2f(5, 5));
        REQUIRE(Vector2f(10, 10) / 0.5f == Vector2f(20, 20));

    };

    TEST_CASE("Vector3<float> math functions")
    {
        using Vector3f = Vector3<float>;

        REQUIRE(Vector3f(10, 10, 10) + Vector3f(20, 30, 30) == Vector3f(30, 40, 40));
        REQUIRE(Vector3f(10, 10, 10) - Vector3f(20, 30, 30) == Vector3f(-10, -20, -20));
        REQUIRE(Vector3f(10, 10, 10) * 0.5f == Vector3f(5, 5, 5));
        REQUIRE(Vector3f(10, 10, 10) / 0.5f == Vector3f(20, 20, 20));

    };
}