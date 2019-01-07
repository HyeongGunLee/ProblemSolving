#include <memory>

#ifndef PRACTICE_LIST_ELEMENT_H
#define PRACTICE_LIST_ELEMENT_H

namespace hg {
    template <class T>
    class ListElement {
    public:
        ListElement(const T &value) : next_(nullptr), data_(value) {}
        ~ListElement() {}
        ListElement(const ListElement &) = delete;
        ListElement &operator=(const ListElement &) = default;

        const T& GetData() const { return data_; }
        ListElement<T> *GetNext() const { return next_; }
        void setData(const T &data) { data_ = data; }
        void SetNext(ListElement<T> *elme) { next_ = elem; }

    private:
        ListElement<T> *next_;
        T data_;
    };
}






#endif //PRACTICE_LIST_ELEMENT_H
