# Notes on Two Number Sum

## Uses Array Techniques

## Approach 1, Use two for loops

For each number, check all the other numbers in the array and if there is a pair that adds up to the target sum, return that pair.

### Time Complexity

$O(n^2)$ - Have to in the worst case loop through all n elements for each element.

### Space Complexity

$O(1)$ - No space is used to store anything additional outside of the array that is already made.

## Approach 2, Use a Hashtable to save time for space

As traversing through the array, store the current num in the hashtable.

When traversing to future elements, check if the target - current num is already in the hash table. If it is return it with the current number.

Use the formula: 
$$x + y = target$$

### Time Complexity

$O(n)$ - traversing through the array only once and using constant time look ups to the dictonary

### Space Complexity

$O(n)$ - since in the worst case you don't find the number until the end and then you store n numbers

## Approach 3, Sorting with Two Pointers

First sort the incoming array, which will take $O(nlogn)$ time.

Have two pointers, the left being initialized to the first element and the right being initialized to the last element.

Can get the sum of the elements pointed by both pointers and compare it to the target sum.

Leads to 3 cases:

1. If the sum of the two numbers equals the target sum, the two numbers are found
2. If the sum of the two numbers are less than the target sum, move the left pointer right one
3. If the sum of the two numbers are greater than the target sum, move the right pointer left one

Pointer manipulation works because the array is sorted. Moving the left pointer right always guarentees a larger sum and moving the right pointer left always guarentees a smaller sum

If the sum does not exist, the pointers will eventually meet up to the same index and this means that the sum does not exist

### Time Complexity

$O(nlogn)$ - Due to the sorting method

### Space Complexity

$O(1)$ - No additional space utilized


