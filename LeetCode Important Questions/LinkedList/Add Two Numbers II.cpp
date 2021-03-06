class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        //Easy implementation using two stack 
        // But doing it in o(1) space 
        // took help from discussion section but next time do it on your
        // own using recursion
        
        ListNode* m1=l1;
        ListNode* m2=l2;
        while(m1!=NULL || m2!=NULL)
        {
            if(m1==NULL)
            {
                ListNode* x=new ListNode(0);
                x->next=l1;
                l1=x;
                m2=m2->next;
            }
            else if(m2==NULL)
            {
                ListNode* x=new ListNode(0);
                x->next=l2;
                l2=x;
                m1=m1->next;
            }
            else
            {
                m1=m1->next;
                m2=m2->next;
            }
        }
        int carry=0;
        ListNode* dummy=new ListNode(-1);
        dummy->next=getcarry(l1,l2,carry);
        
        if(carry!=0)
        {
            ListNode* x=new ListNode(carry);
            x->next=dummy->next;
            dummy->next=x;
        }
        return dummy->next;
    }
    ListNode* getcarry(ListNode* l1,ListNode* l2,int& carry)
    {
        if(l1==NULL && l2==NULL)
            return NULL;
        ListNode* dummy=new ListNode(-1);
        dummy->next=getcarry(l1->next,l2->next,carry);
        dummy->val=(l1->val+l2->val+carry)%10;
        carry=(l1->val+l2->val+carry)/10;
        
        return dummy;
    }
};
