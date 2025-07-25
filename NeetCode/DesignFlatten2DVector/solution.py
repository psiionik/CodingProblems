"""
Design an iterator to flatten a 2D vector. It should support the next and hasNext operations.

Implement the Vector2D class:
- Vector2D(int[][] vec) initializes the object with the 2D vector vec.
- next() returns the next element from the 2D vector and moves the pointer one step forward. 
   You may assume that all the calls to next are valid.
- hasNext() returns true if there are still some elements in the vector, and false otherwise.
 
Example 1:

Input
["Vector2D", "next", "next", "next", "hasNext", "hasNext", "next", "hasNext"]
[[[[1, 2], [3], [4]]], [], [], [], [], [], [], []]
Output
[null, 1, 2, 3, true, true, 4, false]

Explanation
Vector2D vector2D = new Vector2D([[1, 2], [3], [4]]);
vector2D.next();    // return 1
vector2D.next();    // return 2
vector2D.next();    // return 3
vector2D.hasNext(); // return True
vector2D.hasNext(); // return True
vector2D.next();    // return 4
vector2D.hasNext(); // return False

Constraints:

0 <= vec.length <= 200
0 <= vec[i].length <= 500
-500 <= vec[i][j] <= 500
At most 105 calls will be made to next and hasNext.

Follow up: As an added challenge, try to code it using only iterators in C++ or iterators in Java.

Your Vector2D object will be instantiated and called as such:
obj = Vector2D(vec)
param_1 = obj.next()
param_2 = obj.hasNext()
"""


from typing import List

class Vector2D:
   def __init__(self, vec: List[List[int]]):
      self.data = vec
      self.row_pointer = 0
      self.col_pointer = 0

   def _find_next_cell(self, row, col):
      while (row < len(self.data) and col == len(self.data[row])):
         row += 1
         col = 0

      self.row_pointer = row
      self.col_pointer = col

   def next(self) -> int:

      if not self.hasNext():
         raise ValueError("Iterator is exhausted!")
      
      val = self.data[self.row_pointer][self.col_pointer]
      self.col_pointer += 1

      return val

   def hasNext(self) -> bool:
      self._find_next_cell(self.row_pointer, self.col_pointer)

      return self.row_pointer < len(self.data)

