Node *FloydDetectLoop(Node *head)
{
    if (head == NULL)
    {
        return NULL;
    }
    Node *slow = head;
    Node *fast = head;
    while (slow != NULL && fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
            fast = fast->next;
        slow = slow->next;
        if (slow == fast)
        {
            return slow;
        }
    }
    return head;
}

Node *getStartingNode(Node *head)
{
    if (head == NULL)
        return NULL;
    Node *intersection = FloydDetectLoop(head);
    Node *slow = head;
    while (slow != intersection)
    {
        slow = slow->next;
        intersection = intersection->next;
    }
    return slow;
}

Node *RemoveLoop(Node *head)
{
    if (head == NULL)
        return NULL;
    Node *start = getStartingNode(head);
    Node *temp = start;
    while (temp->next != start && temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = NULL;
    return head;
}
Node *removeLoop(Node *head)
{
    return RemoveLoop(head);
}