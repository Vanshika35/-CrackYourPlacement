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
class Solution {
public:
    int length(ListNode* head){
        int cnt = 0;
        while(head != nullptr){
            cnt++;
            head = head->next;
        }
        return cnt;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        int lens = length(head);
        if(lens < k) return head;
        ListNode* prev = nullptr;
        ListNode* temp = head;
        ListNode* front = nullptr;
        int cnt = 0;
        while(temp != nullptr && cnt < k){
            front = temp->next;
            temp->next = prev;
            prev = temp;
            temp = front;
            cnt++;
        }
        if(front != nullptr){
            head->next = reverseKGroup(front, k);
        }
        return prev;
        
    }
};