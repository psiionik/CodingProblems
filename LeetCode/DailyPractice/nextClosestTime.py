"""
Given a time represented in the format "HH:MM", form the next closest time by reusing the current digits.
There is no limit on how many times a digit can be reused.

You may assume the given input string is always valid. For example, "01:34", "12:09" are all valid.
"1:34", "12:9" are all invalid.

Input: "19:34"
Output: "19:39"
Explanation: The next closest time choosing from digits 1, 9, 3, 4, is 19:39, which occurs 5 minutes later.
It is not 19:33, because this occurs 23 hours and 59 minutes later.

Input: "23:59"
Output: "22:22"
Explanation: The next closest time choosing from digits 2, 3, 5, 9, is 22:22.
It may be assumed that the returned time is next day's time since it is smaller than the input time numerically.
"""

import itertools

def nextClosestTime(time):
    ans = start = 60 * int(time[:2]) + int(time[3:])
    elapsed = 24 * 60
    allowed = {int(x) for x in time if x != ':'}
    for h1, h2, m1, m2 in itertools.product(allowed, repeat = 4):
        hours, mins = 10 * h1 + h2, 10 * m1 + m2
        if hours < 24 and mins < 60:
            cur = hours * 60 + mins
            cand_elapsed = (cur - start) % (24 * 60)
            if 0 < cand_elapsed < elapsed:
                ans = cur
                elapsed = cand_elapsed

    return "{:02d}:{:02d}".format(*divmod(ans, 60))

def nextClosestTimeSol2(time):
    cand = sorted(set(time.replace(":", "")))
    res = list(time)
    
    res[4] = findNext(res[4], "9", cand)
    if res[4] > time[4]: return "".join(res)
    
    res[3] = findNext(res[3], "5", cand)
    if res[3] > time[3]: return "".join(res)
    
    res[1] = findNext(res[1], "4" if res[0] == "2" else "9", cand)
    if res[1] > time[1]: return "".join(res)
    
    res[0] = findNext(res[0], "2", cand)
    return "".join(res)
        
        
def findNext(cur, limit, cand):
    i = cand.index(cur)
    if i+1 < len(cand) and cand[i+1] <= limit:
        return cand[i+1]
    return cand[0]

def main():

    # Test 1: Should return "19:39"

    time = "19:34"


    print(nextClosestTimeSol2(time))

main()