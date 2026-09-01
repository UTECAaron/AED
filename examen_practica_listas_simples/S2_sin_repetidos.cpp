/*
    PREDICCION S2: Sin Repetidos (Singly Linked List)

    Enunciado:
    Dada una lista simplemente enlazada de n enteros (no necesariamente
    ordenada), elimina los elementos duplicados dejando solo la primera
    aparicion de cada valor, manteniendo el orden original. Imprime la
    lista resultante.

    Limites: 1 <= n <= 5*10^5, 0 <= valor <= 10^9.

    Idea clave:
    Se recorre la lista una sola vez con un puntero "cur" y otro "prev".
    Un set/unordered_set guarda los valores ya vistos. Si el valor de
    cur ya fue visto, se "salta" (prev->next = cur->next) sin mover
    prev; si es nuevo, se marca como visto y se avanza normalmente.
    Todo en O(n) esperado.
*/
#include<iostream>
#include<unordered_set>
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

    unordered_set<int> seen;
    LinkedNode<int>* prev = nullptr;
    LinkedNode<int>* cur = head;
    while (cur != nullptr) {
        if (seen.count(cur -> data)) {
            LinkedNode<int>* toDelete = cur;
            prev -> next = cur -> next;
            cur = cur -> next;
            delete toDelete;
        } else {
            seen.insert(cur -> data);
            prev = cur;
            cur = cur -> next;
        }
    }

    for (LinkedNode<int>* c = head; c != nullptr; c = c -> next)
        cout << c -> data << (c -> next ? ' ' : '\n');
    if (!head) cout << '\n';
    return 0;
}
