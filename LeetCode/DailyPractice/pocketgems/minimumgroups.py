
def minimumGroups(predators):
    # Write your code here
    # Create a 2d Adjacency Matrix
    # idea is to have rows be species, columns be predators
    # For each index keep finding all direct and indirect predators and set true in matrix
    # At the end find the number of columns with checks which should be the minimum number of groupings
    counter = 0
    adjmatrix = [[0]*len(predators)]*len(predators)
    for i in range(0,len(predators)):
        for j in range(0,len(predators)):
            if(predators[j] == -1):
                break
            else:
                adjmatrix[i][predators[j]] = 1 # set to true

    # Look through all columnns and if column has 1, then add one to the counter
    for i in range(0, len(predators)):
        if(1 in predators[i]):
            counter +=1
    print(predators)
    return counter   

def main():
    a = [1, -1, 3, -1]
    minimumGroups(a)

main()