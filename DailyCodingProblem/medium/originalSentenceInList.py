"""
Given a dictionary of words and a string made up of those words (no spaces), return the original sentence in a list. If there is
more than one possible reconstruction, return any of them. If there is no possible reconstruction, return null.

For example, given the set of words 'quick', 'brown', 'the', 'fox', and the string "thequickbrownfox", you
should return ['the', 'quick', 'brown', 'fox'].

Given the set of words 'bed', 'bath', 'bedbath', 'and', 'beyond', and the string "bedbathandbeyond", return
either ['bed', 'bath', 'and', 'beyond] or ['bedbath', 'and', 'beyond'].

'brown', 'red', 'river' string: 'riverredbrown'
"""

"""
Solution 1, Use backtracking, split up the string by prefix and suffix, we can return the prefix extended with a list of the rest
of the sentence but only if they are both valid.
Do the following:

1. Iterate over the string and split it by prefix and suffix
2. If the prefix is valid (appears in the dictionary) then recursively call on the suffix
3. If that is valid, return. Otherwise, continue searching
4. If we've gone over the entire sentence and haven't found anything, then return empty

Use dynamic programming to store repeated subcomputations. Keep a dictionary that maps from indices to the last word that can be
made up to that index, called starts. Do two nested for loops, one that iterates over the whole string and tries to find a start
at that index, and a loop that checks each start to see if a new word can be made from that start to the current index.

Then take the start at the last index and then build the sentence backwards.

Runtime is O(n^2) and space is O(n)
"""

def original_sentence_in_list_sol1(words, s):
    starts = {0: ''}
    for i in range(len(s) + 1):
        new_starts  = starts.copy()
        for start_index, _ in starts.items():
            word = s[start_index:i]
            if word in words:
                new_starts[i] = word
        starts = new_starts.copy()
    
    result = []
    current_length = len(s)
    if current_length not in starts:
        return None
    while (current_length > 0):
        word = starts[current_length]
        current_length -= len(word)
        result.append(word)
    
    return list(reversed(result))

def main():
    """
    Test 1: Should retrun ['the', 'quick', 'brown', 'fox']
    """

    words = ['quick', 'brown', 'the', 'fox']
    s = 'thequickbrownfox'

    print(original_sentence_in_list_sol1(words, s))

main()