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
            top = make_shared<node<T>>();
        }
    };

}
