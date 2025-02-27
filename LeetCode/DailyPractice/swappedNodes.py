class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


def swapPairs(head):
    """
    :type head: ListNode
    :rtype: ListNode
    """
    count = 0
    if (head == None):
        return None
    if (head.next == None):
        return head
    
    swapped = ListNode(None)
    temp = swapped
    count = 0
    while(head != None):
        count += 1
        if (count == 1):
            save = head
            if(head.next == None):
                swapped.next = ListNode(head.val)
        if (count == 2):
            count = 0
            swapped.next = ListNode(head.val)
            swapped = swapped.next
            swapped.next = ListNode(save.val)
            swapped = swapped.next
        head = head.next
    temp = temp.next
    return temp

def main():
    head = ListNode(1)
    head.next = ListNode(2)
    head.next.next = ListNode(3)
    head.next.next.next = ListNode(4)
    x = swapPairs(head)
    while(x != None):
        print(x.val)
        x = x.next




main()