## Simple Input Binder
A library for binding SDL input events to user defined actions.

Copyright (c) 2024 Bryan Rykowski

### Building

Place sib.hpp and sib_maps.hpp somewhere that your project can find them or add their location to the include path.

(The files #include sib.hpp and sib_maps.hpp without any preceding path)

example g++ command (assuming source files in ./sib and header files in ./include/sib):

```
g++ -o my_program main.cpp sib/sib.cpp sib/sib_readfile.cpp \
-I./include/sib -I{SDL header directory} \
-lSDL2 -lSDL2main
```

### Basic Use

**1. (optional) Define actions using constexpr or #define**

```
constexpr Sib::Action_t Action_Jump = 4;
constexpr Sib::Action_t Action_Activate = 10;
```

This is not required, but Action_Jump is probably easier to remember than 4.

**2. Create a Sib::Binder instance**

```
Sib::Binder binder;
```

**3. Map inputs to actions using MapXXXX() functions**

```
binder.MapScancode(SDL_SCANCODE_SPACE, Action_Jump);
binder.MapMouseButton(SDL_BUTTON_LEFT, Action_Activate);
```

**4. Call HandleInput(const SDL_Event& event) in your SDL event handling loop**

```
SDL_Event e;

while (SDL_PollEvent(&e))
{
    binder.HandleInput(e);

    // Other event handling...
}
```

**5. Check the state of actions using Pressed(Sib::Action_t action) and Released(Sib::Action_t action)**

```
if (binder.Pressed(Action_Jump))
{
    // Do jump logic...
}
```

**6. Once you're done processing inputs, reset the pressed/released state of actions**

```
binder.ResetInputs();
```

This will reset all the pressed and released flags, so make sure to wait until you're done reading them.

It needs to be done before you call HandleInput() again.

### Advanced Use

**Configuration File**

The ReadFile() function can be used to configure input binds at runtime. Syntax is described in [Config Syntax](config_syntax.md)

**Number of Actions**

By default SIB_MAX_ACTIONS is defined as 32. If Sib::Action_t remains typedefed as an
unsigned char, this can be increased up to 256 by editing this file or by macro definition:

```
g++ -DSIB_MAX_ACTION=128 -o my_program {other compile options...}
```

If even more actions are needed, Action_t could be typedefed as an unsigned short.

**Multiple Actions per Input**

Only one action can be mapped to an input. This could be limiting for applications that have more complex requirements. A simple solution is to use more than one Sib::Binder and just send input events to some or all of them as necessary.
