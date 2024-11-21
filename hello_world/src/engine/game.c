#include "game.h"
#include "common.h"
#include <SDL2/SDL_image.h>
#include <SDL2/SDL.h>
#include <time.h>

// That's how we simulate object oriented programming in C
// The first argument is a pointer, just like the implicit `this` in C++
// It's a good practice to prefix "struct methods" with the struct's name
void ng_game_create(ng_game_t *game, const char *title, int width, int height)
{
    // Generating a unique seed for our random number generator
    srand(time(NULL));
    
    // Initializing all SDL components
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
        ng_die("failed to initialize SDL2");

    // Will be used to load PNG images into SDL textures
    if (IMG_Init(IMG_INIT_PNG) < 0)
        ng_die("failed to initialize SDL2/SDL_image");

    game->width = width;
    game->height = height;
    
    // Creating the window at the center of the screen with the specified properties
    game->window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                                    width, height, SDL_WINDOW_SHOWN);

    if (!game->window)
        ng_die("failed to create the default SDL2 window");
    
    // WARNING: Ignore all SDL tutorials that work with surfaces
    // Hardware acceleration was normalized after SDL2 was first released
    // -1 will select the first rendering driver matching the given flags
    game->renderer = SDL_CreateRenderer(game->window, -1, SDL_RENDERER_ACCELERATED);
}

// Clearing up all SDL components
void ng_game_destroy(ng_game_t *game)
{
    SDL_DestroyRenderer(game->renderer);
    SDL_DestroyWindow(game->window);

    IMG_Quit();
    SDL_Quit();
}
