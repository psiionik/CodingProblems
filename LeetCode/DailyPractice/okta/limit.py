
# importing a module for regular expressions
import re

# Class for keeping the client information, will be used in the final array with string method
class Client:
    def __init__(self, name):
        self.clientName = name
        self.requests = 0
        self.blackListed = False
        self.amt = 0
        self.counter = 0
        self.fivecount = 0

    def __str__(self):
        x = self.clientName + " " + str(self.requests)
        return x

def solution(A, Y):


    # Dictionary to hold all of the clients and eventually be used to increase the requests
    # Idea is to use constant time lookup so I don't need to iterate through 2 for loops
    res = {}

    # edge cases
    if (len(A) == 0):
        return A
    
    #Trying to create different Clients based on the amount of clients in the input
    keyCount = 0
    for i in A:
        ifIn = False
        match = re.match(r'(.*)(.*?) .*', i)
        newClient = Client(match.group(1))
        if(len(res) == 0):
            res[0]= newClient
            keyCount += 1
        else:
            for k, v in res.items():
                if (v.clientName== match.group(1)):
                    ifIn = True
                    break
            if(ifIn == False):
                res[keyCount] = newClient
                keyCount += 1

    # At this point res has all possible clients as a Client class and now we need to go through the list
    # for the blacklisting

    # First there has to be some way to check the blacklisting beforehand due to the constraints
    # This works by going through the whole list and since we know that when in 5 mins if requests = 10, some client is being 
    # black listed. This counts every 5 time stamps to see whether the sum of the clients exceeds 10, and if it does, it appends
    # a counter to the end of the list to subtract from the requests in finding the requests per client


    blacklistingnum = [0]*len(res)
    subtractnum = [0]*len(res)
    keyContainer = 0
    timestamp = 0
    clientHolder = res[0].clientName
    totalCount = 0
    fivemincounter = 0
    prev = 0
    amt = 0
    next5 = 0
    prev5 = 0
    wait= 0

    for i in A:
        match = re.match(r'(.*)(.*?) (.*)', i)
        if(clientHolder != match.group(1)):
            clientHolder = match.group(1)
            timestamp = 0
            keyContainer += 1
            fivemincounter = 0

        rollover = int(int(match.group(3)) / 60)
        if(rollover >5 and rollover % 5 == 0):
            next5 += 1
        if(rollover != prev):
            if (fivemincounter % 5 == 0 and next5 != prev5):
                prev5 = next5
                blacklistingnum[keyContainer] = 0
                fivemincounter = 0
                totalCount = 0
            amt = 0
            fivemincounter +=1
            wait += 1

        if (amt < Y):
            amt += 1
            blacklistingnum[keyContainer] += 1

        if(sum(blacklistingnum) > 10 and wait < 2):
            tem = max(blacklistingnum)
            ind = blacklistingnum.index(tem)
            subtractnum[ind] += 1
        
        if (wait >= 2):
            wait = 0
        prev = int(int(match.group(3)) / 60)
    

    # Use mod 60 to be able to distiguish between minutes
    # Use regular expressions to match the strings of the clients in the list and update their requests field accordingly
    # in the resulting list
    
    timestamp = 0
    clientHolder = res[0].clientName
    keyContainer = 0
    
    # For keeping track of the blacklisting, totalCount will keep track of the total amount of requests for all clients

    # fivemincounter counts the last 5 minutes
    # !!! Blocked requests do not count towards the total count of requests

    totalCount = 0

    fivemincounter = 0
    prev = 0
    for i in A:
        match = re.match(r'(.*)(.*?) (.*)', i)

        # Can do this method because the input list is sorted
        if(clientHolder != match.group(1)):
            clientHolder = match.group(1)
            timestamp = 0

            keyContainer += 1

        rollover = int(int(match.group(3)) / 60)
        if(rollover != prev):
            if(res[keyContainer].blackListed == True):
                res[keyContainer].counter +=1
            fivemincounter +=1
            timestamp += 1
            res[keyContainer].amt = 0

        if (fivemincounter == 5):
            totalCount = 0
            res[keyContainer].fivecount = 0

        if(((res[keyContainer].amt /2) > (totalCount/2)) and totalCount > 10):
            res[keyContainer].blackListed = True

        if(res[keyContainer].blackListed == False):
            if(res[keyContainer].amt < Y):
                totalCount += 1
                res[keyContainer].amt += 1
                res[keyContainer].requests += 1
        
        if(res[keyContainer].counter == 2):
            res[keyContainer].blackListed = False
            res[keyContainer].counter = 0
        
        prev = int(int(match.group(3)) / 60)

    resulting = []
    for k,v in res.items():
        v.requests -= subtractnum[k]
        resulting.append(str(v))
    return resulting
        












def main():
    x= ['client1 0', 'client1 15', 'client1 30', 'client1 45', 'client1 60', 'client1 75', 'client1 90', 'client1 120', 'client1 180', 'client1 240', 'client2 0', 'client2 60', 'client2 120', 'client2 180', 'client2 240', 'client2 320']
    t2 = ['java 0', 'java 15', 'java 59', 'java 60', 'java 120', 'java 240', 'python 0', 'python 15', 'python 45', 'python 125']
    y = 3
    # print(*x, sep ="\n")
    k = solution(t2, y)
    print(k)

main()