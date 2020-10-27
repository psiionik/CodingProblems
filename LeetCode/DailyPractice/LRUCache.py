"""
Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and put.

get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
put(key, value) - Set or insert the value if the key is not already present.
When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.

The cache is initialized with a positive capacity.

Follow up:
Could you do both operations in O(1) time complexity?
"""

"""
Solution 1, Use a combination of a dictionary and a linked list to make the get and put operations constant time.
Have one index (Ex. head) in the dictionary point to the head of a linked list of nodes of capacity n.
When putting nodes in, append to the end of the linked list using a tail pointer in the dictionary. Have the key
of the dictionary point to the corresponding node in the linked list.
The general algorithm is:
    1. When using get, if not in dictionary, return -1. Else return the node the key points to and return the value
    2. When using put, if size < capacity, create a new node, append to the end of the dictionary using tail, and add
        a key value pair in the dictionary where the key points to the node in the linked list
    3. If size == capacity, use the head to remove the first node in linked list, remove the key and then append to tail
"""

class Node:
    def __init__(self, key, value):
        self.value = value
        self.prev = None
        self.next = None
        self.key = key

class LRUCache:

    def __init__(self, capacity: int):
        self.cache = {}
        self.size = 0
        self.capacity = capacity
        self.cache['head'] = Node('head', -1)
        self.cache['tail'] = Node('tail', -1)
        self.cache['head'].next = self.cache['tail']
        self.cache['tail'].prev = self.cache['head']

    def get(self, key: int) -> int:
        if (key in self.cache):
            node = self.cache[key]
            node.prev.next = node.next
            node.next.prev = node.prev
            node.prev = self.cache['tail'].prev
            node.next = self.cache['tail']
            self.cache['tail'].prev.next = node
            self.cache['tail'].prev = node
            return node.value
        else:
            return -1

    def put(self, key: int, value: int) -> None:
        if (key in self.cache):
            self.cache[key].value = value
            node = self.cache[key]
            node.prev.next = node.next
            node.next.prev = node.prev
            node.prev = self.cache['tail'].prev
            node.next = self.cache['tail']
            self.cache['tail'].prev.next = node
            self.cache['tail'].prev = node
            return
        if (self.size < self.capacity):
            node = Node(key, value)
            self.cache[key] = node
            node.next = self.cache['tail']
            node.prev = self.cache['tail'].prev
            self.cache['tail'].prev.next = node
            self.cache['tail'].prev = node
            self.size += 1

        elif(self.size == self.capacity):
            remove_node = self.cache['head'].next
            self.cache['head'].next = self.cache['head'].next.next
            self.cache['head'].next.prev = self.cache['head']
            node = Node(key, value)
            self.cache[key] = node
            node.next = self.cache['tail']
            node.prev = self.cache['tail'].prev
            self.cache['tail'].prev.next = node
            self.cache['tail'].prev = node
            try:
                if(self.cache[remove_node.key] == remove_node):
                    del self.cache[remove_node.key]
            except KeyError:
                print('Key Not Found')
    
    def loop_through(self):
        itr = self.cache['head'].next
        while itr != self.cache['tail']:
            print(itr.value)
            itr = itr.next

def main():

    # cache = LRUCache(2)
    # cache.put(1, 1)
    # cache.put(2, 2)
    # print(cache.get(1))
    # cache.put(3, 3)
    # print(cache.get(2))
    # cache.put(4, 4)
    # print(cache.get(1))
    # print(cache.get(3))
    # print(cache.get(4))

    # cache = LRUCache(1)
    # cache.put(2, 1)
    # print(cache.get(2))
    # cache.put(3, 2)
    # print(cache.get(2))
    # print(cache.get(3))

    cache = LRUCache(2)
    cache.put(2, 1)
    cache.put(1, 1)
    cache.put(2, 3)
    cache.put(4, 1)
    print(cache.get(1))
    print(cache.get(2))

    # cache = LRUCache(2)
    # print(cache.get(2))
    # cache.put(2, 6)
    # print(cache.get(1))
    # cache.put(1, 5)
    # cache.put(1, 2)
    # print(cache.get(1))
    # print(cache.get(2))


main()