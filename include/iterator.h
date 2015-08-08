#pragma once

#include <boost/iterator/iterator_facade.hpp>
#include "node.h"

namespace bst {

    using namespace std;
    using namespace boost;

    template<class T>
    class iterator : public iterator_facade<iterator<T>, int, forward_iterator_tag> {
    protected:

        friend class iterator_core_access;

        node<T> *current_node;

    public:

        iterator(node<T> *current_node) : current_node(current_node) { }

        bool equal(iterator<T> const &other) const {
            return current_node == other.current_node;
        }

        T &dereference() const {
            return current_node->get_value();
        }

        virtual void increment() {
            current_node = current_node->next();
        }

    };

    template<class T>
    class reverse_iterator : public iterator<T> {

    public:

        reverse_iterator(node<T> *current_node) : iterator<T>(current_node) { }

        virtual void increment() {
            this->current_node = this->current_node->previous();
        }

    };

}