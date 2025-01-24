#include <raylib.h>
#include <iostream>
#include "simulation.hpp"

int main()
{
    Color GREY = {29, 29, 29 , 255};
    // decrese the cell size to make game bigger
    const int WINDOW_WIDTH = 750;
    const int WINDOW_HEIGHT = 750;
    int CELL_SIZE = 10;
    int FPS = 12;


    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Game of Life");
    SetTargetFPS(FPS);
    Simulation simulation(WINDOW_WIDTH, WINDOW_HEIGHT, CELL_SIZE);

    // std::cout << simulation.CountLiveNeighbours(5, 29) << std::endl;

    //simulation loop
    while(!WindowShouldClose())
    {
        //event handeling
        if(IsKeyPressed(KEY_ENTER))
        {
            simulation.Start();
            SetWindowTitle("Game of Life is running ...");
        }else if(IsKeyPressed(KEY_SPACE))
        {
            simulation.Stop();
            SetWindowTitle("Game of Life has stoped ...");
        }

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




