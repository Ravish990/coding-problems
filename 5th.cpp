#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* nextNode) : val(x), next(nextNode) {}
};

class Solution {
private:
    int gcd(int a, int b) {
        if (b == 0) return a;
        return gcd(b, a % b);
    }

public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* p = head;
        while (p->next != nullptr) {
            ListNode* newNode = new ListNode(gcd(p->val, p->next->val), p->next);
            p->next = newNode;
            p = newNode->next;
        }
        return head;
    }
};

int main() {
    ListNode* head = new ListNode(12);
    head->next = new ListNode(15);
    head->next->next = new ListNode(25);

    Solution solution;
    head = solution.insertGreatestCommonDivisors(head);

    ListNode* p = head;
    while (p != nullptr) {
        std::cout << p->val << " ";
        p = p->next;
    }

    return 0;
}
