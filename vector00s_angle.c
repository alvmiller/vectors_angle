#include <assert.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "vector00s_angle.h"

#define IS_INT_TYPE(x) _Generic((x), int: true, default: false)
#define CHECK_VECTOR00_COORDINATES_TYPE() \
    ({ \
        typeof(((vector00 *)NULL)->x) _x; \
        typeof(((vector00 *)NULL)->y) _y; \
        _Static_assert(IS_INT_TYPE(_x), "Bad type of object (field x)"); \
        _Static_assert(IS_INT_TYPE(_y), "Bad type of object (field y)"); \
    })

static inline double convert_angle_radians_to_degrees(double radians)
{
    return radians * 180.0 / M_PI;
}

static inline double calculate_angle_in_radians(int cross_product, int dot_product)
{
    return atan2(cross_product, dot_product);
}

static inline int calculate_cross_product(const vector00* v1, const vector00* v2)
{
    int cross_product = 0;
    int tmp1 = 0;
    int tmp2 = 0;

    // (v1->x * v2->y - v1->y * v2->x) ~ sinA
    if (__builtin_mul_overflow(v1->x, v2->y, &tmp1)
     || __builtin_mul_overflow(v1->y, v2->x, &tmp2)
     || __builtin_sub_overflow(tmp1, tmp2, &cross_product)) {
        exit(-2);
    }

    return cross_product;
}

static inline int calculate_dot_product(const vector00* v1, const vector00* v2)
{
    int dot_product = 0;
    int tmp1 = 0;
    int tmp2 = 0;

    // (v1->x * v2->x + v1->y * v2->y) ~ cosA
    if (__builtin_mul_overflow(v1->x, v2->x, &tmp1)
     || __builtin_mul_overflow(v1->y, v2->y, &tmp2)
     || __builtin_add_overflow(tmp1, tmp2, &dot_product)) {
        exit(-2);
    }

    return dot_product;
}

static inline bool is_equal(const vector00* v1, const vector00* v2)
{
    if (v1 == v2) {
        return true;
    }
    if (v1->x == v2->x && v1->y == v2->y) {
        return true;
    }
    return false;
}

int get_angle_between_vector00s(
    const vector00* v1,
    const vector00* v2,
    angle_type type,
    double *res)
{
    double angle = 0.0;
    int cross_product = 0;
    int dot_product = 0;

    CHECK_VECTOR00_COORDINATES_TYPE();

    if (v1 == NULL
     || v2 == NULL
     || res == NULL
     || (type != ANGLE_RADIANS_TYPE && type != ANGLE_DEGREES_TYPE)) {
        return -1;
    }
    
    if (is_equal(v1, v2)) {
        *res = 0.0;
        return 0;
    }
    /** @TODO: Check that both vectors are in the same line */

    cross_product = calculate_cross_product(v1, v2);
    dot_product = calculate_dot_product(v1, v2);
    angle = calculate_angle_in_radians(cross_product, dot_product);

    if (type == ANGLE_DEGREES_TYPE) {
        angle = convert_angle_radians_to_degrees(angle);
    }

    *res = angle;
    return 0;
}
