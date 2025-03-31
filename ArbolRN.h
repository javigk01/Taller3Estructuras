#ifndef ARBOLRN_H
#define ARBOLRN_H

#include <set>
#include <list>

template <typename T>
class ArbolRN {
private:
    std::set<T> tree;

public:
    ArbolRN();
    void insertar(T value);
    void eliminar(T value);
    bool buscar(T value);
    void inordenEnLista(std::list<T>& lista);
};

#include "ArbolRN.hxx"

#endif
