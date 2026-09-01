/*
    PREDICCION 3: Zigzag (intercalar dos listas, Singly Linked List)

    Enunciado:
    Se te dan dos listas de enteros L1 y L2 (no necesariamente ordenadas),
    representadas como listas simplemente enlazadas. Construye una tercera
    lista R intercalando alternadamente un elemento de L1, uno de L2, uno
    de L1, etc. Si una lista se acaba antes, agrega el resto de la otra al
    final. Imprime R.

    Limites: 0 <= |L1|, |L2| <= 5*10^5.

    Idea clave:
    Recorrer ambas listas con dos punteros y hacer push_back alternado
    hasta que una se agote; despues volcar el resto de la que sobro.
*/
#include<iostream>
using namespace::std;

template<typename data_type>
struct LinkedNode {
    data_type data;
    LinkedNode* next;
    LinkedNode() { next = nullptr; }
    LinkedNode(data_type data, LinkedNode<data_type>* next = nullptr) : data(data), next(next) {}
};

template<typename data_type>
struct LinkedList {
    LinkedNode<data_type>* head;
    LinkedNode<data_type>* tail;
    LinkedList() { head = tail = nullptr; }

    void push_back(data_type value) {
        LinkedNode<data_type>* new_node = new LinkedNode<data_type>(value);
        if (head == nullptr) head = tail = new_node;
        else { tail -> next = new_node; tail = new_node; }
    }

    void print() {
        for (LinkedNode<data_type>* cur = head; cur != nullptr; cur = cur -> next)
            cout << cur -> data << (cur -> next ? ' ' : '\n');
        if (head == nullptr) cout << '\n';
    }
};

int main() {
    cin.tie(0) -> sync_with_stdio(false);
    int n1;
    cin >> n1;
    LinkedList<int> L1;
    for (int i = 0; i < n1; ++i) { int x; cin >> x; L1.push_back(x); }

    int n2;
    cin >> n2;
    LinkedList<int> L2;
    for (int i = 0; i < n2; ++i) { int x; cin >> x; L2.push_back(x); }

    LinkedList<int> R;
    LinkedNode<int>* p1 = L1.head;
    LinkedNode<int>* p2 = L2.head;
    while (p1 != nullptr && p2 != nullptr) {
        R.push_back(p1 -> data); p1 = p1 -> next;
        R.push_back(p2 -> data); p2 = p2 -> next;
    }
    while (p1 != nullptr) { R.push_back(p1 -> data); p1 = p1 -> next; }
    while (p2 != nullptr) { R.push_back(p2 -> data); p2 = p2 -> next; }

    R.print();
    return 0;
}
