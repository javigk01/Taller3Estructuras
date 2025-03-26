#ifndef REDBLACKTREE_HXX
#define REDBLACKTREE_HXX

#include <iostream>

template <typename T>
RedBlackTree<T>::RedBlackTree() {}

template <typename T>
void RedBlackTree<T>::insert(const T& value) {
    tree.insert(value);
}

template <typename T>
void RedBlackTree<T>::erase(const T& value) {
    tree.erase(value);
}

template <typename T>
bool RedBlackTree<T>::search(const T& value) const {
    return tree.find(value) != tree.end();
}

template <typename T>
void RedBlackTree<T>::inordenEnLista(std::list<T>& lista) const {
    lista.assign(tree.begin(), tree.end());
}

#endif
