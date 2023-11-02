#pragma once

#ifndef VECTORS_ANGLE_H
#define VECTORS_ANGLE_H

/*
   Used only 2D integer coordinates (not floating point)
   
   We always can move vector's start dot to (0,0)
   and recalculate vector's coordinates
   
   A(Ax,Ay) B(Bx,By) -> V(Vx,Vy) : Vx=Bx-Ax Vy=By-Ay
   
   (v1,v2)=|v1||v2|cosL=v1x*v2x+v1y*v2y
   [v1,v2]=|v1||v2|sinL=v1x*v2y-v1y*v2x
   tgL=sinL/cosL=(v1x*v2y-v1y*v2x)/(v1x*v2x+v1y*v2y)=RES1/RES2
   L=atan2(RES1,RES2)
   
   Currently, each vector should be started from (0,0)
   
   reset; gcc -Werror vector00s_angle.c main.c -lm -o main; ./main
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
   https://www.geeksforgeeks.org/function-pointer-in-c/
   https://www.w3schools.com/c/c_enums.php
   https://stackoverflow.com/questions/141720/how-do-you-compare-structs-for-equality-in-c
   https://www.geeksforgeeks.org/c-exit-abort-and-assert-functions/
   https://gcc.gnu.org/onlinedocs/gcc/Integer-Overflow-Builtins.html
   https://www.tutorialspoint.com/c_standard_library/c_function_abs.htm
   https://gcc.gnu.org/onlinedocs/gcc/Typeof.html
   https://en.wikipedia.org/wiki/Assert.h
   https://copyprogramming.com/howto/how-to-compare-two-types-in-c#how-to-compare-data-in-c
   https://stackoverflow.com/questions/5989191/compare-two-floats
   https://www.geeksforgeeks.org/comparison-float-value-c/
   https://how-to.fandom.com/wiki/Howto_compare_floating_point_numbers_in_the_C_programming_language
 */

/* @TODO: Check that both vectors are in the same line */

typedef enum angle_type_t {
  ANGLE_RADIANS_TYPE,
  ANGLE_DEGREES_TYPE
} angle_type;

/* Currently, each vector should be started from (0,0) */
typedef struct vector00_t {
    int x;
    int y;
} vector00;

/* Currently, each vector should be started from (0,0) */
int get_angle_between_vector00s(
    const vector00* v1,
    const vector00* v2,
    angle_type type,
    double *res);

#endif /* !VECTORS_ANGLE_H */
