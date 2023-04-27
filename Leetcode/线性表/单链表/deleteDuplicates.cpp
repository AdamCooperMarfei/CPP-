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

class Solution2{
public:
    ListNode *removeDuplicates(ListNode *head){
        if(head == nullptr) return nullptr;
        for(ListNode *prev = head, *cur = head->next; cur; cur = prev->next){
            if(prev->val = cur->val){
                prev->next = cur->next;
                delete cur;
            }
            else{
                prev = cur;
            }
        }
        return head;
    }
};

class Solution3{
public:
    ListNode *deleteDuplicates(ListNode *head){
        if(!head || !head->next) return head;
        ListNode *p = head->next;
        if(head->val == p->val){
            while(p && head->val == p->val){
                ListNode *tmp = p;
                p = p->next;
                delete tmp;
            }
            delete head;
            return deleteDuplicates(p);
        }
        else{
            head->next = deleteDuplicates(head->next);
            return head;
        }
    }
};

class Solution4{
public:
    ListNode *deleteDuplicates(ListNode *head){
        if(head == nullptr) return head;
        ListNode dummy(-__INT_MAX__);
        dummy.next = head;
        ListNode *prev = &dummy;
        ListNode *cur = head;
        while(cur != nullptr){
            bool duplicated = false;
            while(cur->next != nullptr && cur->val == cur->next->val){
                duplicated = true;
                ListNode *temp = cur;
                cur = cur->next;
                delete temp;
            }
            if(duplicated){
                ListNode *temp = cur;
                cur = cur->next;
                delete temp;
                continue;
            }
            prev->next = cur;
            prev = prev->next;
            cur = cur->next;
        }
        prev->next = cur;
        return dummy.next;
        
    }
};