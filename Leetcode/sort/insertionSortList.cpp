#include<climits>
using namespace std;
struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x): val(x), next(nullptr){}
};
//插入排序
class Solution{
public:
    ListNode* insertionSortedList(ListNode* head){
        ListNode dummy(INT_MIN);
        for(ListNode* cur = head; cur != nullptr;){
            auto pos = findInsertPos(&dummy, cur->val);
            ListNode* tmp = cur->next;
            cur->next = pos->next;
            pos->next = cur;
            cur = tmp;
        }
        return dummy.next;
    }
    ListNode* findInsertPos(ListNode* head, int x){
        ListNode* pre = nullptr;
        for(ListNode* cur = head; cur != nullptr && cur->val <= x; pre = cur, cur = cur->next)
            ;
        return pre;
    }
};