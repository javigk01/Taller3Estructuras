/*
  --------------------------------
  Taller 3: Comparación de árboles
  --------------------------------
  Clase de Estructuras de Datos
  Modificado por: Juan Esteban Díaz Toledo
  Pontificia Universidad Javeriana
  Bogotá, Colombia
*/

#include <ctime>
#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <set>
#include <queue>

// TODO #01: Incluir cabecera de la implementación propia del árbol AVL
#include "ArbolAVL.h"
// TODO #13: Incluir cabecera de la STL correspondiente al montículo
#include "Monticulo.h"

typedef std::list<std::string> TList;
// TODO #02: Definir árbol AVL de tipo std::string
typedef ArbolAVL<std::string> TAVL;
// TODO #14: Definir Montículo de tipo std::string
typedef Monticulo<std::string, std::greater<std::string>> TMonticulo;

template <class TArbol>
bool LeerArbol(TArbol &arbol, const std::string &nomArch);

int main(int argc, char *argv[]) {
    // Verificar archivo de entrada
    if (argc < 2) {
        std::cerr << "Uso: " << argv[0] << " archivo_entrada" << std::endl;
        return -1;
    }

    // ========== PARTE 1: ÁRBOL AVL ==========
    TAVL miArbolAVL;

    std::clock_t inicioAVL = std::clock();
    bool exitoAVL = LeerArbol(miArbolAVL, argv[1]);
    std::clock_t finAVL = std::clock();
    
    double tiempoAVL = (finAVL - inicioAVL) / double(CLOCKS_PER_SEC);

    if (exitoAVL) {
        std::cout << "Tiempo de llenado AVL: " << tiempoAVL << " segundos" << std::endl;
    } else {
        std::cout << "Error al leer el archivo para AVL" << std::endl;
        return -1;
    }

    TList inordenAVL;
    miArbolAVL.inordenLista(inordenAVL);
    std::cout << "Elementos en arbol AVL: " << inordenAVL.size() << std::endl;

    // ========== PARTE 3: MONTÍCULO ==========
    // TODO #15: Definir variable tipo Montículo.
    TMonticulo miMonticulo;

    std::clock_t inicioHeap = std::clock();
    // TODO #16: Usar el archivo para llenar el montículo
    bool exitoHeap = LeerArbol(miMonticulo, argv[1]);
    std::clock_t finHeap = std::clock();
    
    double tiempoHeap = (finHeap - inicioHeap) / double(CLOCKS_PER_SEC);

    // TODO #17: Informar tiempo de llenado del montículo
    if (exitoHeap) {
        std::cout << "\nTiempo de llenado Monticulo: " << tiempoHeap << " segundos" << std::endl;
    } else {
        std::cout << "\nError al leer el archivo para Monticulo" << std::endl;
        return -1;
    }

    TList inordenHeap;
    // TODO #18: Llamar la función que genera el recorrido en inorden del montículo
    miMonticulo.inordenLista(inordenHeap);
    std::cout << "Elementos en monticulo: " << inordenHeap.size() << std::endl;

    return 0;
}

template <class TArbol>
bool LeerArbol(TArbol &arbol, const std::string &nomArch) {
    std::ifstream archivo(nomArch);
    if (!archivo) return false;

    std::string operacion, codigo;
    while (archivo >> operacion >> codigo) {
        if (operacion == "add") {
            arbol.insertar(codigo);
        } else if (operacion == "del") {
            arbol.eliminar(codigo);
        }
    }

    archivo.close();
    return true;
}