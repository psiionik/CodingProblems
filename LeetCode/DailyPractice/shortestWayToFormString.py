"""
From any string, we can form a subsequence of that string by deleting some number of characters (possibly no deletions).

Given two strings source and target, return the minimum number of subsequences of source such
that their concatenation equals target. If the task is impossible, return -1.
"""


def shortest_way(source, target):
    
    target_list = list(target)
    mapping = {}
    mapping_count = 1
    for i in source:
        mapping[i] = mapping_count
        mapping_count += 1

    for i in range(0, len(target_list)):
        if (target_list[i] not in mapping):
            return -1
        num_to_replace = mapping[target_list[i]]
        target_list[i] = num_to_replace
    
    minimum_subsequence = 1
    current_val = target_list[0]
    counter = 0
    for i in range(1, len(target_list)):
        if(counter > len(source)):
            minimum_subsequence+=1
            counter = 0
        if(target_list[i] >= current_val):
            current_val = target_list[i]
            counter += 1
        else:
            minimum_subsequence += 1
            current_val = target_list[i]
            counter = 0
    
    if (counter > 0):
        minimum_subsequence += 1
    
    return minimum_subsequence

def shortest_way_sol2(source, target):
    index = 0
    count = 0
    for val in target:
        index = source.find(val, index)
        
        if index == -1:
            index = source.find(val, 0)
            if index == -1:
                return -1
            count += 1
        index += 1
        
    return count + 1

def main():

    # Test 1: Should return 3
    # source = "xyz"
    # target = "xzyxz"

    # Test 2: Should return 2
    # source = "abc"
    # target = "abcbc"

    # Test 3: Should return -1
    source = "abc"
    target = "accbc"

    print(shortest_way_sol2(source, target))

main()