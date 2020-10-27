# Notes on Valid Subsequence

Subsequences need to have elements appear in the main sequence and in the same order

Have to traverse both arrays

Since order matters, we look for elements in the subsequence in the main sequence in order

## Approach 1, Two Pointers

Since order matters and we have to traverse both arrays, can use two pointers to interate through the array.

Initalize one pointer to start of main array and another to the start of the subsequence.

If the element at pointer in array is the same as element at pointer in subsequence, move both pointers to right one.

If the element at pointer in array is not the same as the elemnt at pointer in subsequence, move pointer at main array only to right one.

If the pointer at subsequence reaches the size of the subsequence, at the end, it is a valid subsequence.

If the pointer at subsequence doesn't reach the end and the pointer at main array is at the end, then it is not a valid subsequence.

### Time Complexity

$O(n)$ - n is the length of the main array, and in the worst case, you have to traverse through all of the elements in the main array.

### Space Complexity

$O(1)$ - no additional space is not required since we only use two pointers.

## Approach 2, Generate all subsequences

Generate all of the possible subsequences from the main array that is the same length of the sequence array.

Do this with recursive helper function and a for loop that appends to the building array before the recursive call and erases the most recently appended element to the building array after the recursive call.

```C++
bool helper(vector<int> &array, vector<int> &sequence, vector<int> &builder, int start_index) {

    bool result;
    if (builder.size() == sequence.size()) {
        return check(builder, sequence);
    }

    for (int i = start_index; i < array.size(); i++) {
        if (builder.size() < sequence.size()) {
            builder.push_back(array[i]);
        }
        result = helper(array, sequence, builder, i + 1);
        if (result) {
            return result;
        }
        builder.erase(builder.begin() + builder.size() - 1);
    }

    return result;
}
```

This works with the base case of whenever the array we are building all subsequences with reaches the same length as the sequence array, we iterate through it with a for loop to check if all the elements are the same and in the same order.

Also, we build the sequence by appending to the building array and then recursively call the helper method to add another element for that subsequence. When we finish from the recursive call (meaning we finished a subsequence) we remove the last added element to append a new element to make another new subsequence.

### Time Complexity

$O(n!m)$ - since we are generating all subsequences, it is $n!$ and since we loop through the size of the subsequence at the base case, it adds $m$ time.

### Space Complexity

$O(m)$ - we limit the building array to be at max the same length as the subsequence array.