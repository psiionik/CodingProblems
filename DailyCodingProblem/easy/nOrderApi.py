"""
You run an e-commerce website and want to record the last N order ids in a log. Implement a data structure to accomplish this with the
following API:

1. record(order_id): adds the order_id to the log
2. get_last(i): gets the ith last element from the log. i is guaranteed to be smaller than or equal to N.

Be as efficient with time and space as possible.
"""

"""
Solution 1, have a class that has its own list in the constructor and then implement those two methods. Can use the length of the
internal list to index into the ith from the last element to return something. Can just implement functions as well since a class
is not that efficient in space.
"""

class Nlist:
    def __init__(self):
        self.list = []
    
    def record(self, order_id):
        self.list.append(order_id)

    def get_last(self, i):
        length_of_list = len(self.list)
        return self.list[length_of_list - i - 1]


"""
Solution 2, To avoid having to pop an element and then move every element down by one which would take O(n) time, keep a current index
and move it up each time we record something. To get the ith last element, can simply take current - i and index into the list
to get the appropriate element. This is called a circular buffer.
"""

class Log:
    def __init__(self, n):
        self.n = n
        self._log = []
        self._cur = 0

    def record(self, order_id):
        if len(self._log) == self.n:
            self._log[self._cur] = order_id
        else:
            self._log.append(order_id)
        
        self._cur = (self._cur + 1) % self.n

    def get_last(self, i):
        return self._log[self._cur - i]

def main():
    test = Log(3)
    test.record(3)
    test.record(10)
    test.record(20)
    test.record(55)

    print(test.get_last(1))


main()