# 3D Renderer

## :zap: About 
This is a 3D Renderer I wrote in C++ to better understand computer graphics. It is created using the SDL Library. Keep reading for a (brief) explanation of the mathematics behind the program. 

The project includes models for a Cube and Pyramid. Please comment out the code and use as you wish.

## :books: Mathematics
The problem with 3D is that computer screens are 2D, which means they do not understand the concept of "depth" or the "z-axis". Fortunately, some very clever people came up with a fascinating concept called **Weak Perspective Projection**.

**NOTE:** I'll only talk _very briefly_ about Weak Perspective Projection. Please refer to [Wikipedia](https://en.wikipedia.org/wiki/3D_projection) to learn more about other projection techniques.

### What is Weak Perspective Projection?
Weak Perspective Projection is a hybrid between two other types of projections - Ortographic (Parallel) and Perspective Projection (refer Wikipedia as they are too complex for me to fully explain (or understand for that matter)). 

### Why not just use Orthographic Projection then?
A big limitation of Orthographic (and other types of Parallel Projections) is the near complete absence of depth or perspective. In particular, parallel lengths at all points in an orthographically projected image are of the same scale, regardless of whether they are far or near the camera.

### How do I do this in my program?
First, we project a 3D point $(a_x, a_y, a_z)$ onto a 2D point $(b_x, b_y)$ using the following equations:

```math
b_x = s_x*a_x + c_x
b_y = s_z*a_z + c_z
```

Here *s* is an abitrary scale factor and *c* is an arbitrary offset to better align everything to the viewport. The equations then become, using matrix multiplication:

```math
\begin{bmatrix} b_x \\\ b_y \end{bmatrix} = \begin{bmatrix} s_x \ 0 \ 0 \\\ 0 \ 0 \ s_z \end{bmatrix} \begin{bmatrix} a_x \\\ a_y \\\ a_z \end{bmatrix} + \begin{bmatrix} c_x \\\ c_z \end{bmatrix}
```

### How to implement perspective estimation?

```math
b_x = (a_x*FOV)/(a_z+FOV)
b_y = (a_y*FOV)/(a_z+FOV)
```

Here $FOV$ is just the distance between the screen and our arbitrary camera.

**NOTE:** Above is just a barebones, **higly** simplified explanation of the core concepts behind 3D Projection. Please check Wikipedia to learn more.

## :desktop_computer: How to run locally
Just clone the repository on your machine, and install a C++ Compiler. Then run the Makefile using the `make` command. SDL2, which the project uses, is already bundled with the source code, so you need not install it separately.
