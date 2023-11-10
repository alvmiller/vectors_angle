#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "vector00s_angle.h"

int main()
{
    int res = -1;
    const double epsilon = 0.0001;
    double angle = 0.0;
    const vector00 va = { .x = 0, .y = 2 };
    const vector00 vb = { .x = 2, .y = 0 };
    angle_type type = ANGLE_DEGREES_TYPE;

    res = get_angle_between_vector00s(&va, &vb, ANGLE_DEGREES_TYPE, &angle);
    if (res != 0) {
        printf("Call failed (1)!\n");
        exit(1);
    }
    printf("Angle (1) = %lf\n", angle);
    assert(fabs(angle - (-90.0)) < epsilon);

    res = get_angle_between_vector00s(&vb, &va, ANGLE_DEGREES_TYPE, &angle);
    if (res != 0) {
        printf("Call failed (2)!\n");
        exit(2);
    }
    printf("Angle (2) = %lf\n", angle);
    assert(fabs(angle - 90.0) < epsilon);

    return 0;
}
