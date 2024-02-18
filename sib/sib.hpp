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
//
// --- Simple Input Binder ---
//
//		A library for binding SDL input events to user defined actions.
//
// - Building -
//
//		Place sib.hpp and sib_maps.hpp somewhere that your project can find them or add their
//		location to the include path.
//
//		(The files #include sib.hpp and sib_maps.hpp without any preceding path)
//
//		example g++ command (assuming source files in ./sib and header files in ./include/sib):
//
//			g++ -o my_program main.cpp sib/sib.cpp sib/sib_readfile.cpp \
//			-I./include/sib -I{SDL header directory} \
//			-lSDL2 -lSDL2main 
//     
// - Basic use -
//
//		1.(optional) Define actions using constexpr or #define
//
//			constexpr Sib::Action_t Action_Jump = 4;
//			constexpr Sib::Action_t Action_Activate = 10;
//
//			This is not required, but Action_Jump is probably easier to remember than 4.
//
//		2. Create a Sib::Binder instance
//
//			Sib::Binder binder;
//
//		3. Map inputs to actions using MapXXXX() functions
//     
//			binder.MapScancode(SDL_SCANCODE_SPACE, Action_Jump);
//			binder.MapMouseButton(SDL_BUTTON_LEFT, Action_Activate);
//
//		4. Call HandleInput(const SDL_Event& event) in your SDL event handling loop
//
//			SDL_Event e;
//			
//			while (SDL_PollEvent(&e))
//			{
//			    binder.HandleInput(e);
//			
//			    // Other event handling...
//			}
//
//		5. Check the state of actions using Pressed(Sib::Action_t action) and
//		Released(Sib::Action_t action)
//
//			if (binder.Pressed(Action_Jump))
//			{
//			    // Do jump logic...
//			}
//
//		6. Once you're done processing inputs, reset the pressed/released state of actions
//
//			binder.ResetInputs();
//
//			This will reset all the pressed and released flags, so make sure to wait until you're done
//			reading them.
//		
//			It needs to be done before you call HandleInput() again.
//
// - Advanced Use -
//
//		Configuration File
//
//			The ReadFile() function can be used to configure input binds at runtime. Syntax is
//			described in config_syntax.txt
//
//		Number of Actions
//
//			By default SIB_MAX_ACTIONS is defined as 32. If Sib::Action_t remains typedefed as an
//			unsigned char, this can be increased up to 256 by editing this file or by macro definition:
//
//				g++ -DSIB_MAX_ACTION=128 -o my_program {other compile options...}
//
//			If even more actions are needed, Action_t could be typedefed as an unsigned short.
//
//		Multiple Actions per Input
//
//			Only one action can be mapped to an input. This could be limiting for applications that have
//			more complex requirements. A simple solution is to use more than one Sib::Binder and just
//			send input events to some or all of them as necessary.

#pragma once
#include <unordered_map>
#include <bitset>
#include <filesystem>
#include <SDL.h>

#ifndef SIB_MAX_ACTIONS
#define SIB_MAX_ACTIONS 32
#endif

namespace Sib
{
	typedef int Error_t;
	typedef unsigned char Action_t;

	typedef void (ErrorCallback_t)(Error_t error, const char* ErrorStr);
	
	constexpr Error_t NO_ERROR = 0;
	constexpr Error_t BAD_ACTION = 1;
	constexpr Error_t BAD_AXIS = 2;
	constexpr Error_t BAD_MB = 3;
	constexpr Error_t BAD_SCANCODE_STR = 4;
	constexpr Error_t BAD_KEYCODE_STR = 5;
	constexpr Error_t BAD_MB_STR = 6;
	constexpr Error_t BAD_CBUTTON_STR = 7;
	constexpr Error_t BAD_AXIS_STR = 8;
	constexpr Error_t BAD_ACTION_STR = 9;
	constexpr Error_t NO_SCANCODE = 10;
	constexpr Error_t BAD_COMMAND = 11;
	constexpr Error_t OPEN_FILE = 12;

	struct ActionBind
	{
		bool exists = false;
		Action_t action;
	};

	enum class Axis
	{
		Left_X_Pos,
		Left_X_Neg,
		Left_Y_Pos,
		Left_Y_Neg,
		Right_X_Pos,
		Right_X_Neg,
		Right_Y_Pos,
		Right_Y_Neg,
		Left_Trigger,
		Right_Trigger
	};

	class Binder
	{
	private:
		std::unordered_map<std::string,Sib::Action_t> action_strings;
		std::unordered_map<SDL_Keycode,Sib::Action_t> keys;
		std::unordered_map<SDL_Scancode,Sib::Action_t> scancodes;
		std::unordered_map<Uint8,Sib::Action_t> cbuttons;
		ErrorCallback_t* error_callback = 0;
		ActionBind left_trigger;
		ActionBind right_trigger;
		ActionBind caxispos[4];
		ActionBind caxisneg[4];
		ActionBind mbuttons[5];
		ActionBind wheels[4];
		std::bitset<SIB_MAX_ACTIONS> pressed;
		std::bitset<SIB_MAX_ACTIONS> released;
		std::string error_str;
		unsigned char axis_threshold_high = 66;
		unsigned char axis_threshold_low = 33;
		Error_t error = NO_ERROR;
		bool axis_state_lt = false;
		bool axis_state_rt = false;
		unsigned char axis_state = 0;

		void SetError(Error_t error, const std::string& error_str);
		void HandleKey(const SDL_KeyboardEvent& event);
		void HandleGamepadButton(const SDL_ControllerButtonEvent& event);
		void HandleGamepadTrigger(const SDL_ControllerAxisEvent& event);
		void HandleGamepadAxis(const SDL_ControllerAxisEvent& event);
		void HandleMouseButton(const SDL_MouseButtonEvent& event);
		void HandleMouseWheel(const SDL_MouseWheelEvent& event);
		bool ValidateAction(Sib::Action_t action);
		bool ValidateActionStr(const std::string& action_str);
		void ReadLine(const std::string& line, unsigned int n);
	public:
		void ErrorCallback(ErrorCallback_t*);
		const char* ErrorStr();
		Error_t Error();
		void MapScancode(SDL_Scancode scancode, Sib::Action_t action);
		void UnmapScancode(SDL_Scancode scancode);
		void MapGamepadButton(Uint8 button, Sib::Action_t action);
		void UnmapGamepadButton(Uint8 button);
		void MapGamepadAxis(Sib::Axis axis, Sib::Action_t action);
		void UnmapGamepadAxis(Sib::Axis axis);
		void MapMouseButton(Uint8 button, Sib::Action_t action);
		void UnmapMouseButton(Uint8 button);
		void MapMouseWheelUp(Sib::Action_t action);
		void UnmapMouseWheelUp();
		void MapMouseWheelDown(Sib::Action_t action);
		void UnmapMouseWheelDown();
		void MapMouseWheelLeft(Sib::Action_t action);
		void UnmapMouseWheelLeft();
		void MapMouseWheelRight(Sib::Action_t action);
		void UnmapMouseWheelRight();
		void AxisThresholdLow(unsigned char value);
		unsigned char AxisThresholdLow();
		void AxisThresholdHigh(unsigned char value);
		unsigned char AxisThresholdHigh();
		bool Pressed(Sib::Action_t action);
		bool Released(Sib::Action_t action);
		void HandleInput(const SDL_Event& event);
		void ResetInputs();
		void ReadFile(std::filesystem::path path);
		void ActionSetString(Sib::Action_t action, const std::string& actions_str);
	};
}

