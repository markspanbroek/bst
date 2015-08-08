#pragma once

#include "node.h"

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

        T *begin() {
            if (top) {
                return top->begin();
            }
            return nullptr;
        }
    };

}
