#ifndef ARBOLRN_H
#define ARBOLRN_H

#include <set>
#include <string>
#include <list>

template <typename T>
class ArbolRN {
private:
    std::set<T> tree;

public:
    ArbolRN();
    void insertar(const T& value);
    void eliminar(const T& value);
    bool buscar(const T& value) const;
    void inordenEnLista(std::list<T>& lista) const;
};

#include "ArbolRN.hxx"

#endif
