"""
Given an array of strictly the characters 'R', 'G', and 'B', segregate the values of the array so that all the Rs come first,
the Gs come second, and the Bs come last. You can only swap elements of the array.

Do this in linear time and in-place.

For example, given the array ['G', 'B', 'R', 'R', 'B', 'R', 'G'], it should become ['R', 'R', 'R', 'G', 'G', 'B', 'B'].
"""

"""
Solution 1, Can make a simpler version of the problem where there is a low index, a high index, and something in the middle.
Maintain 3 sections in the array using two indices, low and high.

    1. Strictly 'R's: array[:low]
    2. Unknown: array[low:high]
    3. Strictly 'G's: array[high:]

Low starts at 0 and high starts at len(arr) - 1. As we iterate through the array, swap any 'G's that we see to the third section
and decrement high. If we see an 'R', then we just need to increment low since that's where it belongs. We can terminate when
low crosses high.

To increase this into 3 partitions, we can maintain 4 sections using 3 indices: low, middle, and high.

    1. Strictly 'R's: array[:low]
    2. Strictly 'G's: array[low:middle]
    3. Unknown: array[middle:high]
    4. Strictly 'B's: array[high:]

Initialize both low and mid to 0 and high to len(arr) - 1.

To maintain the variant, look at mid:
    1. If it is R, then swap array[low] with array[mid] and increment low and mid
    2. If it is G, then increment mid
    3. If it is B, then swap array[mid] with array[high] and decrement high

Once mid crosses over high, then the unknown section is gone and we can terminate
"""

def linear_swap_inplace_sol1(arr):
    low, mid, high = 0, 0, len(arr) - 1

    while(mid <= high):
        if(arr[mid] == 'R'):
            temp = arr[low]
            arr[low] = arr[mid]
            arr[mid] = temp
            low+=1
            mid+=1
        elif(arr[mid] == 'G'):
            mid+=1
        else:
            temp = arr[high]
            arr[high] = arr[mid]
            arr[mid] = temp
            high-=1
    
    return arr


def main():

    # Test 1: Should return ['R', 'R', 'R', 'G', 'G', 'B', 'B']

    arr = ['G', 'B', 'R', 'R', 'B', 'R', 'G', 'R', 'B', 'R', 'G']

    print(linear_swap_inplace_sol1(arr))

main()