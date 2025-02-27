"""
Given n numbers, find the greatest common denominator between them.

For example, given the numbers [42, 56, 14], return 14.
"""

def gcdMultiple(arr):
    min_val = min(arr)
    
    for ind in range(0, len(arr)):
        arr[ind] = arr[ind] % min_val

    for num in arr:
        if (num != 0):
            new_arr = list(filter(lambda a: a != 0, arr))
            min_val = gcdMultiple(new_arr)
            
    return min_val



def main():


    # Test 1: Should return 14

    #arr = [42, 56, 14]

    # Test 2: Should return 12

    arr = [60, 48, 36]


    print(gcdMultiple(arr))


main()

