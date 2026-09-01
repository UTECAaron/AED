/*
    PREDICCION 4: Cache LRU (Doubly Linked List + acceso rapido por indice)

    Enunciado:
    Implementa una cache LRU (Least Recently Used) de capacidad C. Procesa
    q operaciones:

      - GET x : si x esta en la cache, imprime FOUND y lo marca como
                recien usado (se mueve al frente). Si no esta, imprime
                MISS.
      - PUT x : inserta x como el mas recientemente usado. Si x ya
                estaba, solo se actualiza su posicion. Si la cache esta
                llena y x es nuevo, elimina el elemento menos
                recientemente usado antes de insertar.

    Al final, imprime el contenido de la cache de mas a menos reciente.

    Limites: 1 <= C <= 10^5, 1 <= q <= 5*10^5, 0 <= x <= 10^9.

    Idea clave:
    Lista doblemente enlazada donde head = mas reciente, tail = menos
    reciente. Un unordered_map<valor, Node*> permite localizar el nodo de
    cualquier valor en O(1) y moverlo al frente sin recorrer la lista
    (igual que el arreglo boxOf[] del problema de Cajas).
*/
#include<iostream>
#include<unordered_map>
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
struct DoublyLinkedList {
    DoublyLinkedNode<data_type>* head;
    DoublyLinkedNode<data_type>* tail;
    DoublyLinkedList() { head = tail = nullptr; }

    DoublyLinkedNode<data_type>* push_front(data_type value) {
        DoublyLinkedNode<data_type>* new_node = new DoublyLinkedNode<data_type>(value, head);
        if (head == nullptr) tail = new_node; else head -> prev = new_node;
        head = new_node;
        return new_node;
    }

    void detach(DoublyLinkedNode<data_type>* node) {
        if (node -> prev != nullptr) node -> prev -> next = node -> next; else head = node -> next;
        if (node -> next != nullptr) node -> next -> prev = node -> prev; else tail = node -> prev;
    }

    void moveToFront(DoublyLinkedNode<data_type>* node) {
        if (node == head) return;
        detach(node);
        node -> next = head; node -> prev = nullptr;
        if (head != nullptr) head -> prev = node;
        head = node;
        if (tail == nullptr) tail = node;
    }

    void pop_back() {
        DoublyLinkedNode<data_type>* node = tail;
        detach(node);
        delete node;
    }
};

int main() {
    cin.tie(0) -> sync_with_stdio(false);
    int C, q;
    cin >> C >> q;

    DoublyLinkedList<int> L;
    unordered_map<int, DoublyLinkedNode<int>*> pos;
    int size = 0;

    for (int i = 0; i < q; ++i) {
        string op;
        cin >> op;
        int x;
        cin >> x;
        if (op == "GET") {
            auto it = pos.find(x);
            if (it == pos.end()) cout << "MISS\n";
            else { cout << "FOUND\n"; L.moveToFront(it -> second); }
        } else { // PUT
            auto it = pos.find(x);
            if (it != pos.end()) {
                L.moveToFront(it -> second);
            } else {
                if (size == C) {
                    int evicted = L.tail -> data;
                    pos.erase(evicted);
                    L.pop_back();
                    --size;
                }
                DoublyLinkedNode<int>* node = L.push_front(x);
                pos[x] = node;
                ++size;
            }
        }
    }

    for (DoublyLinkedNode<int>* cur = L.head; cur != nullptr; cur = cur -> next)
        cout << cur -> data << (cur -> next ? ' ' : '\n');
    if (L.head == nullptr) cout << '\n';
    return 0;
}
