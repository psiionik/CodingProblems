import $file.Soln1, Soln1.Solution1
import $file.Soln1, Soln1.Solution1.WordDictionary

def testCase1(): Unit = {
    val word_dictionary = new WordDictionary()
    word_dictionary.addWord("bad")
    word_dictionary.addWord("dad")
    word_dictionary.addWord("mad")
    println(word_dictionary.search("pad"))
    println(word_dictionary.search("bad"))
    println(word_dictionary.search(".ad"))
    println(word_dictionary.search("b.."))
}

def runTestCases(): Unit = {
    testCase1()
}

@main def mainSol1() = {
    runTestCases()
}


