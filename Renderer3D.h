#ifndef RENDERER_H
#define RENDERER_H

#include <vector>
#include <SDL2/SDL.h>

struct Point3D { float x, y, z;};
struct Point2D { float x, y;};
struct Edge { int start, end;};

class Renderer3D {
    public:
        Renderer3D(SDL_Window* _window, SDL_Renderer* _renderer, std::vector<Point3D>& _vertices, std::vector<Edge>& _edges);
        void render();
    private:
        Point3D rotateX(Point3D point);
        Point3D rotateY(Point3D point);
        Point2D projection(Point3D point);
        
        float rotation = 0.0f;
        float FOV = 10;
        float DeltaTime = 0.0f;

        int WindowSizeX, WindowSizeY;
        SDL_Renderer *renderer;

        std::vector<Point3D> vertices;
        std::vector<Edge> edges;
};

#endif