// Copyright (c) 2024 Bryan Rykowski
// 
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
// 
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#include <cstdio>
#include <SDL.h>
#include "sib.hpp"

// Define actions
constexpr Sib::Action_t q = 0;
constexpr Sib::Action_t up = 1;
constexpr Sib::Action_t scroll_up = 2;
constexpr Sib::Action_t left_mb = 3;
constexpr Sib::Action_t left_stick_down = 4;
constexpr Sib::Action_t right_trigger = 5;
constexpr Sib::Action_t left_trigger = 6;
constexpr Sib::Action_t button_a = 7;

bool quit = false;
SDL_Window* window;
Sib::Binder input;

void ErrorCallback(Sib::Error_t error, const char* error_str)
{
	std::fprintf(stderr, "%s\n", input.ErrorStr());
}

int main(int argc, char** argv)
{
	input.ErrorCallback(ErrorCallback);

	// Run this program in the main project directory to use binds.txt or provide a path to a file as an argument.
	std::filesystem::path path = "example_binds.txt";
	if (argc > 1) path = argv[1];

	// Set the strings for actions in binds.txt
	input.ActionSetString(q, "q");
	input.ActionSetString(up, "up");
	input.ActionSetString(scroll_up, "scroll_up");
	input.ActionSetString(left_mb, "left_mb");
	input.ActionSetString(left_stick_down, "left_stick_down");
	input.ActionSetString(right_trigger, "right_trigger");
	input.ActionSetString(left_trigger, "left_trigger");
	input.ActionSetString(button_a, "button_a");

	input.ReadFile(path);

	// Error() will return the last error (if any) and ErrorStr() will provide a pointer to description of the problem.
	if (input.Error() == Sib::OPEN_FILE) return -1;

	// SDL setup
	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_Window* window = SDL_CreateWindow("sib basic", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 200, 200, 0);

	// Activate gamepads
	for (int i = 0; i < SDL_NumJoysticks(); i++)
	{
		if (SDL_IsGameController(i))
		{
			SDL_GameControllerOpen(i);
		}
	}

	SDL_Event e;

	while (!quit)
	{
		// Check SDL events since last loop
		while (SDL_PollEvent(&e))
		{
			input.HandleInput(e);
			if (e.type == SDL_QUIT) quit = true;
		}

		if (input.Pressed(q))
		{
			quit = true;
			std::printf("q key pressed\n");
		}
		
		if (input.Pressed(left_mb))
		{
			std::printf("left mouse button pressed\n");
		}

		if (input.Pressed(up))
		{
			std::printf("up key pressed\n");
		}

		if (input.Pressed(scroll_up))
		{
			std::printf("mouse scrolled up\n");
		}

		if (input.Pressed(left_stick_down))
		{
			std::printf("left stick moved down\n");
		}

		if (input.Pressed(left_trigger))
		{
			std::printf("left trigger pressed\n");
		}

		if (input.Pressed(right_trigger))
		{
			std::printf("right trigger pressed\n");
		}

		if (input.Pressed(button_a))
		{
			std::printf("a button pressed\n");
		}
		
		input.ResetInputs();
	}

	SDL_Quit();
	return 0;
}
