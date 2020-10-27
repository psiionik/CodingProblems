
def longestPalindromeSubseq(s):
    if(s == s[::-1]):
        return len(s)

    n = [[ 0 for j in range(len(s))] for i in range(len(s))]

    # for i in range(len(s)):
    #     n[i][i] = 1
    
    for i in range(len(s)-1, -1, -1):
        n[i][i] = 1
        for j in range(i+1, len(s)):
            if(s[i] == s[j]):
                n[i][j] = n[i+1][j-1] + 2
            else:
                n[i][j] = max(n[i+1][j],n[i][j-1])
        print('\n'.join([''.join(['{:4}'.format(item) for item in row]) 
      for row in n]))
        print('\n')
    return n[0][-1]



def main():

    s = "cbbd"
    x = longestPalindromeSubseq(s)
    print(x)



main()