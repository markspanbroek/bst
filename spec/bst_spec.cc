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

        describe("iteration", [&] {

            before("each", [&] {
                my_tree->add(7);
                my_tree->add(5);
                my_tree->add(3);
                my_tree->add(4);
                my_tree->add(10);
                my_tree->add(1);
            });

            it("can determine the lowest value", [&] {
                expect(*(my_tree->begin())).to(be == 1);
            });

            it("can determine the highest value", [&] {
                expect(*(my_tree->rbegin())).to(be == 10);
            });

            it("iterates over its elements in ascending order", [&] {
                auto elements = vector<int>(my_tree->begin(), my_tree->end());

                expect(elements).to(be == vector<int>{1, 3, 4, 5, 7, 10});
            });

            it("iterates over its elements in descending order", [&] {
                auto elements = vector<int>(my_tree->rbegin(), my_tree->rend());

                expect(elements).to(be == vector<int>{10, 7, 5, 4, 3, 1});
            });

        });

    }));

    DocumentationFormatter formatter(cout);
    Reporter reporter(&formatter);

    bool success = example_group->run(reporter);

    return !success;
}