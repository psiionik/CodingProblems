def countSubstrings(s):
    if(len(s) == 0):
        return 0
    if(len(s) == 1):
        return 1
    dic = {}
    counter = 0
    for i in range(0,len(s)):
        if(s[i] not in dic):
            dic[s[i]] = 1
        else:
            dic[s[i]] += 1
        for j in range(i + 1, len(s)):
            if (s[i:j+1] not in dic):
                dic[s[i:j+1]] = 1
            else:
                dic[s[i:j+1]] += 1
    
    for k, v in dic.items():
        if(k== k[::-1]):
            counter += v

    return counter




def main():
    s = "abbba"
    x = countSubstrings(s)
    print(x)



main()