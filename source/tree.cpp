#include "tree.h"

namespace bst {

    tree::tree() {
        empty = true;
    }

    bool tree::is_empty() {
        return empty;
    }

    void tree::add(int element) {
        empty = false;
    }
}

