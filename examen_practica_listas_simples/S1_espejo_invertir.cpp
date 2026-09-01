/*
    PREDICCION S1: Espejo (Invertir una Singly Linked List)

    Enunciado:
    Dada una lista simplemente enlazada de n enteros, invierte el orden
    de sus elementos e imprime la lista resultante.

    Limites: 1 <= n <= 5*10^5.

    Idea clave:
    Se recorre la lista una sola vez manteniendo 3 punteros: prev (nodo
    ya invertido), cur (nodo actual) y nxt (guarda el siguiente antes de
    romper el enlace). En cada paso se voltea cur->next para que apunte
    a prev, y se avanza. Al final, prev es el nuevo head. Todo en O(n)
    y O(1) de memoria extra (no se crean nodos nuevos).
*/
#include<iostream>
using namespace::std;

template<typename data_type>
struct LinkedNode {
    data_type data;
    LinkedNode* next;
    LinkedNode(data_type data, LinkedNode* next = nullptr) : data(data), next(next) {}
};

int main() {
    cin.tie(0) -> sync_with_stdio(false);
    int n;
    cin >> n;

    LinkedNode<int>* head = nullptr;
    LinkedNode<int>* tail = nullptr;
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        LinkedNode<int>* node = new LinkedNode<int>(x);
        if (!head) head = tail = node;
        else { tail -> next = node; tail = node; }
    }

    LinkedNode<int>* prev = nullptr;
    LinkedNode<int>* cur = head;
    while (cur != nullptr) {
        LinkedNode<int>* nxt = cur -> next;
        cur -> next = prev;
        prev = cur;
        cur = nxt;
    }
    head = prev;

    for (LinkedNode<int>* c = head; c != nullptr; c = c -> next)
        cout << c -> data << (c -> next ? ' ' : '\n');
    if (!head) cout << '\n';
    return 0;
}
