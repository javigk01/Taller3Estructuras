#ifndef ARBOLAVL_H
#define ARBOLAVL_H

#include "NodoAVL.h"
#include <list>
#include <string>

template<class T>
class ArbolAVL {
  protected: 
    NodoAVL<T> *raiz;
  
  public:
    ArbolAVL();
    ~ArbolAVL();
    bool esVacio();
    void fijarRaiz(NodoAVL<T>* raiz);
    NodoAVL<T>* obtenerRaiz();
    T& datoRaiz();
    int altura();
    int altura(NodoAVL<T> *nodo);
    int tamano();
    bool insertar(T &val);
    bool eliminar(T &val);
    bool buscar(T &val);
    void preOrden();
    void preOrden(NodoAVL<T>* nodo);
    void inOrden();
    void inOrden(NodoAVL<T>* nodo, std::list<T>& lista);
    void inordenLista(std::list<T>& lista);
    void posOrden();
    void posOrden(NodoAVL<T>* nodo);
    void nivelOrden();
  
  private:
    NodoAVL<T>* rotacionDerecha(NodoAVL<T>* nodo);
    NodoAVL<T>* rotacionIzquierda(NodoAVL<T>* nodo);
    NodoAVL<T>* rotacionIzquierdaDerecha(NodoAVL<T>* nodo);
    NodoAVL<T>* rotacionDerechaIzquierda(NodoAVL<T>* nodo);
    NodoAVL<T>* insertar(NodoAVL<T>* nodo, T &val);
    NodoAVL<T>* eliminar(NodoAVL<T>* nodo, T &val);
    NodoAVL<T>* nodoMinimo(NodoAVL<T>* nodo);
    int factorBalance(NodoAVL<T>* nodo);
};

#include "ArbolAVL.cxx"

#endif // ARBOLAVL_H