/*
    PREDICCION S3: K-esimo desde el final (Singly Linked List, dos punteros)

    Enunciado:
    Dada una lista simplemente enlazada de n enteros y un entero k,
    imprime el valor del k-esimo elemento contando desde el final
    (k=1 es el ultimo elemento, k=2 el penultimo, etc). Se garantiza
    1 <= k <= n.

    Limites: 1 <= n <= 5*10^5, 1 <= k <= n.

    Idea clave (SIN saber el largo de antemano ni usar doble puntero prev):
    Tecnica de dos punteros "adelantado y atrasado": se avanza un
    puntero "fast" k posiciones desde el head. Luego se avanzan "fast" y
    "slow" (que empieza en head) al mismo tiempo hasta que fast llegue
    al final (nullptr). En ese momento, slow apunta exactamente al
    k-esimo nodo desde el final. Todo en una sola pasada, O(n), O(1)
    memoria extra.
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
    int n, k;
    cin >> n >> k;

    LinkedNode<int>* head = nullptr;
    LinkedNode<int>* tail = nullptr;
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        LinkedNode<int>* node = new LinkedNode<int>(x);
        if (!head) head = tail = node;
        else { tail -> next = node; tail = node; }
    }

    LinkedNode<int>* fast = head;
    for (int i = 0; i < k; ++i) fast = fast -> next;

    LinkedNode<int>* slow = head;
    while (fast != nullptr) {
        fast = fast -> next;
        slow = slow -> next;
    }

    cout << slow -> data << '\n';
    return 0;
}
