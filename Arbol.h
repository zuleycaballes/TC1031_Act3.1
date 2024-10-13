#ifndef ARBOL_H
#define ARBOL_H

// Clase Nodo
class Nodo{
private:
    Nodo *right, *left; // Punteros a los nodos hijo derecho e izquierdo
    int dato;   // Dato almacenado en el nodo

public:
    Nodo(); // Constructor por defecto
    Nodo(int d); // Constructor que inicializa el nodo con un dato
    int getDato(); // Obtiene el dato almacenado en el nodo
    Nodo* getLeft(); // Obtiene el hijo izquierdo del nodo
    Nodo* getRight(); // Obtiene el hijo derecho del nodo
  	void setLeft(Nodo *_left); // Asigna el hijo izquierdo del nodo
  	void setRight(Nodo *_right); // Asigna el hijo derecho del nodo
    void setDato(int _dato); // Asigna el dato del nodo
    ~Nodo(); // Destructor de la clase Nodo
};
 
// Clase Arbol
class Arbol {
public:
    Nodo *raiz; // Puntero a la raíz del árbol
    Arbol(); // Constructor por defecto
    Nodo* insertarNodo(Nodo *r, int d); // Inserta un nuevo nodo en el árbol
    void preOrden(Nodo* r); // Recorre el árbol en preorden
    void inOrden(Nodo* r);  // Recorre el árbol en inorden
    void postOrden(Nodo* r); // Recorre el árbol en postorden
    void imprimirNivel(Nodo *r, int nivel); // Imprime los nodos en un nivel específico
    void nivelporNivel(Nodo *r);  // Recorre el árbol nivel por nivel
    void visit(int tipoOrden); // Despliega los datos del árbol según el orden especificado
    int height(Nodo *r); // Calcula la altura del árbol
    void ancestors(Nodo *r, int value); // Imprime los ancestros de un nodo con el valor especificado
    int whatlevelamIrecursivo(Nodo* nodo, int dato); // Calcula el nivel de un nodo
    int whatlevelamI(int value);  //Imprime el nivel del nodo 
    ~Arbol(); // Destructor de la clase Arbol
};


#endif