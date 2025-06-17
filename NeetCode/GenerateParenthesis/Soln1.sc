/* 
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

 

Example 1:

Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]
Example 2:

Input: n = 1
Output: ["()"]
 

Constraints:

1 <= n <= 8

 */

object Solution1 {
    def generateParenthesis(n: Int): List[String] = {
        var res = List[String]()
        def dfs(n: Int, acc: String, left_count: Int, right_count: Int): Unit = {
            if right_count > left_count || left_count > n
            then
                return

            if left_count == n && right_count == n
            then
                res = acc :: res
                return

            dfs(n, acc + "(", left_count + 1, right_count)
            dfs(n, acc + ")", left_count, right_count + 1)

        }
        dfs(n, "", 0, 0)
        res
    }
}