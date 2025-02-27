class Node:
    def __init__(self, listKeys, index):
        self.listofkeys = listKeys
        self.index = index
        self.visited = False

def canVisitAllRooms(rooms):
        """
        :type rooms: List[List[int]]
        :rtype: bool
        """
        listOfNodes = []
        for i in range(len(rooms)):
            nod = Node(rooms[i], i)
            listOfNodes.append(nod)
        
        stack = []
        stack.append(listOfNodes[0])
        listOfNodes[0].visited = True
        while(len(stack) != 0):
            v = stack.pop()
            
            for i in v.listofkeys:
                
                if(listOfNodes[i].visited == False):
                    listOfNodes[i].visited = True
                    stack.append(listOfNodes[i])

        for i in listOfNodes:
            
            if (i.visited == False):
                return False
        return True


def main():
    testCase = [[1,3],[3,0,1],[2],[0]]
    print(canVisitAllRooms(testCase))


main()