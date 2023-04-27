struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(nullptr){}
};

class Solution1{
public:
    ListNode *reverseKGroup(ListNode *head, int k){
        if(head == nullptr || head->next == nullptr || k < 2) return head;
        ListNode *nextGroup = head;
        for(int i = 0; i < k; ++i){
            if(nextGroup)
                nextGroup = nextGroup->next;
            else
                return head;
        }
        ListNode *nexNextGroup = reverseKGroup(nexNextGroup, k);
        ListNode *prev = nullptr, *cur = head;
        while(cur != nextGroup){
            ListNode *next = cur->next;
            cur->next = prev? prev: nexNextGroup;
            prev = cur;
            cur = next;
        }
        return prev;
    }
};

class Solution2{
public:
    ListNode *reverseKGroup(ListNode *head, int k){
        if(head == nullptr || head->next == nullptr || k < 2) return head;
        ListNode dummy(-1);
        dummy.next = head;
        for(ListNode *prev = &dummy, *end = head; end; end = prev->next){
            for(int i = 0; i < k && end; ++i)
                end = end->next;
            if(end == nullptr) break;;
            prev = reverse(prev, prev->next, end);
        }
        return dummy.next;
    }
    ListNode *reverse(ListNode *prev, ListNode *begin, ListNode *end){
        ListNode *endNext = end->next;
        for(ListNode *p = begin, *cur = p->next, *next = cur->next;
            cur != end->next;
            p = cur, cur = next, next = next?next: nullptr)
                cur->next = p;
        begin->next = end->next;
        prev->next = end;
        return begin;
    }
};