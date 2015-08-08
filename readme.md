Binary Search Tree
==================

Say you're asked to create a binary search tree in C++. What would you do?
The first thing that came to my mind was: why not use std::map or std::set;
they are usually implemented as red-black binary search trees, and the odds
that I'll come up with a better implementation than something that's in the
C++ Standard Template Library are slim at best.

However, it can be a fun programming exercise. And that's how you should
approach the implementation here; it is done purely as an exercise. Feel
free to study the git commits to see how I approached the problem, which
tests I wrote and how the implementation took shape. Think about how you
would approach the problem, what different steps you would take and why.
But whatever you do, do not use this implementation in your program or library.
Simply use the STL instead.

Dependencies & Building
-----------------------

To build, use [biicode][3]:

    bii init
    bii new markspanbroek/bst
    git clone https://github.com/markspanbroek/bst blocks/markspanbroek/bst
    bii test


I used the [CCSpec][1] testing framework and the [Boost.Iterator][2] library.

[1]: https://github.com/zhangsu/ccspec
[2]: http://www.boost.org/doc/libs/1_58_0/libs/iterator/doc/index.html
[3]: http://biicode.com