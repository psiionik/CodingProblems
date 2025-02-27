def customSortString(S, T):
    """
    :type S: str
    :type T: str
    :rtype: str
    """
    if(S == ""):
        return T
    if(T == ""):
        return ""
    
    result = ""
    dic = {}
    for i in T:
        if (i not in dic):
            dic[i] = 1
        else:
            dic[i] += 1
    
    for j in S:
        if(j in dic):
            result += j*dic[j]
            del dic[j]
    
    for k, v in dic.items():
        result += k*v
        
    return result

def main():
    s= "kqep"
    t = "pekeq"
    k = customSortString(s,t)
    print(k)


main()