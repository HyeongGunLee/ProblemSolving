#include <iostream>
using namespace std;


struct Node {
    int data;
    Node* next;
    Node(int data) : data(data), next(NULL) {}
};

class LinkedList {
public:
    Node* head;

public:
    LinkedList() {
        head = NULL;
    }

    void append(int data) {
        if (head == NULL) {
            head = new Node(data);
            return;
        }

        Node* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new Node(data);
    }

    void prepend(int data) {
        Node* newNode = new Node(data);
        newNode->next = head;
        head = newNode;
    }

    void deleteWithValue(int data) {
        Node* current = head;
        if (head == NULL) return;

        if (head->data == data) {
            head = head->next;
            delete current;
            return;
        }

        while (current->next != NULL) {
            if (current->next->data == data) {
                delete current->next;
                current->next = current->next->next;
                return;
            }
            current = current->next;
        }
    }

    void printList() {
        Node* current = head;
        while (current != NULL) {
            cout << current->data <<endl;
            current = current->next;
        }
    }
};

int main(void) {
    LinkedList list;
    list.append(5);
    list.append(4);
    list.prepend(6);
    cout << list.head->data << endl;
    list.printList();
}