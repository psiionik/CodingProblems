"""
You are given a M by N matrix consisting of booleans that represent a board. Each True boolean represents a wall. Each False boolean
represents a tile that you can walk on.

Given this matrix, a start coordinate, and an end coordinate, return the minimum number of steps required to reach the end
coordinate from the start. If there is no possible path, then return null. You can move up, left, down, and right. You cannot
move through walls. You cannot wrap around the edges of the board.

For example, given the following board:

[[f, f, f, f],
[t, t, f, t],
[f, f, f, f],
[f, f, f, f]]

and start = (3, 0) (bottom left) and end = (0, 0) (top left), the minimum number of steps required to reach the end is 
7, since we would need to go through (1, 2) because there is a wall everywhere else on the second row.
"""

"""
Brute Force Solution, generate all possible permutations of moving through the matrix and then when at the end coordinate, return
the number of steps that it took to get there. The first one that reaches the end coordinate should return, thus giving the minimum
number of steps.
"""

"""
Solution 1, Generate all permutations to get to the end coordinate but use dynamic programming to reduce the runtime. Keep another
2D matrix of the same size that keeps the min number of steps to that coordinate on the matrix as permutations are made. Only replace
that coordinate step if there is a new way to get there in a smaller amount of steps than that is already in the matrix for that
coordinate. When trying new coordinates, only go down that path if adding the current coordinate step is smaller than that of
the coordinate step number in that matrix spot. Runtime is O(N^2) and space is O(N^2).
"""

from collections import deque

def min_boolean_board_steps_sol1(board, start, end):

    # Creating the dynamic programming memory board
    memory = [[10000000 for i in range(len(board[0]))] for j in range(len(board))]

    memory[start[0]][start[1]] = 0

    

    memory = helper(board, start[0], start[1], end[0], end[1], memory, True)

    return memory[end[0]][end[1]]

# Helper function that recurses unless you reach the end coordinate or there is no way to get there
def helper(board, current_x, current_y, end_x, end_y, memory, is_valid):
    if(is_valid == False):
        return None

    while(current_x != end_x or current_y != end_y):
        for row in range(current_x -1, current_x + 2):
            if (row == current_x):
                for col in range(current_y - 1, current_y + 2):
                    if(col == current_y):
                        continue
                    elif((col < len(board[0]) and col >= 0) and board[row][col] == False):
                        if (memory[row][col] >= memory[current_x][current_y] + 1):
                            memory[row][col] = memory[current_x][current_y] + 1
                            helper(board, row, col, end_x, end_y, memory, True)
                    else:
                        helper(board, row, col, end_x, end_y, memory, False)
            elif((row < len(board) and row >= 0) and board[row][current_y] == False):
                if (memory[row][current_y] >= memory[current_x][current_y] + 1):
                    memory[row][current_y] = memory[current_x][current_y] + 1
                    helper(board, row, current_y, end_x, end_y, memory, True)
            else:
                helper(board, row, current_y, end_x, end_y, memory, False)
    
    return memory


"""
Solution 2, Use BFS or DFS to traverse the matrix, starting from the start coordinate and keeping track of what we've seen so far
as well as the steps from the start until we find the end coordinate. Use BFS and initialize a queue with the start coordinate along
with a count of 0. Also initialize a seen set to ensure that we only add coordinates we haven't seen before. Then as long as there
is something in the queue, dequeue from the queue and first check if it's our target coordinate. If it is, then return the count.
Otherwise, get the valid neighbours of the coordinate and enqueue them in the queue. Make some helper functions such to check
whether the tile is valid, and to return the neighboring coordinates. Runtime is O(M*N), space is O(N*M).
"""

def walkable(board, row, col):
    if (row < 0 or row >= len(board)):
        return False

    if (col < 0 or col >= len(board[0])):
        return False

    return not board[row][col]

def get_walkable_neighbours(board, row, col):
    return [(r, c) for r, c in [
            (row, col - 1),
            (row -1 , col),
            (row + 1, col),
            (row, col + 1)]
            if walkable(board, r, c)
        ]

def min_boolean_board_steps_sol2(board, start, end):
    seen = set()
    queue = deque([(start, 0)])

    while queue:
        coords, count = queue.popleft()
        if coords == end:
            return count

        seen.add(coords)
        neighbours = get_walkable_neighbours(board, coords[0], coords[1])
        queue.extend((neighbour, count + 1) for neighbour in neighbours
                if neighbour not in seen)


def main():

    board = [[False, False, False, False],
            [True, True, False, True],
            [False, False, False, False],
            [False, False, False, False]]

    print(min_boolean_board_steps_sol2(board, (3, 0), (0, 0)))

    


main()
