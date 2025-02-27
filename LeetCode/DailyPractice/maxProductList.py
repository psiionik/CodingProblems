class Node:
    def __init__(self, val):
        self.val = val
        self.factors = []


def integerBreak( n):
    """
    :type n: int
    :rtype: int
    """
    result = [0]*(n + 1)
    indexList = []
    
    if (n == 0):
        return 0
    if(n == 1):
        return 1
    if (n==2):
        return 1
    
    for i in range(0,n +1):
        indexList.append(i)
    result[0] = Node(0)
    result[1] = Node(1)
    result[2] = Node(1)
    result[2].factors.append(1)
    result[2].factors.append(1)
    
    for j in indexList:
        if(j == 0 or j == 1 or j == 2):
            continue
        val = 0
        ind = 0
       
        for k in range(0,len(result[j-1].factors)):
            temp = result[j-1].factors[k] + 1
            prod = 1
            for l in result[j-1].factors:
                prod *= l
            prod /= result[j-1].factors[k]
            prod *= temp
            if(val < prod):
                val = prod
                ind = k
       
        result[j] = Node(val)
        result[j].factors = result[j-1].factors
        result[j].factors[ind] +=1
        if(result[j].factors[ind] == 4):
            result[j].factors[ind] -=2
            result[j].factors.append(2)
    return result[-1].val

def main():
    s = 10
    x = integerBreak(s)
    print(x)
main()