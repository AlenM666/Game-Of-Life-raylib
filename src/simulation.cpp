#include "simulation.hpp"
#include <vector>
#include <utility>

void Simulation::Draw()
{
    grid.Draw();

}

void Simulation::SetCellValue(int row, int column, int value)
{
    grid.SetValue(row, column, value);
}

int Simulation::CountLiveNeighbours(int row, int column)
{
    int liveNeighbours = 0;
    std::vector<std::pair<int, int>> neighborOffsets = 
    {
        {-1, 0}, // Directly above
        {1, 0},  // Directly below
        {0, -1}, // To the left
        {0, 1},  // To the right
        {-1, -1},// Diagonal upper left
        {-1, 1}, // Diagonal upper right
        {1, -1}, // Diagonal lower left
        {1, 1}   // Diagonal lower right
    };

    for(const auto& offset : neighborOffsets)
    {
        int neighbourRow = (row + offset.first + grid.getRows()) % grid.getRows();
        int neighbourColumn = (column + offset.second + grid.getColumns())% grid.getColumns();
        liveNeighbours += grid.GetValue(neighbourRow, neighbourColumn);

    }
    return liveNeighbours;
}

void Simulation::Update()
{
    if(IsRunning())
    {
        for(int row=0;row<grid.getRows(); row++)
        {
            for(int column = 0; column < grid.getColumns();column++)
            {
                int liveNeigbours = CountLiveNeighbours(row, column);
                int cellValue = grid.GetValue(row, column);
                if(cellValue == 1)
                {
                    if(liveNeigbours > 3 || liveNeigbours < 2)
                    {
                        tempGrid.SetValue(row, column, 0);
                    }
                    else 
                    {
                        tempGrid.SetValue(row, column, 1);
                    }
                }
                else{
                    if(liveNeigbours == 3)
                    {
                        tempGrid.SetValue(row, column, 1);
                    }
                    else
                    {
                        tempGrid.SetValue(row, column, 0);
                    }
                }
            }
        }
        grid = tempGrid;
    }
}
