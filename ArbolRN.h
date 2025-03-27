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
    void insert(const T& value);
    void erase(const T& value);
    bool search(const T& value) const;
    void inordenEnLista(std::list<T>& lista) const;
};

#include "ArbolRN.hxx"

#endif
