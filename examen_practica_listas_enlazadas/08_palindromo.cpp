/*
    PREDICCION 8: Palindromo (Doubly Linked List)

    Enunciado:
    Dada una secuencia de n enteros almacenada como lista doblemente
    enlazada, determina si es palindroma (se lee igual de adelante hacia
    atras) usando dos punteros que avanzan desde ambos extremos hacia el
    centro (aprovechando que es doblemente enlazada).

    Limites: 1 <= n <= 10^5.

    Idea clave:
    A diferencia de una lista simple (donde ir hacia atras es O(n)), en
    una lista doble se puede tener un puntero l que avanza con next y
    otro r que avanza con prev, comparando datos hasta que se crucen.
    Esto evita tener que invertir o copiar la lista a un arreglo.
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

int main() {
    cin.tie(0) -> sync_with_stdio(false);
    int n; cin >> n;

    DoublyLinkedNode<int>* head = nullptr;
    DoublyLinkedNode<int>* tail = nullptr;
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        DoublyLinkedNode<int>* node = new DoublyLinkedNode<int>(x, nullptr, tail);
        if (!head) head = node; else tail -> next = node;
        tail = node;
    }

    DoublyLinkedNode<int>* l = head;
    DoublyLinkedNode<int>* r = tail;
    bool ok = true;
    while (l != r && l -> prev != r) {
        if (l -> data != r -> data) { ok = false; break; }
        l = l -> next;
        r = r -> prev;
    }

    cout << (ok ? "SI" : "NO") << '\n';
    return 0;
}
