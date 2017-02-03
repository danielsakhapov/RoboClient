#include <stdio.h>

#include "includes/guiFunctions.h"

int main()
{
	Platform wi;
    struct nk_context* ctx;

	windowInitialization(&wi, "Cl", 320, 200);
	ctx = ctxInitialization(&wi, 320, 200);
	loadDefaultFont(&wi);

	while(true)
	{
		if (nk_begin(ctx, "Cl", nk_rect(50, 50, 200, 200),
            NK_WINDOW_BORDER|NK_WINDOW_MOVABLE|NK_WINDOW_SCALABLE|
            NK_WINDOW_CLOSABLE|NK_WINDOW_MINIMIZABLE|NK_WINDOW_TITLE))
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
            nk_layout_row_dynamic(ctx, 22, 1);
            nk_property_int(ctx, "Compression:", 0, &property, 100, 10, 1);
        }
        nk_end(ctx);

		render(&wi);
	}


	shutdown(&wi);    

	return 0;
}
