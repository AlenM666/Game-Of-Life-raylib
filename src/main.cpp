#include <raylib.h>
#include "grid.hpp"

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
    Grid grid(WINDOW_WIDTH, WINDOW_HEIGHT, CELL_SIZE);
    grid.SetValue(0,0,1);
    grid.SetValue(2,1,1);


    //simulation loop
    while(!WindowShouldClose())
    {
        //event handeling

        //update state

        //drawing
        BeginDrawing();
        ClearBackground(GREY);
        grid.Draw();
        EndDrawing();
    }
    CloseWindow();


    return 0;
}




