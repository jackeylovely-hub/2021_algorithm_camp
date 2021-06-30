/**
 解法二：分治法
 */
class Solution {
private:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        auto dummy = new ListNode(-1), head = dummy;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                head = head->next = l1;
                l1 = l1->next;
            }
            else {
                head = head->next = l2;
                l2 = l2->next;
            }
        }
        if (l1) head->next = l1;
        if (l2) head->next = l2;
        return dummy->next;
    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0) {
            return NULL;
        }
        if (lists.size() == 1) {
            return lists[0];
        }
        if (lists.size() == 2)
        {
            return  mergeTwoLists(lists[0], lists[1]);
        }

        int mid = lists.size() / 2;
        vector<ListNode*> sub1_lists;
        vector<ListNode*> sub2_lists;

        for (int i = 0; i < mid; i++) {
            sub1_lists.push_back(lists[i]);
        }
        for (int i = mid; i < lists.size(); i++) {
            sub2_lists.push_back(lists[i]);
        }
        ListNode* l1 = mergeKLists(sub1_lists);
        ListNode* l2 = mergeKLists(sub2_lists);

        return mergeTwoLists(l1, l2);
    }
};