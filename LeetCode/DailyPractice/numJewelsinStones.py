def numJewelsInStones(J, S):
    """
    :type J: str
    :type S: str
    :rtype: int
    """
    resulting_dict = {}

    if (J == "" or S == ""):
        return 0

    for i in J:
        resulting_dict[i] = 0
    
    resultsum = 0
    
    for i in S:
        if (i in resulting_dict):
            resultsum += 1
    return resultsum

def main():
    J = "acD"
    S = "bdDcbbza"
    x = numJewelsInStones(J, S)
    print(x)


main()