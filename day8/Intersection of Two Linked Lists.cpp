class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *a = headA;
        ListNode* b = headB;
        int countA = 0, countB = 0;
        while(a != nullptr){
            countA++;
            a = a->next;
        }
        while(b != nullptr){
            countB++;
            b = b->next;
        }
        while(countA > countB){
            countA--;
            headA = headA->next;
        }
        while(countB > countA){
            countB--;
            headB = headB->next;
        }
        while(headA != headB){
            headA = headA->next;
            headB = headB->next;
        }
        return headA;
    }
};