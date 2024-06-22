#include "Renderer3D.h"

Renderer3D::Renderer3D(SDL_Window* _window, SDL_Renderer* _renderer, std::vector<Point3D>& _vertices, std::vector<Edge>& _edges) {
    renderer = _renderer;
    vertices = _vertices;
    edges = _edges;
    SDL_GetWindowSize(_window, &WindowSizeX, &WindowSizeY);
}

void Renderer3D::render() {
    auto time1 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration(0);

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
    SDL_RenderClear(renderer);
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);

    rotation += 1 * DeltaTime;

    for (auto& edge : edges) {
        Point3D rotatedStartPoint = rotateY(rotateX(vertices[edge.start]));
        Point3D rotatedEndPoint = rotateY(rotateX(vertices[edge.end]));
        Point2D start = projection(rotatedStartPoint);
        Point2D end = projection(rotatedEndPoint);
        SDL_RenderDrawLine(renderer, start.x, start.y, end.x, end.y);
    }
    SDL_RenderPresent(renderer);

    auto time2 = std::chrono::high_resolution_clock::now();
    duration = time2 - time1;
    DeltaTime = duration.count();
    time1 = time2;
} 