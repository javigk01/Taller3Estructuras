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
// TODO #01: Incluir cabecera de la implementación propia del árbol AVL
#include "ArbolAVL.h"

typedef std::list<std::string> TList;
// TODO #02: Definir árbol AVL de tipo std::string
typedef ArbolAVL<std::string> TAVL;

template <class TArbol>
bool LeerArbol(TArbol &arbol, const std::string &nomArch);

int main(int argc, char *argv[]) {
    // Verificar archivo de entrada
    if (argc < 2) {
        std::cerr << "Uso: " << argv[0] << " archivo_entrada" << std::endl;
        return -1;
    }

    // Declarar árbol AVL
    // TODO #03: Definir variable tipo árbol AVL.
    TAVL miArbolAVL;

    // Medir tiempo de llenado
    std::clock_t inicio = std::clock();
    // TODO #04: Usar el archivo para llenar el árbol AVL a través del uso de la función genérica provista para ello.
    bool exito = LeerArbol(miArbolAVL, argv[1]);
    std::clock_t fin = std::clock();
    
    double tiempo = (fin - inicio) / double(CLOCKS_PER_SEC);

    // Mostrar resultados
    if (exito) {
     // TODO #05: Informar tiempo de llenado del árbol AVL dado que la ejecución de la función de llenado sea exitosa.
        std::cout << "Tiempo de llenado AVL: " << tiempo << " segundos" << std::endl;
    } else {
        std::cout << "Error al leer el archivo" << std::endl;
        return -1;
    }

// Generar recorrido inorden
TList inorden;
// TODO #06: Llamar la función que genera el recorrido en inorden del árbol AVL y lo guarda en una lista dada como parámetro. 
miArbolAVL.inordenLista(inorden);
std::cout << "Elementos en arbol AVL: " << inorden.size() << std::endl;

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