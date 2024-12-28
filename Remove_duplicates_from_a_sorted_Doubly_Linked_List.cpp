Node *removeDuplicates(Node *head)
{
    Node *ptr = head;
    while (ptr->next != NULL)
    {
        if (ptr->data != ptr->next->data)
            ptr = ptr->next;
        else
        {
            Node *temp = ptr->next->next;
            delete ptr->next;
            ptr->next = temp;
        }
    }
    return head;
}
