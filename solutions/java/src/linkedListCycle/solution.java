package linkedListCycle;

public class solution {
    public boolean hasCycle(ListNode head) {
        ListNode l1 = head;
        ListNode l2 = head;
        while (l2 != null && l2.next != null) {
            l2 = l2.next.next;
            l1 = l1.next;
            if (l1 == l2) {
                return true;
            }
        }
        return false;
    }
}