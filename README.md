# Fractol
Fractal viewer in C + SDL
Tested on MacOS and Linux but it should be working on Windows too.


![MANDELBROT](https://i.imgur.com/bx1Gl4e.png)
![JULIA (interactible)](https://i.imgur.com/aJKzXPi.png)
![BURNING SHIP](https://i.imgur.com/8azLELF.png)


--------------------- COMPILATION ------------------------

Use the Makefile to compile (make).
Needs SDL 2.0+

------------------------ USAGE ----------------------------

usage: ./fractol [fractal]
fractals:
+ Mandelbrot
+ Julia
+ Burning_Ship
 
----------------------- CONTROLS --------------------------

+ Mouse scroll to zoom to cursor
+ Arrow keys to move camera
+ Keypad 1, 2, 3 to change fractal type without restarting
+ Keypad + and - to change the number of iterations
+ Spacebar to reset view
+ Return key to switch color type

--------------------- JULIA PARAMETERS --------------------

+ Move mouse to change parameters
+ Left Ctrl key to freeze / un-freeze parameters

-----------------------------------------------------------
