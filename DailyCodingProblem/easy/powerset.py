"""
The power set of a set is the set of all its subsets. Write a function that, given a set, generates its power set.

For example, given the set {1, 2, 3}, it should return {{}, {1}, {2}, {3}, {1, 2}, {1, 3}, {2, 3}, {1, 2, 3}}.

You may also use a list or array to represent a set
"""

"""
Solution 1, Can do this with a recursive formula to generate the power set:
    1. If the input set is empty, return an empty set with it
    2. Otherwise, take an element from our set, (call x)
    3. Generate the power set of our input set without x. Call it result
    4. Return the union of name with name + x
"""

def power_set(s):
    if not s:
        return [[]]
    result = power_set(s[1:])
    return result + [subset + [s[0]] for subset in result]

class Solution:
    def __init__(self):
        self.res = []
        
    def power_set_sol2(self, s):
        s = sorted(s)
        temp = []
        self.helper(temp, s, 0)
        return self.res

    def helper(self, tempList, numbers, start):
        self.res.append(tempList)
        for i in range(start, len(numbers)):
            self.helper(tempList + [numbers[i]], numbers, i + 1)

def main():
    # Test 1: Should return {{}, {1}, {2}, {3}, {1, 2}, {1, 3}, {2, 3}, {1, 2, 3}}
    arr = [1, 2, 3]
    sol = Solution()
    print(sol.power_set_sol2(arr))

main()