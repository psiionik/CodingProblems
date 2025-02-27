def minSteps(n):
    """
    :type n: int
    :rtype: int
    """
    if(n==1):
        return 2
    if(n==0):
        return 0

    resWant = ['a']*n
    stringsofar = 'a'
    steps = 2
    sofar = []
    x = calculate(n, stringsofar, steps, sofar)
    return x

def calculate(resWant, stringsofar, steps, sofar):
    # if(len(resWant) == len(stringsofar)):
    #     return steps

    sofar.append(1)
    sofar.append(2)
    current = 1
    copy = 0
    while(resWant != sofar[-1]):
        if(resWant % sofar[current] == 0):
            sofar.append(sofar[current] + sofar[current])
            steps += 2
            copy = current
            current+=1
        else:
            sofar.append(sofar[copy] + sofar[current])
            steps +=1
            current+=1
    return steps

    



def main():
    k = 5
    x = minSteps(k)
    print(x)

main()