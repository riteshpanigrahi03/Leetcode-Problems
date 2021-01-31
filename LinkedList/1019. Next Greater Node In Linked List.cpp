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
    vector<int> nextLargerNodes(ListNode* head) {
        
        vector<int> arr; // to store all node values into array
        stack <int> s; // stack to store indices
        while(head!=NULL){
            arr.push_back(head->val);
            head = head->next;
        }
        vector<int> res(arr.size(),0);  // to store next greater element
        for(int i=0;i<arr.size();i++){
            while(!s.empty() && arr[i] > arr[s.top()]){
                res[s.top()] = arr[i];
                s.pop();
            }
            s.push(i);
        }
        while(!s.empty()){
            res[s.top()] = 0;
            s.pop();
        }
        
        return res;
    }
};