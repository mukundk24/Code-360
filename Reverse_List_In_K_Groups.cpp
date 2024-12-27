int getLength(Node *head)
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
Node* kReverse(Node* head, int k) {
    if(head == NULL)
        return NULL;
    if(getLength(head)<k)
        return head;
    
    Node*next = NULL;
    Node* prev = NULL;
    Node* curr = head;
    int count = 0;

    while(curr!=NULL && count < k)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }

    if(next!=NULL)
        head->next = kReverse(next,k);
    
    return prev;
}