#include "intbst.h"
#include <iostream>
using std::cout;
using std::endl;

IntBST::IntBST() : root(nullptr) {}

void IntBST::clear(Node* n) {
    if (!n) return;
    clear(n->left);
    clear(n->right);
    delete n;
}

IntBST::~IntBST() {
    clear(root);
}

bool IntBST::insert(int value) {
    if (!root) {
        root = new Node(value);
        return true;
    }
    return insert(value, root);
}

bool IntBST::insert(int value, Node* n) {
    if (value == n->info) return false;
    if (value < n->info) {
        if (n->left) return insert(value, n->left);
        n->left = new Node(value);
        n->left->parent = n;
        return true;
    } else {
        if (n->right) return insert(value, n->right);
        n->right = new Node(value);
        n->right->parent = n;
        return true;
    }
}




void IntBST::printPreOrder() const { printPreOrder(root); }
void IntBST::printInOrder()  const { printInOrder(root);  }
void IntBST::printPostOrder() const { printPostOrder(root); }



void IntBST::printPreOrder(Node* n) const {
    if (!n) return;
    cout << n->info;
    if (getSuccessor(n->info) != 0) cout << ' ';
    printPreOrder(n->left);
    printPreOrder(n->right);
}

void IntBST::printInOrder(Node* n) const {
    if (!n) return;
    printInOrder(n->left);
    cout << n->info;
    if (getSuccessor(n->info) != 0) cout << ' ';
    printInOrder(n->right);
}

void IntBST::printPostOrder(Node* n) const {
    if (!n) return;
    printPostOrder(n->left);
    printPostOrder(n->right);
    cout << n->info;
    if (n != root) cout << ' ';
}
int IntBST::sum(Node* n) const {
    if (!n) return 0;
    return n->info + sum(n->left) + sum(n->right);
}
int IntBST::sum()   const { return sum(root); }

int IntBST::count(Node* n) const {
    if (!n) return 0;
    return 1 + count(n->left) + count(n->right);
}
int IntBST::count() const { return count(root); }

IntBST::Node* IntBST::getNodeFor(int value, Node* n) const {
    if (!n) return nullptr;
    if (value == n->info) return n;
    return (value < n->info)
         ? getNodeFor(value, n->left)
         : getNodeFor(value, n->right);
}

bool IntBST::contains(int value) const {
    return getNodeFor(value, root) != nullptr;
}

IntBST::Node* IntBST::getPredecessorNode(int value) const {
    Node* n = getNodeFor(value, root);
    if (!n) return nullptr;
    if (n->left) {
        n = n->left;
        while (n->right) n = n->right;
        return n;
    }
    Node* p = n->parent;
    while (p && n == p->left) { n = p; p = p->parent; }
    return p;
}
int IntBST::getPredecessor(int value) const {
    Node* p = getPredecessorNode(value);
    return p ? p->info : 0;
}

IntBST::Node* IntBST::getSuccessorNode(int value) const {
    Node* n = getNodeFor(value, root);
    if (!n) return nullptr;
    if (n->right) {
        n = n->right;
        while (n->left) n = n->left;
        return n;
    }
    Node* p = n->parent;
    while (p && n == p->right) { n = p; p = p->parent; }
    return p;
}
int IntBST::getSuccessor(int value) const {
    Node* s = getSuccessorNode(value);
    return s ? s->info : 0;
}

bool IntBST::remove(int value) {
    Node* n = getNodeFor(value, root);
    if (!n) return false;
    if (n->left && n->right) {
        Node* succ = getSuccessorNode(value);
        n->info = succ->info;
        n = succ;
    }
    Node* child = n->left ? n->left : n->right;
    if (!n->parent) {
        root = child;
        if (child) child->parent = nullptr;
    } else {
        if (n == n->parent->left)  n->parent->left  = child;
        else                       n->parent->right = child;
        if (child) child->parent = n->parent;
    }
    delete n;
    return true;
}
