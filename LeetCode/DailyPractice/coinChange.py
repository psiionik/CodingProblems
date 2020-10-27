"""
You are given coins of different denominations and a total amount of money amount. Write a function to compute the fewest number of coins 
that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

Example 1:

Input: coins = [1, 2, 5], amount = 11
Output: 3 
Explanation: 11 = 5 + 5 + 1

Example 2:

Input: coins = [2], amount = 3
Output: -1
"""

MAX_VAL = 100000000

def coinChange(coins, amount):
    result = [0] * (amount + 1)
    
    for ind in range(1, amount + 1):
        min_val = MAX_VAL 
        for coin in coins:
            if (ind - coin >= 0):
                if (result[ind - coin] + 1 < min_val):
                    min_val = result[ind - coin] + 1
        
        if (min_val == MAX_VAL):
            result[ind] = MAX_VAL
        else:
            result[ind] = min_val

    if (result[-1] == MAX_VAL):
        return -1
    else:
        return result[-1]


def main():

    # Test 1: Should return 3

    #coins = [1, 2, 5]
    #amount = 11

    # Test 2: Should return -1

    coins = [2]
    amount = 3


    print(coinChange(coins, amount))

main()
