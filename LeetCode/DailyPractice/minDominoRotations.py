"""
In a row of dominoes, A[i] and B[i] represent the top and bottom halves of the i-th domino.
(A domino is a tile with two numbers from 1 to 6 - one on each half of the tile.)

We may rotate the i-th domino, so that A[i] and B[i] swap values.

Return the minimum number of rotations so that all the values in A are the same, or all the values in B are the same.

If it cannot be done, return -1.

Input: A = [2,1,2,4,2,2], B = [5,2,6,2,3,2]
Output: 2
Explanation: 
The first figure represents the dominoes as given by A and B: before we do any rotations.
If we rotate the second and fourth dominoes, we can make every value in the top row equal to 2, as indicated by the second figure.
"""

"""
Solution 1, Use a greedy approach. Get the very first value and see if it needs a rotation to match with the rest of the list.
Then loop through the list and see if each index is equal to that first value with or without a rotation. If it doesn't match with or
without a rotation for both lists then return -1, else return the min of the two lists.
"""
def minDominoRotations(A, B):
    A_startval = A[0]
    Ap_startval = B[0]
    B_startval = B[0]
    Bp_startval = A[0]
    A_rot = 0
    B_rot = 0
    Ap_rot = 1
    Bp_rot = 1
    for i in range(1, len(A)):
        if (A_startval == A[i]):
            A_rot = A_rot
        elif (A_startval == B[i]):
            A_rot += 1
        elif (A_startval != A[i] and A_startval != B[i]):
            A_startval = -1

        if(B_startval == B[i]):
            B_rot = B_rot
        elif (B_startval == A[i]):
            B_rot += 1
        elif (B_startval != A[i] and B_startval != B[i]):
            B_startval = -1

        if (Ap_startval == A[i]):
            Ap_rot == Ap_rot        
        elif (Ap_startval == B[i]):
            Ap_rot += 1
        elif (Ap_startval != A[i] and Ap_startval != B[i]):
            Ap_startval = -1
        
        if(Bp_startval == B[i]):
            Bp_rot = Bp_rot
        elif (Bp_startval == A[i]):
            Bp_rot += 1
        elif (Bp_startval != A[i] and Bp_startval != B[i]):
            Bp_startval = -1
        
        


    if (A_startval == -1 and B_startval == -1 and Ap_startval == -1 and Bp_startval == -1):
        return -1
    
    if (A_startval == -1):
        A_rot = 999999999
    if(B_startval == -1):
        B_rot = 99999999
    if(Ap_startval == -1):
        Ap_rot = 9999999999
    if (Bp_startval == -1):
        Bp_rot = 9999999999


    return min(A_rot, B_rot, Ap_rot, Bp_rot)

def minDominoRotationsSol2(A, B):
    def check(x):
        a_rot = 0
        b_rot = 0
        for i in range(n):
            if A[i] != x and B[i] != x:
                return -1
            elif A[i] != x:
                a_rot += 1
            elif B[i] != x:
                b_rot += 1
            
        return min(a_rot, b_rot)

    n = len(A)
    rotations = check(A[0])
    if rotations != -1 or A[0] == B[0]:
        return rotations
    else:
        return check(B[0])


def main():

    # Test 1: Should return 2
    A = [2, 1, 2, 4, 2, 2]
    B = [5, 2, 2, 2, 2, 2]

    # Test 2: Should return -1
    # A = [3,5,1,2,3]
    # B = [3,6,3,3,4]

    print(minDominoRotationsSol2(A, B))

main()