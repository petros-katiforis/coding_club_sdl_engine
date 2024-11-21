#ifndef _NG_MATH_H
#define _NG_MATH_H

#include <SDL2/SDL.h>
#include <stdbool.h>

typedef struct
{
    float x, y;
} ng_vec2_t;

// Much faster to just copy and return by value,
// no need to introduce indirection (pointers) like previously.
// Let's hope that our compiler will store this struct on a set of registers
ng_vec2_t ng_vec2_add(ng_vec2_t first, ng_vec2_t second);
ng_vec2_t ng_vec2_subtract(ng_vec2_t first, ng_vec2_t second);
ng_vec2_t ng_vec2_multiply_by_scalar(ng_vec2_t src, float scalar);

float ng_vec2_get_magnitude(ng_vec2_t vector);
ng_vec2_t ng_vec2_normalize(ng_vec2_t src);

bool ng_point_in_rect(SDL_Rect *rect, int x, int y);

#endif
