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
    // bool isPalindrome(ListNode* head) {
    //     vector<int> v;
    //     ListNode* temp = head;
    //     while(temp != nullptr){
    //         v.push_back(temp->val);
    //         temp = temp->next;
    //     }
    //     int i = 0, j = v.size() - 1;
    //     while(i < j && v[i] == v[j]){
    //         i++;
    //         j--;
    //     }
    //     return i>=j;
        
    // }
    // bool isPalindrome(ListNode* head) {
    //     stack<int> st;
    //     ListNode *curr = head;
    //     while(curr != nullptr){
    //         st.push(curr->val);
    //         curr = curr->next;
    //     }
    //     curr = head;
    //     while(curr != nullptr){
    //         if(curr->val == st.top()){
    //             st.pop();
    //             curr = curr->next;
    //         }else{
    //             return false;
    //         }
    //     }
    //     return true;
        
    // }
    ListNode* reverse(ListNode* head){
        ListNode *prev = nullptr;
        ListNode * curr = head;
        while(curr != nullptr){
            ListNode* front = curr->next;
            curr->next = prev;
            prev = curr;
            curr = front;
        }
        return prev;
    }

    bool isPalindrome(ListNode* head) {
       ListNode *slow = head;
       ListNode *fast = head->next;
       while(fast != nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
       }
       ListNode* rev = reverse(slow->next);
       slow->next = nullptr;
       while(rev != nullptr){
        if(head->val != rev->val){
            return false;
        }
        head = head->next;
        rev = rev->next;
       }
       return true; 
    }
};