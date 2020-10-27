"""
Given an integer k and a string s, find the length of the longest substring that contains at most k distinct characters.

For example, given s = 'abcba' and k = 2, the longest substring with k distinct characters is "bcb". 
"""

"""
Solution 1, Keep a running window of the longest substring. Keep a dictionary that maps characters to the index of their last
occurence. As we iterate over the string, check the size of the dictionary. If it is larger than k, that means the window is 
too big, so we have to pop the smallest item in the dictionary and recompute bounds. If we add a character to the dictionary
and it doesn't go over k, then we are safe. The dictionary hasn't been filled yet or it is a character we've seen before.
This is O(n*k) time and O(k) space.
"""

def find_kth_longest_substring_sol_1(s, k):
    if k == 0:
        return 0

    bounds = (0,0)
    h = {}
    max_length = 0

    for i, char in enumerate(s):
        h[char] = i
        if (len(h) <= k):
            new_lower_bound = bounds[0]
        else:
            key_to_pop = min(h, key=h.get)
            new_lower_bound = h.pop(key_to_pop) + 1

        bounds = (new_lower_bound, bounds[1] + 1)
        max_length = max(max_length, bounds[1] - bounds[0])
    
    return max_length


def main():
    """
    Test 1: Should return 3
    """

    s = "abcbabbca"
    k = 2

    print(find_kth_longest_substring_sol_1(s, k))

main()