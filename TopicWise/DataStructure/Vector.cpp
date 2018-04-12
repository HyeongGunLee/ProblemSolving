/*
 *  Vector
 *      - using array (space O(n))
 *          * size(), O(1)
 *          * empty(), O(1)
 *          * at(i), O(1)
 *          * set(i,e), O(1)
 *          * insert(i, e), O(n)
 *          * erase(i), O(n)
 *          * reserve, resize, operator[i], push_back, pop_back()
 *      - Extendable Array
 *          * insert시 reserve(max * 2)
 */

void ArrayVector::reserve(int N) {
    if (capacity >= N) return;
    Elem* B = new Elem[N];
    for (int i = 0; i < N; ++i) {
        B[i] = A[i];
    }
    if (A != NULL) delete [] A;
    A = B;
    capacity = N;
}

void ArrayVector::insert(int i, const Elem& e)
{
    if (n >= capacity)
        reserve(max(1, 2 * capacity));
    for (int j = n - 1; j >= i; j--) {
        A[j+1] = A[j];
    }
    A[i] = e;
    n++;
}