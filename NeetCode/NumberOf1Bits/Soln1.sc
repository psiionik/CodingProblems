/* 
Given a positive integer n, write a function that returns the number of set bits in its
binary representation (also known as the Hamming weight).

Example 1:

Input: n = 11

Output: 3

Explanation:

The input binary string 1011 has a total of three set bits.

Example 2:

Input: n = 128

Output: 1

Explanation:

The input binary string 10000000 has a total of one set bit.

Example 3:

Input: n = 2147483645

Output: 30

Explanation:

The input binary string 1111111111111111111111111111101 has a total of thirty set bits.

Constraints:

1 <= n <= 231 - 1
 

Follow up: If this function is called many times, how would you optimize it?
 */

object Solution1 {
    def hammingWeight(n: Int): Int = {
        def recurse(num: Int): Int = {
            num match {
                case 0 => 0
                case _ => (num % 2) + recurse(num / 2)
            }
        }

        recurse(n)
    }

    def hammingWeightOpt(n: Int): Int = {
        var num_of_1s = 0
        var num = n

        while (num != 0) {
            num_of_1s += 1
            num &= (num - 1)
        }

        num_of_1s
    }
}