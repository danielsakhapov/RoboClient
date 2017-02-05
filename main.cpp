#include <stdio.h>

#include "includes/guiFunctions.h"

#define WINDOW_HEIGHT 720
#define WINDOW_WIDTH  1280

int main()
{
	Platform wi;
    struct nk_context* ctx;

    int running = 1;

	windowInitialization(&wi, "Client", WINDOW_WIDTH, WINDOW_HEIGHT);
	ctx = ctxInitialization(&wi, WINDOW_WIDTH, WINDOW_HEIGHT);
	loadDefaultFont(&wi);

	while (running)
    {
        /* Input */
        SDL_Event evt;
        nk_input_begin(ctx);
        while (SDL_PollEvent(&evt)) {
            if (evt.type == SDL_QUIT) {
                shutdown(&wi);
                return 0;
            }
            nk_sdl_handle_event(&evt);
        }
        nk_input_end(ctx);

        /* GUI */
        if (nk_begin(ctx, "Stream", nk_rect(0, 0, WINDOW_WIDTH - 300, WINDOW_HEIGHT), NK_WINDOW_TITLE))
        {}
        nk_end(ctx);

        if (nk_begin(ctx, "Info", nk_rect(WINDOW_WIDTH - 300, 0, 300, WINDOW_HEIGHT), NK_WINDOW_TITLE))
        {}
        nk_end(ctx);

		render(&wi);
	}

	shutdown(&wi);    

	return 0;
}
