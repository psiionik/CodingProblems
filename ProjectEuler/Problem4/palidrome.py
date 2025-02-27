import math


def is_palindrome_v1(prod):
    str_prod = str(prod)
    if (str_prod == str_prod[::-1]):
        return True
    else:
        return False

def is_palindrome_v2(number):
    reversednumber = 0
    copynum = number

    while(copynum > 0):
        reversednumber = reversednumber * 10 + copynum % 10
        copynum = math.floor(copynum / 10)

    return reversednumber == number or number == math.floor(copynum / 10)

def v0():
    res = 0
    for i in range(100, 999):
        for j in range(100, 999):
            prod = i * j
            if (prod > res and is_palindrome_v1(prod)):
                res = prod

    return res

def v1():
    res = 0
    for i in range(990, 99, -11):
        for j in range(999, 99, -1):
            prod = i * j

            if (prod > res and is_palindrome_v1(prod)):
                res = prod
                break
            elif (res > prod):
                break
    
    return res

import time

if __name__ == "__main__":
    start_time_v0 = time.perf_counter()
    res_v0 = v0()
    end_time_v0 = time.perf_counter()

    print("The largest palindrome is: " + str(res_v0) + " with an elapsed time of: " + str(end_time_v0 - start_time_v0) + " seconds for v0.")

    start_time_v1 = time.perf_counter()
    res_v1 = v1()
    end_time_v1 = time.perf_counter()

    print("The largest palindrome is: " + str(res_v1) + " with an elapsed time of: " + str(end_time_v1 - start_time_v1) + " seconds for v1.")

