#include <iostream>
using namespace std;


struct ListNode {
    int data;
    ListNode* next;

    ListNode(int data) : data(data) {}
};

void swap(ListNode* s1, ListNode* s2) {
    int temp = s1->data;
    s1->data = s2->data;
    s2->data = temp;
}

void moveHead(ListNode** head) {
    *head = (*head)->next;
}


/*
int main(void) {
    ListNode* head = new ListNode(1);
    ListNode** follow = &head;
    ListNode* tail = new ListNode(5);
    ListNode* mid = new ListNode(3);
    head->next = mid;
    mid->next = tail;
    //out << head->data << " " << mid->data << " " <<  tail->data << endl;
    //cout << head->data << " " << mid->data << " " <<  tail->data << endl;
    cout << head->data << endl;
    cout << (*follow)->data << endl;
    cout << (*follow)->next->data << endl;
    moveHead(&head);

    cout << head->data  << endl;
    cout << (*follow)->data << endl;
    cout << (*follow)->next->data << endl;
}
 */