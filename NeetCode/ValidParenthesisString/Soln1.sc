/* 
Given a string s containing only three types of characters: '(', ')' and '*', return true if s is valid.

The following rules define a valid string:

- Any left parenthesis '(' must have a corresponding right parenthesis ')'.
- Any right parenthesis ')' must have a corresponding left parenthesis '('.
- Left parenthesis '(' must go before the corresponding right parenthesis ')'.
- '*' could be treated as a single right parenthesis ')' or a single left parenthesis '(' or an empty string "".

Example 1:
Input: s = "()"
Output: true

Example 2:
Input: s = "(*)"
Output: true

Example 3:
Input: s = "(*))"
Output: true

Constraints:
1 <= s.length <= 100
s[i] is '(', ')' or '*'.
 */

import scala.collection.mutable.Stack
import scala.util.boundary, boundary.break

object Solution1 {
    def checkValidStringDP(s: String): Boolean = {
        // Create our bottom-up tabulation memory structure to hold computation states in DP
        // Here the row indexes represent the character we are at in the string
        // The column indexes represent the count of open parenthesis we have so far
        val dp = Array.fill[Array[Boolean]](s.length + 1)(Array.fill[Boolean](s.length + 1)(false))

        // If we have seen all of the characters in the string and the amount of open parenthesis is 0, then it is a valid parenthesis string
        dp(s.length)(0) = true

        // Loop through all of the indexes of the string backward
        for (char_index <- Range(s.length - 1, -1, -1))
        do 
            // Loop through all of the possible numbers of open parenthesis counts
            for (open_paren_count <- 0 until (s.length))
            do 
                var is_valid = false

                // If the current character is a "*", then we try to explore the possibilities when the "*" is a "(", ")", or ""
                if s(char_index) == '*'
                then
                    // When "*" is "(", then we have to look at the previous char index and the open paren count + 1 
                    is_valid |= dp(char_index + 1)(open_paren_count + 1)

                    // When "*" is ")", then we have to loko at the previous char index and open paren count - 1
                    if open_paren_count > 0
                    then
                        is_valid |= dp(char_index + 1)(open_paren_count - 1)
                    
                    // When "*" is "", then we just look at the validity of the previous char index with no change to open paren count
                    is_valid |= dp(char_index + 1)(open_paren_count)
                else
                    // When the current character is "(", then look at the validity of the previous char index and open paren count + 1
                    if s(char_index) == '('
                    then
                        is_valid |= dp(char_index + 1)(open_paren_count + 1)
                    else
                        // When the current character is ")", then look at the validity of the previous char_index and open paren count - 1
                        if open_paren_count > 0
                        then
                            is_valid |= dp(char_index + 1)(open_paren_count - 1)
                
                // Store the result in the dp cell
                dp(char_index)(open_paren_count) = is_valid

        dp(0)(0)
    }

    def checkValidString(s: String): Boolean = {
        var res = true 
        val left_paren_stack = Stack[Int]()
        val star_stack = Stack[Int]()

        // First storing all of the indexes in the left paren / star stack and matching right parens as it loops through
        boundary {
            for (char_index <- 0 until s.length)
            do 
                val char = s(char_index)
                char match
                    case '(' => left_paren_stack.push(char_index)
                    case '*' => star_stack.push(char_index)
                    case ')' => 
                        if !left_paren_stack.isEmpty
                        then
                            left_paren_stack.pop()
                        else if !star_stack.isEmpty
                        then
                            star_stack.pop()
                        else
                            res = false
                            break()
        }

        // At this point we have matched all of the right parens and now want to match existing left parens with stars
        if res == true
        then
            boundary {
                while (!left_paren_stack.isEmpty && !star_stack.isEmpty) {
                    val left_paren_index = left_paren_stack.pop()
                    val star_index = star_stack.pop()

                    if left_paren_index > star_index
                    then
                        res = false
                        break()
                }
            }

        // At this point we should have all of the left parens matched with stars, we just need to check if the left parens stack is still populated
        // This means that either we had a left parenthesis after a star or we ran out of stars to match with
        if res == true 
        then
            res = left_paren_stack.isEmpty

        // We don't care if there are still stars left as they can be turned into ""

        res
    }
}