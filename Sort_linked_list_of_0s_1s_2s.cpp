Node *sortList(Node *head)
{
    int count0 = 0, count1 = 0, count2 = 0;
    Node *ptr = head;
    while (ptr != NULL)
    {
        if (ptr->data == 0)
            count0++;
        else if (ptr->data == 1)
            count1++;
        else
            count2++;
        ptr = ptr->next;
    }
    ptr = head;
    while (count0--)
    {
        if (ptr->data != 0)
            ptr->data = 0;
        ptr = ptr->next;
    }
    while (count1--)
    {
        if (ptr->data != 1)
            ptr->data = 1;
        ptr = ptr->next;
    }
    while (count2--)
    {
        if (ptr->data != 2)
            ptr->data = 2;
        ptr = ptr->next;
    }
    return head;
}

// Another Approach without replacing data
void Insert(Node *&tail, Node *curr)
{
    tail->next = curr;
    tail = tail->next;
}
Node *sortList(Node *head)
{
    Node *head0 = new Node(-1);
    Node *tail0 = head0;
    Node *head1 = new Node(-1);
    Node *tail1 = head1;
    Node *head2 = new Node(-1);
    Node *tail2 = head2;

    Node *curr = head;
    while (curr != NULL)
    {
        if (curr->data == 0)
            Insert(tail0, curr);
        else if (curr->data == 1)
            Insert(tail1, curr);
        else
            Insert(tail2, curr);
        curr = curr->next;
    }
    if (head1->next != NULL)
        tail0->next = head1->next;
    else
        tail0->next = head2->next;
    tail1->next = head2->next;
    tail2->next = NULL;
    head = head0->next;
    delete head0;
    delete head1;
    delete head2;
    return head;
}