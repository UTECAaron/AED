/*
    PREDICCION 1: Editor de texto (Doubly Linked List + cursor)

    Enunciado:
    Tienes un editor de texto simple representado como una lista doblemente
    enlazada de caracteres, con un cursor que apunta a una posicion entre dos
    caracteres (o al inicio/final). Procesa q operaciones:

      - L        : mueve el cursor una posicion a la izquierda.
      - R        : mueve el cursor una posicion a la derecha.
      - INS c    : inserta el caracter c justo a la izquierda del cursor.
      - DEL      : borra el caracter inmediatamente a la izquierda del
                   cursor (si no hay caracter a la izquierda, ignora).

    Al final, imprime el contenido completo del editor.

    Limites: 1 <= q <= 5*10^5.

    Idea clave:
    El cursor se representa como un puntero al nodo INMEDIATAMENTE a la
    derecha del cursor (nullptr si el cursor esta al final de todo).
    Insertar y borrar son operaciones O(1) porque solo se reconectan
    punteros prev/next alrededor del cursor.
*/
#include<iostream>
using namespace::std;

template<typename data_type>
struct DoublyLinkedNode {
    data_type data;
    DoublyLinkedNode* next;
    DoublyLinkedNode* prev;
    DoublyLinkedNode() { next = prev = nullptr; }
    DoublyLinkedNode(data_type data, DoublyLinkedNode<data_type>* next = nullptr,
                      DoublyLinkedNode<data_type>* prev = nullptr) : data(data), next(next), prev(prev) {}
};

template<typename data_type>
struct DoublyLinkedList {
    DoublyLinkedNode<data_type>* head;
    DoublyLinkedNode<data_type>* tail;
    DoublyLinkedNode<data_type>* cursor; // nodo inmediatamente a la derecha del cursor (nullptr = al final)

    DoublyLinkedList() { head = tail = cursor = nullptr; }

    void moveLeft() {
        if (cursor == head) return; // ya esta al inicio
        cursor = (cursor == nullptr) ? tail : cursor -> prev;
    }

    void moveRight() {
        if (cursor == nullptr) return; // ya esta al final
        cursor = cursor -> next;
    }

    void insertChar(data_type c) {
        DoublyLinkedNode<data_type>* new_node = new DoublyLinkedNode<data_type>(c, cursor);
        DoublyLinkedNode<data_type>* left = (cursor == nullptr) ? tail : cursor -> prev;
        new_node -> prev = left;
        if (left != nullptr) left -> next = new_node; else head = new_node;
        if (cursor != nullptr) cursor -> prev = new_node; else tail = new_node;
    }

    void deleteChar() {
        DoublyLinkedNode<data_type>* target = (cursor == nullptr) ? tail : cursor -> prev;
        if (target == nullptr) return; // no hay nada a la izquierda del cursor
        DoublyLinkedNode<data_type>* left = target -> prev;
        if (left != nullptr) left -> next = cursor; else head = cursor;
        if (cursor != nullptr) cursor -> prev = left; else tail = left;
        delete target;
    }

    void print() {
        for (DoublyLinkedNode<data_type>* cur = head; cur != nullptr; cur = cur -> next) cout << cur -> data;
        cout << '\n';
    }
};

int main() {
    cin.tie(0) -> sync_with_stdio(false);
    int q;
    cin >> q;
    DoublyLinkedList<char> L;
    for (int i = 0; i < q; ++i) {
        string op;
        cin >> op;
        if (op == "L") L.moveLeft();
        else if (op == "R") L.moveRight();
        else if (op == "DEL") L.deleteChar();
        else { // INS c
            char c;
            cin >> c;
            L.insertChar(c);
        }
    }
    L.print();
    return 0;
}
