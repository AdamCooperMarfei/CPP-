struct RandomListNode{
    int val;
    RandomListNode *next;
    RandomListNode *randomPointer;
    RandomListNode(int x):val(x), next(nullptr), randomPointer(nullptr){}
};

class Solution1{
public:
    RandomListNode *copyRandomList(RandomListNode *head){
        for(RandomListNode *cur = head;cur != nullptr;){
            RandomListNode *node = new RandomListNode(cur->val);
            node->next = cur->next;
            cur->next = node;
            cur = node->next;
        }
        for(RandomListNode *cur = head; cur != nullptr;){
            if(cur->randomPointer != nullptr) cur->next->randomPointer = cur->randomPointer->next;
            cur = cur->next->next;
        }
        RandomListNode dummmy(-1);
        for(RandomListNode *cur = head, *new_cur = &dummmy;
            cur != nullptr;){
                new_cur->next = cur->next;
                new_cur = new_cur->next;
                cur->next = cur->next->next;
                cur = cur->next;
            }
        return dummmy.next;
    }
};