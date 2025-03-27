#include "ArbolAVL.h"
#include <algorithm>
#include <queue>

template<class T>
ArbolAVL<T>::ArbolAVL() : raiz(nullptr) {}

template<class T>
ArbolAVL<T>::~ArbolAVL() {
    // Implementar si es necesario
}

template<class T>
bool ArbolAVL<T>::esVacio() {
    return raiz == nullptr;
}

template<class T>
void ArbolAVL<T>::fijarRaiz(NodoAVL<T>* raiz) {
    this->raiz = raiz;
}

template<class T>
NodoAVL<T>* ArbolAVL<T>::obtenerRaiz() {
    return raiz;
}

template<class T>
T& ArbolAVL<T>::datoRaiz() {
    return raiz->obtenerDato();
}

template<class T>
int ArbolAVL<T>::altura() {
    return altura(raiz);
}

template<class T>
int ArbolAVL<T>::altura(NodoAVL<T>* nodo) {
    if (nodo == nullptr) return 0;
    return nodo->obtenerAltura();
}

template<class T>
int ArbolAVL<T>::tamano() {
    // Implementación pendiente
    return 0;
}

template<class T>
int ArbolAVL<T>::factorBalance(NodoAVL<T>* nodo) {
    if (nodo == nullptr) return 0;
    return altura(nodo->obtenerHijoIzq()) - altura(nodo->obtenerHijoDer());
}

template<class T>
NodoAVL<T>* ArbolAVL<T>::rotacionDerecha(NodoAVL<T>* y) {
    NodoAVL<T>* x = y->obtenerHijoIzq();
    NodoAVL<T>* T2 = x->obtenerHijoDer();

    x->fijarHijoDer(y);
    y->fijarHijoIzq(T2);

    y->actualizarAltura();
    x->actualizarAltura();

    return x;
}

template<class T>
NodoAVL<T>* ArbolAVL<T>::rotacionIzquierda(NodoAVL<T>* x) {
    NodoAVL<T>* y = x->obtenerHijoDer();
    NodoAVL<T>* T2 = y->obtenerHijoIzq();

    y->fijarHijoIzq(x);
    x->fijarHijoDer(T2);

    x->actualizarAltura();
    y->actualizarAltura();

    return y;
}

template<class T>
NodoAVL<T>* ArbolAVL<T>::rotacionIzquierdaDerecha(NodoAVL<T>* nodo) {
    nodo->fijarHijoIzq(rotacionIzquierda(nodo->obtenerHijoIzq()));
    return rotacionDerecha(nodo);
}

template<class T>
NodoAVL<T>* ArbolAVL<T>::rotacionDerechaIzquierda(NodoAVL<T>* nodo) {
    nodo->fijarHijoDer(rotacionDerecha(nodo->obtenerHijoDer()));
    return rotacionIzquierda(nodo);
}

template<class T>
NodoAVL<T>* ArbolAVL<T>::insertar(NodoAVL<T>* nodo, T &val) {
    if (nodo == nullptr)
        return new NodoAVL<T>(val);

    if (val < nodo->obtenerDato())
        nodo->fijarHijoIzq(insertar(nodo->obtenerHijoIzq(), val));
    else if (val > nodo->obtenerDato())
        nodo->fijarHijoDer(insertar(nodo->obtenerHijoDer(), val));
    else
        return nodo;

    nodo->actualizarAltura();

    int balance = factorBalance(nodo);

    // Caso izquierda izquierda
    if (balance > 1 && val < nodo->obtenerHijoIzq()->obtenerDato())
        return rotacionDerecha(nodo);

    // Caso derecha derecha
    if (balance < -1 && val > nodo->obtenerHijoDer()->obtenerDato())
        return rotacionIzquierda(nodo);

    // Caso izquierda derecha
    if (balance > 1 && val > nodo->obtenerHijoIzq()->obtenerDato())
        return rotacionIzquierdaDerecha(nodo);

    // Caso derecha izquierda
    if (balance < -1 && val < nodo->obtenerHijoDer()->obtenerDato())
        return rotacionDerechaIzquierda(nodo);

    return nodo;
}

template<class T>
bool ArbolAVL<T>::insertar(T &val) {
    raiz = insertar(raiz, val);
    return true;
}

template<class T>
NodoAVL<T>* ArbolAVL<T>::nodoMinimo(NodoAVL<T>* nodo) {
    NodoAVL<T>* actual = nodo;
    while (actual && actual->obtenerHijoIzq() != nullptr)
        actual = actual->obtenerHijoIzq();
    return actual;
}

template<class T>
NodoAVL<T>* ArbolAVL<T>::eliminar(NodoAVL<T>* nodo, T &val) {
    if (nodo == nullptr) return nodo;

    if (val < nodo->obtenerDato())
        nodo->fijarHijoIzq(eliminar(nodo->obtenerHijoIzq(), val));
    else if (val > nodo->obtenerDato())
        nodo->fijarHijoDer(eliminar(nodo->obtenerHijoDer(), val));
    else {
        if (nodo->obtenerHijoIzq() == nullptr || nodo->obtenerHijoDer() == nullptr) {
            NodoAVL<T>* temp = nodo->obtenerHijoIzq() ? nodo->obtenerHijoIzq() : nodo->obtenerHijoDer();

            if (temp == nullptr) {
                temp = nodo;
                nodo = nullptr;
            } else {
                *nodo = *temp;
            }

            delete temp;
        } else {
            NodoAVL<T>* temp = nodoMinimo(nodo->obtenerHijoDer());
            nodo->fijarDato(temp->obtenerDato());
            nodo->fijarHijoDer(eliminar(nodo->obtenerHijoDer(), temp->obtenerDato()));
        }
    }

    if (nodo == nullptr) return nodo;

    nodo->actualizarAltura();

    int balance = factorBalance(nodo);

    // Caso izquierda izquierda
    if (balance > 1 && factorBalance(nodo->obtenerHijoIzq()) >= 0)
        return rotacionDerecha(nodo);

    // Caso izquierda derecha
    if (balance > 1 && factorBalance(nodo->obtenerHijoIzq()) < 0)
        return rotacionIzquierdaDerecha(nodo);

    // Caso derecha derecha
    if (balance < -1 && factorBalance(nodo->obtenerHijoDer()) <= 0)
        return rotacionIzquierda(nodo);

    // Caso derecha izquierda
    if (balance < -1 && factorBalance(nodo->obtenerHijoDer()) > 0)
        return rotacionDerechaIzquierda(nodo);

    return nodo;
}

template<class T>
bool ArbolAVL<T>::eliminar(T &val) {
    raiz = eliminar(raiz, val);
    return true;
}

template<class T>
bool ArbolAVL<T>::buscar(T &val) {
    NodoAVL<T>* actual = raiz;
    while (actual != nullptr) {
        if (val < actual->obtenerDato())
            actual = actual->obtenerHijoIzq();
        else if (val > actual->obtenerDato())
            actual = actual->obtenerHijoDer();
        else
            return true;
    }
    return false;
}

template<class T>
void ArbolAVL<T>::inOrden(NodoAVL<T>* nodo, std::list<T>& lista) {
    if (nodo != nullptr) {
        inOrden(nodo->obtenerHijoIzq(), lista);
        lista.push_back(nodo->obtenerDato());
        inOrden(nodo->obtenerHijoDer(), lista);
    }
}

template<class T>
void ArbolAVL<T>::inordenLista(std::list<T>& lista) {
    inOrden(raiz, lista);
}

template<class T>
void ArbolAVL<T>::preOrden(NodoAVL<T>* nodo) {
    if (nodo != nullptr) {
        std::cout << nodo->obtenerDato() << " ";
        preOrden(nodo->obtenerHijoIzq());
        preOrden(nodo->obtenerHijoDer());
    }
}

template<class T>
void ArbolAVL<T>::preOrden() {
    preOrden(raiz);
}

template<class T>
void ArbolAVL<T>::posOrden(NodoAVL<T>* nodo) {
    if (nodo != nullptr) {
        posOrden(nodo->obtenerHijoIzq());
        posOrden(nodo->obtenerHijoDer());
        std::cout << nodo->obtenerDato() << " ";
    }
}

template<class T>
void ArbolAVL<T>::posOrden() {
    posOrden(raiz);
}

template<class T>
void ArbolAVL<T>::nivelOrden() {
    if (raiz == nullptr) return;

    std::queue<NodoAVL<T>*> cola;
    cola.push(raiz);

    while (!cola.empty()) {
        NodoAVL<T>* nodo = cola.front();
        cola.pop();
        std::cout << nodo->obtenerDato() << " ";

        if (nodo->obtenerHijoIzq() != nullptr)
            cola.push(nodo->obtenerHijoIzq());
        if (nodo->obtenerHijoDer() != nullptr)
            cola.push(nodo->obtenerHijoDer());
    }
}