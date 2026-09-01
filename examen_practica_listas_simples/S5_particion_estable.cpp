/*
    PREDICCION S5: Particion Estable (Singly Linked List)

    Enunciado:
    Dada una lista simplemente enlazada de n enteros y un valor pivote
    x, reordena la lista de modo que todos los elementos menores que x
    queden antes que todos los elementos mayores o iguales a x. Debe
    mantenerse el orden relativo original dentro de cada grupo (particion
    ESTABLE). Imprime la lista resultante.

    Limites: 1 <= n <= 5*10^5, 0 <= valor, x <= 10^9.

    Idea clave:
    Se construyen dos listas auxiliares con push_back: "menores" (para
    los que son < x) y "mayoresIguales" (para los que son >= x),
    recorriendo la lista original una sola vez y anexando cada nodo a la
    lista que corresponda (reutilizando los mismos nodos, sin crear
    nuevos). Al final se conecta el tail de "menores" con el head de
    "mayoresIguales". Esto logra estabilidad automaticamente porque cada
    lista preserva el orden en que llegaron sus elementos.
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
    int n, x;
    cin >> n >> x;

    LinkedNode<int>* head = nullptr;
    LinkedNode<int>* tail = nullptr;
    for (int i = 0; i < n; ++i) {
        int v; cin >> v;
        LinkedNode<int>* node = new LinkedNode<int>(v);
        if (!head) head = tail = node;
        else { tail -> next = node; tail = node; }
    }

    LinkedNode<int>* lessHead = nullptr;
    LinkedNode<int>* lessTail = nullptr;
    LinkedNode<int>* geHead = nullptr;
    LinkedNode<int>* geTail = nullptr;

    LinkedNode<int>* cur = head;
    while (cur != nullptr) {
        LinkedNode<int>* nxt = cur -> next;
        cur -> next = nullptr;
        if (cur -> data < x) {
            if (!lessHead) lessHead = lessTail = cur;
            else { lessTail -> next = cur; lessTail = cur; }
        } else {
            if (!geHead) geHead = geTail = cur;
            else { geTail -> next = cur; geTail = cur; }
        }
        cur = nxt;
    }

    LinkedNode<int>* result;
    if (lessHead == nullptr) {
        result = geHead;
    } else {
        lessTail -> next = geHead;
        result = lessHead;
    }

    for (LinkedNode<int>* c = result; c != nullptr; c = c -> next)
        cout << c -> data << (c -> next ? ' ' : '\n');
    if (!result) cout << '\n';
    return 0;
}
