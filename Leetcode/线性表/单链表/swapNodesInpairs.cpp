#include<algorithm>
struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(nullptr){}

};

class Solution1{
public:
    ListNode *swapNodes(ListNode *head){
        if(head == nullptr || head->next == nullptr) return head;
        ListNode dummy(-1);
        dummy.next = head;
        for(ListNode *prev = &dummy, *cur = prev->next, *next = cur->next; 
            next;
            prev = cur, cur = cur->next, next = cur?cur->next: nullptr){
                prev->next = next;
                cur->next = next->next;
                next->next = cur;
            }
        return dummy.next;
    }
};

class Solution2{
public:
    ListNode *swapNodes(ListNode *head){
        ListNode *p = head;
        while (p && p->next){
            std::swap(p->val, p->next->val);
            p = p->next->next;
        }
        return head;
    }
};