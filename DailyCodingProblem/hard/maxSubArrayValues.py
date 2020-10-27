"""
Given an array of integers and a number k, where 1 <= k <= length of the array, compute the maximum values of each subarray of length k.
For example, given array = [10, 5, 2, 7, 8, 7] and k = 3, we should get: [10, 7, 8, 8], since:

10 = max(10, 5, 2)
7 = max(5, 2, 7)
8 = max(2, 7, 8)
8 = max(7, 8, 7)

Do this in O(n) time and O(k) space. You can modify the input array in-place and you do not need to store the results.
You can simply print them out as you compute them.
"""

"""
Solution 1, Make a running buffer that is the size of k. Loop through the array and then append to this subarray. When the length
of the subarray is equal to k, start comparing the max in this array and then printing that out. As you read new values, try to
append more of them and kick the most recent out by using list operations. Print all of them out until you reach the end.
This takes O(n*k) time.
"""

from collections import deque

def max_sub_array_sol1(values, k):
    subarray = []

    for i in values:
        if len(subarray) < k:
            subarray.append(i)
        else:
            print(max(subarray))
            subarray = subarray[1:]
            subarray.append(i)
    
    print(max(subarray))

"""
Solution 2, Use a max-heap of size k. Add the first k elements to the heap initially and then pop off the max and add the next
element for the rest of the array. Since this requires adding and removing things from the heap, this will take O(n * log(k)).
"""

"""
Solution 3, Keep a double-ended queue with max size k and only keep what we need to evaluate in it. For example, if we have
[1, 3, 5] then we only need to keep [5], since we know that 1 and 3 cannot be the maxes. Maintain an ordered list of indices
where we only keep the elements that we care about. Maintain the loop invariant that our queue is always ordered so that we
only keep the indices that we care about. This means that there are no greater elements after since we would just pick the
greater element as the max instead.
"""

def max_sub_array_sol2(values, k):
    q = deque()
    for i in range(k):
        while q and values[i] >= values[q[-1]]:
            q.pop()
        q.append(i)
    
    for i in range(k, len(values)):
        print(values[q[0]])
        while q and q[0] <= i - k:
            q.popleft()
        while q and values[i] >= values[q[-1]]:
            q.pop()
        q.append(i)
    
    print(values[q[0]])


def main():
    values = [10, 5, 2, 7, 8, 7]
    max_sub_array_sol2(values, 3)

main()