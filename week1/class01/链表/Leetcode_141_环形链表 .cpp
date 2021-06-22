class Solution {
public:
    bool hasCycle(ListNode* head) {
        ListNode* fast = head;
        while (fast != nullptr && fast->next != nullptr)
        {
            fast = fast->next->next;
            head = head->next;
            if (fast == head) return true;
        }
        return false;
    }
};