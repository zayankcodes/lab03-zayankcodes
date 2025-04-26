#include "intbst.h"
#include <iostream>
using namespace std;

int getTest();

int main() {
    IntBST bst1, bst2;

    int vals[] = {64, 128, 8, 512, 256, 32, 16, 4};
    for (int v : vals) bst1.insert(v);

    bool all = true;
    int testnum = getTest();
    if (testnum) all = false;

    cout << "BST:\n  pre-order: ";
    bst1.printPreOrder();
    if (all || testnum == 1) {
        cout << "  in-order: ";
        bst1.printInOrder();
    }
    if (all || testnum == 2) {
        cout << "  post-order: ";
        bst1.printPostOrder();
    }
    if (all || testnum == 3)
        cout << "  sum: " << bst1.sum() << '\n';
    if (all || testnum == 4)
        cout << "  count: " << bst1.count() << '\n';
    if (all || testnum == 5) {
        cout << "  contains 64? "  << (bst1.contains(64)  ? "Y" : "N") << '\n'
             << "  contains 4? "   << (bst1.contains(4)   ? "Y" : "N") << '\n'
             << "  contains 16? "  << (bst1.contains(16)  ? "Y" : "N") << '\n'
             << "  contains 128? " << (bst1.contains(128) ? "Y" : "N") << '\n'
             << "  contains 17? "  << (bst1.contains(17)  ? "Y" : "N") << '\n'
             << "  contains 512? " << (bst1.contains(512) ? "Y" : "N") << '\n';
    }
    if (all || testnum == 6) {
        cout << "  predecessor of 64 is: "  << bst1.getPredecessor(64)  << '\n'
             << "  predecessor of 512 is: " << bst1.getPredecessor(512) << '\n'
             << "  predecessor of 4 is: "   << bst1.getPredecessor(4)   << '\n'
             << "  successor of 64 is: "    << bst1.getSuccessor(64)    << '\n'
             << "  successor of 512 is: "   << bst1.getSuccessor(512)   << '\n'
             << "  successor of 4 is: "     << bst1.getSuccessor(4)     << '\n';
    }
    if (all || testnum == 7) {
        cout << "  removing 4\n";   bst1.remove(4);
        cout << "  removing 64\n";  bst1.remove(64);
        cout << "  removing 128\n"; bst1.remove(128);

        cout << "  contains 64? "  << (bst1.contains(64)  ? "Y" : "N") << '\n'
             << "  contains 4? "   << (bst1.contains(4)   ? "Y" : "N") << '\n'
             << "  contains 16? "  << (bst1.contains(16)  ? "Y" : "N") << '\n'
             << "  contains 128? " << (bst1.contains(128) ? "Y" : "N") << '\n'
             << "  contains 17? "  << (bst1.contains(17)  ? "Y" : "N") << '\n'
             << "  contains 512? " << (bst1.contains(512) ? "Y" : "N") << '\n'
             << "  pre-order: ";
        bst1.printPreOrder();
    }

    cout << "Empty BST:\n  pre-order: ";
    bst2.printPreOrder();
    if (all || testnum == 1) {
        cout << "  in-order: ";
        bst2.printInOrder();
    }
    if (all || testnum == 2) {
        cout << "  post-order: ";
        bst2.printPostOrder();
    }
    if (all || testnum == 3)
        cout << "  sum: " << bst2.sum() << '\n';
    if (all || testnum == 4)
        cout << "  count: " << bst2.count() << '\n';
    if (all || testnum == 5)
        cout << "  contains 16? " << (bst2.contains(16) ? "Y" : "N") << '\n';

    return 0;
}

int getTest() {
    cout << "Choice of tests:\n"
         << "  0. all tests\n"
         << "  1. just printInOrder\n"
         << "  2. just printPostOrder\n"
         << "  3. just sum\n"
         << "  4. just count\n"
         << "  5. just contains\n"
         << "  6. just predecessor/successor\n"
         << "  7. just remove\n";

    while (true) {
        cout << "Enter choice:\n";
        int choice;
        if (cin >> choice && choice >= 0 && choice <= 7)
            return choice;
        cout << "0-7 only!\n";
        cin.clear();
        cin.ignore(10000, '\n');
    }
}
