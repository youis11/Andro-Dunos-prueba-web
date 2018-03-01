#include "SDL\include\SDL.h"
#pragma comment(lib, "SDL/lib/x86/SDL2.lib")
#pragma comment(lib, "SDL/lib/x86/SDL2main.lib")

int main(int argc, char* argv[]) {
	
		SDL_Window *window;

		SDL_Renderer* renderer;					// Declare a pointer

		int playing=1, i=0, right=1;

		SDL_Init(SDL_INIT_VIDEO);              // Initialize SDL2
		
											   // Create an application window with the following settings:
		window = SDL_CreateWindow(
			"My Awesome Game",                  // window title
			SDL_WINDOWPOS_UNDEFINED,           // initial x position
			SDL_WINDOWPOS_UNDEFINED,           // initial y position
			640,                               // width, in pixels
			480,                               // height, in pixels
			SDL_WINDOW_OPENGL                  // flags - see below

		);

		// We must call SDL_CreateRenderer in order for draw calls to affect this window.
		renderer = SDL_CreateRenderer(window, -1, 0);

		// Creat a rect at pos ( 50, 50 ) that's 50 pixels wide and 50 pixels high.
		SDL_Rect r;
		r.x = 0;
		r.y = 190;
		r.w = 50;
		r.h = 50;

		// The window is open: could enter program loop here (see SDL_PollEvent())
		while (playing==1) {
		
			if (i >= 10000000) {

				// Select the color for drawing. It is set to red here.
				SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);

				// Clear the entire screen to our selected color.
				SDL_RenderClear(renderer);

				// Set render color to red ( rect will be rendered in this color )
				SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);

				// Render rect
				SDL_RenderFillRect(renderer, &r);

				if (r.x >= 590) {
					right = 0;
				}

				if (r.x <= 0) {
					right = 1;
				}

				if (right == 1) {

					r.x = r.x + 1;
				}
				else if (right == 0) {

					r.x = r.x - 1;
				}
								
				// Render the rect to the screen
				SDL_RenderPresent(renderer);

				i = 0;
			}

			i++;
		}

	// Close and destroy the window
	SDL_DestroyWindow(window);

	// Clean up
	SDL_Quit();
	return 0;
}