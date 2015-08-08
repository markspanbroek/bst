#pragma once

namespace bst {

    using namespace std;

    template<class T>
    class node {

        T value;

        shared_ptr<node<T>> lower;

    public:

        node(T value) : value(value) {}

        void add(T value) {
            if (value < this->value) {
                if (lower) {
                    lower->add(value);
                } else {
                    lower = make_shared<node<T>>(value);
                }
            }
        }

        T *begin() {
            if (lower) {
                return lower->begin();
            }
            return &value;
        }

    };

}