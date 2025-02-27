"""
Given a stream of elements too large to store in memory, pick a random element from the stream with uniform probability.
"""

"""
Naive Solution, process the stream and store all the elements in a list, find the size, and then pick a random element from [0, size - 1].
This would be a problem if each piece of data is large however since this is O(N) for a large N.
"""

"""
Solution 1, loop invariants. On the ith iteration of the loop to pick a random element, let's assume we already picked an element
uniformly from  [0, i-1], in order to maintain the loop invariant, need to pick the ith element as the new random element at 
1 / (i + 1) chance. Uses a technique called Reservoir Sampling.
"""

import random

def random_stream_picker_sol1(big_stream):
    random_element = None

    for i, e in enumerate(big_stream):
        if(random.randint(1, i + 1) == 1):
            random_element = e

    return random_element

def main():
    big_st = [12, 4, 5]
    print(random_stream_picker_sol1(big_st))


main()