"""
You have N bulbs in a row numbered from 1 to N. Initially, all the bulbs are turned off.
We turn on exactly one bulb everyday until all bulbs are on after N days.

You are given an array bulbs of length N where bulbs[i] = x means that on the (i+1)th day,
we will turn on the bulb at position x where i is 0-indexed and x is 1-indexed.

Given an integer K, find out the minimum day number such that there exists two turned on bulbs
that have exactly K bulbs between them that are all turned off.

If there isn't such day, return -1.

Input: 
bulbs: [1,3,2]
K: 1
Output: 2
Explanation:
On the first day: bulbs[0] = 1, first bulb is turned on: [1,0,0]
On the second day: bulbs[1] = 3, third bulb is turned on: [1,0,1]
On the third day: bulbs[2] = 2, second bulb is turned on: [1,1,1]
We return 2 because on the second day, there were two on bulbs with one off bulb between them.

Input: 
bulbs: [1,2,3]
K: 1
Output: -1
"""

def kEmptySlots(bulbs, K):
    # Memory matrix for the bulbs, add a 0 on the beginning since it is 1-indexed
    memory = [0] + [0] * len(bulbs)

    # Loop through each bulb and then continuously check if there exists K unlit bulbs in between at any given day
    for i in range(len(bulbs)):
        memory[bulbs[i]] = 1
        isKBulbs = checkKBulbs(memory, K)

        if isKBulbs:
            return i + 1

    # Reaching here means, we did not find any possible day
    return -1

def checkKBulbs(memory, K):
    count = 0
    # Getting rid of 0s before and after the first one
    for i in range(1,len(memory)):
        if memory[i] == 0:
            memory.pop(i)
            print(memory)
            i -= 2
        else:
            break

    for j in range(len(memory) - 1, 0, -1):
        if (memory[j] == 0):
            memory = memory[:j]
            j -= 1
        else:
            break

    # Skipping the 0-index since it is 1-indexed
    for bulb in range(1, len(memory)):
        if memory[bulb] == 1:
            count = 0
        else:
            count += 1

        if count == K:
            return True

    return False


from collections import deque

class MinQueue(deque):
    def __init__(self):
        deque.__init__(self)
        self.mins = deque()

    def append(self, x):
        deque.append(self, x)
        while self.mins and x < self.mins[-1]:
            self.mins.pop()
        self.mins.append(x)

    def popleft(self):
        x = deque.popleft(self)
        if self.mins[0] == x:
            self.mins.popleft()
        return x

    def min(self):
        return self.mins[0]

def kEmptySlotsSol2(flowers, k):
    days = [0] * len(flowers)
    for day, position in enumerate(flowers, 1):
        days[position - 1] = day

    window = MinQueue()
    ans = len(days)

    for i, day in enumerate(days):
        window.append(day)
        if k <= i < len(days) - 1:
            window.popleft()
            if k == 0 or days[i-k] < window.min() > days[i+1]:
                ans = min(ans, max(days[i-k], days[i+1]))

    return ans if ans < len(days) else -1


def kEmptySlotsSol3(flowers, k):
    days = [0] * len(flowers)
    for day, position in enumerate(flowers, 1):
        days[position - 1] = day

    ans = float('inf')
    left, right = 0, k+1
    while right < len(days):
        for i in range(left + 1, right):
            if days[i] < days[left] or days[i] < days[right]:
                left, right = i, i+k+1
                break
        else:
            ans = min(ans, max(days[left], days[right]))
            left, right = right, right+k+1

    return ans if ans < float('inf') else -1

def main():

    # Test 1: Should return 2

    # bulbs = [1, 3, 2]
    # K = 1

    # Test 2: Should return 8
    bulbs = [6,5,8,9,7,1,10,2,3,4]
    K = 2


    print(kEmptySlotsSol2(bulbs, K))


main()