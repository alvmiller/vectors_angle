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
    const vector00* restrict v1,
    const vector00* restrict v2,
    angle_type type,
    double *res);

#endif /* !VECTORS_ANGLE_H */
