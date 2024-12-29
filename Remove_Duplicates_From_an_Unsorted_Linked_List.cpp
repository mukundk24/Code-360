Node *removeDuplicates(Node *head)
{
    Node *ptr = head;
    unordered_map <int, bool> s;
    Node* prev = NULL;
    while(ptr!=NULL)
    {
        if(!s[ptr->data])
        {
            s[ptr->data] = true;
            prev = ptr;
            ptr = ptr->next;
        }
        else
        {
            prev->next = ptr->next;
            delete ptr;
            ptr = prev->next;
        }
    }
    return head;
}