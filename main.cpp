#include <iostream>
#include <stdio.h>
using namespace std;

typedef struct _nodo {
    float valor;
    struct _nodo *siguiente;
    struct _nodo *anterior;
} tipoNodo;

typedef tipoNodo *pNodo;
typedef tipoNodo *Lista;

/* Funciones con listas: */
void InsertarINICIO(Lista *l, float v);

void BorrarLista(Lista *);

void MostrarLista(Lista l);

void InsertarFINAL(Lista *l, float valor);

void Insertar_POS(Lista *l, float valor, int pos);

void MayorElemento(Lista l);

void SumarDatos(Lista lista);

void ListaOrdenada(Lista lista);

void IntercambiarNodos(Lista *l, int pos1, int pos2);

int main() {

    Lista lista = NULL;
    pNodo p;

    float valor;
    int op;

    do{
        cout<<"\n<< PROGRAMA PARA MAINPULAR LISTAS >>";
        cout<<"\n** Seleccione una opción del menu [0-9] **";
        cout<<"\n[ 1 ] Mostrar la lista";
        cout<<"\n[ 2 ] Insertar un elemento al INICIO de la lista";
        cout<<"\n[ 3 ] Insertar un elemento al FINAL de la lista";
        cout<<"\n[ 4 ] Insertar un elemento en una POSICION elegida por el usuario";
        cout<<"\n[ 5 ] Calculo del MAYOR de los elementos y cuantas veces se REPITE";
        cout<<"\n[ 6 ] SUMA de todos los datos de la lista";
        cout<<"\n[ 7 ] Comprobar si la lista está ORDENADA";
        cout<<"\n[ 8 ] ELIMINAR todas las OCURRENCIAS de un elemento dado de la lista";
        cout<<"\n[ 9 ] INVERTIR la lista";
        cout<<"\n[ 10 ] INTERCAMBIAR 2 nodos DADOS en la lista";
        cout<<"\n[ 0 ] SALIR";
        cout<<"\nIngrese su opción :",cin>>op;
        switch (op){
            case 1:
                MostrarLista(lista);
                break;
            case 2:
                cout<<"\nInsertar valor: ",cin>>valor;
                InsertarINICIO(&lista, valor);
                break;
            case 3:
                cout<<"\nInsertar valor: ",cin>>valor;
                InsertarFINAL(&lista, valor);
                break;
            case 4:
                int pos;
                cout<<"\nPosición de la lista: ",cin>>pos;
                cout<<"\nInsertar valor: ",cin>>valor;
                Insertar_POS(&lista, valor, pos);
                break;
            case 5:
                MayorElemento(lista);
                break;
            case 6:
                SumarDatos(lista);
                break;
            case 7:
                ListaOrdenada(lista);
                break;
            case 8:
                BorrarLista(&lista);
                break;
            case 9:
                int pos1, pos2;
                cout<<"\nPosición 1 de la lista: ",cin>>pos1;
                cout<<"\nPosición 2 de la lista: ",cin>>pos2;
                IntercambiarNodos(&lista, pos1, pos2);
                break;
            case 10:
                break;
        }
    }while(op!=0);
    cout<<"\n FIN DEL PROGRAMA";


    return 0;
}

void IntercambiarNodos(Lista *l, int pos1, int pos2) {
    pNodo actual= *l;

    pNodo posicion1;
    pNodo posicion2;

    pNodo principio;
    pNodo intermedio;
    pNodo final;


    if(!actual){
        printf("Lista vacía"); //Si no hay valores
    }
    else{
        while(actual->anterior) actual = actual->anterior; //empezar de nuevo
        for (int i = 0 ; i < pos1; i++){
            actual = actual->siguiente;
        }
        posicion1 = actual;
        while(actual->anterior) actual = actual->anterior; //empezar de nuevo
        for (int i = 0 ; i < pos2; i++){
            actual = actual->siguiente;
        }
        posicion2 = actual;
        principio = posicion1 -> anterior;
        intermedio = posicion1 -> siguiente;
        final = posicion2 -> siguiente;
    }
}

void ListaOrdenada(Lista lista) {
    pNodo nodo;
    float valor;
    bool orden;

    if(!lista){
        printf("Lista vacía"); //Si no hay valores
    }
    else{
        nodo = lista;
        while(nodo->anterior) nodo = nodo->anterior; //empezar de nuevo

        do {
            valor = nodo -> valor;
            if(nodo -> siguiente){
                if(valor <= nodo -> siguiente -> valor){
                    orden = true;
                }
                else{
                    orden = false;
                }
            }
            nodo = nodo->siguiente;
        }while (nodo && orden);

        if(orden){
            printf("La lista esta ordenada");
        }
        else{
            printf("La lista no esta ordenada");
        }
    }
}

void SumarDatos(Lista lista) {
    pNodo nodo;
    float sumatotal = 0;

    if(!lista){
        printf("Lista vacía"); //Si no hay valores
    }
    else{
        nodo = lista;
        while(nodo->anterior) nodo = nodo->anterior; //empezar de nuevo

        while(nodo) { //Empezar a sumar
            sumatotal = sumatotal + nodo -> valor;
            nodo = nodo->siguiente;
        }
        printf("La suma total es de: %.*f -> ", 3, sumatotal);
    }
}

void MayorElemento(Lista lista) {
    pNodo nodo;
    float mayor = 0; //Por defecto
    int repeticiones = -1;

    if(!lista){
        printf("Lista vacía"); //Si no hay valores
    }
    else{
        nodo = lista;
        while(nodo->anterior) nodo = nodo->anterior; //empezar de nuevo
        while(nodo) {
            float valor = nodo->valor;
            if(valor > mayor){
                mayor = valor;
                repeticiones = -1;
            }
            if(valor == mayor){
                repeticiones++;
            }
            nodo = nodo->siguiente;
        }
        printf("Se repite %i veces ", repeticiones);
        printf("el número mayor: %.*f -> ", 3, mayor);
    }
}

void Insertar_POS(Lista *l, float v, int pos) {
    pNodo nuevo, actual;

    /* Crear un nodo nuevo */
    nuevo = (pNodo)malloc(sizeof(tipoNodo));
    nuevo->valor = v;

    /* Copiar la lista */
    actual = *l;

    if(!actual){
        //Lista vacia
        if(!*l){
            *l = nuevo;
        }
        nuevo->siguiente = actual;
        nuevo->anterior = NULL;
    }
    if(actual){
        //Empezar de nuevo
        while(actual->anterior) actual = actual->anterior;
        //Empezar a mover posiciones
        for (int i = 0 ; i < pos; i++){
            actual = actual->siguiente;
        }
        nuevo->siguiente = actual->siguiente;
        actual->siguiente = nuevo;
        nuevo->anterior = actual;
        nuevo -> siguiente -> anterior = nuevo;
    }
}

void InsertarFINAL(Lista *l, float v) {
    pNodo nuevo, actual;

    /* Crear un nodo nuevo */
    nuevo = (pNodo)malloc(sizeof(tipoNodo));
    nuevo->valor = v;

    /* Copiar la lista */
    actual = *l;

    if(!actual){
        //Lista vacia
        if(!*l){
            *l = nuevo;
        }
        nuevo->siguiente = actual;
        nuevo->anterior = NULL;
    }

    if(actual){
        //Si tiene elementos mover al final
        while(actual->siguiente) actual = actual->siguiente;
        //insertar el nodo al principio de la lista
        nuevo->siguiente = actual->siguiente;
        actual->siguiente = nuevo;
        nuevo->anterior = actual;
    }
}

void InsertarINICIO(Lista *l, float v) {
    pNodo nuevo, actual;

    /* Crear un nodo nuevo */
    nuevo = (pNodo)malloc(sizeof(tipoNodo));
    nuevo->valor = v;

    /* copiar la lista */
    actual = *l;

    if(!actual){
        //Lista vacia
        if(!*l){
            *l = nuevo;
        }
        nuevo->siguiente = actual;
        nuevo->anterior = NULL;
    }

    if(actual){
        //Si tiene elementos mover al principio
        while(actual->anterior) actual = actual->anterior;
        //insertar el nodo al principio de la lista
        nuevo->siguiente = actual;
        nuevo->anterior = NULL;
        actual->anterior = nuevo;
    }
}

void BorrarLista(Lista *lista) {
    pNodo nodo, actual;

    actual = *lista;

    if(!actual){
        printf("Lista vacía"); //Si no hay valores
    }
    else{
        //while(actual->anterior) actual = actual->anterior;

        while(actual) {
            nodo = actual;
            //actual = actual->siguiente;
            actual = actual->anterior; //Pasar al anterior nodo antes de borrar
            delete nodo;//Eliminar el nodo seleccionado
        }
        *lista = NULL;
        printf("Todos los valores han sido borradas");
    }
}

void MostrarLista(Lista lista) {
    pNodo nodo;

    if(!lista){
        printf("Lista vacía"); //Si no hay valores
    }
    else{
        nodo = lista;
        while(nodo->anterior) nodo = nodo->anterior; //empezar de nuevo
        while(nodo) { //Empezar a imprimir
            printf("%.*f -> ", 3, nodo->valor);
            nodo = nodo->siguiente;
        }
    }

    printf("\n");
    cout<<*&lista<<endl;
    cout<<&lista<<endl;
}