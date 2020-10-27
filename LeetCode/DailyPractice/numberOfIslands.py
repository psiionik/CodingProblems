"""
Given a 2d grid map of '1's (land) and '0's (water), count the number of islands.
An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically.
You may assume all four edges of the grid are all surrounded by water.

Ex 1:
    Input:
    11110
    11010
    11000
    00000

    Output: 1

Ex 2:
    Input:
    11000
    11000
    00100
    00011

    Output: 3
"""

"""
Solution 1, Use DFS to get a count of the number of islands.
First preprocess the matrix to get every "1" to be a tuple (1, false). The second parameter is for visited
Double for loop through each of the cells and for each cell, if it is a 0 then ignore.
If it is a 1 and unvisited, then run it through the BFS algorithm.
BFS algorithm:
    Add the neighbours to the queue as long as they are (1, unvisted)

When BFS while loop ends add 1 to the total count.

Keep looping through to the next 1 and unvisted and repeat until the whole cell is visited.

Return the count
"""

def num_islands_sol1(grid):

    # Double for loop for going through the grid and running BFS on the (1, False)
    queue = []
    total_islands = 0
    for i in range(len(grid)):
        for j in range(len(grid[0])):
            if(grid[i][j] == '1'):
                total_islands += 1
                grid[i][j] = '0'
                queue.append((i,j))
            
                while(queue):
                    coords = queue.pop(0)
                    row = coords[0]
                    col = coords[1]
                    
                    neighbours = get_neighbours(grid, row, col)
                    for neighbour in neighbours:
                        if(grid[neighbour[0]][neighbour[1]] == '1'):
                            queue.append(neighbour)
                            grid[neighbour[0]][neighbour[1]] = '0'


    return total_islands

def is_visitable(row, col, board):
    if (row < 0 or row >= len(board)):
        return False

    if (col < 0 or col >= len(board[0])):
        return False
    
    if (board[row][col] == '0'):
        return False
    
    return True

def get_neighbours(board, row, col):
    return [(r, c) for r, c in [(row, col - 1), (row -1 , col), (row + 1, col), (row, col + 1)]
            if is_visitable(r, c, board)
        ]

def main():

    # Test 1: Should return 1

    # grid = [['1','1','1','1','0'],
    #         ['1','1','0','1','0'],
    #         ['1','1','0','0','0'],
    #         ['0','0','0','0','0']]

    # Test 2: Should return 3

    # grid = [['1','1','0','0','0'],
    #         ['1','1','0','0','0'],
    #         ['0','0','1','0','0'],
    #         ['0','0','0','1','1']]

    grid = [["1","1","1","1","1","0","1","1","1","1","1","1","1","1","1","0","1","0","1","1"],["0","1","1","1","1","1","1","1","1","1","1","1","1","0","1","1","1","1","1","0"],["1","0","1","1","1","0","0","1","1","0","1","1","1","1","1","1","1","1","1","1"],["1","1","1","1","0","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1"],["1","0","0","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1"],["1","0","1","1","1","1","1","1","0","1","1","1","0","1","1","1","0","1","1","1"],["0","1","1","1","1","1","1","1","1","1","1","1","0","1","1","0","1","1","1","1"],["1","1","1","1","1","1","1","1","1","1","1","1","0","1","1","1","1","0","1","1"],["1","1","1","1","1","1","1","1","1","1","0","1","1","1","1","1","1","1","1","1"],["1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1"],["0","1","1","1","1","1","1","1","0","1","1","1","1","1","1","1","1","1","1","1"],["1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1"],["1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1"],["1","1","1","1","1","0","1","1","1","1","1","1","1","0","1","1","1","1","1","1"],["1","0","1","1","1","1","1","0","1","1","1","0","1","1","1","1","0","1","1","1"],["1","1","1","1","1","1","1","1","1","1","1","1","0","1","1","1","1","1","1","0"],["1","1","1","1","1","1","1","1","1","1","1","1","1","0","1","1","1","1","0","0"],["1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1"],["1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1"],["1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1"]]


    print(num_islands_sol1(grid))

main()

