#ifndef MONTICULO_H
#define MONTICULO_H

#include <deque>
#include <algorithm>
#include <functional>
#include <list>

template<class T>
class Monticulo {
private:
    std::deque<T> datos;
    std::greater<T> comparador; // Cambiado a comparador fijo
    
public:
    void insertar(T valor);
    bool eliminar(T valor);
    bool buscar(T valor);
    void inordenEnLista(std::list<T>& lista);
    bool vacio();
    size_t tamano();
};

#include "Monticulo.hxx"

#endif // MONTICULO_H