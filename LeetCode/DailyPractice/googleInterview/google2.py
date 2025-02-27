# you can write to stdout for debugging purposes, e.g.
# print("this is a debug message")
import sys

def solution(stores, houses):
    # write your code in Python 3.6
    
    len1 = len(stores)
    len2 = len(houses)
    if(len1 == 0):
        return houses
    if(len2 == 0):
        return stores
    minilen = min(len1, len2)
    maxlen = max(len1, len2)
    result = [-1]*min(len1, len2)
    diff = sys.maxsize
    for i in range(minilen):
        diff = sys.maxsize
        for j in range(0, maxlen):
            if(len1 < len2):
                if(diff > abs(stores[i] - houses[j])):
                    diff = abs(stores[i] - houses[j])

            else:
                if(diff > abs(houses[i] - stores[j])):
                    diff = abs(houses[i] - stores[j])
        for k in range(0, maxlen):
            if(len1 < len2):
                if(diff == abs(stores[i] - houses[k])):
                    result[i] = houses[k]
            else:
                if(diff == abs(houses[i] - stores[k])):
                    result[i] = stores[k]
    return result




def main():
    a = [1, 5, 20, 11, 16]
    b = [5, 10, 17]
    x = solution(a, b)
    print(x)


main()