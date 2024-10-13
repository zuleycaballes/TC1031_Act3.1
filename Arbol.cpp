#include "Arbol.h"
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

// Definición del constructor por defecto de la clase Nodo
Nodo::Nodo(){
    right = left = nullptr;
}

// Definición del constructor que recibe un dato
Nodo::Nodo(int d){
    dato = d;
    right = left = nullptr;
}

// Obtener datos
int Nodo::getDato(){
    return dato;
}

// Obtener nodo izquierdo  
Nodo* Nodo::getLeft(){
    return left;
}

// Obtener nodo derecho   
Nodo* Nodo::getRight(){
    return right;
}

// Establecer nodo izquierdo
void Nodo::setLeft(Nodo *_left){
    left = _left;
}

// Establecer nodo derecho
void Nodo::setRight(Nodo *_right){
    right = _right;
}

// Establecer datos
void Nodo::setDato(int _dato){
    dato = _dato;
}

// Destructor de la clase Nodo
Nodo::~Nodo(){}

// Constructor de la clase Arbol
Arbol::Arbol(){
    raiz = nullptr;
}

// Complejidad del peor caso: O(n) 
// Donde n es la altura del árbol.
// En el peor caso, el árbol está completamente desbalanceado (lista ligada), 
// lo que significa que n puede ser igual al número de nodos.
// Método para insertar un nodo en el árbol
Nodo* Arbol::insertarNodo(Nodo *r, int d){
    if (r == nullptr) {
        r = new Nodo(d);
    } else if(d < r->getDato()) {
        r->setLeft(insertarNodo(r->getLeft(),d));
    } else if(d > r->getDato()) {
        r->setRight(insertarNodo(r->getRight(),d));
    } else {
        cout << "ERROR. Solo puede existir una vez el valor." << endl;
    }
    return r;
}

// Destructor de la clase Arbol
Arbol::~Arbol(){}

// Complejidad del peor caso: O(n) 
// Donde n es el número de nodos. En el peor caso, el recorrido debe visitar cada nodo.
// Método para realizar el recorrido en preorden
void Arbol::preOrden(Nodo *r){
    if (r != nullptr){
        cout << r->getDato() << ", ";
        preOrden(r->getLeft());
        preOrden(r->getRight());
    }
}

// Complejidad del peor caso: O(n) 
// Método para realizar el recorrido en inorden
void Arbol::inOrden(Nodo *r){
    if (r != nullptr){
        inOrden(r->getLeft());
        cout << r->getDato() << ", ";
        inOrden(r->getRight());
    }
}

// Complejidad del peor caso: O(n) 
// Método para realizar el recorrido en postorden  		
void Arbol::postOrden(Nodo *r){
    if (r != nullptr){
        postOrden(r->getLeft());
        postOrden(r->getRight());
        cout << r->getDato() << ", ";
    }
}

// Complejidad del peor caso: O(n)
// Hay que recorrer todos los nodos.
// Método para imprimir los nodos de un nivel específico
void Arbol::imprimirNivel(Nodo *r, int nivel){
    if (r == nullptr){
        return;
    }
    if (nivel == 0) {
        cout << r->getDato() << " ";
    } else if (nivel > 0){
        imprimirNivel(r->getLeft(),nivel-1);
        imprimirNivel(r->getRight(),nivel-1);
    }
}

// Complejidad del peor caso: O(n)
// Debe recorrer todos los niveles del árbol hasta la altura máxima.
// Método para recorrer el árbol por niveles
void Arbol::nivelporNivel(Nodo *r){
    int altura = height(r);
    if (r != nullptr) {
        for (int i = 0; i < altura; i++) {
            imprimirNivel(r, i);
            cout << endl;
        }
    }
}

// Complejidad del peor caso: O(n) 
// El recorrido depende del número de nodos en el árbol.
// Método para realizar el recorrido basado en la opción seleccionada
void Arbol::visit(int tipoOrden) {
    Nodo *raiz = this->raiz;
    switch(tipoOrden) {
        case 1:
            cout << "\nRecorrido PreOrder: \n";
            preOrden(raiz);
            cout << endl;
            break;
        case 2:
            cout << "\nRecorrido InOrder: \n";
            inOrden(raiz);
            cout << endl;
            break;
        case 3:
            cout << "\nRecorrido PostOrder: \n";
            postOrden(raiz);
            cout << endl;
            break;
        case 4:
            cout << "\nRecorrido Nivel por Nivel: \n";
            nivelporNivel(raiz);
            cout << endl;
            break;
        default:
            cout << "\nElemento no válido. Ingrese un número entre 1 y 4.\n";
            break;
    }
}

// Complejidad del peor caso: O(n)
// La función recorre todo el árbol para calcular la altura.
// Método para calcular la altura del árbol
int Arbol::height(Nodo* r) {
    if (r == nullptr) return 0;
    int leftHeight = height(r->getLeft());
    int rightHeight = height(r->getRight());
    return 1 + max(leftHeight, rightHeight);
}

// Complejidad del peor caso: O(n)
// Si el árbol está desbalanceado, puede tener que recorrer todos los nodos para encontrar los ancestros.
// Método para mostrar los ancestros de un nodo
void Arbol::ancestors(Nodo *r, int value) {
    if (r == nullptr) return;

    if (r->getDato() == value) {
        return;
    }

    if (value < r->getDato()) {
        cout << r->getDato() << " ";
        ancestors(r->getLeft(), value);
    } else {
        cout << r->getDato() << " ";
        ancestors(r->getRight(), value);
    }
}

// Complejidad del peor caso: O(n)
// En el peor caso, el dato está al final de una rama y hay que recorrer todos los niveles.
// Método recursivo para encontrar el nivel de un nodo
int Arbol::whatlevelamIrecursivo(Nodo* nodo, int dato){
    if (nodo == nullptr){
        return -1;
    }
    if (nodo->getDato() == dato){
        return 0;
    } 

    int nivelIzquierdo = whatlevelamIrecursivo(nodo->getLeft(), dato);
    if (nivelIzquierdo != -1) {
        return nivelIzquierdo + 1;
    }

    int nivelDerecho = whatlevelamIrecursivo(nodo->getRight(), dato);
    if (nivelDerecho != -1) {
        return nivelDerecho + 1;
    }

    return -1;
}

// Complejidad del peor caso: O(n)
// Debe buscar el dato en todo el árbol, lo que en el peor caso (árbol desbalanceado) puede ser O(n).
// Método para determinar el nivel de un nodo
int Arbol::whatlevelamI(int dato){
    return whatlevelamIrecursivo(raiz, dato);
}