"""
You have N gardens, labelled 1 to N.  In each garden, you want to plant one of 4 types of flowers.

paths[i] = [x, y] describes the existence of a bidirectional path from garden x to garden y.

Also, there is no garden that has more than 3 paths coming into or leaving it.

Your task is to choose a flower type for each garden such that,
for any two gardens connected by a path, they have different types of flowers.

Return any such a choice as an array answer, where answer[i] is the type of flower
planted in the (i+1)-th garden.  The flower types are denoted 1, 2, 3, or 4.  It is guaranteed an answer exists.
"""
import collections

def gardenNoAdj(N, paths):
    g = collections.defaultdict(list)
    for x, y in paths:
        g[x].append(y)
        g[y].append(x)
    plantdict = {i: 0 for i in range(1, N+1)}
    for garden in g:
        pick = set(range(1,5))
        for each in g[garden]:
            if plantdict[each] != 0 and plantdict[each] in pick:
                pick.remove(plantdict[each])
        plantdict[garden] = pick.pop()

    return [plantdict[x] if plantdict[x] != 0 else 1 for x in range(1, N+1)]

def main():

    # Test 1: Should return [1, 2, 3]
    N = 3
    paths = [[1,2], [2,3], [3, 1]]

    # Test 2: Should return [1, 2, 1, 2] or [1, 2, 3, 4]
    # N = 4
    # paths = [[1, 2], [3, 4]]

    # Test 3: Should return [1, 2, 3, 4]
    # N = 4
    # paths = [[1,2],[2,3],[3,4],[4,1],[1,3],[2,4]]

    print(gardenNoAdj(N, paths))


main()