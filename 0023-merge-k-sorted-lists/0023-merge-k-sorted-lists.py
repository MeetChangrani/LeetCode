import heapq

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def mergeKLists(self, lists):
        # lists: List[ListNode]
        min_heap = []
        for i, node in enumerate(lists):
            if node:
                # heap element: (value, list_index, node)
                heapq.heappush(min_heap, (node.val, i, node))

        dummy = ListNode(0)
        curr = dummy

        while min_heap:
            val, idx, node = heapq.heappop(min_heap)
            curr.next = node
            curr = curr.next
            if node.next:
                heapq.heappush(min_heap, (node.next.val, idx, node.next))

        return dummy.next