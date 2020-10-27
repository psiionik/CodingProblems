import math

def repeatedStringMatch(A, B):
    if(len(A) == 0 or len(B) == 0):
        return -1
    maxratio = math.ceil(len(B)/len(A)) + 1
    if(B in A*maxratio):
        return maxratio
    if(B in A*(maxratio + 1)):
        return maxratio + 1
    return -1

def main():
    A = "abcd"
    B = "cdabcdab"
    x = repeatedStringMatch(A,B)
    print(x)

main()