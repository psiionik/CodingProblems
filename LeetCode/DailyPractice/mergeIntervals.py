"""
Given a collection of intervals, merge all overlapping intervals.

Ex 1.
Input: [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].

Ex 2.
Input: [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.
"""

def merge_intervals_sol1(intervals):
    if intervals == []:
        return intervals

    sorted_list = sorted(intervals, key=lambda x: x[0])

    start = [sorted_list[0][0], sorted_list[0][1]]
    
    result = []

    for i in range(1,len(sorted_list)):
        if sorted_list[i][0] > start[1]:
            result.append(start)
            start = [sorted_list[i][0], sorted_list[i][1]]
        else:
            start[1] = max(sorted_list[i][1], start[1])
    
    result.append(start)

    return result


def main():

    # Test 1: Should return [[1,6],[8,10],[15,18]]

    # intervals = [[1,3],[2,6],[8,10],[15,18]]

    # Test 2: Should return [[1, 5]]

    # intervals = [[1,4],[4,5]]

    # Test 3: Should return [[1,4]]

    intervals = [[1,4],[2,3]]


    print(merge_intervals_sol1(intervals))

main()