/*
    PREDICCION 5: Deque (Doubly Linked List)

    Enunciado:
    Implementa un deque. Operaciones:
      - push_front x
      - push_back x
      - pop_front       (ignora si esta vacio)
      - pop_back        (ignora si esta vacio)
      - front           (imprime el primero o EMPTY)
      - back            (imprime el ultimo o EMPTY)

    Limites: 1 <= q <= 5*10^5.

    Idea clave:
    Es el ejercicio mas basico de lista doblemente enlazada: dominar
    push/pop en AMBOS extremos actualizando correctamente head y tail.
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
struct Deque {
    DoublyLinkedNode<data_type>* head;
    DoublyLinkedNode<data_type>* tail;
    Deque() { head = tail = nullptr; }

    void push_front(data_type v) {
        DoublyLinkedNode<data_type>* n = new DoublyLinkedNode<data_type>(v, head);
        if (head) head -> prev = n; else tail = n;
        head = n;
    }
    void push_back(data_type v) {
        DoublyLinkedNode<data_type>* n = new DoublyLinkedNode<data_type>(v, nullptr, tail);
        if (tail) tail -> next = n; else head = n;
        tail = n;
    }
    void pop_front() {
        if (!head) return;
        DoublyLinkedNode<data_type>* n = head;
        head = head -> next;
        if (head) head -> prev = nullptr; else tail = nullptr;
        delete n;
    }
    void pop_back() {
        if (!tail) return;
        DoublyLinkedNode<data_type>* n = tail;
        tail = tail -> prev;
        if (tail) tail -> next = nullptr; else head = nullptr;
        delete n;
    }
};

int main() {
    cin.tie(0) -> sync_with_stdio(false);
    int q;
    cin >> q;
    Deque<int> D;
    for (int i = 0; i < q; ++i) {
        string op;
        cin >> op;
        if (op == "push_front" || op == "push_back") {
            int x; cin >> x;
            if (op == "push_front") D.push_front(x); else D.push_back(x);
        } else if (op == "pop_front") D.pop_front();
        else if (op == "pop_back") D.pop_back();
        else if (op == "front") cout << (D.head ? to_string(D.head -> data) : "EMPTY") << '\n';
        else cout << (D.tail ? to_string(D.tail -> data) : "EMPTY") << '\n';
    }
    return 0;
}
