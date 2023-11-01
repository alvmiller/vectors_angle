#include <math.h>
#include <stdio.h>

#include "func.h"

double get_angle_degree_between_vectors(const vector* v1, const vector* v2)
{
    int cross_product = v1->x * v2->y - v1->y * v2->x; // for sin
    int dot_product = v1->x * v2->x + v1->y * v2->y; // for cos
    double angle_radians = atan2(cross_product, dot_product); // C Math Library call
    double angle_degrees = angle_radians * 180 / M_PI;
    
    return angle_degrees;
}
