// Iterative Approach
LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head)
{
    LinkedListNode<int> *prev = NULL;
    LinkedListNode<int> *curr = head;
    LinkedListNode<int> *forward = NULL;
    while (curr != NULL)
    {
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }
    return prev;
}

// Recursive Approach
void reverse(LinkedListNode<int> *&head, LinkedListNode<int> *curr, LinkedListNode<int> *prev)
{
    if (curr == NULL)
    {
        head = prev;
        return;
    }
    LinkedListNode<int> *forward = curr->next;
    reverse(head, forward, curr);
    curr->next = prev;
}
LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head)
{
    LinkedListNode<int> *prev = NULL;
    LinkedListNode<int> *curr = head;
    reverse(head, curr, prev);
    return head;
}