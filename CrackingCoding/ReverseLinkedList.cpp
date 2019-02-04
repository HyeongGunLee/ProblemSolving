SinglyLinkedListNode* reverse(SinglyLinkedListNode* head) {

    SinglyLinkedListNode* prev = nullptr;
    SinglyLinkedListNode* current = head;
    SinglyLinkedListNode* next;

    while (current != nullptr) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}
