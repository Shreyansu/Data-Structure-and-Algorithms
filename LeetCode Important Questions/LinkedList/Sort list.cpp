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
    void reorderList(ListNode* head) 
    {
        if(head==NULL || head->next==NULL)
            return;
        ListNode* p1=head;
        ListNode* p2=head->next;
        
        while(p2 && p2->next)
        {
            p1=p1->next;
            p2=p2->next->next;
        }
        ListNode* head2=p1->next;
        p1->next=NULL;
        p2=head2->next;
        head2->next=NULL;
        
        while(p2)
        {
            p1=p2->next;
            p2->next=head2;
            head2=p2;
            p2=p1;
        }
        p1=head,p2=head2;
        while(p1!=NULL && p2!=NULL)
        {
            auto t=p1->next;
            auto q=p2->next;
            p1->next=p2;
            p2->next=t;
            p1=t;
            p2=q;
            
        }
        
        
    }
};
