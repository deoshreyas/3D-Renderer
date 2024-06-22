#include <iostream>
#include <vector>
#include <SDL2/SDL.h>
#include "Renderer3D.h"

const int WIDTH = 600;
const int HEIGHT = 400;

// Cube
std::vector<Point3D> vertices{Point3D{-1.0f, -1.0f, -1.0f}, Point3D{-1.0f, -1.0f, 1.0f},
                            Point3D{1.0f, -1.0f, -1.0f}, Point3D{-1.0f, 1.0f, -1.0f},
                            Point3D{-1.0f, 1.0f, 1.0f}, Point3D{1.0f, -1.0f, 1.0f},
                            Point3D{1.0f, 1.0f, -1.0f}, Point3D{1.0f, 1.0f, 1.0f}};

std::vector<Edge> edges{Edge{0, 1}, Edge{0, 2}, Edge{0, 3},
                        Edge{2, 5}, Edge{3, 6}, Edge{3, 4},
                        Edge{4, 7}, Edge{6, 7}, Edge{7, 5},
                        Edge{5, 1}, Edge{4, 1}, Edge{2, 6}};

// Pyramid (comment cube and uncomment pyramid to see the pyramid)
// std::vector<Point3D> vertices{Point3D{-1.0f, -1.0f, -1.0f}, Point3D{-1.0f, -1.0f, 1.0f},
//                             Point3D{1.0f, -1.0f, -1.0f}, Point3D{1.0f, -1.0f, 1.0f},
//                             Point3D{0.0f, 1.0f, 0.0f}};

// std::vector<Edge> edges{Edge{0, 1}, Edge{0, 2}, Edge{1, 3}, Edge{2, 3}, 
//                         Edge{0, 4}, Edge{1, 4}, Edge{2, 4}, Edge{3, 4}};

int main(int argc, char *argv[]) {
    SDL_Init(SDL_INIT_EVERYTHING);

    // Creating window and renderer
    SDL_Window *window = SDL_CreateWindow("3D Renderer", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    if (window == nullptr) {
        std::cout << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
        return 1;
    } 

    // Creating a 3D Renderer
    Renderer3D renderer3D(window, renderer, vertices, edges);

    SDL_Event windowEvent;

    bool running = true;
    while (running) {
        if (SDL_PollEvent(&windowEvent)) {
            if (windowEvent.type == SDL_QUIT) {
                running = false;
                break;
            }
        }
        renderer3D.render();
    }

    SDL_DestroyWindow(window);
    SDL_Quit();

    return EXIT_SUCCESS;
}