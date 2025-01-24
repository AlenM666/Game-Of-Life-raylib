#include <raylib.h>
#include <iostream>
#include "simulation.hpp"

int main()
{
    Color GREY = {29, 29, 29 , 255};
    // Color GREY = {36, 34, 34};
    const int WINDOW_WIDTH = 750;
    const int WINDOW_HEIGHT = 750;
    int CELL_SIZE = 25;
    int FPS = 12;


    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Game of Life");
    SetTargetFPS(FPS);
    Simulation simulation(WINDOW_WIDTH, WINDOW_HEIGHT, CELL_SIZE);
        

    // std::cout << simulation.CountLiveNeighbours(5, 29) << std::endl;

    //simulation loop
    while(!WindowShouldClose())
    {
        //event handeling

        //update state
        simulation.Update();

        //drawing
        BeginDrawing();
        ClearBackground(GREY);
        simulation.Draw();
        EndDrawing();
    }
    CloseWindow();


    return 0;
}




