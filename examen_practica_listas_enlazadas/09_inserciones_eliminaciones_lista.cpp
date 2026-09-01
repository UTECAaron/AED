/*
    PREDICCION 9: Version "lista enlazada real" del examen viejo (Doubly Linked List)

    Enunciado (variante esperada del problema A del examen anterior, pero
    ahora obligando a usar una lista enlazada real en vez de shiftear un
    arreglo):

    Tienes una lista de elementos, inicialmente vacia. Procesa q
    operaciones:
      - INS pos val : inserta val de forma que quede en la posicion pos
                      (0-indexado), desplazando el resto.
      - DEL pos     : elimina el elemento en la posicion pos.

    Al final, imprime la lista resultante.

    Limites: 1 <= q <= 5*10^5, 0 <= pos <= tamano actual, 0 <= val <= 10^9.

    Idea clave:
    Aunque "insertar en la posicion pos" suena a arreglo, se implementa
    con una lista doblemente enlazada: se camina desde el extremo mas
    cercano (head o tail, el que este mas cerca de pos) para llegar en
    O(min(pos, n-pos)) en vez de O(n) siempre, y luego la insercion /
    eliminacion en si es O(1) con punteros.
*/
#include<iostream>
using namespace::std;

template<typename data_type>
struct DoublyLinkedNode {
    data_type data;
    DoublyLinkedNode* next;
    DoublyLinkedNode* prev;
    DoublyLinkedNode(data_type data, DoublyLinkedNode* next = nullptr, DoublyLinkedNode* prev = nullptr)
        : data(data), next(next), prev(prev) {}
};

template<typename data_type>
struct DoublyLinkedList {
    DoublyLinkedNode<data_type>* head;
    DoublyLinkedNode<data_type>* tail;
    int size;
    DoublyLinkedList() { head = tail = nullptr; size = 0; }

    // Devuelve el nodo que actualmente esta en la posicion pos (0-indexado)
    DoublyLinkedNode<data_type>* nodeAt(int pos) {
        if (pos <= size / 2) {
            DoublyLinkedNode<data_type>* cur = head;
            for (int i = 0; i < pos; ++i) cur = cur -> next;
            return cur;
        } else {
            DoublyLinkedNode<data_type>* cur = tail;
            for (int i = size - 1; i > pos; --i) cur = cur -> prev;
            return cur;
        }
    }

    void insertAt(int pos, data_type val) {
        if (pos == size) { // insertar al final
            DoublyLinkedNode<data_type>* new_node = new DoublyLinkedNode<data_type>(val, nullptr, tail);
            if (tail) tail -> next = new_node; else head = new_node;
            tail = new_node;
        } else {
            DoublyLinkedNode<data_type>* Y = nodeAt(pos); // el que va a quedar justo despues
            DoublyLinkedNode<data_type>* left = Y -> prev;
            DoublyLinkedNode<data_type>* new_node = new DoublyLinkedNode<data_type>(val, Y, left);
            Y -> prev = new_node;
            if (left) left -> next = new_node; else head = new_node;
        }
        ++size;
    }

    void deleteAt(int pos) {
        DoublyLinkedNode<data_type>* target = nodeAt(pos);
        DoublyLinkedNode<data_type>* left = target -> prev;
        DoublyLinkedNode<data_type>* right = target -> next;
        if (left) left -> next = right; else head = right;
        if (right) right -> prev = left; else tail = left;
        delete target;
        --size;
    }

    void print() {
        for (DoublyLinkedNode<data_type>* cur = head; cur != nullptr; cur = cur -> next)
            cout << cur -> data << (cur -> next ? ' ' : '\n');
        if (head == nullptr) cout << '\n';
    }
};

int main() {
    cin.tie(0) -> sync_with_stdio(false);
    int q;
    cin >> q;
    DoublyLinkedList<int> L;
    for (int i = 0; i < q; ++i) {
        string op;
        cin >> op;
        int pos;
        cin >> pos;
        if (op == "INS") {
            int val;
            cin >> val;
            L.insertAt(pos, val);
        } else { // DEL
            L.deleteAt(pos);
        }
    }
    L.print();
    return 0;
}
