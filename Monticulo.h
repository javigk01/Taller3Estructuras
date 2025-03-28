#ifndef MONTICULO_H
#define MONTICULO_H

#include <vector>
#include <algorithm>
#include <functional>
#include <unordered_set> // Agregado para mejorar eficiencia en búsqueda

template<class T, class Compare = std::greater<T>>
class Monticulo {
private:
    std::vector<T> datos;
    Compare comparador;
    std::unordered_set<T> elementos; // Para evitar duplicados en O(1)

    void heapifyUp(size_t indice);
    void heapifyDown(size_t indice);
    
public:
    Monticulo() = default;

    void insertar(const T& valor);
    bool eliminar(const T& valor);
    bool buscar(const T& valor) const;
    void inordenEnLista(std::list<T>& lista) const;
    bool vacio() const { return datos.empty(); }
    size_t tamano() const { return datos.size(); }
};

#include "Monticulo.hxx"

#endif // MONTICULO_H
