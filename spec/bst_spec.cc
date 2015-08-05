#include <iostream>

#include "ccspec/core.h"
#include "ccspec/expectation.h"
#include "ccspec/matchers.h"

using namespace std;
using namespace ccspec;
using namespace ccspec::core;
using namespace ccspec::core::formatters;
using namespace ccspec::matchers;

int main() {

    unique_ptr<ExampleGroup> example_group(describe("Binary Search Tree", [] {

    }));

    DocumentationFormatter formatter(cout);
    Reporter reporter(&formatter);

    bool success = example_group->run(reporter);

    return !success;
}