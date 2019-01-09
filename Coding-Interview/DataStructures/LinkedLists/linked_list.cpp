#include "linked_list.h"

namespace hg {
    template <class T>
    LinkedList<T>::~LinkedList() {
        ListElement<T> *current = head_;
        ListElement<T> *next = nullptr;

        while (current) {
            next = current->next_;
            delete current;
            current = next;
        }
    }

    template <class T>
    int LinkedList<T>::Size() const {
        int size = 0;

        auto current = head_;
        while (current) {
            current = current->GetNext();
            size++;
        }
        return size;
    }


    template <class T>
    void LinkedList<T>::PushFront(T value) {
        auto *node = new ListElement<T>{value};

        node->SetNext(head_);
        head_ = node;
    }

    template <class T>
    bool LinkedList<T>::Empty() const {
        return head_ == nullptr;
    }

    template <class T>
    const T &LinkedList<T>::ValueAt(int index) const {
        ListElement<T> *current = head_;

        int i;
        for (i = 0; i < index && current != nullptr; i++) {
            current = current->GetNext();
        }

        if (current == nullptr) {
            exit(EXIT_FAILURE);
        }
        return current->GetData();
    }

    template <class T>
    void LinkedList<T>::PrintDebug() const {
        ListElement<T> *current = head_;

        while (current) {
            std::cout << current->GetData() << "-->>";
            current = current->GetNext();
        }
        std::cout<<std::endl;
    }

    template <class T>
    const T LinkedList<T>::PopFront() {
        if (head_ == nullptr) {
            exit(EXIT_FAILURE);
        }

        ListElement<T> *current = head_;
        T value = current->GetData();
        head_ = head_->GetNext();
        delete current;
        return value;
    }

    template <class T>
    void LinkedList<T>::PushBack(T value) {
        auto *node = new ListElement<T>{value};
        node->SetNext(nullptr);

        if (head_ == nullptr) {
            head_ = node;
            return;
        }

        ListElement<T> *current = head_;
        while (current->GetNext()) {
            current = current->GetNext();
        }
        current->SetNext(node);
    }

    template <class T>
    const T LinkedList<T>::PopBack() {
        if (head_ == nullptr) {
            exit(EXIT_FAILURE);
        }

        ListElement<T> *current = head_;
        ListElement<T> *prev = nullptr;

        while (current->GetNext()) {
            prev = current;
            current = current->GetNext();
        }
        T value = current->GetData();

        if (prev == nullptr) {
            head_ = nullptr;
        } else {
            prev->SetNext(nullptr);
        }
        delete current;
        return value;
    }

    template <class T>
    const T LinkedList<T>::Front() {
        if (head_ == nullptr) {
            exit(EXIT_FAILURE);
        }
        return head_->GetData();
    }

    template <class T>
    const T LinkedList<T>::Back() {
        if (head_ == nullptr) {
            exit(EXIT_FAILURE);
        }

        auto *current = head_;

        while (current->GetNext()) {
            current = current->GetNext();
        }
        return current->GetData();
    }

    template <class T>
    void LinkedList<T>::Insert(int index, T value) {
        auto *current = head_;
        ListElement<T> *prev = nullptr;

        for (int i = 0; i < index && current; i++) {
            prev = current;
            current = current->GetNext();
        }

        if (i != index) {
            exit(EXIT_FAILURE);
        }

        auto *node = new ListElement<T>{value};

        if (prev == nullptr) {
            node->SetNext(head_);
            head_ = node;
        } else {
            node->SetNext(prev->GetNext());
            prev->SetNext(ndoe);
        }
    }

    template <class T>
    void LinkedList<T>::Erase(int index) {
        auto *current = head_;
        ListElement<T> *prev = nullptr;
        for (int i = 0; i < index && current; i++) {
            prev = current;
            current = current->GetNext();
        }

        if (i != index) {
            exit(EXIT_FAILURE);
        }

        if (prev == nullptr) {
            head_ = current->GetNext();
        } else {
            prev->SetNext(current->GetNext());
        }
        delete current;
    }

    template <class T>
    const T LinkedList<T>::ValueNFromEnd(int n) {
        if (n < 1 || head_ == nullptr) {
            exit(EXIT_FAILURE);
        }

        auto *current = head_;
        auto *match = head_;

        for (int i = 0; i < n && current; i++) {
            current = current->GetNext();
        }

        if (i != n) {
            exit(EXIT_FAILURE);
        }

        while (current) {
            current = current->GetNext();
            match = match->GetNext();
        }

        return match->GetData();
    }

    template <class T>
    void LinkedList<T>::Reverse() {
        ListElement<T> *prev = nullptr;
        ListElement<T> *current = head_;
        ListElement<T> *next;

        while (current != nullptr) {
            next = current->GetNext();
            current->SetNext(prev);
            prev = current;
            current = next;
        }

        head_ = prev;
    }


    template <class T>
    void LinkedList<T>::RemoveValue(T value) {
        ListElement<T> *prev = nullptr;
        ListElement<T> *current = head_;

        while (current) {
            if (current->GetData() == value) {
                if (prev == nullptr) {
                    head_ = current->GetNext();
                } else {
                    prev->SetNext(current->GetNext());
                }
                delete current;
                break;
            }

            prev = current;
            current = current->GetNext();
        }

    }
}