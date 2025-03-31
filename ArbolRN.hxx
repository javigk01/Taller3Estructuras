#ifndef ARBOLRN_HXX
#define ARBOLRN_HXX

#include <iostream>
#include "ArbolRN.h"

template <typename T>
ArbolRN<T>::ArbolRN() {}

template <typename T>
void ArbolRN<T>::insertar(T value) {
    tree.insert(value);
}

template <typename T>
void ArbolRN<T>::eliminar(T value) {
    tree.erase(value);
}

template <typename T>
bool ArbolRN<T>::buscar(T value) {
    return tree.find(value) != tree.end();
}

template <typename T>
void ArbolRN<T>::inordenEnLista(std::list<T>& lista) {
    lista.assign(tree.begin(), tree.end());
}

#endif
