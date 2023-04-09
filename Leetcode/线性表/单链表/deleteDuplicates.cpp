struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(nullptr){}
};

class Solution1{
public:
    ListNode *deleteDuplicates(ListNode *head){
        if(!head) return head;
        ListNode dummy(head->val + 1);
        dummy.next = head;
        recur(&dummy, head);
        return dummy.next;
    }
private:
    static void recur(ListNode *prev, ListNode *cur){
        if(cur == nullptr) return;
        if(prev->val == cur->val){
            prev->next = cur->next;
            delete cur;
            recur(prev, prev->next);
        }
        else{
            recur(prev->next, cur->next);
        }
    }
};
