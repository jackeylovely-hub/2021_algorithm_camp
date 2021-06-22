
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//解法一：
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* new_head = NULL;
        while (head) {
            ListNode* next = head->next;//备份head->next
            head->next = new_head;//指向new_head
            new_head = head;
            head = next;
        }
        return new_head;
    }
};
//递归反转链表
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head || !head->next) return head;
        auto tail = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return tail;
    }
};