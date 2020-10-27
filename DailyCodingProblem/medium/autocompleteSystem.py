"""
Implement an autocomplete system
Given a query string s and a set of all possible query strings, return all strings in in the set that has s as a prefix

For example, given the query string de and the set of strings [dog, deer, deal], return [deer, deal].

Hint: Try preprocessing the dictionary into a more efficient data structure to speed up queries.
"""


# Solution 1, loop through all of the words and check if the string starts with the prefix
# This will take O(n*m) time where n is the length of the list and m is the length of the prefix

# Solution 2, preprocess the dictionary in one pass then check if the strings are prefixed with the query string.
# For example, make [dog, deer, deal] in to [do, de, de] or the same length as the query string.
# After this, its just simple to just check if the each string in the dictionary equals the prefix string
# Time complexity would then be O(n)
# Creates extra space so space complexity is O(n)

def find_all_prefixes_solution_2(dictionary, prefix_string):
    # preprocess to make each string in dictionary the same length as prefix string
    temp_dictionary = [0]*len(dictionary)
    for i in range(0, len(temp_dictionary)):
        if (len(dictionary[i]) != len(prefix_string)):
            temp_dictionary[i] = dictionary[i][:len(prefix_string)]
    
    # loop through the dictionary list to find which strings equal the prefix string and append the index
    result_list = []
    for word_index in range(0, len(dictionary)):
        if temp_dictionary[word_index] == prefix_string:
            result_list.append(dictionary[word_index])
    
    return result_list

# Solution 3, pre-sort the list and then use a tree where each child of a node represents one character of the alphabet
# For example let's say we had the words 'a' and 'dog' in our dictionary. Then the tree would look like this:
#   x
#  / \
# a   d
#      \
#       o
#        \
#         g
#
# Then to find all the words beginning with 'do' start at the root, go to 'd' child, and then 'o' child and gather up
# all the words under there 
# Have some terminal mark to mark whether or not 'do' is actually a word in the dictionary or not
# This data structure is known as a trie
#
# Preprocess the dictionary into this tree, and then when we search for a prefix, go into the trie and get all the words under
# that prefix node and return those
# Runtime: O(n) if all the search results have that prefix, if the words are uniformly distribute across the alphabet, it should
# be much more faster on average

ENDS_HERE = '__ENDS_HERE'

class Trie:
    def __init__(self):
        self._trie = {}
    
    def insert(self, text):
        trie = self._trie
        for char in text:
            if char not in trie:
                trie[char] = {}
            trie = trie[char]
        trie[ENDS_HERE] = True
    
    def elements(self, prefix):
        d = self._trie
        print(d)
        for char in prefix:
            if char in d:
                d = d[char]
            else:
                return []
        return self._elements(d)

    def _elements(self, d):
        result = []
        for c, v in d.items():
            if c == ENDS_HERE:
                subresult = ['']
            else:
                subresult = [c + s for s in self._elements(v)]
            result.extend(subresult)
        return result

def autocomplete(s, trie):
    suffixes = trie.elements(s)
    return [s + w for w in suffixes]

def main():
    words = ['dog', 'deer', 'deal']
    trie = Trie()
    for word in words:
        trie.insert(word)
    
    print(autocomplete('d', trie))


main()