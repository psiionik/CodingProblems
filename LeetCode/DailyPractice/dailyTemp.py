class Node:
    def __init__(self,value, index):
        self.value = value
        self.index = index

def dailyTemperatures(temperatures):
    # This is the BruteForce solution
    #
    # edge = [0]
    # result = [0]*len(temperatures)
    # if (temperatures == None):
    #     return None
    # if (len(temperatures) == 1):
    #     return edge
        
    # for i in range(0, len(temperatures)):
    #     for j in range(i, len(temperatures)):
    #         if (temperatures[i] < temperatures[j]):
    #             result[i] = j-i
    #             break
                
    # return result

    edge =[0]
    result = [0]*len(temperatures)
    stack = []
    # dic = {}
    if(temperatures == None):
        return None
    if (len(temperatures) == 1):
        return edge

    for i in range(len(temperatures) -1, -1, -1):
        while( stack and temperatures[stack[-1]] <= temperatures[i]):
            stack.pop()
        if not stack:
            stack.append(i)
        else:
            result[i] = stack[-1] - i
            stack.append(i)
    return result


    
    # for i in range(0, len(temperatures)):
    #     nod = Node(temperatures[i], i)
    #     dic[i] = nod    

    # # for k, v in dic.items():
    # #     print(k)
    # #     print(v.value)
    # #     print("next")
    # for i in range(0, len(temperatures)):
    #     if(sortedList[i] < dic[i].value and i < dic[i].index):
    #         result[i] = dic[i].index - i

    # print(sortedList)
    # print(temperatures)



def main():
    ar = [73, 74, 75, 71, 69, 72, 76, 73]
    print(dailyTemperatures(ar))



main()