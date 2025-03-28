#include "Monticulo.h"



template<class T, class Compare>
void Monticulo<T, Compare>::heapifyUp(size_t indice) {
    while (indice > 0) {
        size_t padre = (indice - 1) / 2;
        if (comparador(datos[padre], datos[indice])) {
            std::swap(datos[padre], datos[indice]);
            indice = padre;
        } else {
            break;
        }
    }
}

template<class T, class Compare>
void Monticulo<T, Compare>::heapifyDown(size_t indice) {
    size_t hijoIzq, hijoDer, hijoMayor;
    size_t n = datos.size();
    
    while (true) {
        hijoIzq = 2 * indice + 1;
        hijoDer = 2 * indice + 2;
        hijoMayor = indice;
        
        if (hijoIzq < n && comparador(datos[hijoIzq], datos[hijoMayor])) {
            hijoMayor = hijoIzq;
        }
        
        if (hijoDer < n && comparador(datos[hijoDer], datos[hijoMayor])) {
            hijoMayor = hijoDer;
        }
        
        if (hijoMayor != indice) {
            std::swap(datos[indice], datos[hijoMayor]);
            indice = hijoMayor;
        } else {
            break;
        }
    }
}

template<class T, class Compare>
void Monticulo<T, Compare>::insertar(const T& valor) {
    datos.push_back(valor);
    heapifyUp(datos.size() - 1);
}

template<class T, class Compare>
bool Monticulo<T, Compare>::eliminar(const T& valor) {
    auto it = std::find(datos.begin(), datos.end(), valor);
    if (it == datos.end()) return false;
    
    *it = datos.back();
    datos.pop_back();
    
    if (!datos.empty()) {
        size_t indice = it - datos.begin();
        heapifyDown(indice);
        heapifyUp(indice);
    }
    
    return true;
}

template<class T, class Compare>
bool Monticulo<T, Compare>::buscar(const T& valor) const {
    return std::find(datos.begin(), datos.end(), valor) != datos.end();
}

template<class T, class Compare>
void Monticulo<T, Compare>::inordenEnLista(std::list<T>& lista) const {
    // Copiar los datos para no modificar el heap original
    std::vector<T> copia = datos;
    std::sort(copia.begin(), copia.end());
    lista.assign(copia.begin(), copia.end());
}