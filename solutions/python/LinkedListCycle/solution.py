from typing import List


class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


def create_linked_list(lst: List[int], pos: int) -> ListNode:
    head = p = s = None
    for i, v in enumerate(lst):
        if i == 0:
            head = ListNode(v)
            s = head
        else:
            s.next = ListNode(v)
            s = s.next
            if i == pos:
                p = s
            elif i == len(lst) - 1:
                s.next = p
    return head


def print_linked_list(head: ListNode, length: int):
    cnt = 0
    p = head
    while cnt < length:
        if p is None:
            break
        print(p.val, end=' ')
        p = p.next
        cnt += 1
    print()


def has_cycle(head: ListNode) -> bool:
    p = q = head
    while q and q.next:
        p = p.next
        q = q.next.next
        if p == q:
            return True
    return False


if __name__ == '__main__':
    lst = [1, 2, 3, 4]
    head_cycle = create_linked_list(lst, 1)
    print_linked_list(head_cycle, 10)

    head = create_linked_list(lst, -1)
    print_linked_list(head, 10)

    assert(has_cycle(head_cycle))
    assert(not has_cycle(head))
