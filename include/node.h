#pragma once

namespace bst {

    using namespace std;

    template<class T>
    class node {

        T value;

        node<T> *parent;

        shared_ptr<node<T>> lower;

        shared_ptr<node<T>> higher;

    public:

        node(T value, node<T> *parent = nullptr) : value(value), parent(parent) {}

        T &get_value() {
            return value;
        }

        void add(T value) {
            if (value < this->value) {
                if (lower) {
                    lower->add(value);
                } else {
                    lower = make_shared<node<T>>(value, this);
                }
            } else {
                if (higher) {
                    higher->add(value);
                } else {
                    higher = make_shared<node<T>>(value, this);
                }
            }
        }

        node<T> *begin() {
            if (lower) {
                return lower->begin();
            }
            return this;
        }

        node<T> *next() {
            if (higher) {
                return higher->begin();
            } else {
                return next_backtrack();
            }
        }

        node<T> *next_backtrack() {
            if (parent) {
                if (parent->lower.get() == this) {
                    return parent;
                } else {
                    return parent->next_backtrack();
                }
            }
            return nullptr;
        }

        node<T> *rbegin() {
            if (higher) {
                return higher->rbegin();
            }
            return this;
        }

    };

}