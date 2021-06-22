
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//�ⷨһ��
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* new_head = NULL;
        while (head) {
            ListNode* next = head->next;//����head->next
            head->next = new_head;//ָ��new_head
            new_head = head;
            head = next;
        }
        return new_head;
    }
};
//�ݹ鷴ת����
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