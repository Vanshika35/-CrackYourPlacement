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
    ListNode* reverseList(ListNode* head) {
        // stack<int> data;
        // ListNode *temp = head;
        // while(temp != nullptr){
        //     data.push(temp->val);
        //     temp = temp->next;
        // }
        // temp = head;
        // while(temp != nullptr && !data.empty()){
        //     temp->val = data.top();
        //     data.pop();
        //     temp = temp->next;
        // }
        // return head;
        ListNode *temp = head;
        ListNode *prev = nullptr;
        while(temp != nullptr){
            ListNode *front = temp->next;
            temp->next = prev;
            prev = temp;
            temp = front;
        }
        return prev;
    }
};