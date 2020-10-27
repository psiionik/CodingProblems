"""
We have a list of points on the plane.  Find the K closest points to the origin (0, 0).

(Here, the distance between two points on a plane is the Euclidean distance.)

You may return the answer in any order.  The answer is guaranteed to be unique (except for the order that it is in.)

 

Example 1:

Input: points = [[1,3],[-2,2]], K = 1
Output: [[-2,2]]
Explanation: 
The distance between (1, 3) and the origin is sqrt(10).
The distance between (-2, 2) and the origin is sqrt(8).
Since sqrt(8) < sqrt(10), (-2, 2) is closer to the origin.
We only want the closest K = 1 points from the origin, so the answer is just [[-2,2]].

Example 2:

Input: points = [[3,3],[5,-1],[-2,4]], K = 2
Output: [[3,3],[-2,4]]
(The answer [[-2,4],[3,3]] would also be accepted.)
"""

import math
import heapq

def k_min_distance_sol1(points, K):
    heap = []

    for point in points:
        dis = distance(point[0], point[1])
        heapq.heappush(heap, (dis, (point[0], point[1])))

    result = []
    for i in heapq.nsmallest(K, heap):
        result.append(i[1])

    return result

def k_min_distance_sol2(points, K):
    pass

def distance(x2, y2):
    return math.sqrt((x2 - 0)**2 + (y2 - 0)**2)

def main():

    # Test 1: Should reutrn [[-2, 2]]

    # points = [[1, 3], [-2 ,2]]
    # K = 1

    # Test 2: Should return [[3,3],[-2,4]]

    points = [[3,3],[5,-1],[-2,4]]
    K = 2

    print(k_min_distance_sol2(points, K))

main()