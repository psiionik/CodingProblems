"""
In a row of seats, 1 represents a person sitting in that seat, and 0 represents that the seat is empty. 

There is at least one empty seat, and at least one person sitting.

Alex wants to sit in the seat such that the distance between him and the closest person to him is maximized. 

Return that maximum distance to closest person.

Input: [1,0,0,0,1,0,1]
Output: 2
Explanation: 
If Alex sits in the second open seat (seats[2]), then the closest person has distance 2.
If Alex sits in any other open seat, the closest person has distance 1.
Thus, the maximum distance to the closest person is 2.

Input: [1,0,0,0]
Output: 3
Explanation: 
If Alex sits in the last seat, the closest person is 3 seats away.
This is the maximum distance possible, so the answer is 3.
"""

def maxDistToClosest(seats):
    longest_length = 0
    for ind,seat in enumerate(seats):
        if seat == 1:
            continue
        
        count = 1
        left_ind = ind -1
        right_ind = ind + 1
        while left_ind >= 0 or right_ind < len(seats):
            if left_ind >= 0 and right_ind < len(seats):
                if seats[left_ind] == 1 or seats[right_ind] == 1:
                    break

                count += 1
                left_ind -= 1
                right_ind += 1

            elif left_ind >= 0:
                if seats[left_ind] == 1:
                    break
                count += 1
                left_ind -= 1
            elif right_ind < len(seats):
                if seats[right_ind] == 1:
                    break
                count += 1
                right_ind += 1

        longest_length = max(longest_length, count)
        
    return longest_length



def main():

    # Test 1: Should return 2
    seats = [1,0,0,0,1,0,1]

    # Test 2: Should return 3
    # seats = [1, 0, 0, 0]


    print(maxDistToClosest(seats))


main()