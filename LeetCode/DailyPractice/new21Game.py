"""
Alice plays the following game, loosely based on the card game "21".

Alice starts with 0 points, and draws numbers while she has less than K points.
During each draw, she gains an integer number of points randomly from the range [1, W], where W is an integer.
Each draw is independent and the outcomes have equal probabilities.

Alice stops drawing numbers when she gets K or more points.  What is the probability that she has N or less points?

Input: N = 10, K = 1, W = 10
Output: 1.00000
Explanation:  Alice gets a single card, then stops.

Input: N = 6, K = 1, W = 10
Output: 0.60000
Explanation:  Alice gets a single card, then stops.
In 6 out of W = 10 possibilities, she is at or below N = 6 points.

Input: N = 21, K = 17, W = 10
Output: 0.73278
"""

"""
Solution 1, Use dynamic programming to store probability calculations that you have made in the past.
Create a list of size N
For each index, find the probability that it takes to get to that index number using what you have already calculated before.
After your index passes K, then stop adding probabilities from those index values >= K. At the end of the list, you should have the
total probability to get that number from all the indexes > k.
"""

def new21game(N, K, W):
    
    memory = [0] * (N + 1)

    memory[0] = 1

    for index in range(1, N + 1):
        probability_to_add = 0
        w = 1
        while (w <= W and index - w  >= 0):
            if (index - w < K):
                probability_to_add = probability_to_add + (memory[index - w] * (1/W)) 
            w += 1
            
        memory[index] = probability_to_add

    result = 0
    for i in range(0, len(memory)):
        if (i >= K):
            result += memory[i]

    return result

def new21gamesol2(N, K, W):
    if K == 0 or N >= K + W:
        return 1
    dp = [1.0] + [0.0] * N
    Wsum = 1.0
    for i in range(1, N + 1):
        dp[i] = Wsum / W
        if i < K: 
            Wsum += dp[i]
        if i - W >= 0: 
            Wsum -= dp[i - W]
    return sum(dp[K:])

def main():

    # Test 1: Should return 0.73278

    N = 21
    K = 17
    W = 10

    # Test 2: Should return 1
    # N = 10
    # K = 1
    # W = 10

    # Test 3: Should return 0.6
    # N = 6
    # K = 1
    # W = 10

    # N = 9811
    # K = 8776
    # W = 1096

    print(new21gamesol2(N, K, W))



main()