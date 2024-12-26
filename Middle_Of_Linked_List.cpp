int getLength(Node* head)
{
    Node* ptr = head;
    int cnt = 0;
    while(ptr!=NULL)
    {
        ptr = ptr->next;
        cnt++;
    }
    return cnt;
}
Node *findMiddle(Node *head) {
    int len = getLength(head);
    int ans = len/2;
    Node* temp = head;
    while(ans--)
    {
        temp = temp->next;
    }
    return temp;
}

// Another Approach
Node *getMiddle(Node* head)
{
    if(head == NULL || head->next == NULL)
        return head;
    else if(head->next->next == NULL)
        return head->next;
    else
    {
        Node *fast = head->next;
        Node* slow = head;
        while(fast!=NULL)
        {
            fast = fast->next;
            if(fast!=NULL)
            {
                fast = fast->next;
            }
            slow = slow->next;
        }
        return slow;
    }
}
Node *findMiddle(Node *head) {
    return getMiddle(head);
}