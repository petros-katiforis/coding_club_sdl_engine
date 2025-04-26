#include "custom_math.h"
#include <math.h>

#define SQUARE(x) ((x) * (x))

float ng_vec2_get_magnitude(ng_vec2_t vec)
{
    return sqrt(SQUARE(vec.x) + SQUARE(vec.y));
}

// Since operator overloading is not available, I have to do it this way
ng_vec2_t ng_vec2_normalize(ng_vec2_t vec)
{
    return ng_vec2_multiply_by_scalar(vec, 1.0f / ng_vec2_get_magnitude(vec));
}

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

bool ng_is_point_inside(SDL_Rect *rect, int x, int y)
{
    // This function only works for rectangles
    return x > rect->x && x < rect->x + rect->w &&
           y > rect->y && y < rect->y + rect->h;
}

int ng_get_distance(int x, int y, int other_x, int other_y)
{
    // Basically getting the magnitude of the distance vector
    return sqrt(SQUARE(other_x - x) + SQUARE(other_y - y));
}

float ng_clamp(float min, float max, float value)
{
    if (value <= min) return min;
    if (value >= max) return max;
    return value;
}

