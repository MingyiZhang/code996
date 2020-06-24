package splitLinkedListInParts;

public class Solution {
    public ListNode[] splitListToParts(ListNode root, int k) {
        // length / k = q, length % k = r, k * q + r = length
        // [0...r - 1] q + 1, [r...k - 1] q
        int length = 0;
        ListNode p = root;
        while (p != null) {
            length++;
            p = p.next;
        }
        int q = length / k;
        int r = length % k;
        int size = q;
        ListNode head = root;
        ListNode[] parts = new ListNode[k];
        for (int i = 0; i < k; i++) {
            if (i < r) {
                size = q + 1;
            } else {
                size = q;
            }
            ListNode[] twoParts = getPart(head, size);
            parts[i] = twoParts[0];
            head = twoParts[1];
            
        }
        return parts;
    }

    private ListNode[] getPart(ListNode head, int size) {
        if (size == 0) {
            return new ListNode[]{null, null};
        }
        ListNode p = head;
        ListNode temp = head;
        while (--size > 0) {
            temp = temp.next;
        }
        head = temp.next;
        temp.next = null;
        return new ListNode[]{p, head};
    }
}