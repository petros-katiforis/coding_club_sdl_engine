#include "engine/game.h"
#include "engine/custom_math.h"
#include <stdbool.h>
#include <SDL2/SDL.h>

#define FPS 60
#define MS_PER_FRAME (1000.0 / FPS)

/*
 * Creating a context to store all our global variables
 * This is a really common pattern in data-oriented game development
 *  it effectively works like a namespace
 */
typedef struct
{
    ng_game_t game;
    bool is_paused;

    bool is_game_running;
} ctx_t;

// Static here refers to linkage, it's not a storage class as you
// might have expected! This means that this variable will only be
// available in this file. The default behavior is identical to that of
// writing `extern`, so be careful!

// TIP: All functions that should not be accessible to other files
// should by prefixed by `static`, otherwise they might clash with each
// other!
static ctx_t ctx;

// Functions that do not accept any arguments should be defined as
// (void). initialize_game() would have been a function that accepts
// **any** number of arguments, so initialize_game(1, 2) would have
// worked just fine, strangely enough...
static void initialize_game(void)
{
    ctx.is_game_running = true;
    ng_game_create(&ctx.game, "Minecraft 2", 320, 320);
}

int main(int argc, char **argv)
{
    initialize_game();

    // or just SDL_Rect example = {10, 10, 100, 100};
    SDL_Rect example = {
        .x = 10, .y = 10,
        .w = 100, .h = 100,
    };

    SDL_Event event;
    uint32_t last_time = 0;
    uint32_t delta = 0;

    while (ctx.is_game_running)
    {
        // Calculating the amount of milliseconds that passed
        // since the last execution of this loop. Delta time is
        // important, because some frames might take longer to update
        // and draw than others. That duration should be reflected to
        // the amount by which we update stuff, such as velocities and
        // positions!
        uint32_t cur_time = SDL_GetTicks();
        delta = cur_time - last_time;
        last_time = cur_time;

        // Before trying to render stuff on the screen,
        // we should first check if any new input is available
        while (SDL_PollEvent(&event))
        {
            // SDL_QUIT = the window is about to close, for whatever
            // reason (exit button, alt f4 etc)
            switch (event.type)
            {
                case SDL_QUIT:
                    ctx.is_game_running = false;
                    break;

                case SDL_MOUSEBUTTONDOWN:
                    // Mouse position is accessible from the event struct,
                    // which is efficiently defined to be a C union!
                    if (ng_point_in_rect(&example, event.button.x, event.button.y))
                        example.x += 10;
                    
                    break;
            }
        }

        SDL_SetRenderDrawColor(ctx.game.renderer, 10, 10, 10, 255);
        SDL_RenderClear(ctx.game.renderer);

        SDL_SetRenderDrawColor(ctx.game.renderer, 255, 0, 0, 255);
        // Will use the active render draw color, as defined earlier!
        SDL_RenderFillRect(ctx.game.renderer, &example);

        // Sends the instructions into our GPU, updates the screen
        SDL_RenderPresent(ctx.game.renderer);

        // Don't update too fast, introduce an FPS limit!
        // This is an important performance measure, since
        // updating faster is pointless! The frequency is too fast
        // for it to ever be visible on the monitor
        if (delta < MS_PER_FRAME)
            SDL_Delay(MS_PER_FRAME - delta);
    }

    ng_game_destroy(&ctx.game);
}
