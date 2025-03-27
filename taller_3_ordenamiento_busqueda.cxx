/*
  --------------------------------
  Taller 3: Comparación de árboles
  --------------------------------
  Clase de Estructuras de Datos
  Modificado por: Ing. Alejandro Castro Martinez
  Pontificia Universidad Javeriana
  Bogotá, Colombia
*/

/*
  ================================
  Include de las librerías estándar
  ================================
*/
#include <ctime>
#include <iostream>
#include <fstream>
#include <string>

#include <list>

#include <algorithm>

/*
  =================================
  Include de la implementación propia
  =================================
*/
// TODO #01: Incluir cabecera de la implementación propia del árbol AVL
// #include "arbolAVL.h"

// TODO #07: Incluir cabecera de la STL correspondiente al árbol rojinegro
#include "ArbolRN.h"

// TODO #13: Incluir cabecera de la STL correspondiente al montículo

/*
  ================================
  Definiciones de tipos de datos
  ================================
*/
typedef std::list<std::string> TList;

// TODO #02: Definir árbol AVL de tipo std::string
// typedef arbolAVL< std::string > TAVL;

// TODO #08: Definir árbol rojinegro de tipo std::string
typedef ArbolRN<std::string> TRN;

// TODO #14: Definir Montículo de tipo std::string
// typedef std::XXXXXX< std::string > THeap;

/*
  ================================
  Prototipos de función genérica
  para el llenado de los árboles
  ================================
*/
template <class TArbol>
bool LeerArbol(TArbol &arbol, const std::string &nomArch);

/*
  ================================
  Función principal
  ================================
  - Parámetros para la ejecución:
    - argv[ 1 ]: nombre del archivo con las operaciones
*/
int main(int argc, char *argv[])
{
  /*
    Verificar que se haya pasado un archivo de entrada
  */
  if (argc < 2)
  {
    std::cerr << "Uso: " << argv[0] << " archivo_entrada" << std::endl;
    return (-1);
    
  } // End if

  /*
    =============================================
    Declarar e inicializar los árboles a utilizar
    =============================================
  */

  // Declarar variable tipo árbol AVL
  // TODO #03: Definir variable tipo árbol AVL.

  // Declarar variable tipo árbol rojinegro
  // TODO #09: Definir variable tipo árbol rojinegro.
  TRN miArbolRN;

  // Declarar variable tipo Montículo
  // TODO #15: Definir variable tipo Montículo.
  // XXXX miMonticulo;

  /*
    +++++++++++++++++++++++++++++++++++++++++++++++++++++++
    Llenar el árbol AVL y calcular el tiempo empleado
    +++++++++++++++++++++++++++++++++++++++++++++++++++++++
  */
  std::clock_t inicioLecturaAVL = std::clock();
  // TODO #04: Usar el archivo para llenar el árbol AVL a través del uso de la función genérica provista para ello.
  // bool lecturaAVL = LeerArbol( miArbolAVL, argv[ 1 ] );
  std::clock_t finLecturaAVL = std::clock();
  double tiempoLecturaAVL = (finLecturaAVL - inicioLecturaAVL) / double(CLOCKS_PER_SEC);
  // TODO #05: Informar tiempo de llenado del árbol AVL dado que la ejecución de la función de llenado sea exitosa.
  /*
     if( lecturaAVL )
     std::cout
        << "Tiempo de llenado arbol AVL = "
        << tiempoLecturaAVL << "segs."
        << std::endl;
     else
     std::cout
        << "Error al leer \"" << argv[ 1 ]
        << "\" para llenar el arbol AVL."
        << std::endl;
  */

  /*
     +++++++++++++++++++++++++++++++++++++++++++++++++++++++
     Llenar el árbol rojinegro y calcular el tiempo empleado
     +++++++++++++++++++++++++++++++++++++++++++++++++++++++
   */
  std::clock_t inicioLecturaRN = std::clock();
  // TODO #10: Usar el archivo para llenar el árbol rojinegro a través del uso de la función genérica provista para ello.
  bool lecturaRN = LeerArbol(miArbolRN, argv[1]);
  std::clock_t finLecturaRN = std::clock();
  double tiempoLecturaRN = (finLecturaRN - inicioLecturaRN) / double(CLOCKS_PER_SEC);
  // TODO #11: Informar tiempo de llenado del árbol rojinegro dado que la ejecución de la función de llenado sea exitosa.
  
    if (lecturaRN)
      std::cout
          << "Tiempo de llenado arbol RN = "
          << tiempoLecturaRN << "segs."
          << std::endl;
    else
      std::cout
          << "Error al leer \"" << argv[1]
          << "\" para llenar el arbol RN."
          << std::endl;
  

  /*
     +++++++++++++++++++++++++++++++++++++++++++++++++++++++
     Llenar el montículo y calcular el tiempo empleado
     +++++++++++++++++++++++++++++++++++++++++++++++++++++++
   */
  std::clock_t inicioLecturaHeap = std::clock();
  // TODO #16: Usar el archivo para llenar el montículo a través del uso de la función genérica provista para ello.
  // bool lecturaHeap = LeerArbol(miArbolHeap, argv[1]);
  std::clock_t finLecturaHeap = std::clock();
  double tiempoLecturaHeap = (finLecturaHeap - inicioLecturaHeap) / double(CLOCKS_PER_SEC);
  // TODO #17: Informar tiempo de llenado del montículo dado que la ejecución de la función de llenado sea exitosa.
  /*
    if (lecturaHeap)
      std::cout
          << "Tiempo de llenado montículo = "
          << tiempoLecturaHeap << "segs."
          << std::endl;
    else
      std::cout
          << "Error al leer \"" << argv[1]
          << "\" para llenar el montículo."
          << std::endl;
  */

  /*
    =============================================
    Comparar los árboles y mostrar el resultado
    =============================================
  */
  // Obtener el recorrido en inorden del arbol AVL
  TList inordenAVL, inordenRN, inordenHeap;
  // TODO #06: Llamar la función que genera el recorrido en inorden del árbol AVL y lo guarda en una lista dada como parámetro.
  // miArbolAVL.inordenEnLista( inordenAVL );

  // TODO #12: Llamar la función que genera el recorrido en inorden del árbol rojinegro y lo guarda en una lista dada como parámetro.
  miArbolRN.inordenEnLista( inordenRN );

  // TODO #18: Llamar la función que genera el recorrido en inorden del montículo y lo guarda en una lista dada como parámetro.
  // miMonticulo.inordenEnLista( inordenHeap );

  /*
    ===============================================================
    Verificar que los arboles tengan la misma cantidad de elementos
    ===============================================================
  */

  // Obtener el tamaño de los distintos arboles
  size_t sizeAVL = inordenAVL.size();
  size_t sizeRN = inordenRN.size();
  size_t sizeHeap = inordenHeap.size();

  // Calcular cual de las estructuras tiene menos elementos
  size_t minSize = std::min({sizeAVL, sizeRN, sizeHeap});
  
  // Informar si las estructuras tienen la misma cantidad de elementos
  if (sizeAVL == sizeRN && sizeRN == sizeHeap)
  {
    std::cout << "Las tres estructuras tienen la misma cantidad de elementos." << std::endl;
  }
  else
  {
    // Informar cual es la estructura con menos elementos
    std::cout << "La estructura con menos elementos es: ";
    if (sizeAVL == minSize)
      std::cout << "AVL ";
    if (sizeRN == minSize)
      std::cout << "Árbol Rojo-Negro ";
    if (sizeHeap == minSize)
      std::cout << "Heap ";
    std::cout << "con " << minSize << " elementos." << std::endl;
  }
  
  /*
    ===============================================================
    Comparar los elementos y su posición de cada uno de los árboles
    ===============================================================
  */
  // TODO #19: Crear iteradores para recorrer cada una de las estructuras lineales 
  
  // TODO #20: Recorrer las estructuras lineales y comparar elemento a elemento la igualdad o desigualdad

  // TODO #21: Informar si los árboles coinciden en la totalidad de los elementos teniendo en cuenta su posición

  return (0);
}

/*
  ===============================================================
  Función genérica para leer del archivo los datos para ser 
  insertados en las distintas estructuras de datos
  ===============================================================
*/
template <class TArbol>
bool LeerArbol(TArbol &arbol, const std::string &nomArch)
{
  // Verificar que el archivo exista
  std::ifstream entrada(nomArch.c_str());
  // Verificar que el archivo se haya abierto correctamente
  if (!entrada)
    return (false);
  // Leer el archivo
  while (!entrada.eof())
  {
    // Leer el código y el valor
    std::string codigo, valor;
    entrada >> codigo >> valor;
    if (codigo == "add")
      arbol.insert(valor); // El arbol debe proveer el metodo "insert"
    else if (codigo == "del")
      arbol.erase(valor); // El arbol debo proveer el metodo "erase"

  } // End while
  // Cerrar el archivo
  entrada.close();
  // Retornar que la lectura fue exitosa
  return (true);
}

// eof - taller_3_ordenamiento_busqueda.cxx
