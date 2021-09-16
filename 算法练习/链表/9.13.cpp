/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
    ListNode* ReverseList(ListNode* pHead) {
        if(pHead==nullptr)
            return nullptr;
        
        ListNode* pre=nullptr;
        ListNode* next=nullptr;
        
       while(pHead!=nullptr){
            next=pHead->next;
            pHead->next=pre;
            pre=pHead;
            pHead=next;
        }
        return pre;
        
    }
};