/*
    PREDICCION 2: El circulo (Josephus generalizado, Circular Linked List)

    Enunciado:
    Hay n ninos en un circulo numerados de 1 a n. Empezando en el nino 1 y
    contando en sentido horario, cada vez se elimina al k-esimo nino
    contado (contando tambien al que empieza la cuenta). Imprime el orden
    de eliminacion.

    Limites: 1 <= n <= 2*10^5, 1 <= k <= n.

    Idea clave:
    Reutiliza la CircularLinkedList del profe (la de Round Robin).
    "Contar k" equivale a hacer (k-1) veces send_front_to_back() y luego
    eliminar el nuevo front con pop_front().
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
struct CircularLinkedList {
    LinkedNode<data_type>* head;
    LinkedNode<data_type>* tail;
    CircularLinkedList() { head = tail = nullptr; }

    data_type front() { return head -> data; }

    void send_front_to_back() {
        head = head -> next;
        tail = tail -> next;
    }

    void pop_front() {
        LinkedNode<data_type>* current = head;
        if (head == tail) head = tail = nullptr;
        else { head = head -> next; tail -> next = head; }
        delete current;
    }

    void push_back(data_type value) {
        if (head == nullptr) {
            LinkedNode<data_type>* new_node = new LinkedNode<data_type>(value);
            head = tail = new_node;
            new_node -> next = head;
        } else {
            LinkedNode<data_type>* new_node = new LinkedNode<data_type>(value, head);
            tail -> next = new_node;
            tail = tail -> next;
        }
    }
};

int main() {
    cin.tie(0) -> sync_with_stdio(false);
    int n, k;
    cin >> n >> k;

    CircularLinkedList<int> L;
    for (int i = 1; i <= n; ++i) L.push_back(i);

    for (int i = 0; i < n; ++i) {
        for (int step = 1; step < k; ++step) L.send_front_to_back();
        cout << L.front() << (i + 1 == n ? '\n' : ' ');
        L.pop_front();
    }
    return 0;
}
