#include "hgvector.h"
#include <iostream>

namespace hg {
    HGVector::HGVector(int capacity) : size_{0} {
        if (capacity < 1) {
            std::cout<< "Cannot make vector of that size" << std::endl;
            exit(EXIT_FAILURE);
        }

        int true_capacity = determineCapacity(capacity);

        capacity_ = true_capacity;
        data_ = std::unique_ptr<int[]>(new int[true_capacity]);
    }

    HGVector::~HGVector() {}

    int HGVector::determineCapacity(int capacity) const {
        int true_capacity = kMinCapacity;
        while (capacity > true_capacity/kGrowthFactor) {
            true_capacity *= kGrowthFactor;
        }
        return true_capacity;
    }

    int HGVector::getSize() const {
        return size_;
    }

    bool HGVector::isEmpty() const {
        return size_ == 0;
    }

    int HGVector::getCapacity() const {
        return capacity_;
    }

    void HGVector::debugString() const {
        std::cout << "size: " << size_ << std::endl;
        std::cout << "capacity: " << capacity_ << std::endl;
        std::cout << "item: " << std::endl;
        for (int i = 0; i < size_; i++) {
            printf("%d: %d", i, data_[i]);
            std::cout << std::endl;
        }
    }

    void HGVector::push(int value) {
        resizeForSize(size_ + 1);
        data_[size_] = value;
        ++size_;
    }

    void HGVector::resizeForSize(int candidate_size) {
        if (size_ < candidate_size) {
            if (size_ == capacity_) {
                increaseSize();
            }
        } else if (size_ > candidate_size) {
            if (size_ < capacity_ / kShrinkFactor) {
                decreaseSize();
            }
        }
    }

    void HGVector::increaseSize() {
        int old_capacity = capacity_;
        int new_capacity = determineCapacity(old_capacity);

        if (old_capacity != new_capacity) {
            std::unique_ptr<int[]> new_data(new int[new_capacity]);

            for (int i = 0; i < size_; ++i) {
                new_data[i] = data_[i];
            }

            data_ = std::move(new_data);
            capacity_ = new_capacity;
        }
    }

    void HGVector::decreaseSize() {
        int old_capacity = capacity_;
        int new_capacity = old_capacity / 2;

        if (new_capacity < kMinCapacity) {
            new_capacity = kMinCapacity;
        }

        if (new_capacity != old_capacity) {
            std::unique_ptr<int[]> new_data(new int[new_capacity]);

            for (int i = 0; i < size_; ++i) {
                new_data[i] = data_[i];
            }

            data_ = std::move(new_data);
            capacity_ = new_capacity;
        }
    }

    int HGVector::getValueAt(int index) const {
        if (index < 0 or index >= size_) {
            exit(EXIT_FAILURE);
        }
        return data_[index];
    }

    int HGVector::pop() {
        if (size_ == 0) {
            exit(EXIT_FAILURE);
        }
        resizeForSize(size_ - 1);
        int value = data[size_-1];
        --size_;
        return value;
    }

    void HGVector::insert(int index, int value) {
        if (index < 0 or index >= size_) {
            exit(EXIT_FAILURE);
        }
        resizeForSize(size_ + 1);
        for (int i = size_; i > index; --i) {
            data_[i] = data[i-1];
        }
        data_[index] = value;
        size_++;
    }

    void HGVector::prepend(int value) {
        insert(0, 42);
    }

    void HGVector::Delete(int index) {
        if (index < 0 or index >= size_) {
            exit(EXIT_FAILURE);
        }
        resizeForSize(size_ - 1);

        for (int i = index; i < size_-1; i++) {
            data_[i] = data_[i+1];
        }
        --size_;
    }

    void HGVector::remove(int value) {
        for (int i = 0; i < size_; ++i) {
            if (data_[i] == value) {
                Delete(i);
                --i;
            }
        }
    }

    int HGVector::find(int value) const {
        int found_index = -1;

        for (int i = 0; i < size_; i++) {
            if (data_[i] == value) {
                found_index = i;
                break;
            }
        }
        return found_index;
    }
}