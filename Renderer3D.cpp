#include "Renderer3D.h"

Renderer3D::Renderer3D(SDL_Window* _window, SDL_Renderer* _renderer, std::vector<Point3D>& _vertices, std::vector<Edge>& _edges) {
    renderer = _renderer;
    vertices = _vertices;
    edges = _edges;
    SDL_GetWindowSize(_window, &WindowSizeX, &WindowSizeY);
}