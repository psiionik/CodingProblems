"""
You have a set of tiles, where each tile has one letter tiles[i] printed on it.
Return the number of possible non-empty sequences of letters you can make.
"""
def numTilePossibilities(tiles):
    res = set()
    def dfs(path, t):
        if path:
            res.add(path)
        for i in range(len(t)):
            dfs(path+t[i], t[:i] + t[i+1:])
                
    dfs('', tiles)
    return len(res)


def main():

    # Test 1: Should return 8
    # tiles = "AAB"
    
    # Test 2: Should return 188
    tiles = "AAABBC"

    print(numTilePossibilities(tiles))
    
main()