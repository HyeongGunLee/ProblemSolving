#include <iostream>
#include "p_queue.h"
using namespace std;


int main(void) {
  int A[10] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
  p_queue q1(A, 10);

  cout << q1.maximum() << endl;
  q1.insert(20);
  q1.insert(10);
  cout << q1.maximum() << endl;
  q1.extract_max();
  cout << q1.maximum() << endl;
  q1.increase_key(0, 5);
  cout << q1.maximum() << endl;
  q1.extract_max();
  cout << q1.maximum() << endl;
  q1.increase_key(1, 30);
  cout << q1.maximum() << endl;
  return 0;
}
