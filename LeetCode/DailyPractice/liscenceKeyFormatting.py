"""
You are given a license key represented as a string S which consists only alphanumeric character and dashes.
The string is separated into N+1 groups by N dashes.

Given a number K, we would want to reformat the strings such that each group contains exactly K characters,
except for the first group which could be shorter than K, but still must contain at least one character.
Furthermore, there must be a dash inserted between two groups and all lowercase letters should be converted to uppercase.

Given a non-empty string S and a number K, format the string according to the rules described above.
"""

def liscenceKeyFormatting(S, K):
    # Join all of the strings together, omitting the "-"
    joined_string = ""
    split_strings = S.split("-")
    for split_string in split_strings:
        joined_string += split_string

    result = ""

    # Looping through the combined strings and appending the last K characters together for result
    count = 0
    for char in range(len(joined_string) -1, -1, -1):
        if count == K:
            result += "-"
            count = 0
        
        result += joined_string[char].upper()
        count += 1

    return result[::-1]

def main():


    # Test 1: Should return "5F3Z-2E9W"

    # S = "5F3Z-2e-9-w"
    # K = 4

    # Test 2: Should return "2-5G-3J"
    S = "2-5g-3-J"
    K = 2


    print(liscenceKeyFormatting(S, K))



main()