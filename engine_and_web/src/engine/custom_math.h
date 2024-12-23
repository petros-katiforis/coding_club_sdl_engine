#ifndef _NG_CUSTOM_MATH_H
#define _NG_CUSTOM_MATH_H

#include <stdbool.h>
#include <SDL2/SDL.h>

typedef struct
{
    float x, y;
} ng_vec2_t;

float ng_vector_get_magnitude(ng_vec2_t vec);
ng_vec2_t ng_vec2_normalize(ng_vec2_t vec);

ng_vec2_t ng_vec2_add(ng_vec2_t first, ng_vec2_t second);
ng_vec2_t ng_vec2_subtract(ng_vec2_t first, ng_vec2_t second);
ng_vec2_t ng_vec2_multiply_by_scalar(ng_vec2_t vec, float scalar);

// Other math-related functions
bool ng_is_point_inside(SDL_Rect *rect, int x, int y);
int ng_get_distance(int x, int y, int other_x, int other_y);
float ng_clamp(float min, float max, float value);

#endif
