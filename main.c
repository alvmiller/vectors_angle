#include <stdio.h>

#include "func.h"

int main()
{
    vector va = { .x = 0, .y = 2 };
    vector vb = { .x = 2, .y = 0 };

    double angle = get_angle_degree_between_vectors(&va, &vb);
    printf("Angle = %lf\n", angle);
    angle = get_angle_degree_between_vectors(&vb, &va);
    printf("Angle = %lf\n", angle);

    return 0;
}
