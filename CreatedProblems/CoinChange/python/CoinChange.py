"""
Problem where given a list of coins (always sorted in ascending order) and a target coin value, find the minimum
amount of coins that are needed to reach that target coin value exactly.

If there is no such possible amount of coins that can reach that target coin value, return -1.

Example 1.
    list_of_coins = [1, 5, 10]
    target_value = 12

    return 3 -> 1 "10" coin value, 2 "1" coin value to reach an amount of "12"

Example 2.
    list_of_coins = [2]
    target_value = 3

    return -1 -> there is no possible number of coins with value "2" to reach an amount of "3"
"""


from enum import Enum
import sys

class SolutionEnumerations(Enum):
    NAIVE = 1
    MEMOIZATION = 2
    DYNAMICPROGRAMMING = 3
    GREEDY = 4

class CoinChangeSolution():
    def coinChange(self, list_of_coins: list[int], target_value: int, solution_approach: SolutionEnumerations) -> int:
        result = -1
        
        if solution_approach == SolutionEnumerations.NAIVE:
            result = self.coinChangeNaive(list_of_coins, target_value)
        elif solution_approach == SolutionEnumerations.MEMOIZATION:
            cache = [-1 for _ in range(target_value + 1)]
            result = self.coinChangeMemoization(list_of_coins, target_value, cache)
        elif solution_approach == SolutionEnumerations.DYNAMICPROGRAMMING:
            result = self.coinChangeDynamicProgramming(list_of_coins, target_value)
        elif solution_approach == SolutionEnumerations.GREEDY:
            result = self.coinChangeGreedy(list_of_coins, target_value)
        else:
            print("An invalid solution approach was selected. Failing out...")

        return result
   
    def coinChangeNaive(self, list_of_coins: list[int], target_value: int) -> int:
        
        # Base case of when we use a coin and then reached the lowest point and need to recurse back
        if target_value == 0:
            return 0

        number_of_coins = sys.maxsize
         
        # Recursive step where we loop through all possible coin values and then take the min coin amount for the next iteration
        for coin_value in list_of_coins:
            if coin_value <= target_value:
                number_of_coins = min(number_of_coins, self.coinChangeNaive(list_of_coins, target_value - coin_value ) + 1)
            else:
                continue

        return number_of_coins


    def coinChangeMemoization(self, list_of_coins: list[int], target_value: int, cache: list[int]) -> int:
        if target_value == 0:
            return 0
        
        # Same as NAIVE implementation except now we have a case for when we have seen a "target amount" already
        # and we should store that value so we just return the min value
        if cache[target_value] >= 0:
            return cache[target_value]

        number_of_coins = sys.maxsize

        for coin_value in list_of_coins:
            if coin_value <= target_value:
                number_of_coins = min(number_of_coins, self.coinChangeMemoization(list_of_coins, target_value - coin_value, cache) + 1)
            else:
                continue

        cache[target_value] = number_of_coins
        return number_of_coins


    def coinChangeDynamicProgramming(self, list_of_coins: list[int], target_value: int) -> int:
        # Need some sort of memory allocated to remember the values that we have calculated so far
        memory: list[int] = [sys.maxsize for _ in range(target_value + 1)]

        # Initialize the first value since to get a value of 0 we need 0 coins
        memory[0] = 0

        # Build up to the target value amount
        for value in range(0, target_value + 1):
            # Have to go through all of the coin amounts
            for coin_value in list_of_coins:
                if coin_value <= value:
                    memory[value] = min(memory[value], memory[value - coin_value] + 1)
                else:
                    continue

        return memory[-1]

    def coinChangeGreedy(self, list_of_coins: list[int], target_value: int) -> int:
        # This method assumes that the "list_of_coins" values are sorted in ascending order
        number_of_coins = 0
        
        while target_value > 0:
            for coin_value in list_of_coins[::-1]:
                if coin_value <= target_value:
                    number_of_coins += 1
                    target_value -= coin_value
                    break
        
        return number_of_coins


def runTestSuiteOne(greedy: bool = False):
    """
    Positive Test Cases using the most basic / classic example in this problem: [1, 5, 10, 25] coins

    This method works with a Greedy approach because of the list of coin values are a multiple of each other.
    """

    list_of_coins: list[int] = [1, 5, 10, 25]
    target_value_list: list[int] = [11, 31, 40]
    target_amount_list: list[int] = [2, 3, 3]

    success_count: int = 0
    failed_count: int = 0
    total_count: int = 0

    coin_change_solution = CoinChangeSolution()
    
    for iteration_index in range(0, len(target_value_list)):
        for sol_enum in SolutionEnumerations:
            if sol_enum == SolutionEnumerations.GREEDY and greedy == False:
                continue
            
            print("Running test number {} with solution: {} with coin list: {} and target value: {}...\n".format(iteration_index, sol_enum, str(list_of_coins), target_value_list[iteration_index]))

            actual = coin_change_solution.coinChange(list_of_coins, target_value_list[iteration_index], sol_enum)

            if actual == target_amount_list[iteration_index]:
                success_count += 1
                print("[PASSED]: The minimum amount of coins to reach target value {} is {}.\n".format(target_value_list[iteration_index], target_amount_list[iteration_index]))
            else:
                failed_count += 1
                print("[FAILED]: Expected to reach target value {} with {} coins but got {} instead.\n".format(target_value_list[iteration_index], target_amount_list[iteration_index], actual))
            
            total_count += 1

    print("============================================================================")
    print("TEST RESULTS FOR TEST CASE: 1")
    print(f"[SUCCESS TEST CASES]: {success_count}")
    print(f"[FAILED TEST CASES]: {failed_count}")
    print(f"[CONCLUSION]: Passed {success_count} test cases out of {total_count} for this run")
    print("============================================================================")

def runTestSuiteTwo(greedy: bool = False):
    """
    Positive Test Cases using an example where the coin values are not multiples of each other: [1, 5, 6, 9] coins

    This method doesn't work with a Greedy approach because of the list of coin values are not a multiple of each other.
    """

    list_of_coins: list[int] = [1, 5, 6, 9]
    target_value_list: list[int] = [13, 38, 21]
    target_amount_list: list[int] = [3, 5, 3]

    success_count: int = 0
    failed_count: int = 0
    total_count: int = 0

    coin_change_solution = CoinChangeSolution()
    
    for iteration_index in range(0, len(target_value_list)):
        for sol_enum in SolutionEnumerations:
            if sol_enum == SolutionEnumerations.GREEDY and greedy == False:
                continue
            
            print("Running test number {} with solution: {} with coin list: {} and target value: {}...\n".format(iteration_index, sol_enum, str(list_of_coins), target_value_list[iteration_index]))

            actual = coin_change_solution.coinChange(list_of_coins, target_value_list[iteration_index], sol_enum)

            if actual == target_amount_list[iteration_index]:
                success_count += 1
                print("[PASSED]: The minimum amount of coins to reach target value {} is {}.\n".format(target_value_list[iteration_index], target_amount_list[iteration_index]))
            else:
                failed_count += 1
                print("[FAILED]: Expected to reach target value {} with {} coins but got {} instead.\n".format(target_value_list[iteration_index], target_amount_list[iteration_index], actual))
            
            total_count += 1

    print("============================================================================")
    print("TEST RESULTS FOR TEST CASE: 2")
    print(f"[SUCCESS TEST CASES]: {success_count}")
    print(f"[FAILED TEST CASES]: {failed_count}")
    print(f"[CONCLUSION]: Passed {success_count} test cases out of {total_count} for this run")
    print("============================================================================")

def runTestSuite():
    runTestSuiteOne(True)
    runTestSuiteTwo()


def main():
    runTestSuite()


if __name__ == "__main__":
    main()
