#include "NodoAVL.h"

template<class T>
NodoAVL<T>::NodoAVL() : hijoIzq(nullptr), hijoDer(nullptr), altura(1) {}

template<class T>
NodoAVL<T>::NodoAVL(T val) : dato(val), hijoIzq(nullptr), hijoDer(nullptr), altura(1) {}

template<class T>
NodoAVL<T>::~NodoAVL() {
    // Destructor
}

template<class T>
T& NodoAVL<T>::obtenerDato() {
    return dato;
}

template<class T>
void NodoAVL<T>::fijarDato(T& val) {
    dato = val;
}

template<class T>
NodoAVL<T>* NodoAVL<T>::obtenerHijoIzq() {
    return hijoIzq;
}

template<class T>
NodoAVL<T>* NodoAVL<T>::obtenerHijoDer() {
    return hijoDer;
}

template<class T>
void NodoAVL<T>::fijarHijoIzq(NodoAVL<T>* izq) {
    hijoIzq = izq;
}

template<class T>
void NodoAVL<T>::fijarHijoDer(NodoAVL<T>* der) {
    hijoDer = der;
}

template<class T>
bool NodoAVL<T>::esHoja() {
    return (hijoIzq == nullptr && hijoDer == nullptr);
}

template<class T>
int NodoAVL<T>::obtenerAltura() {
    return altura;
}

template<class T>
void NodoAVL<T>::actualizarAltura() {
    int alturaIzq = hijoIzq ? hijoIzq->obtenerAltura() : 0;
    int alturaDer = hijoDer ? hijoDer->obtenerAltura() : 0;
    altura = 1 + std::max(alturaIzq, alturaDer);
}