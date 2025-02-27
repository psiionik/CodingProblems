"""
Given an m x n matrix of non-negative integers representing the height of each unit cell in a continent, the "Pacific ocean" touches the left and top edges
of the matrix and the "Atlantic ocean" touches the right and bottom edges.

Water can only flow in four directions (up, down, left, or right) from a cell to another one with height equal or lower.

Find the list of grid coordinates where water can flow to both the Pacific and Atlantic ocean.

Note:

The order of returned grid coordinates does not matter.
Both m and n are less than 150.
 

Example:

Given the following 5x5 matrix:

  Pacific ~   ~   ~   ~   ~ 
       ~  1   2   2   3  (5) *
       ~  3   2   3  (4) (4) *
       ~  2   4  (5)  3   1  *
       ~ (6) (7)  1   4   5  *
       ~ (5)  1   1   2   4  *
          *   *   *   *   * Atlantic

Return:

[[0, 4], [1, 3], [1, 4], [2, 2], [3, 0], [3, 1], [4, 0]] (positions with parentheses in above matrix). 
"""
from collections import deque

def getWaterFlow(matrix):
    result = []

    for i in range(0, len(matrix)):
        for j in range(0, len(matrix[0])):
            find = findValid(i, j, matrix, result)
            if find:
                result.append([i, j])

    return result

def findValid(org_i, org_j, matrix, result):
    seen = set()
    queue = deque()
    queue.append((org_i, org_j))
    seen.add((org_i, org_j))

    reach_atlantic = False
    reach_pacific = False

    while(queue):
        i, j = queue.pop()

        if (i == 0 or j == 0):
            reach_pacific = True
        
        if (i == len(matrix) -1 or j == len(matrix[0]) -1):
            reach_atlantic = True

        if (reach_atlantic and reach_pacific):
            return True
        
        neighbors = getNeighbors(i, j, matrix)
        for neighbor in neighbors:
            if neighbor not in seen and matrix[neighbor[0]][neighbor[1]] <= matrix[i][j]:
                queue.append([neighbor[0], neighbor[1]])
                seen.add((neighbor[0],neighbor[1]))

    return False


def getNeighbors(i, j, matrix):
    neighbors = []
    for row in range(i-1, i+2):
        for col in range(j-1, j+2):
            if row < 0 or row >= len(matrix):
                continue
            if col < 0 or col >= len(matrix[0]):
                continue
            if i == row and j == col:
                continue
            if i == row or j == col: 
                neighbors.append((row, col))
    
    return neighbors

def solution(matrix):
    if not matrix:
        return []
    
    directions = [(1, 0), (-1, 0), (0, 1), (0, -1)]
    m = len(matrix)
    n = len(matrix[0])

    p_visited = [[False for _ in range(n)] for _ in range(m)]
    a_visited = [[False for _ in range(n)] for _ in range(m)]

    result = []

    for i in range(m):
        dfs(matrix, i, 0, p_visited, m, n, directions)
        dfs(matrix, i, n-1, a_visited, m, n, directions)

    for j in range(n):
        dfs(matrix, 0, j, p_visited, m, n, directions)
        dfs(matrix, m-1, j, a_visited, m, n, directions)

    for i in range(m):
        for j in range(n):
            if p_visited[i][j] and a_visited[i][j]:
                result.append([i, j])

    return result

def dfs(matrix, i, j, visited, m, n, directions):
    visited[i][j] = True
    for direction in directions:
        x, y = i + direction[0], j + direction[1]
        if x < 0 or x >= m or y < 0 or y >= n or visited[x][y] or matrix[x][y] < matrix[i][j]:
            continue
        dfs(matrix, x, y, visited, m, n, directions)

def main():

    # Test 1: Should return [[0, 4], [1, 3], [1, 4], [2, 2], [3, 0], [3, 1], [4, 0]] 

    matrix = [[1, 2, 2, 3, 5],
              [3, 2, 3, 4, 4],
              [2, 4, 5, 3, 1],
              [6, 7, 1, 4, 5],
              [5, 1, 1, 2, 4]]


    print(solution(matrix))




main()
