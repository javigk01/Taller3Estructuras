#ifndef NODOAVL_H
#define NODOAVL_H

#include <iostream>
#include <list>

template<class T>
class NodoAVL {
  public:
    T dato;
    NodoAVL<T> *hijoDer;
    NodoAVL<T> *hijoIzq;
    int altura;
  
  public:
    NodoAVL();
    NodoAVL(T val);
    ~NodoAVL();
    T& obtenerDato();
    void fijarDato(T& val);
    NodoAVL<T>* obtenerHijoIzq();
    NodoAVL<T>* obtenerHijoDer();
    void fijarHijoIzq(NodoAVL<T> *izq);
    void fijarHijoDer(NodoAVL<T> *der);
    bool esHoja();
    int obtenerAltura();
    void actualizarAltura();
};

#include "NodoAVL.hxx"

#endif // NODOAVL_H