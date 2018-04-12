/*
 *  HashTable (efficient means of implementing unordered map)
 *      - consists of bucket array and a hash function
 *      - drawbacks: waste of space, keys are required to be integers(0 ~ N-1)
 *
 *      * Hash Functions
 *          - problem of collisions: minimize
 *          - easy to compute, and fast
 *          - mapping key to an integer: hash code
 *              * Hash Code: converting to an integer, Polynomial Hash Codes,
 *                           cyclic shift hash codes
 *
 *          * Compression Functions
 *              - Division Method: h(k) = |K| mod N,
 *              - MAD Methond: h(k) = |ak+b| mod N,
 *
 *          * load factor = n/N (n entries, N capacity)
*
*           * Collision Handling:
 *            - separate chaining: O(n/N), bucket A[i] to be an empty list-based map
 *                      *requires auxiliary data structure
 *            - open-addressing
 *                      - requires that load factor is always at most 1
 *                      *Linear probing: try next at A[(i+1) mod N - - -
 *                          - search시 느린 단점
 *                      *Quadratic probing: A[(i+f(j))mod N], f(j) = j^2
 *                      *Double Hasing: use secondary hash function, minimize clustering
 *                          - A[(i+f(j))mod N], where f(j) = j*h'(k)
 *                          - h'(k) = q - (k mod q) (q < N , N is a prime)
 *
 *      9.2.6) Load Factors and Rehashing
 *          - keep load factors < 0.5 (open-addressing)
 *                              < 0.9 (seperate chaining)
 *
 *
 *
 *       *Ordered map
 *          - Skip lists: search & update: O(log n) average
 *              - randomized data structure.
 *

 *
 */

class HashEntry{
private:
    int key;
    int value;
public:
    HashEntry(int key, int value) : key(key), value(value) {}

    int getKey() {
        return key;
    }

    int getValue() {
        return value;
    }
};

const int TABLE_SIZE = 128;

class HashMap {
private:
    HashEntry **table;

public:
    HashMap() {
        table = new HashEntry*[TABLE_SIZE];
        for (int i = 0; i < TABLE_SIZE; i++) {
            table[i] = NULL;
        }
    }

    int get(int key) {
        int hash = (key % TABLE_SIZE);
        while (table[hash] != NULL && table[hash]->getKey() != key)
            hash = (hash+1) % TABLE_SIZE;
        if (table[hash] == NULL)
            return -1;
        else
            return table[hash]->getValue();
    }

    void put(int key, int value) {
        int hash = (key % TABLE_SIZE);
        while (table[hash] != NULL && table[hash]->getKey() != key)
            hash = (hash+1) % TABLE_SIZE;
        if (table[hash] == NULL)
            delete table[hash];
        table[hash] = new HashEntry(key, value);
    }

    ~HashMap() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            if (table[i] != NULL)
                delete table[i];
        }
        delete [] table;
    }

};

