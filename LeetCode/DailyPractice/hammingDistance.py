def hammingDistance(x, y):
    # comparator = max(x,y)
    # inc = 1
    # numberofbits = 0
    # while(inc <= comparator):
    #     inc*=2
    #     numberofbits += 1

    # binaryx = format(x, '0'+str(numberofbits)+'b')
    # binaryy = format(y, '0'+str(numberofbits)+'b')
    # result = 0
    # for i in range(0, len(binaryx)):
    #     if(binaryx[i] != binaryy[i]):
    #         result+=1

    # return result
    counter = 0
    xorval = x^y
    while(xorval > 0):
        lastbit = xorval & 1
        if(lastbit == 1):
            counter += 1
        xorval = xorval >> 1

    return counter

def main():
    x = 1
    y = 128
    print(hammingDistance(x,y))

main()