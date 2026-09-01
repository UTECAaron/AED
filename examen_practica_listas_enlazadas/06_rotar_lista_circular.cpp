/*
    PREDICCION 6: Rotacion (Circular Linked List)

    Enunciado:
    Dada una lista circular de n elementos, rotala k posiciones hacia la
    derecha (el elemento en la posicion n-1 pasa a la posicion k-1, etc.)
    e imprime el resultado empezando por lo que antes era la posicion 0.

    Limites: 1 <= n <= 10^5, 0 <= k < n.

    Idea clave:
    Se arma la lista como circular (tail->next = head). Para rotar k a la
    derecha basta con encontrar cual sera el nuevo "tail" avanzando
    (n - k - 1) pasos desde el head original: el nodo siguiente a ese es
    el nuevo head. Luego se corta el enlace circular en ese punto para
    poder imprimir en linea recta.
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
    tail -> next = head; // hacemos la lista circular

    // avanzamos (n - k - 1) pasos desde head para encontrar el nuevo "tail"
    LinkedNode<int>* newTail = head;
    for (int i = 0; i < n - k - 1; ++i) newTail = newTail -> next;
    LinkedNode<int>* newHead = newTail -> next;
    newTail -> next = nullptr; // rompemos el circulo para poder imprimir en linea recta

    for (LinkedNode<int>* cur = newHead; cur != nullptr; cur = cur -> next)
        cout << cur -> data << (cur -> next ? ' ' : '\n');
    return 0;
}
