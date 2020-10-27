import math

def smallestMultipleV1():
    for i in range(2521, 10000000000000):
        theNum = True
        for num in range(20, 1, -1):
            if (i % num != 0):
                theNum = False
                break
        
        if (theNum == True):
            return i

def smallestMultipleV2():
    for i in range(2520, 10000000000000000000, 20):
        theNum = True
        for num in range(20, 1, -1):
            if (i % num != 0):
                theNum = False
                break
        
        if (theNum == True):
            return i

def smallestMultipleV3():

    def generatePrimes(n):
        primes = []

        primes.append(2)

        for i in range(3, n+1, 2):
            j = 0
            isPrime = True
            while(primes[j]*primes[j] <= i):
                if(i % primes[j] == 0):
                    isPrime = False
                    break
                j += 1
            
            if(isPrime):
                primes.append(i)

        return primes

    primeList = generatePrimes(20)

    result = 1

    for i in range(0, len(primeList)):
        a = math.floor(math.log10(20) / math.log10(primeList[i]))
        result = result * int(math.pow(primeList[i], a))

    return result

if __name__ == "__main__":
    print(smallestMultipleV3())