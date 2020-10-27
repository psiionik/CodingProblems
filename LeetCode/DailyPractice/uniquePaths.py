"""
A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time.
The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

How many possible unique paths are there?
"""

"""
Solution 1, To solve the problem, go through these steps:
    1. Initialize a matrix of size nxm with 0s
    2. Initialize the first row and the first column to be 1s
    3. Loop from (1,1) to end and the element of that index is equal to the sum of the element above it and left of it
    4. At the end of the loop the bottom-rightmost element should have the number of unique paths
"""

def unique_paths_sol1(m, n):

    # Initializing the matrix with the right size
    matrix = [[0 for i in range(m)] for j in range(n)]
    
    # Setting the 1st column and 1st row to be 1s
    for i in range(0, len(matrix)):
        matrix[i][0] = 1
    
    for i in range(0, len(matrix[0])):
        matrix[0][i] = 1

    # Double for loop that sets the element based on the top and left
    for i in range(1, len(matrix)):
        for j in range(1, len(matrix[0])):
            matrix[i][j] = matrix[i-1][j] + matrix[i][j-1]
    
    # Return the bottom-rightmost element in the matrix
    return matrix[-1][-1]

def main():

    # Test 1: Should return 3

    # m = 3
    # n = 2

    # Test 2: Should return 28
    m = 7
    n = 3

    print(unique_paths_sol1(m, n))

main()