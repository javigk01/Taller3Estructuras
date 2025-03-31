#include "Monticulo.h"

template<class T>
void Monticulo<T>::insertar(T valor) {
    // Verificar si ya existe (no permitir duplicados)
    if (std::find(datos.begin(), datos.end(), valor) != datos.end()) {
        return;
    }
    
    datos.push_back(valor);
    std::push_heap(datos.begin(), datos.end(), comparador);
}

template<class T>
bool Monticulo<T>::eliminar(T valor) {
    auto it = std::find(datos.begin(), datos.end(), valor);
    if (it == datos.end()) return false;
    
    // Mover el elemento al final
    std::swap(*it, datos.back());
    datos.pop_back();
    
    // Rehacer el heap
    std::make_heap(datos.begin(), datos.end(), comparador);
    return true;
}

template<class T>
bool Monticulo<T>::buscar(T valor) {
    return std::find(datos.begin(), datos.end(), valor) != datos.end();
}

template<class T>
void Monticulo<T>::inordenEnLista(std::list<T>& lista) {
    std::deque<T> copia(datos.begin(), datos.end());
    std::sort(copia.begin(), copia.end(), std::less<T>());
    lista.assign(copia.begin(), copia.end());
}

template<class T>
bool Monticulo<T>::vacio() {
    return datos.empty();
}

template<class T>
size_t Monticulo<T>::tamano() {
    return datos.size();
}