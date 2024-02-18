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

#include "sib.hpp"
#include <string>

static_assert(SDL_BUTTON_LEFT == 1);
static_assert(SDL_BUTTON_MIDDLE == 2);
static_assert(SDL_BUTTON_RIGHT == 3);
static_assert(SDL_BUTTON_X1 == 4);
static_assert(SDL_BUTTON_X2 == 5);
static_assert(SDL_CONTROLLER_AXIS_LEFTX == 0);
static_assert(SDL_CONTROLLER_AXIS_LEFTY == 1);
static_assert(SDL_CONTROLLER_AXIS_RIGHTX == 2);
static_assert(SDL_CONTROLLER_AXIS_RIGHTY == 3);
static_assert(SDL_CONTROLLER_AXIS_TRIGGERLEFT == 4);
static_assert(SDL_CONTROLLER_AXIS_TRIGGERRIGHT == 5);

void Sib::Binder::SetError(Error_t error_in, const std::string& error_str_in)
{
	error = error_in;
	error_str = error_str_in;
	if (error_callback) error_callback(error, error_str.c_str());
}

void Sib::Binder::HandleKey(const SDL_KeyboardEvent& event)
{
	if (keys.find(event.keysym.scancode) == keys.end()) return;

	if (event.state == SDL_PRESSED)
	{
		pressed.set(keys[event.keysym.scancode]);
	}
	else
	{
		released.set(keys[event.keysym.scancode]);
	}
}

void Sib::Binder::HandleGamepadButton(const SDL_ControllerButtonEvent& event)
{
	if (cbuttons.find(event.button) == cbuttons.end()) return;

	if (event.state == SDL_PRESSED)
	{
		pressed.set(cbuttons[event.button]);
	}
	else
	{
		released.set(cbuttons[event.button]);
	}
}

void Sib::Binder::HandleGamepadTrigger(const SDL_ControllerAxisEvent& event)
{
	int value = event.value / 327;

	if (event.axis == SDL_CONTROLLER_AXIS_TRIGGERLEFT)
	{
		if (value > axis_threshold_high && !axis_state_lt)
		{
			axis_state_lt = true;
			if (left_trigger.exists) pressed.set(left_trigger.action);
		}
		else if (value < axis_threshold_low && axis_state_lt)
		{
			axis_state_lt = false;
			if (left_trigger.exists) released.set(left_trigger.action);
		}
	}
	else
	{
		if (value > axis_threshold_high && !axis_state_rt)
		{
			axis_state_rt = true;
			if (right_trigger.exists) pressed.set(right_trigger.action);
		}
		else if (value < axis_threshold_low && axis_state_rt)
		{
			axis_state_rt = false;
			if (right_trigger.exists) released.set(right_trigger.action);
		}
	}
}

void Sib::Binder::HandleGamepadAxis(const SDL_ControllerAxisEvent& event)
{
	if (event.axis == SDL_CONTROLLER_AXIS_TRIGGERRIGHT || event.axis == SDL_CONTROLLER_AXIS_TRIGGERLEFT)
	{
		HandleGamepadTrigger(event);
		return;
	}

	unsigned char mask = (1 << event.axis);
	int value = event.value;
	
	if (value == 0)
	{
		if (axis_state & mask)
		{
			axis_state &= ~mask;
			if (caxisneg[event.axis].exists) released.set(caxisneg[event.axis].action);
		}

		mask <<= 4;

		if (axis_state & mask)
		{
			axis_state &= ~mask;
			if (caxispos[event.axis].exists) released.set(caxispos[event.axis].action);
		}

		return;
	}
	else if (value > 0)
	{
		mask <<= 4;

		if ((value / 327 > axis_threshold_high) && !(mask & axis_state))
		{
			axis_state |= mask;
			if (caxispos[event.axis].exists) pressed.set(caxispos[event.axis].action);
		}
		else if ((value / 327 < axis_threshold_low) && (mask & axis_state))
		{
			axis_state &= ~mask;
			if (caxispos[event.axis].exists) released.set(caxispos[event.axis].action);
		}
	}
	else
	{
		value = -value;

		if ((value / 327 > axis_threshold_high) && !(mask & axis_state))
		{
			axis_state |= mask;
			if (caxispos[event.axis].exists) pressed.set(caxispos[event.axis].action);
		}
		else if ((value / 327 < axis_threshold_low) && (mask & axis_state))
		{
			axis_state &= ~mask;
			if (caxispos[event.axis].exists) released.set(caxispos[event.axis].action);
		}
	}
}

void Sib::Binder::HandleMouseButton(const SDL_MouseButtonEvent& event)
{
	unsigned int index = event.button - 1;

	if (!mbuttons[index].exists) return;

	if (event.state == SDL_PRESSED)
	{
		pressed.set(mbuttons[index].action);
	}
	else
	{
		released.set(mbuttons[index].action);
	}
}

void Sib::Binder::HandleMouseWheel(const SDL_MouseWheelEvent& event)
{
	unsigned int i;

	if (event.x)
	{
		if (event.direction == SDL_MOUSEWHEEL_NORMAL)
		{
			i = ( event.x > 0 ? 1 : 0 );
		}
		else
		{
			i = ( event.x > 0 ? 0 : 1 );
		}

		if (wheels[i].exists)
		{
			pressed.set(wheels[i].action);
			released.set(wheels[i].action);
		}
	}

	if (event.y)
	{
		if (event.direction == SDL_MOUSEWHEEL_NORMAL)
		{
			i = ( event.y > 0 ? 3 : 2 );
		}
		else
		{
			i = ( event.y > 0 ? 2 : 3 );
		}

		if (wheels[i].exists)
		{
			pressed.set(wheels[i].action);
			released.set(wheels[i].action);
		}
	}
}

bool Sib::Binder::ValidateAction(Sib::Action_t action)
{
	if (action >= SIB_MAX_ACTIONS)
	{
		std::stringstream s;
		s << "Action " << action << " not in range 0-" << SIB_MAX_ACTIONS;
		SetError(BAD_ACTION, s.str());
		return true;
	}

	return false;
}

void Sib::Binder::ErrorCallback(ErrorCallback_t* ptr)
{
	error_callback = ptr;
}

const char* Sib::Binder::ErrorStr()
{
	return error_str.c_str();
}

Sib::Error_t Sib::Binder::Error()
{
	return error;
}

void Sib::Binder::MapScancode(SDL_Scancode scancode, Sib::Action_t action)
{
	if (ValidateAction(action)) return;
	keys[scancode] = action;
}
	
void Sib::Binder::UnmapScancode(SDL_Scancode scancode)
{
	keys.erase(scancode);
}

void Sib::Binder::MapGamepadButton(Uint8 button, Sib::Action_t action)
{
	if (ValidateAction(action)) return;
	cbuttons[button] = action;
}

void Sib::Binder::UnmapGamepadButton(Uint8 button)
{
	cbuttons.erase(button);
}

void Sib::Binder::MapGamepadAxis(Sib::Axis axis, Sib::Action_t action)
{
	if (ValidateAction(action)) return;

	switch (axis)
	{
	case Axis::Left_X_Pos:
		caxispos[0].exists = true;
		caxispos[0].action = action;
		break;
	case Axis::Left_X_Neg:
		caxisneg[0].exists = true;
		caxisneg[0].action = action;
		break;
	case Axis::Left_Y_Pos:
		caxispos[1].exists = true;
		caxispos[1].action = action;
		break;
	case Axis::Left_Y_Neg:
		caxisneg[1].exists = true;
		caxisneg[1].action = action;
		break;
	case Axis::Right_X_Pos:
		caxispos[2].exists = true;
		caxispos[2].action = action;
		break;
	case Axis::Right_X_Neg:
		caxisneg[2].exists = true;
		caxisneg[2].action = action;
		break;
	case Axis::Right_Y_Pos:
		caxispos[3].exists = true;
		caxispos[3].action = action;
		break;
	case Axis::Right_Y_Neg:
		caxisneg[3].exists = true;
		caxisneg[3].action = action;
		break;
	case Axis::Left_Trigger:
		left_trigger.exists = true;
		left_trigger.action = action;
		break;
	case Axis::Right_Trigger:
		right_trigger.exists = true;
		right_trigger.action = action;
		break;
	}
}

void Sib::Binder::UnmapGamepadAxis(Sib::Axis axis)
{
	switch (axis)
	{
	case Axis::Left_X_Pos:
		caxispos[0].exists = false;
		break;
	case Axis::Left_X_Neg:
		caxisneg[0].exists = false;
		break;
	case Axis::Left_Y_Pos:
		caxispos[1].exists = false;
		break;
	case Axis::Left_Y_Neg:
		caxisneg[1].exists = false;
		break;
	case Axis::Right_X_Pos:
		caxispos[2].exists = false;
		break;
	case Axis::Right_X_Neg:
		caxisneg[2].exists = false;
		break;
	case Axis::Right_Y_Pos:
		caxispos[3].exists = false;
		break;
	case Axis::Right_Y_Neg:
		caxisneg[3].exists = false;
		break;
	case Axis::Left_Trigger:
		left_trigger.exists = false;
		break;
	case Axis::Right_Trigger:
		right_trigger.exists = false;
		break;
	}
}

void Sib::Binder::MapMouseButton(Uint8 button, Sib::Action_t action)
{
	if (ValidateAction(action)) return;

	if (button > 5)
	{
		std::stringstream s;
		s << "Mouse button " << button << " out of range 1-5";
		SetError(BAD_MB, s.str());
		return;
	}

	mbuttons[button - 1].exists = true;
	mbuttons[button - 1].action = action;
}

void Sib::Binder::UnmapMouseButton(Uint8 button)
{
	if (button > 5)
	{
		std::stringstream s;
		s << "Mouse button " << button << " out of range 1-5";
		SetError(BAD_MB, s.str());
		return;
	}

	mbuttons[button - 1].exists = false;
}

void Sib::Binder::MapMouseWheelUp(Sib::Action_t action)
{
	if (ValidateAction(action)) return;
	wheels[3].exists = true;
	wheels[3].action = action;
}

void Sib::Binder::UnmapMouseWheelUp()
{
	wheels[3].exists = false;
}

void Sib::Binder::MapMouseWheelDown(Sib::Action_t action)
{
	if (ValidateAction(action)) return;
	wheels[2].exists = true;
	wheels[2].action = action;
}

void Sib::Binder::UnmapMouseWheelDown()
{
	wheels[2].exists = false;
}

void Sib::Binder::MapMouseWheelLeft(Sib::Action_t action)
{
	if (ValidateAction(action)) return;
	wheels[0].exists = true;
	wheels[0].action = action;
}

void Sib::Binder::UnmapMouseWheelLeft()
{
	wheels[0].exists = false;
}

void Sib::Binder::MapMouseWheelRight(Sib::Action_t action)
{
	if (ValidateAction(action)) return;
	wheels[1].exists = true;
	wheels[1].action = action;
}

void Sib::Binder::UnmapMouseWheelRight()
{
	wheels[1].exists = false;
}

void Sib::Binder::AxisThresholdLow(unsigned char value)
{
	if (value > 100)
	{
		axis_threshold_low = 100;
		return;
	}

	axis_threshold_low = value;
}

unsigned char Sib::Binder::AxisThresholdLow()
{
	return axis_threshold_low;
}

void Sib::Binder::AxisThresholdHigh(unsigned char value)
{
	if (value > 100)
	{
		axis_threshold_high = 100;
		return;
	}

	axis_threshold_high = value;
}

unsigned char Sib::Binder::AxisThresholdHigh()
{
	return axis_threshold_high;
}

bool Sib::Binder::Pressed(Sib::Action_t action)
{
	if (ValidateAction(action)) return false;
	return pressed[action];
}

bool Sib::Binder::Released(Sib::Action_t action) 
{
	if (ValidateAction(action)) return false;
	return released[action];
}

void Sib::Binder::HandleInput(const SDL_Event& event)
{
	switch (event.type)
	{
	default:
		break;
	case SDL_KEYDOWN:
	case SDL_KEYUP:
		HandleKey(event.key);
		break;
	case SDL_MOUSEBUTTONDOWN:
	case SDL_MOUSEBUTTONUP:
		HandleMouseButton(event.button);
		break;
	case SDL_MOUSEWHEEL:
		HandleMouseWheel(event.wheel);
		break;
	case SDL_CONTROLLERBUTTONDOWN:
	case SDL_CONTROLLERBUTTONUP:
		HandleGamepadButton(event.cbutton);
		break;
	case SDL_CONTROLLERAXISMOTION:
		HandleGamepadAxis(event.caxis);
		break;
	}
}

void Sib::Binder::ResetInputs()                                                         
{
	pressed.reset();
	released.reset();
}

