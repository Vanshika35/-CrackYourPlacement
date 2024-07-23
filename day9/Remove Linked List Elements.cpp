/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
// class Solution {
// public:
//     ListNode* removeElements(ListNode* head, int val) {
//         ListNode* temp = head;
//         ListNode* newHead = new ListNode(0);
//         ListNode* newTemp = newHead;
//         while(temp != nullptr){
//             if(temp->val != val){
//                 newTemp->next = new ListNode(temp->val);
//                 newTemp = newTemp->next;
//             }
//             temp = temp->next;
//         }
//         return newHead->next;
//     }
// };

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if(head == NULL) return head;
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* tail = dummy;
        while(tail != NULL && tail->next!= NULL){
            if(tail->next->val == val){
                ListNode* temp = tail->next;
                tail->next = temp->next;
                delete(temp);
            }else{
                tail = tail->next;
            }
        }
        return dummy->next;
    }
};