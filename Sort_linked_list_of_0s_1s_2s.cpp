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