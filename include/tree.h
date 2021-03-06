#pragma once

#include "node.h"
#include "iterator.h"

namespace bst {

    using namespace std;

    template<class T>
    class tree {

        shared_ptr<node<T>> top;

    public:

        bool is_empty() {
            return !top;
        }

        void add(T element) {
            if (top) {
                top->add(element);
            } else {
                top = make_shared<node<T>>(element);
            }
        }

        iterator<T> begin() {
            node<T> *begin_node = nullptr;
            if (top) {
                begin_node = top->begin();
            }
            iterator<T> result(begin_node);
            return result;
        }

        reverse_iterator<T> rbegin() {
            node<T> *rbegin_node = nullptr;
            if (top) {
                rbegin_node = top->rbegin();
            }
            reverse_iterator<T> result(rbegin_node);
            return result;
        }

        iterator<T> end() {
            iterator<T> null_iterator(nullptr);
            return null_iterator;
        }

        reverse_iterator<T> rend() {
            reverse_iterator<T> null_iterator(nullptr);
            return null_iterator;
        }

    };

}
