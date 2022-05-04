struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
struct ListNode *ptr=NULL,*p=NULL;
ptr=(struct ListNode*)malloc(sizeof(struct ListNode));
    p=ptr;
    int c=0,add,t;
    ptr->val=-1;
    while(l1!=NULL||l2!=NULL||c!=0)
    {
        add=0;
        if(l1!=NULL)
        {
            add=add+l1->val;
            l1=l1->next;
        }
        if(l2!=NULL)
        {
            add=add+l2->val;
            l2=l2->next;
        }
        add=add+c;
        c=0;
        if(add>=10)
        {
            t=add;
            c=t/10;
            add=add%10;
        }
        if(ptr->val==-1)
        {
        ptr->val=add;
        ptr->next=NULL;   
        }
        else{
        ptr->next=(struct ListNode*)malloc(sizeof(struct ListNode));
        ptr=ptr->next;
        ptr->val=add;
        ptr->next=NULL;
        }
    }
    return p;
}
