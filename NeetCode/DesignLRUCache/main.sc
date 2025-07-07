import $file.Soln1, Soln1.Solution1
import $file.Soln2, Soln2.Solution2

def testCase1(): Unit = {
    val capacity = 2
    val lru_cache = Solution1.LRUCache(capacity)
    lru_cache.put(1, 1)
    lru_cache.put(2, 2)
    println(lru_cache.get(1))
    lru_cache.put(3, 3)
    println(lru_cache.get(2))
    lru_cache.put(4, 4)
    println(lru_cache.get(1))
    println(lru_cache.get(3))
    println(lru_cache.get(4))
}

def testCase2(): Unit = {
    val capacity = 2
    val lru_cache = Solution2.LRUCache(capacity)
    lru_cache.put(1, 1)
    lru_cache.put(2, 2)
    println(lru_cache.get(1))
    lru_cache.put(3, 3)
    println(lru_cache.get(2))
    lru_cache.put(4, 4)
    println(lru_cache.get(1))
    println(lru_cache.get(3))
    println(lru_cache.get(4))
}

def testCase3(): Unit = {
    val capacity = 2
    val lru_cache = Solution2.LRUCache(capacity)
    lru_cache.put(1, 0)
    lru_cache.put(2, 2)
    println(lru_cache.get(1))
    lru_cache.put(3, 3)
    println(lru_cache.get(2))
    lru_cache.put(4, 4)
    println(lru_cache.get(1))
    println(lru_cache.get(3))
    println(lru_cache.get(4))
}

def runTestCases(): Unit = {
    // testCase1()
    // testCase2()
    testCase3()
}

@main def mainSol1() = {
    runTestCases()
}


