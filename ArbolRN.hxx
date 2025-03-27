#ifndef ARBOLRN_HXX
#define ARBOLRN_HXX

#include <iostream>
#include "ArbolRN.h"

template <typename T>
ArbolRN<T>::ArbolRN() {}

template <typename T>
void ArbolRN<T>::insert(const T& value) {
    tree.insert(value);
}

template <typename T>
void ArbolRN<T>::erase(const T& value) {
    tree.erase(value);
}

template <typename T>
bool ArbolRN<T>::search(const T& value) const {
    return tree.find(value) != tree.end();
}

template <typename T>
void ArbolRN<T>::inordenEnLista(std::list<T>& lista) const {
    lista.assign(tree.begin(), tree.end());
}

#endif
