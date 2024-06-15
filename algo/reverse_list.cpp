// Reverse Linked list in with O(1) space
//


ListNode* reverseLinkedList(ListNode* head)
{
    ListNode* curr = head;
    ListNode* prev = nullptr;
    while (curr != nullptr)
    {
        ListNode* nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }

    return prev;
}