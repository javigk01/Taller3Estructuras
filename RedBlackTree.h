#ifndef REDBLACKTREE_H
#define REDBLACKTREE_H

#include <set>
#include <string>
#include <list>

template <typename T>
class RedBlackTree {
private:
    std::set<T> tree;

public:
    RedBlackTree();
    void insert(const T& value);
    void erase(const T& value);
    bool search(const T& value) const;
    void inordenEnLista(std::list<T>& lista) const;
};

#include "RedBlackTree.hxx"

#endif
