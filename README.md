# 2D Graphics Editor (C Project)

## 📌 Project Aim
The aim of this project is to design a simple **menu-driven 2D graphics editor** in C that demonstrates basic graphics algorithms using ASCII art.  
It helps visualize how shapes can be represented on a 2D grid and reinforces concepts of arrays, functions, and user input handling in C programming.

---

## 🎯 Learning Outcomes
- Represent a canvas using 2D arrays.
- Implement functions to draw basic shapes (rectangle, line, triangle, circle).
- Practice handling user input and menu-driven program design.
- Gain experience with compiling and running C programs using GCC.
- Manage objects with **add, delete, and modify** operations.

---

## ⚙️ Compilation & Execution
To compile and run the program using GCC:
```bash
gcc graphics_editor.c -o graphics_editor.exe
.\graphics_editor.exe
--- 2D GRAPHICS EDITOR ---
1. Add Rectangle
2. Add Line
3. Add Triangle
4. Add Circle
5. Display Picture
6. Delete Object
7. Modify Object
0. Exit
Shape Inputs
Rectangle → Enter top-left x y and bottom-right x y

Line → Enter x1 y1 x2 y2

Triangle → Enter x1 y1 x2 y2 x3 y3

Circle → Enter center x y and radius

Other Options
Display Picture → Shows the ASCII drawing with all objects.

Delete Object → Removes a shape by its index.

Modify Object → Updates a shape’s type or parameters.

Exit → Quits the program.
