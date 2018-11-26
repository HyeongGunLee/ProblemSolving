#include "p_queue.h"
#include <limits>

p_queue::p_queue(int * A, int n)
{
  for (int i = 0; i < n; i++) {
    a[i] = A[i];
  }
  size = n;
  buildMaxHeap(a, size);
}

void p_queue::insert(int x)
{
  size++;
  a[size-1] = x;
  int i = size - 1;
  while (i > 0 && a[parent(i)] < a[i]) {
    swap(a[parent(i)], a[i]);
    i = parent(i);
  }
}

int p_queue::maximum()
{
  if (size <= 0) {
    cerr << "heap overflow" << endl;
    return -1;
  }

  return a[0];
}

int p_queue::extract_max()
{
  if (size <= 0) {
    cerr << "Heap overflow" << endl;
    return -1;
  }
  int max = a[0];
  a[0] = a[size-1];
  size--;
  maxHeapify(a, size, 0);
  return max;
}


void p_queue::increase_key(int i, int x)
{
  a[i] = max(a[i], x);

  while (i > 0 && a[i] > a[parent(i)]) {
    swap(a[parent(i)], a[i]);
    i = parent(i);
  }
}


int p_queue::parent(int i )
{
  return (i-1)/2;
}

int p_queue::left(int i)
{
  return 2*i+1;
}

int p_queue::right(int i)
{
  return 2*i+2;
}

void p_queue::maxHeapify(int A[], int n, int i)
{
  while (i <= (n-1)) {
    int l = left(i);
    int r = right(i);
    int largest = i;

    if (l < n && A[l] > A[i]) {
      largest = l;
    }

    if (r < n && A[r] > A[i]) {
      largest = r;
    }

    if (largest != i) {
      swap(A[largest], A[i]);
      i = largest;
    } else {
      break;
    }
  }
}

void p_queue::buildMaxHeap(int A[], int n)
{
  for (int i = n/2-1; i >= 0; i--) {
    maxHeapify(A, n, i);
  }
}


void p_queue::heapsort(int A[], int n)
{
  buildMaxHeap(A, n);
  for (int i = n-1; i > 0; i--) {
    swap(A[0], A[i]);
    maxHeapify(A, --n, 0);
  }
}


