/*
   This problem is similar to those fun kids games where you pick a tile and
   everything related to that tile that of the same type gets flipped.

   You are given a board of some size containing characters of either '*' or
   '-'. Also provided in the input is a coordinate that is some cell in the
   board. Given the grid and the coordinate, implement a function that "flips"
   the type of cell in that grid to the other "type" and also flips all
   neighbors (not including diagonals) to the other type if they are the same
   initial type as that cell in the given coordinate.

   Ex. grid: [
                [* * - * *]
                [* - - - *]
                [* * - * *]
                [* - - - *]
                [* * * * *]
             ]
        coordinate: (0, 2) -> 
            [
                [* * * * *]
                [* * * * *]
                [* * * * *]
                [* * * * *]
                [* * * * *]
            ]

            grid: [
                [* * *]
                [* - *]
                [* * *]
            ]
        coordinate: (1, 1) -> 

            grid: [
                [* * *]
                [* * *]
                [* * *]
            ]
    
    Second Part: Can you change the implementation such that it abstracts a lot of the complexity out and makes
    the flipCells function generic? Meaning how would you change the implementation such that the user can pass
    their own flipCells functionality into the function?
*/

#include <iostream>
#include <utility>
#include <functional>
#include <vector>
#include <queue>
#include <set>

#include <BoardFlip.h>

void flipCells(std::vector<std::vector<char>> &grid, std::pair<int, int> &coordinate) {
    int row = coordinate.first;
    int col = coordinate.second;

    std::queue<std::pair<int, int>> bfs_queue;
    bfs_queue.emplace(std::make_pair(row, col));
    std::set<std::pair<int, int>> visited;

    while (bfs_queue.size() > 0) {
        std::pair<int, int> cell_coord = bfs_queue.front();
        int cell_row = cell_coord.first;
        int cell_col = cell_coord.second;
        bfs_queue.pop();
        visited.emplace(std::make_pair(row, col));

        char cell_char = grid[cell_row][cell_col];
        grid[cell_row][cell_col] = cell_char == '*' ? '-' : '*';

        for (int i = cell_row - 1; i < cell_row + 2; i++) {
            // Skipping rows that are out of bounds
          if (i < 0 || i >= grid.size()) {
                continue;
            }
          for (int j = cell_col - 1; j < cell_col + 2; j++) {
              // Skipping columns that are out of bounds
            if (j < 0 || j >= grid[i].size()) {
                  continue;
              }

            // Skipping for same cell            
              if (i == cell_row && j == cell_col) {
                continue;
                }

                // Skipping diagonals
                if (i != cell_row && j != cell_col) {
                  continue;
              }

                // Add neighbors
                if (grid[i][j] == cell_char) {
                    bfs_queue.emplace(std::make_pair(i, j));
                }
            }
        }
    }
}

void flipCellsGeneric(std::vector<std::vector<char>> &grid, std::pair<int, int> &coordinate, std::function<void (std::vector<std::vector<char>> &, std::pair<int, int> &)> callback) {
    callback(grid, coordinate);
}

void printBoard(std::vector<std::vector<char>> &grid) {
    std::cout << "-------------------Printing Board-----------------" << std::endl;
  for (int i = 0; i < grid.size(); i++) {
    for (int j = 0; j < grid[i].size(); j++) {
        std::cout << grid[i][j] << " ";
      }
    std::cout << std::endl;
    }

  std::cout << "--------------------------------------------------" << std::endl;
}

void Test_Example1_Successful() {
      std::vector<std::vector<char>> grid {
        { '*', '*', '-', '*', '*' },
        { '*', '-', '-', '-', '*' },
        { '*', '*', '-', '*', '*' },
        { '*', '-', '-', '-', '*' },
        { '*', '*', '*', '*', '*' }
    };
    
    printBoard(grid);

    std::pair<int, int> flip1 = std::make_pair(0, 2); 
    flipCells(grid, flip1);
    printBoard(grid);
}

void Test_Example1_Generic_Successful() {
      std::vector<std::vector<char>> grid {
        { '*', '*', '-', '*', '*' },
        { '*', '-', '-', '-', '*' },
        { '*', '*', '-', '*', '*' },
        { '*', '-', '-', '-', '*' },
        { '*', '*', '*', '*', '*' }
    };
    
    printBoard(grid);

    std::pair<int, int> flip1 = std::make_pair(0, 2);

    flipCellsGeneric(grid, flip1,
                     [&](std::vector<std::vector<char>> &grid,
                         std::pair<int, int> &coordinate) -> void {
                        int row = coordinate.first;
                        int col = coordinate.second;

                        std::queue<std::pair<int, int>> bfs_queue;
                        bfs_queue.emplace(std::make_pair(row, col));
                        std::set<std::pair<int, int>> visited;

                        while (bfs_queue.size() > 0) {
                            std::pair<int, int> cell_coord = bfs_queue.front();
                            int cell_row = cell_coord.first;
                            int cell_col = cell_coord.second;
                            bfs_queue.pop();
                            visited.emplace(std::make_pair(row, col));

                            char cell_char = grid[cell_row][cell_col];
                            grid[cell_row][cell_col] = cell_char == '*' ? '-' : '*';

                            for (int i = cell_row - 1; i < cell_row + 2; i++) {
                                // Skipping rows that are out of bounds
                              if (i < 0 || i >= grid.size()) {
                                    continue;
                                }
                              for (int j = cell_col - 1; j < cell_col + 2; j++) {
                                  // Skipping columns that are out of bounds
                                if (j < 0 || j >= grid[i].size()) {
                                      continue;
                                  }

                                // Skipping for same cell            
                                  if (i == cell_row && j == cell_col) {
                                    continue;
                                    }

                                    // Skipping diagonals
                                    if (i != cell_row && j != cell_col) {
                                      continue;
                                  }

                                    // Add neighbors
                                    if (grid[i][j] == cell_char) {
                                        bfs_queue.emplace(std::make_pair(i, j));
                                    }
                                }
                            }
                        }
            }
    );
    
    printBoard(grid);
    
    std::pair<int, int> flipGeneric1 = std::make_pair(2, 2);

    flipCellsGeneric(grid, flipGeneric1,
                     [&](std::vector<std::vector<char>> &grid,
                         std::pair<int, int> &coordinate) -> void {
                            int coord_row = coordinate.first;
                            int coord_col = coordinate.second;
                            char cell = grid[coord_row][coord_col] == '*' ? '-' : '*';
                            for (int row = coord_row - 1; row < coord_row + 2;
                                 row++) {
                              if (row < 0 || row >= grid.size()) {
                                continue;
                              }
                              for (int col = coord_col - 1; col < coord_col + 2;
                                   col++) {
                                if (col < 0 || col >= grid[row].size()) {
                                    continue;
                                  }
                                  if (row != coord_row &&
                                      col != coord_col) {
                                    continue;
                                  }
                                    grid[row][col] = cell;
                                }
                            }
            }
    );


    printBoard(grid);
}

void Test_Example2_Successful() {
  std::vector<std::vector<char>> grid {
        {'*', '-'},
        {'-', '*'}
    };

    printBoard(grid);
}

int main() {
    
    Test_Example1_Successful();
    Test_Example1_Generic_Successful();
    // Test_Example2_Successful();

    return 0;
}
