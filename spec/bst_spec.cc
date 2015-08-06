#include <iostream>

#include "ccspec/core.h"
#include "ccspec/expectation.h"
#include "ccspec/matchers.h"

#include "tree.h"

using namespace std;
using namespace ccspec;
using namespace ccspec::core;
using namespace ccspec::core::formatters;
using namespace ccspec::matchers;

int main() {

    unique_ptr<ExampleGroup> example_group(describe("Binary Search Tree", [] {

        it("can create a tree", [] {
            bst::tree my_tree;
        });

        it("is empty by default", [] {
            bst::tree my_tree;
            expect(my_tree.is_empty()).to(be_truthy);
        });

        it("can contain a value", [] {
            bst::tree my_tree;

            my_tree.add(1);

            expect(my_tree.is_empty()).to(be_falsey);
        });

    }));

    DocumentationFormatter formatter(cout);
    Reporter reporter(&formatter);

    bool success = example_group->run(reporter);

    return !success;
}