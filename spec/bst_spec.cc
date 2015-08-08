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
using namespace bst;

int main() {

    shared_ptr<tree<int>> my_tree;

    unique_ptr<ExampleGroup> example_group(describe("Binary Search Tree", [&] {

        before("each", [&] {
            my_tree = make_shared<tree<int>>();
        });

        it("is empty by default", [&] {
            expect(my_tree->is_empty()).to(be_truthy);
        });

        it("can contain a value", [&] {
            my_tree->add(1);

            expect(my_tree->is_empty()).to(be_falsey);
        });

        it("can contain values of different types", [&] {
            auto string_tree = tree<string>();
            string_tree.add("a");
        });

        it("can determine the lowest value", [&] {
            my_tree->add(3);
            my_tree->add(2);
            my_tree->add(1);
            my_tree->add(4);

            expect(*(my_tree->begin())).to(be == 1);
        });

    }));

    DocumentationFormatter formatter(cout);
    Reporter reporter(&formatter);

    bool success = example_group->run(reporter);

    return !success;
}