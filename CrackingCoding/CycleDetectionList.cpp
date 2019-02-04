bool has_cycle(SinglyLinkedListNode* head) {
    SinglyLinkedListNode* norm = head;
    SinglyLinkedListNode* fast = head;

    if (head == nullptr) {
        return 0;
    }

    while (fast != nullptr && fast->next != nullptr) {
        norm = norm->next;
        fast = fast->next->next;

        if (norm == fast) {
            return 1;
        }
    }
    return 0;
}
