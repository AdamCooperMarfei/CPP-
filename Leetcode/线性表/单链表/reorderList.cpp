#include<algorithm>
struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(nullptr){}
};

class Solution{
public:
    void reorderList(ListNode *head){
        if(head == nullptr || head->next == nullptr) return;
        ListNode *slow = head, *fast = head, *prev = nullptr;
        while(fast || fast->next){
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        prev->next = nullptr;
        slow = reverse(slow);
        //merge two lists
        ListNode *cur = head;
        while(cur->next){
            ListNode *temp = cur->next;
            cur->next = slow;
            slow = slow->next;
            cur->next->next = temp;
            cur = temp;
        }
        cur->next = slow;
    }
    ListNode *reverse(ListNode *head){
        if(head == nullptr || head->next == nullptr) return head;
        ListNode *prev = head;
        for(ListNode *cur = head->next, *next = cur->next;cur;
            prev = cur, cur = next, next = next?next->next : nullptr)
                cur->next = prev;
        head->next = nullptr;
        return prev;
    }
};