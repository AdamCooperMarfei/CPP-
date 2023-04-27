struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(nullptr){}
};

//快慢指针
class Solution1{
public:
    bool hasCircle(ListNode *head){
        ListNode *fast = head, *slow = head;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast) return true;
        }
        return false;
    }
};

class Solution2{
public:
    ListNode *detectCircle(ListNode *head){
        ListNode *fast = head, *slow = head;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast){
                ListNode *slow2 = head;
                while(slow2 != slow){
                    slow2 = slow2->next;
                    slow = slow->next;
                }
                return slow2;
            }
        }
        return nullptr;
    }
};