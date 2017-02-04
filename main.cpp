#include <stdio.h>

#include "includes/guiFunctions.h"

#define WINDOW_HEIGHT 500
#define WINDOW_WIDTH  350

int main()
{
	Platform wi;
    struct nk_context* ctx;

    int running = 1;

	windowInitialization(&wi, "Cl", WINDOW_WIDTH, WINDOW_HEIGHT);
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
        if (nk_begin(ctx, "Demo", nk_rect(50, 50, 210, 250),
            NK_WINDOW_BORDER|NK_WINDOW_MOVABLE|NK_WINDOW_SCALABLE|
            NK_WINDOW_MINIMIZABLE|NK_WINDOW_TITLE))
        {
            enum {EASY, HARD};
            static int op = EASY;
            static int property = 20;

            nk_layout_row_static(ctx, 30, 80, 1);
            if (nk_button_label(ctx, "button"))
                fprintf(stdout, "button pressed\n");
            nk_layout_row_dynamic(ctx, 30, 2);
            if (nk_option_label(ctx, "easy", op == EASY)) op = EASY;
            if (nk_option_label(ctx, "hard", op == HARD)) op = HARD;
            nk_layout_row_dynamic(ctx, 25, 1);
            nk_property_int(ctx, "Compression:", 0, &property, 100, 10, 1);        
        }
        nk_end(ctx);

		render(&wi);
	}

	shutdown(&wi);    

	return 0;
}
