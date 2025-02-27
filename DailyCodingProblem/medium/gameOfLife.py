"""
Conway's Game of Life takes place on an infinite two-dimensional board of square cells.
Each cell is either dead or alive, and at each tick, the following rules apply:

Any live cell with less than two live neighbours dies.
Any live cell with two or three live neighbours remains living.
Any live cell with more than three live neighbours dies.
Any dead cell with exactly three live neighbours becomes a live cell.
A cell neighbours another cell if it is horizontally, vertically, or diagonally adjacent.

Implement Conway's Game of Life. It should be able to be initialized with a starting list of live cell coordinates
and the number of steps it should run for. Once initialized, it should print out the board state at each step.
Since it's an infinite board, print out only the relevant coordinates, i.e. from the top-leftmost live cell to
bottom-rightmost live cell.

You can represent a live cell with an asterisk (*) and a dead cell with a dot (.).
"""

"""
Solution 1, Use the algorithm above in a while loop that loops through the number of steps.
Make your own arbitrary size and at each iteration print the board that changed according to the steps above.
To change each of the cells, loop through the list of live cells and then check all of its neighbors and if any of the cells
become live, then add them to the list.
If any of them become dead then remove them for the list.
Have a set each iteration of cells that have already been seen to prevent double counting.
"""

import time

def game_of_life_sol1(arr, steps):
    matrix = [['.' for i in range(30)] for j in range(30)]
    counter = 0
    for i in arr:
        matrix[i[0]][i[1]] = '*'

    live_list = arr
    dead_list = []
   
    while counter <= steps:
        print(to_string(matrix))
        seen = set()
        for cell in live_list:
            neighbors = get_neighbors(cell[0], cell[1], matrix)
            for neighbor in neighbors:
                seen.add(neighbor)

        live_list = []
        dead_list = []

        for unique_cell in seen:
            live_list_temp, dead_list_temp = change_cells(unique_cell[0], unique_cell[1], matrix)
            live_list += live_list_temp
            dead_list += dead_list_temp

        for live_cell in live_list:
            matrix[live_cell[0]][live_cell[1]] = "*"
        for dead_cell in dead_list:
            matrix[dead_cell[0]][dead_cell[1]] = '.'
        
        

        counter += 1
        time.sleep(0.3)

def visitable(row, col, board):
    if (row < 0 or row >= len(board)):
        return False
    if (col < 0 or col >= len(board[0])):
        return False
    return True

def change_cells(row, col, board):
    live_cells = []
    dead_cells = []

    dead_count = 0
    live_count = 0
    if board[row][col] == '.':
        for i in range(row - 1 , row + 2):
            for j in range(col -1, col + 2):
                if(i == row and j == col):
                        continue
                if(visitable(i, j, board)):
                    if(board[i][j] == '*'):
                        dead_count += 1
        if (dead_count == 3):
            live_cells.append((row, col))
    else:
        for i in range(row - 1, row + 2):
            for j in range(col -1, col + 2):
                if(visitable(i, j, board)):
                    if(i == row and j == col):
                        continue
                    if(board[i][j] == '*'):
                        live_count += 1
        
        if(live_count < 2):
            dead_cells.append((row, col))
        elif(live_count >= 2 and live_count <= 3):
            live_cells.append((row, col))
        elif(live_count > 3):
            dead_cells.append((row, col))
    
    return live_cells, dead_cells


def get_neighbors(row, col, board):
    list_of_neighbors = []
    for i in range(row -1, row + 2):
        for j in range(col -1, col + 2):
            if(visitable(i, j, board)):
                list_of_neighbors.append((i,j))
    
    return list_of_neighbors


def to_string(given_array):
    list_rows = []
    for row in given_array:
        list_rows.append(str(row))
    return '[' + ',\n '.join(list_rows) + ']'

"""
Solution 2, Represent each cell simply as a pair of cartesian coordinates (row, col). Keep the set of cells as a property on
the class. Each tick, create a new set of cells that represents the next generation. Do this so that changing the board
doesn't affect the future cells we process from the current generation.
Look at each live cell, compute the number of neighbors for each one and preserve it according to the rules.
Similarly, we look at all the neighboring cells of all the live cells. If they have exactly 3 live cells as neighbors, then
add them to the set of live cells.

For printing the board, we need to find the top-leftmost cell and the bottom-rightmost cell. These are the boundaries for the board.
Then we can print out each row and cell one by one and checking if the current spot is in our set of cells.

Useful to create helper functions:
    1. get_number_of_live_neighbors
    2. get_neighboring_cells
    3. get_boundaries
"""

class GameOfLife:
    def __init__(self, n, cells=set()):
        self.cells = cells
        for _ in range(n):
            self.print_board()
            self.next()
            time.sleep(0.2)

    def get_number_of_live_neighbors(self, row, col):
        count = 0
        for cell_row, cell_col in self.cells:
            if abs(cell_row - row) > 1:
                continue
            if abs(cell_col - col) > 1:
                continue
            if cell_row == row and cell_col == col:
                continue
            count += 1

        return count

    def get_neighboring_cells(self, row, col):
        return set([
            (row -1, col -1),
            (row, col - 1),
            (row + 1, col - 1),
            (row - 1, col),
            (row + 1, col),
            (row - 1, col + 1),
            (row, col + 1),
            (row + 1, col + 1),
        ])

    def next(self):
        new_cells = set()
        for row, col in self.cells:
            num_of_neighbors = self.get_number_of_live_neighbors(row, col)
            if 2 <= num_of_neighbors <= 3:
                new_cells.add((row, col))

        potential_live_cells = set()
        for row, col in self.cells:
            potential_live_cells = potential_live_cells.union(self.get_neighboring_cells(row, col))
        
        potential_live_cells =  potential_live_cells - self.cells

        for row, col in potential_live_cells:
            num_of_neighbors = self.get_number_of_live_neighbors(row, col)
            if num_of_neighbors == 3:
                new_cells.add((row, col))
        
        self.cells = new_cells
    
    def get_boundaries(self):
        top = min(self.cells, key=lambda cell: cell[0])[0]
        left = min(self.cells, key=lambda cell: cell[1])[1]
        bottom = max(self.cells, key=lambda cell: cell[0])[0]
        right = max(self.cells, key=lambda cell: cell[1])[1]
        return top, left, bottom, right
    
    def print_board(self):
        top, left, bottom, right = self.get_boundaries()
        print('--------------------------------------')
        for i in range(top, bottom + 1):
            for j in range(left, right + 1):
                if (i, j) in self.cells:
                    print("*", end='')
                else:
                    print('.', end='')
            print('')
        print('--------------------------------------')

def main():

    # Test 1: Square that doesn't change

    # arr = [(5,5), (5,6), (6,5), (6,6)]
    # steps = 100000

    # Test 2: Column that iterates back and forth

    # arr = [(5,5), (5,6), (5,4)]
    # steps = 1000000

    # Test 3: Pulsar

    arr = set([(3, 1), (4, 1), (5, 1), (1, 3), (1, 4), (1, 5), (6, 3), (6, 4), (6, 5),
    (3, 6), (4, 6), (5, 6), (3, 8), (4, 8), (5, 8), (1, 9), (1, 10), (1, 11), (6, 9),
    (6, 10), (6, 11), (3, 13), (4, 13), (5, 13), (8, 3), (8, 4), (8, 5), (9, 1), (10, 1),
    (11, 1), (9, 6), (10, 6), (11, 6), (13, 3), (13, 4), (13, 5), (8, 9), (8, 10), (8, 11),
    (9, 8), (10, 8), (11, 8), (9, 13), (10, 13), (11, 13), (13, 9), (13, 10), (13, 11)])

    steps = 1000000

    # Test 4: Beacon

    # arr = set([(5, 6), (5, 7), (6,6), (7,9), (8,8), (8,9)])
    # steps = 1000000

    # game_of_life_sol1(arr, steps)
    game_of_life_obj = GameOfLife(steps, arr)

main()