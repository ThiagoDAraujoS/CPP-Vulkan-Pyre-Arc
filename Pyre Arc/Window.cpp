#include "Servo.hpp"

Servo::Window::Window() {
	if (SDL_Init(SDL_INIT_VIDEO) != 0) {
		COUT("[ERROR] Could not initialize SDL.")
	}
	resource= SDL_CreateWindow("Pyre Arc", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_OPENGL);
	if (resource == NULL) {
		COUT("[ERROR] Could not create SDL window.")
	}
	else {
		COUT("[DONE] Window")
	}
};


Servo::Window::~Window() {
	SDL_DestroyWindow(resource);
	SDL_Quit();
	COUT("[UNDONE] Window")
};