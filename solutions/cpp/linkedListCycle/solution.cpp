//
// Created by mingyi on 16.04.20.
//

#include <vector>
#include <iostream>
#include <cassert>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  explicit ListNode(int x) : val(x), next(nullptr) {}
};

ListNode *createLinkedList(vector<int> &vec, int pos) {
  ListNode *head = nullptr;
  ListNode *p = nullptr;
  ListNode *s = nullptr;
  for (int i = 0; i < vec.size(); i++) {
    if (i == 0) {
      head = new ListNode(vec[i]);
      s = head;
    } else {
      s->next = new ListNode(vec[i]);
      s = s->next;
      if (i == pos) {
        p = s;
      } else if (i == vec.size() - 1) {
        s->next = p;
      }
    }
  }
  return head;
}

void printLinkedList(ListNode *head, int length) {
  int count = 0;
  ListNode *p = head;
  while (count < length) {
    if (p == nullptr) {
      break;
    }
    cout << p->val << ' ';
    p = p->next;
    count++;
  }
  cout << '\n';
}

bool hasCycle(ListNode *head) {
  ListNode *p = head;
  ListNode *q = head;
  while (q && q->next) {
    p = p->next;
    q = q->next->next;
    if (q == p) {
      return true;
    }
  }
  return false;
}

int main() {
  vector<int> vec{1, 2, 3, 4};
  int pos = 1;
  ListNode *headCycle = createLinkedList(vec, pos);
  printLinkedList(headCycle, 10);

  ListNode *head = createLinkedList(vec, -1);
  printLinkedList(head, 10);

  assert(hasCycle(headCycle));
  assert(!hasCycle(head));

  return 0;
}
