#pragma once

namespace bst {

    template<class T>
    class tree {

        bool empty;

    public:

        tree() {
            empty = true;
        }

        bool is_empty() {
            return empty;
        }

        void add(T element) {
            empty = false;
        }
    };

}
