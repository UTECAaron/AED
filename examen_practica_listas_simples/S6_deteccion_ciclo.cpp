/*
    PREDICCION S6: Deteccion de Ciclo (Singly Linked List, algoritmo de Floyd)

    Enunciado:
    Se construye una lista simplemente enlazada de n nodos (numerados de
    0 a n-1 en el orden en que se leen). Ademas del enlace normal
    0->1->2->...->(n-1), se recibe un entero c:
      - Si c == -1, la lista termina normalmente en nullptr (no hay ciclo).
      - Si 0 <= c < n, el ultimo nodo (n-1) en vez de apuntar a nullptr,
        apunta de vuelta al nodo con indice c (esto crea un ciclo).
    Determina si la lista tiene un ciclo. Imprime "SI" o "NO".

    Limites: 1 <= n <= 5*10^5, -1 <= c <= n-1.

    Idea clave:
    Algoritmo de Floyd (tortuga y liebre): dos punteros recorren la
    lista, uno avanzando de a 1 nodo (slow) y otro de a 2 nodos (fast).
    Si hay un ciclo, eventualmente fast alcanza a slow (se vuelven
    iguales) dentro del ciclo. Si no hay ciclo, fast llega a nullptr
    primero. Esto se hace en O(n) tiempo y O(1) memoria extra, sin
    necesidad de marcar nodos visitados con un set.
*/
#include<iostream>
#include<vector>
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

    vector<LinkedNode<int>*> nodes(n);
    for (int i = 0; i < n; ++i) nodes[i] = new LinkedNode<int>(i);
    for (int i = 0; i + 1 < n; ++i) nodes[i] -> next = nodes[i + 1];

    int c;
    cin >> c;
    if (c != -1) nodes[n - 1] -> next = nodes[c];
    else nodes[n - 1] -> next = nullptr;

    LinkedNode<int>* head = nodes[0];

    LinkedNode<int>* slow = head;
    LinkedNode<int>* fast = head;
    bool hasCycle = false;
    while (fast != nullptr && fast -> next != nullptr) {
        slow = slow -> next;
        fast = fast -> next -> next;
        if (slow == fast) { hasCycle = true; break; }
    }

    cout << (hasCycle ? "SI" : "NO") << '\n';
    return 0;
}
