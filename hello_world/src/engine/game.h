#ifndef _NG_GAME_H
#define _NG_GAME_H

#include <SDL2/SDL.h>

/*
 * The game struct will manage and encapsule the two most basic SDL components:
 * the window and the renderer, which is responsible for exploiting
 * hardware acceleration (GPU) to provide basic drawing operations.
 */
typedef struct
{
    SDL_Window *window;
    SDL_Renderer *renderer;

    int width, height;
// No namespaces in C, we need to use prefixes instead
// Suffixing all new types with _t, a common practice
} ng_game_t;

// External interface!
void ng_game_create(ng_game_t *game, const char *title, int width, int height);
void ng_game_destroy(ng_game_t *game);

#endif
