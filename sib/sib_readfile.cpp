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
#include "sib_maps.hpp"
#include <fstream>
#include <sstream>

bool Sib::Binder::ValidateActionStr(const std::string& action_str)
{
	if (action_strings.find(action_str) == action_strings.end())
	{
		std::stringstream s;
		s << "String \"" << action_str << "\" does not match any registered action";
		SetError(BAD_ACTION_STR, s.str());
		return true;
	}

	return false;
}

void Sib::Binder::ReadLine(const std::string& line, unsigned int n)
{
	if (line.size() == 0) return;

	std::string str0, str1, str2;
	unsigned int i = 0;
	
	while (i < line.size() && line[i] == ' ')
	{
		++i;
	}

	while (i < line.size() && line[i] != ' ')
	{
		str0.push_back(line[i]);
		++i;
	}

	while (i < line.size() && line[i] == ' ')
	{
		++i;
	}

	while (i < line.size() && line[i] != ' ')
	{
		str1.push_back(line[i]);
		++i;
	}

	while (i < line.size() && line[i] == ' ')
	{
		++i;
	}

	while (i < line.size() && line[i] != ' ')
	{
		str2.push_back(line[i]);
		++i;
	}

	if (str0 == "scancode" || str0 == "unmap_scancode")
	{
		if (str_to_scancodes.find(str1) == str_to_scancodes.end())
		{
			std::stringstream s;
			s << "Line " << n << ": String \"" << str1 << "\" does not match any SDL scancode";
			SetError(BAD_SCANCODE_STR, s.str());
			return;
		}

		SDL_Scancode scancode = str_to_scancodes[str1];

		if (str0 == "unmap_scancode")
		{
			UnmapScancode(scancode);
			return;
		}

		if (ValidateActionStr(str2)) return;
		MapScancode(str_to_scancodes[str1], action_strings[str2]);
	}
	else if (str0 == "keycode" || str0 == "unmap_keycode")
	{
		if (str_to_keycodes.find(str1) == str_to_keycodes.end())
		{
			std::stringstream s;
			s << "Line " << n << ": String \"" << str1 << "\" does not match any SDL keycode";
			SetError(BAD_KEYCODE_STR, s.str());
			return;
		}

		SDL_Scancode scancode = SDL_GetScancodeFromKey(str_to_keycodes[str1]);

		if (scancode == SDL_SCANCODE_UNKNOWN)
		{
			std::stringstream s;
			s << "Line " << n << ": Keycode " << SDL_GetKeyName(str_to_keycodes[str1]) << " has no matching scancode";
			SetError(NO_SCANCODE, s.str());
			return;
		}

		if (str0 == "unmap_keycode")
		{
			UnmapScancode(scancode);
			return;
		}

		if (ValidateActionStr(str2)) return;
		MapScancode(scancode, action_strings[str2]);
	}
	else if (str0 == "mbutton" || str0 == "unmap_mbutton")
	{
		if (str_to_mbuttons.find(str1) == str_to_mbuttons.end())
		{
			std::stringstream s;
			s << "Line " << n << ": String \"" << str1 << "\" does not match any SDL mouse button";
			SetError(BAD_MB_STR, s.str());
			return;
		}

		Uint8 button = str_to_mbuttons[str1];

		if (str0 == "unmap_mbutton")
		{
			UnmapMouseButton(button);
		}

		if (ValidateActionStr(str2)) return;
		MapMouseButton(button, action_strings[str2]);
	}
	else if (str0 == "cbutton" || str0 == "unmap_cbutton")
	{
		if (str_to_cbuttons.find(str1) == str_to_cbuttons.end())
		{
			std::stringstream s;
			s << "Line " << n << ": String \"" << str1 << "\" does not match any SDL controller button";
			SetError(BAD_CBUTTON_STR, s.str());
			return;
		}

		Uint8 button = str_to_cbuttons[str1];

		if (str0 == "unmap_cbutton")
		{
			UnmapGamepadButton(button);
			return;
		}

		if (ValidateActionStr(str2)) return;
		MapGamepadButton(button, action_strings[str2]);
	}
	else if (str0 == "caxis" || str0 == "unmap_caxis")
	{
		if (str_to_caxis.find(str1) == str_to_caxis.end())
		{
			std::stringstream s;
			s << "Line " << n << ": String \"" << str1 << "\" is not a valid axis";
			SetError(BAD_AXIS_STR, s.str());
			return;
		}

		Sib::Axis axis = str_to_caxis[str1];

		if (str0 == "unmap_caxis")
		{
			UnmapGamepadAxis(axis);
			return;
		}

		if (ValidateActionStr(str2)) return;
		MapGamepadAxis(axis, action_strings[str2]);
	}
	else if (str0 == "wheelup")
	{
		if (ValidateActionStr(str1)) return;
		MapMouseWheelUp(action_strings[str1]);
	}
	else if (str0 == "unmap_wheelup")
	{
		UnmapMouseWheelUp();
	}
	else if (str0 == "wheeldown")
	{
		if (ValidateActionStr(str1)) return;
		MapMouseWheelDown(action_strings[str1]);
	}
	else if (str0 == "unmap_wheeldown")
	{
		UnmapMouseWheelDown();
	}
	else if (str0 == "wheelleft")
	{
		if (ValidateActionStr(str1)) return;
		MapMouseWheelLeft(action_strings[str1]);
	}
	else if (str0 == "unmap_wheelleft")
	{
		UnmapMouseWheelLeft();
	}
	else if (str0 == "wheelright")
	{
		if (ValidateActionStr(str1)) return;
		MapMouseWheelRight(action_strings[str1]);
	}
	else if (str0 == "unmap_wheelright")
	{
		UnmapMouseWheelRight();
	}
	else
	{
		std::stringstream s;
		s << "Line " << n << ": String \"" << str0 << "\" is not a valid bind command";
		SetError(BAD_COMMAND, s.str());
		return;
	}
}

void Sib::Binder::ReadFile(std::filesystem::path path)
{
	std::ifstream file(path);

	if (file.fail())
	{
		std::stringstream s;
		s << "Failed to open file: " << path.string(); 	
		SetError(OPEN_FILE, s.str());
		return;
	}

	unsigned int n = 0;
	std::string line;
	while (true)
	{
		if (file.eof()) break;
		std::getline(file, line);
		ReadLine(line, n);
		++n;
	}
}

void Sib::Binder::ActionSetString(Sib::Action_t action, const std::string& action_str)
{
	if (ValidateAction(action)) return;
	action_strings[action_str] = action;	
}

