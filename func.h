#pragma once

#ifndef FUNCANGLE_H
#define FUNCANGLE_H

/*
   Used only 2D integer coordinates (not floating point)
   
   We always can move vector's start dot to (0,0)
   and recalculate vector's coordinates
   
   A(Ax,Ay) B(Bx,By) -> V(Vx,Vy) : Vx=Bx-Ax Vy=By-Ay
   
   (v1,v2)=|v1||v2|cosL=v1x*v2x+v1y*v2y
   [v1,v2]=|v1||v2|sinL=v1x*v2y-v1y*v2x
   tgL=sinL/cosL=(v1x*v2y-v1y*v2x)/(v1x*v2x+v1y*v2y)=RES1/RES2
   L=atan2(RES1,RES2)
   
   gcc func.c main.c -lm -o main
 */

/*
   https://stackoverflow.com/questions/21483999/using-atan2-to-find-angle-between-two-vectors
   https://wumbo.net/formulas/angle-between-two-vectors-2d/
   https://gamedev.stackexchange.com/questions/69649/using-atan2-to-calculate-angle-between-two-vectors
   https://wumbo.net/functions/arc-tangent-2/
   https://www.programiz.com/c-programming/library-function/math.h/atan2
   https://www.tutorialspoint.com/c_standard_library/c_function_atan2.htm
   https://en.cppreference.com/w/c/numeric/math/atan2
   https://en.wikipedia.org/wiki/Euclidean_vector
   https://en.wikipedia.org/wiki/Coordinate_vector
   https://courses.lumenlearning.com/suny-osuniversityphysics/chapter/2-2-coordinate-systems-and-components-of-a-vector/
   https://www.programiz.com/c-programming/library-function/math.h/atan2
   https://www.tutorialspoint.com/c_standard_library/c_function_atan2.htm
 */

/* @TODO: Check overflow in  */

typedef struct vector_t {
    int x;
    int y;
} vector;

double get_angle_degree_between_vectors(const vector* v1, const vector* v2);

#endif /* !FUNCANGLE_H */
