#ifndef PRACTICE_HGVECTOR_H
#define PRACTICE_HGVECTOR_H

namespace hg {

    static const int kMinCapacity = 16;
    static const int kGrowthFactor = 2;
    static const int kShrinkFactor = 4;

    class HGVector {
    public:
        HGVector(int capacity);
        HGVector(const HGVector &other) = default;
        ~HGVector();
        int getSize() const;
        bool isEmpty() const;
        int getCapacity() const;
        void debugString() const;
        void push(int value);
        int getValueAt(int index) const;
        int pop();
        void insert(int index, int value);
        void prepend(int value);
        void Delete(int index);
        void remove(int value);
        int find(int value) const;

    private:
        int capacity_{kMinCapacity};
        int size_{0};
        std::unique_ptr<int[]> data_;
        int determineCapacity(int capacity) const;
        void resizeForSize(int candidate_size);
        void increaseSize();
        void decreaseSize();
    };

}


#endif //PRACTICE_HGVECTOR_H
