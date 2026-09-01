/*
    PREDICCION 7: Merge (Singly Linked List)

    Enunciado:
    Dadas dos listas simplemente enlazadas ya ordenadas de forma
    ascendente, fusionalas en una sola lista ordenada e imprimela.

    Limites: 0 <= |L1|, |L2| <= 5*10^5.

    Idea clave:
    Merge clasico de mergesort pero sobre listas enlazadas: dos punteros
    p y q recorren L1 y L2; en cada paso se anexa a R el nodo con el
    valor mas chico y se avanza ese puntero. Es O(n1 + n2) y no requiere
    memoria extra (se reutilizan los mismos nodos).
*/
#include<iostream>
using namespace::std;

template<typename data_type>
struct LinkedNode {
    data_type data;
    LinkedNode* next;
    LinkedNode(data_type data, LinkedNode* next = nullptr) : data(data), next(next) {}
};

LinkedNode<int>* readList(int n) {
    LinkedNode<int>* head = nullptr;
    LinkedNode<int>* tail = nullptr;
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        LinkedNode<int>* node = new LinkedNode<int>(x);
        if (!head) head = tail = node;
        else { tail -> next = node; tail = node; }
    }
    return head;
}

int main() {
    cin.tie(0) -> sync_with_stdio(false);
    int n1; cin >> n1;
    LinkedNode<int>* p = readList(n1);
    int n2; cin >> n2;
    LinkedNode<int>* q = readList(n2);

    LinkedNode<int>* head = nullptr;
    LinkedNode<int>* tail = nullptr;
    auto append = [&](LinkedNode<int>* node) {
        if (!head) head = tail = node;
        else { tail -> next = node; tail = node; }
    };

    while (p != nullptr && q != nullptr) {
        if (p -> data <= q -> data) { append(p); p = p -> next; }
        else { append(q); q = q -> next; }
    }
    while (p != nullptr) { append(p); p = p -> next; }
    while (q != nullptr) { append(q); q = q -> next; }

    if (tail) tail -> next = nullptr;
    for (LinkedNode<int>* cur = head; cur != nullptr; cur = cur -> next)
        cout << cur -> data << (cur -> next ? ' ' : '\n');
    if (!head) cout << '\n';
    return 0;
}
