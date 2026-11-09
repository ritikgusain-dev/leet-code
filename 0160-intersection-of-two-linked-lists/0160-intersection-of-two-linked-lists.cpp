/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        //BRUTE
        // map<ListNode*,int>mp;
        // ListNode* temp = headA;
        // while(temp!=nullptr){
        //     mp[temp]=1;
        //     temp=temp->next;
        // }
        // temp=headB;
        // while(temp!=nullptr){
        //     if(mp.find(temp)!=mp.end()) return temp;
        //     temp=temp->next;
        // }
        // return nullptr;
        // OPTIMAL
        if(headA==nullptr || headB==nullptr) return nullptr;
        ListNode* t1 = headA;
        ListNode* t2 = headB;
        while(t1 != t2){
            t1 = t1->next;
            t2 = t2->next;
            if(t1==nullptr && t2==nullptr) return nullptr;
            if(t1==nullptr) t1=headB;
            if(t2==nullptr) t2=headA;
        }
        return t1;
    }
};