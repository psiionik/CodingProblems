from collections import defaultdict
def maxChunksToSorted(arr):
    """
    :type arr: List[int]
    :rtype: int
    """
    maxOfLeft = [-1]*len(arr)
    minOfRight = [-1]*len(arr)

    maxOfLeft[0] = arr[0]
    for i in range(1, len(arr)):
        maxOfLeft[i] = max(maxOfLeft[i-1], arr[i])

    minOfRight[len(arr) -1] = arr[len(arr) -1]
    for i in range(len(arr) - 2, -1, -1):
        minOfRight[i] = min(minOfRight[i+1], arr[i])

    res = 0
    for i in range(0, len(arr)-1):
        if(maxOfLeft[i] <= minOfRight[i+1]):
            res += 1

    return res + 1

def main():
    arr = [5,1,1,8,1,6,5,9,7,8]
    arr2 = [2, 1, 3, 4, 4]
    arr3 = [1, 0, 1, 3, 2]
    x = maxChunksToSorted(arr2)
    print(x)



main()