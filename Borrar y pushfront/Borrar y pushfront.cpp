#include <iostream>
using namespace std;

class Lista
{
private:
    struct nodo
    {
        int valor;
        nodo* anterior;
        nodo* siguiente;
    };

    nodo* aux = nullptr;
    nodo* primero = nullptr;
    nodo* ultimo = nullptr;
    int cant_nodos = 0;

public:
    Lista() {};

    void pushback(int n)
    {
        if (primero == nullptr)
        {
            primero = new nodo();
            ultimo = new nodo();

            primero->valor = n;
            primero->anterior = nullptr;
            primero->siguiente = nullptr;

            ultimo = primero;
        }

        else
        {
            aux = new nodo;

            aux->valor = n;
            aux->anterior = ultimo;
            aux->siguiente = nullptr;

            ultimo->siguiente = aux;
            ultimo = aux;
        }

        cant_nodos++;
    };

    void pushfront(int n)
    {
        if (primero == nullptr)
        {
            primero = new nodo;
            ultimo = new nodo;

            primero->valor = n;
            primero->anterior = nullptr;
            primero->siguiente = nullptr;

            ultimo = primero;
        }

        else
        {
            aux = new nodo;

            aux->valor = n;
            aux->siguiente = primero;
            aux->anterior = nullptr;

            primero->anterior = aux;
            primero = aux;
        };

        cant_nodos++;
    };

    void imprimir()
    {
        aux = primero;
        while (aux != nullptr)
        {
            cout << aux->valor << "-> ";
            aux = aux->siguiente;
        };

        cout << endl << "Primero: " << primero->valor << endl;

        cout << "Ultimo: " << ultimo->valor << endl;

        cout << "Cantidad nodos: " << cant_nodos << endl;
    };

    bool buscar(int num)
    {
        aux = new nodo;
        aux = primero;
        while (aux != nullptr)
        {
            if (aux->valor = num)
            {
                return true;
            };
            aux = aux->siguiente;
        };
        return false;
    };

    void insertar(int pos, int n)
    {
        if (pos == 0)
        {
            /*aux = new nodo;
            aux->valor = n;
            aux->anterior = nullptr;
            aux->siguiente = primero;

            primero->anterior = aux;
            primero = aux;
            cant_nodos++;*/
            pushfront(n);//reemplazado con un pushfront
        }
        else if (pos > cant_nodos)
        {
            pushback(n);
        }
        else
        {
            nodo* actual = new nodo;
            actual = primero;//creamos un nodo para navegar y hacer los cambios
            int index = 0;//contador para el bucle
            while (index < pos)
            {
                actual = actual->siguiente;
                index++;
            };


            aux = new nodo;//nuevo
            aux->valor = n;
            aux->siguiente = actual;//el siguiente del nuevo será el actual
            aux->anterior = actual->anterior; //el anterior del nuevo será el anterior del actual

            if (actual->anterior != nullptr)
            {
                actual->anterior->siguiente = aux; //el siguiente del anterior (del actual) será el nuevo
            };

            actual->anterior = aux; //el anterior del actual será el nuevo
            cant_nodos++;
        };

    };

    void eliminar(int pos)
    {
        if (pos == 0)
        {
            nodo* actual = new nodo;
            actual = primero;
            primero = primero->siguiente;
            primero->anterior = nullptr;

            
            delete actual;
            
        }
        else if (pos >= cant_nodos)
        {
            nodo* actual = new nodo;
            actual = ultimo;
            ultimo = ultimo->anterior;
            ultimo->siguiente = nullptr;

            delete actual;
            
        }
        else
        {
            nodo* actual = new nodo;
            actual = primero;
            int index = 0;

            while (index < pos)
            {
                actual = actual->siguiente;
                index++;
            };

            //hacemos la desconexion antes de borrar
            actual->anterior->siguiente = actual->siguiente; //el siguiente del anterior del actual será el anterior del siguiente del actual
            actual->siguiente->anterior = actual->anterior;  //el anterior del siguiente del actual será el anterior del actual

            delete actual;//borramos

        };
        cant_nodos--;
    };
};


int main()
{
    Lista test;
    test.pushback(1);
    test.pushback(2);

    test.pushback(3);
    test.pushfront(4);
    test.insertar(0, 6);
    test.pushfront(8);
    test.insertar(50, 40);

    test.insertar(3, 100);
    
    test.eliminar(0);
    test.eliminar(10);
    test.eliminar(3);
    
    test.pushfront(7);
    test.pushfront(10);
    test.pushback(5);

    test.imprimir();

    if (test.buscar(3) == true)
    {
        cout << "zi";
    }
    else
    {
        cout << "no";
    };
     
}

/*
========================================================================================================================
  MMP""MM""YMM `7MM"""Mq.  `YMM'   `MM'    `7MMF'  `7MMF'      db      `7MM"""Mq.  `7MM"""Yb.   `7MM"""YMM  `7MM"""Mq.
  P'   MM   `7   MM   `MM.   VMA   ,V        MM      MM       ;MM:       MM   `MM.   MM    `Yb.   MM    `7    MM   `MM.
       MM        MM   ,M9     VMA ,V         MM      MM      ,V^MM.      MM   ,M9    MM     `Mb   MM   d      MM   ,M9
       MM        MMmmdM9       VMMP          MMmmmmmmMM     ,M  `MM      MMmmdM9     MM      MM   MMmmMM      MMmmdM9
       MM        MM  YM.        MM           MM      MM     AbmmmqMA     MM  YM.     MM     ,MP   MM   Y  ,   MM  YM.
       MM        MM   `Mb.      MM           MM      MM    A'     VML    MM   `Mb.   MM    ,dP'   MM     ,M   MM   `Mb.
     .JMML.    .JMML. .JMM.   .JMML.       .JMML.  .JMML..AMA.   .AMMA..JMML. .JMM..JMMmmmdP'   .JMMmmmmMMM .JMML. .JMM.
==========================================================================================================================
*/
