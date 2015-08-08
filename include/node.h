#pragma once

namespace bst {

    using namespace std;

    template<class T>
    class node {

        T value;

        shared_ptr<node<T>> lower;

    public:

        node(T value) : value(value) {}

        T &get_value() {
            return value;
        }

        void add(T value) {
            if (value < this->value) {
                if (lower) {
                    lower->add(value);
                } else {
                    lower = make_shared<node<T>>(value);
                }
            }
        }

        node<T> *begin() {
            if (lower) {
                return lower->begin();
            }
            return this;
        }

    };

}