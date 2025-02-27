# Notes on Maximum Non Adjacent Sum

## Uses Dynamic Programming

## High Level Algorithm

* Keep a secondary array for memoization, the same length as original
* Populate the elements
    * Add the first element by default
    * The other elements can be found with the function:
    
$$ dp[ele]= max \left\{
\begin{array}{ll}
      dp[i - 1] \\
      dp[i - 2] + currentNum[i]
\end{array} 
\right. $$ 

* Last number will have the max subset sum

## Intuition

* Since we build the greatest possible sum at any given index, we can guarentee that when we look back in previous sums, they are the greatest sum
    * Avoids having to look at all of the sums calculated before

## Complexity

### Time

* Run through all of the elements to be able to calculate the maximum possible sum
    * O(n), n is the length of the array

### Space

Solution 1:

* Have to keep a copy array of the same length
    * O(n)

Solution 2:

* Can only store the two values that are being used in piecewise function to calculate the current max subset sum
    * O(1)