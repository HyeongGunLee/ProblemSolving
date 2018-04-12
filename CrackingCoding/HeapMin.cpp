#include <iostream>
using namespace std;


class MinIntHeap {
private:
    int capacity = 10;
    int size = 0;
    int* items = new int[capacity];

public:
    int getLeftChildIndex(int parentIndex) { return 2 * parentIndex + 1;}
    int getRightChild(int parentIndex) { return 2 * parentIndex + 2;}
    int getParentIndex(int childIndex) { return (childIndex -1 ) / 2;}

    bool hasLeftChild(int index) {return getLeftChildIndex(index) < size;}
    bool hasRightChild(int index) {return getRightChild(index) < size;}
    bool hasParent(int index) {return getParentIndex(index) >= 0;}

    int leftChild(int index) {return items[getLeftChildIndex(index)];}
    int rightChild(int index) {return items[getRightChild(index)];}
    int parent(int index) {return items[getParentIndex(index)];}

    void swap(int indexOne, int indexTwo) {
        int temp = items[indexOne];
        items[indexOne] = items[indexTwo];
        items[indexTwo] = temp;
    }

    void ensureExtraCapacity() {
        if (size == capacity) {
            items = arrays.copyOf(items, capacity * 2);
            capacity *= 2;
        }
    }

    int peek() {
        if (size == 0) throw new;
        return items[0];
    }

    int poll() {
        if (size == ) throw ;
        int item = items[0];
        items[0] = items[size-1];
        size--;
        heapifyDown();
        return item;
    }

    void add(int item) {
        ensureExtraCapacity();
        items[size] = item;
        size++;
        heapifyUp();
    }

    void heapifyDown() {
        int index = 0;
        while (hasLeftChild(index)) {
            int smallerChildIndex = getLeftChildIndex(index);
            if (hasRightChild(index) && rightChild(index) < leftChild(index)) {
                smallerChildIndex = rightChild(index);
            }

            if (items[index] < items[smallerChildIndex]) {
                break;
            } else {
                swap(index, smallerChildIndex);
            }
            index = smallerChildIndex;
        }

    }

    void heapifyUp() {
        int index = size - 1;
        while (hasParent(index) && parent(index) > items[index]) {
            swap(getParentIndex(index), index);
            index = getParentIndex(index);
        }
    }

};


int main(void) {

}