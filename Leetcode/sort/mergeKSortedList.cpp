#include<vector>
using namespace std;
struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x):val(x), next(nullptr){}
};

class Solution{
public:
    ListNode* mergeKSortedList(vector<ListNode*> &lists){
        if(lists.empty()) return nullptr;
        ListNode* p = lists[0];
        for(int i = 1; i < lists.size(); ++i){
            p = mergeTwoLists(p, lists[i]);
        }
    }
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2){
        if(l1 == nullptr) return l2;
        if(l2 == nullptr) return l1;
        ListNode dummy(-1);
        ListNode* p = &dummy;
        for(; l1 != nullptr && l2 != nullptr; p = p->next){
            if(l1->val > l2->val){
                p->next = l2;
                l2 = l2->next;
            }
            else{
                p->next = l1;
                l1 = l1->next;
            }
        }
        p->next = l1 != nullptr?l1: l2;
        return dummy.next;
    }
};