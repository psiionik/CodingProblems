"""
You have an N by N board. Write a function that, given N, returns the number of possible arrangements of the board where
N queens can be placed on the board without threatening each other, i.e. no two queens share the same row, column, or diagonal.
"""

"""
Solution 1, Use backtracking. In backtracking, we can visualize the search space like a tree and then explore it using DFS.
Each node will be a possible configuration. If the configuration contains N queens and is valid, then we can add it to our count.
Otherwise, we can try to place another queen somewhere on the board and search from there. If we encounter an invalid board, we can
just prune the entire subtree from our search (there is no point in exploring a board that we know won't work).

Can reduce the search space by ensuring we only place queens in distinct rows, since we know that queens can never occupy the same
row.

Can represent the board as a one-dimensional array of max size N, where each value represents which column the queen is on.

(My solution)
Take these steps for a backtracking algorithm to solve this problem:
    1. Create a NxN board filled with 0s (Going to represent 0s as nothing and 1s as queens)
    2. Loop through each cell and for each one, place a queen and check if it is valid
    3. If valid, recurse to the next available spot
    4. If not valid, remove it and loop to the next cell
    5. Continuously check if the board complete, if it is then just return out of the function
"""

def n_queens_sol1(n: int, board=[]) -> int:
    if n == len(board):
        return 1

    count = 0
    for col in range(n):
        board.append(col)
        if is_valid(board):
            count += n_queens_sol1(n, board)
        board.pop()
    
    return count
    
def is_valid(board):
    current_queen_row, current_queen_col = len(board) - 1, board[-1]
    # Iterate over all already-placed queens and check if any of them can attack
    # each other.
    for row, col in enumerate(board[:-1]):
        diff = abs(current_queen_col - col)
        if diff == 0 or diff == current_queen_row - row:
            return False

    return True

def main():

    # Test 1

    n = 4

    print(n_queens_sol1(n))

main()