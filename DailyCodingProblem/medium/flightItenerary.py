"""
Given an unordered list of flights taken by someone, each represented as (origin, destination) pairs, and
a starting airport, compute the person's itinerary. If no such itinerary exists, return null.
If there are multiple possible itineraries, return the lexicographically smallest one.
All flights must be used in the itinerary.

For example, given the list of flights [('SFO', 'HKO'), ('YYZ', 'SFO'), ('YUL', 'YYZ'), ('HKO', 'ORD')]
and starting airport 'YUL', you should return the list ['YUL', 'YYZ', 'SFO', 'HKO', 'ORD'].

Given the list of flights [('SFO', 'COM'), ('COM', 'YYZ')] and starting airport 'COM', you should return null.

Given the list of flights [('A', 'B'), ('A', 'C'), ('B', 'C'), ('C', 'A')] and starting airport 'A',
you should return the list ['A', 'B', 'C', 'A', 'C'] even though ['A', 'C', 'A', 'B', 'C'] is also a valid itinerary.
However, the first one is lexicographically smaller.
"""

from collections import defaultdict

"""
Solution 1, Create an adjacency list and have nodes that have an index that go to the next thing in the adjacency list.
Have a dictionary to map the values of the nodes to the corresponding indexes in the adjancency list.
Append to a result list as you travel through the adjacency list.
At the end check if all of the starting nodes in the adjacency list have been visited, if not then return null.
Else return the list
"""

class Node:
    def __init__(self, value):
        self.value = value
        self.next = None
        self.visited = False

def flight_itenerary_sol1(arr, start):
    dic = {}
    result_list = []
    adjacency_list = []
    
    for i in range(0, len(arr)):
        adjacency_list.append(Node(arr[i][0]))
        dic[arr[i][0]] = i

    current_node = None

    for j in range(0, len(arr)):
        adjacency_list[j].next = Node(arr[j][1])
        if (start == adjacency_list[j].value ):
            current_node = adjacency_list[j]
            adjacency_list[j].visited = True

    result_list.append(current_node.value)

    while(current_node != None):
        if current_node.next.value in dic:
            index = dic[current_node.next.value]
            current_node = adjacency_list[index]
            adjacency_list[index].visited = True
            result_list.append(current_node.value)
        else:
            result_list.append(current_node.next.value)
            current_node = None

    for i in adjacency_list:
        if i.visited == False:
            return None

    return result_list

"""
Solution 2, Problem is similar to that of the N queens problem.
Have a desired final state (all the flights are used up), we can construct partial itineraries and reject them, and each step we have
potentially multiple avenues to explore

Use Backtracking

Can do the following:
    - Keep a list of itinerary candidates
    - Keep a current itinerary initialized with the starting airport
    - Then recursively:
        - Iterate over all the flights that start from the last airport in the itinerary
        - For each flight, temporarily add the destination to our itinerary and remove it from the flight list
            Then recursively call with the new itinerary and flight list
        - Concatenate all the results to our list of itinerary candidates
    - Sort the itinerary candidates and pick the lexiographically smallest one

To speed it up, we can store all the flights in a dictionary with the origin as a key and a list of flight destinations from that
origin as a value.
Then we can look up the options in O(1) time instead of O(n) time.
"""

def flight_itenerary_sol2(arr, start):
    # Store all the flights into a dictionary key: origin -> val: list of destinations
    flight_map = defaultdict(list)
    for origin, destination in arr:
        flight_map[origin] += [destination]
    
    def visit(flight_map, total_flights, current_itinerary):
        # If our itinerary uses up all the flights, we are done
        if len(current_itinerary) == total_flights + 1:
            return [current_itinerary[:]]

        last_stop = current_itinerary[-1]

        # If we haven't used all the flights yet but we have no way
        # of getting out of this airport, then we're stuck. Backtrack out.
        if not flight_map[last_stop]:
            return []
        
        # Otherwise, let's try all the options out of the current stop recursively.
        # We temporarily take them out of the mapping once we use them.
        potential_itineraries = []
        for i, flight in enumerate(flight_map[last_stop]):
            flight_map[last_stop].pop(i)
            current_itinerary.append(flight)
            potential_itineraries.extend(visit(flight_map, total_flights, current_itinerary))
            flight_map[last_stop].insert(i, flight)
            current_itinerary.pop()
        
        return potential_itineraries
    
    valid_itineraries = visit(flight_map, len(arr), [start])
    if valid_itineraries:
        return sorted(valid_itineraries)[0]

def main():

    # Test 1: Should return ['YUL', 'YYZ', 'SFO', 'HKO', 'ORD']

    arr = [('SFO', 'HKO'), ('YYZ', 'SFO'), ('YUL', 'YYZ'), ('HKO', 'ORD')]
    start = 'YUL'

    # Test 2: Should return None

    # arr = [('SFO', 'COM'), ('COM', 'YYZ')]
    # start = 'COM'

    # Test 3: Should return ['A', 'B', 'C', 'A', 'C']
    
    # arr = [('A', 'B'), ('A', 'C'), ('B', 'C'), ('C', 'A')]
    # start = 'A'

    print(flight_itenerary_sol2(arr, start))


main()
