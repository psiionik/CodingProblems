"""
Given a string s and a list of words words, where each word is the same length, find all starting indices of substrings in s that is a concatenation of every word in words exactly once.

For example, given s = "dogcatcatcodecatdog" and words = ["cat", "dog"], return [0, 13], since "dogcat" starts at index 0 and "catdog" starts at index 13.

Given s = "barfoobazbitbyte" and words = ["dog", "cat"], return [] since there are no substrings composed of "dog" and "cat" in s.

The order of the indices does not matter.
"""
from collections import Counter
def findSubstringIndices(s, words):
    result = []
    dic = {}
    for word in words:
        dic[word] = list(find_all(s, word))

    print(dic)

def find_all(a_str, sub):
    start = 0
    while True:
        start = a_str.find(sub, start)
        if start == -1: return
        yield start
        start += len(sub)

def solution(s, words):
    if not words:
        return []

    k = len(words[0])
    result = []

    for i in range(k):
        print("NEW ITERATION")
        dic = Counter(words)
        for j in range(i + k, len(s) + 1, k):
            word = s[j - k: j]
            dic[word] -= 1
            while dic[word] < 0:
                dic[s[i:i + k]] += 1
                i += k

            if i + k * len(words) == j:
                result.append(i)

    return result

def main():

    # Test 1: Should return [0, 13]

    s = "dogcatcatcodecatdog"
    words = ["cat", "dog"]

    # Test 2: Should return []

    #s = "barfoobazbitbyte"
    #words = ["dog", "cat"]

    # Test 3: Should return [0, 16]

    #s = "dogcatfoocatcodecatfoodog"
    
    #words = ["dog", "cat", "foo"]

    #print(findSubstringIndices(s, words))

    print(solution(s, words))


main()
