#
# Complete the 'playlist' function below.
#
# The function is expected to return a LONG_INTEGER.
# The function accepts INTEGER_ARRAY songs as parameter.
#

def playlist(songs):
    # Write your code here

    # Brute force method
    # counter = 0
    # for i in range(0, len(songs)):
    #     for j in range(i, len(songs)):
    #         if(i == j):
    #             continue
    #         if((songs[i] + songs[j]) % 60 == 0):
    #             counter += 1

    # return counter

    # Optimized with Dictionary O(n) space
    dic = {}
    counter = 0 
    # Storing the objects as keys and the value needed to the nearest multiple of 60
    for i in songs:
        dic[i] = ((int(i/60) + 1)*60) - i
    
    keylist = list(dic.keys())
    valuelist = list(dic.values())
    for k,v in dic.items():
        if (k in keylist and v in valuelist):
            del dic[k]
        
    for k,v in dic.items():
        if(k == v):
            continue
        if (v in songs):
            counter+=1
        
    
    for k, v in dic.items():
        print(k)
        print("++++++++++++")
        print(v)
        print("____________")

    return counter

def main():
    x= [5,30,20,150,100,40]
    y = playlist(x)
    print(y)

main()