"""
Given an array of time intervals (start, end) for classroom lectures (possibly overlapping), find the minimum number of rooms required.

For example, given [(30, 75), (0, 50), (60, 150)] should return 2
"""

"""
Solution 1, First sort the list based on the start time for each classroom lecture. Keep a min heap of the tuples based on their
end times. Loop through the sorted list and when there is a start time that is less than the current min end time, add it
and then make it the root (since thats what a min-heap does). When there is a start time that is greater than the current min
end time, pop the root and then add that. Runs in O(n*log(n)) time because of the sorting.
"""

import heapq

def min_rooms_required_sol1(intervals):
    intervals = sorted(intervals, key=lambda x: x[0])
    print(intervals)
    
    heap = []
    heapq.heappush(heap, intervals[0][1])

    for i in range(1, len(intervals)):
        if (intervals[i][0] >= heap[0]):
            _ = heapq.heappop(heap)
            heapq.heappush(heap, intervals[i][1])
        else:
            heapq.heappush(heap, intervals[i][1])
    
    return len(heap)

"""
Solution 2, The minimum number of classrooms is the maximum number of overlapping intervals. We can extract the start times and end
times of all the intervals and sort them. Then we can start two pointers on each list:

1. If the current start is before the current end, then we have a new overlap; increment the start pointer
2. If the current start is after the current end, then our overlap closes; increment the end pointer

Just need to keep track of the max number of overlaps seen so far and the current number of overlaps.
"""

def min_rooms_required_sol2(intervals):
    starts = sorted(start for start, end in intervals)
    ends = sorted(end for start, end in intervals)

    current_max = 0
    current_overlap = 0
    i, j = 0, 0
    while i < len(intervals) and j < len(intervals):
        if starts[i] < ends[j]:
            current_overlap += 1
            current_max = max(current_max, current_overlap)
            i += 1
        else:
            current_overlap -= 1
            j += 1
    return current_max
    
def main():
    """
    Test 1: Should return 2
    """

    # intervals = [(30, 75), (0, 50), (60, 150)]


    """
    Test 2: Should return 2
    """

    intervals = [(10, 15), (25, 30), (0, 50), (75, 105)]

    print(min_rooms_required_sol1(intervals))


main()