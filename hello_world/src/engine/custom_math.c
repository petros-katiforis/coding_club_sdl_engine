#include "custom_math.h"
#include <math.h>

// Much faster than pow(, 2)!
#define SQUARED(x) (x * x)

ng_vec2_t ng_vec2_add(ng_vec2_t first, ng_vec2_t second)
{
    return (ng_vec2_t) { first.x + second.x, first.y + second.y };
}

ng_vec2_t ng_vec2_subtract(ng_vec2_t first, ng_vec2_t second)
{
    return (ng_vec2_t) { first.x - second.x, first.y - second.y };
}

ng_vec2_t ng_vec2_multiply_by_scalar(ng_vec2_t vec, float scalar)
{
    return (ng_vec2_t) { vec.x * scalar, vec.y * scalar };
}

float ng_vec2_get_magnitude(ng_vec2_t vec)
{
    return sqrt(SQUARED(vec.x) + SQUARED(vec.y));
}

ng_vec2_t ng_vec2_normalize(ng_vec2_t src)
{
    // Normalized vectors are super important! They represent plain directions
    return ng_vec2_multiply_by_scalar(src, 1.0f / ng_vec2_get_magnitude(src));
}

bool ng_point_in_rect(SDL_Rect *rect, int x, int y)
{
    return x >= rect->x && x <= rect->x + rect->w
        && y >= rect->y && y <= rect->y + rect->h;
}
