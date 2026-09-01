/*
    PREDICCION S4: Suma Gigante (Singly Linked List)

    Enunciado:
    Dos numeros muy grandes A y B se representan como listas simplemente
    enlazadas donde cada nodo guarda un digito (0-9), con el digito
    MENOS significativo primero (es decir, la cabeza de la lista es la
    unidad, el siguiente nodo son las decenas, etc). Calcula A + B y
    devuelve el resultado en el mismo formato (digito menos
    significativo primero), sin ceros a la izquierda salvo que el
    resultado sea 0.

    Limites: 1 <= cantidad de digitos de A, B <= 5*10^5.

    Idea clave:
    Es exactamente como la suma "a mano" que se aprende en la escuela,
    pero recorriendo dos listas en paralelo con un acarreo (carry). Se
    recorre mientras haya digitos en A, en B, o quede carry pendiente;
    en cada paso se calcula (dA + dB + carry) % 10 como digito y
    (dA + dB + carry) / 10 como nuevo carry. Al final se quitan los
    ceros sobrantes al final de la lista resultado (que representan los
    ceros mas significativos).
*/
#include<iostream>
using namespace::std;

template<typename data_type>
struct LinkedNode {
    data_type data;
    LinkedNode* next;
    LinkedNode(data_type data, LinkedNode* next = nullptr) : data(data), next(next) {}
};

LinkedNode<int>* readNumber(int len) {
    // Se lee como string y se guarda con el digito menos significativo primero
    string s;
    cin >> s;
    LinkedNode<int>* head = nullptr;
    LinkedNode<int>* tail = nullptr;
    for (int i = (int)s.size() - 1; i >= 0; --i) {
        int d = s[i] - '0';
        LinkedNode<int>* node = new LinkedNode<int>(d);
        if (!head) head = tail = node;
        else { tail -> next = node; tail = node; }
    }
    return head;
}

int main() {
    cin.tie(0) -> sync_with_stdio(false);
    int lenA;
    cin >> lenA;
    LinkedNode<int>* A = readNumber(lenA);
    int lenB;
    cin >> lenB;
    LinkedNode<int>* B = readNumber(lenB);

    LinkedNode<int>* head = nullptr;
    LinkedNode<int>* tail = nullptr;
    auto append = [&](int v) {
        LinkedNode<int>* node = new LinkedNode<int>(v);
        if (!head) head = tail = node;
        else { tail -> next = node; tail = node; }
    };

    int carry = 0;
    LinkedNode<int>* pa = A;
    LinkedNode<int>* pb = B;
    while (pa != nullptr || pb != nullptr || carry != 0) {
        int da = (pa != nullptr) ? pa -> data : 0;
        int db = (pb != nullptr) ? pb -> data : 0;
        int sum = da + db + carry;
        append(sum % 10);
        carry = sum / 10;
        if (pa) pa = pa -> next;
        if (pb) pb = pb -> next;
    }

    // Quitar ceros sobrantes al final de la lista (ceros mas significativos),
    // dejando al menos un digito.
    while (head != tail && tail && head) {
        // encontrar el penultimo nodo
        LinkedNode<int>* cur = head;
        if (tail -> data != 0) break;
        if (head == tail) break;
        while (cur -> next != tail) cur = cur -> next;
        delete tail;
        tail = cur;
        tail -> next = nullptr;
    }

    // Imprimir del digito mas significativo al menos significativo:
    // como el resultado esta guardado con el menos significativo primero,
    // primero lo invertimos para imprimir en el orden humano habitual.
    LinkedNode<int>* prev = nullptr;
    LinkedNode<int>* cur = head;
    while (cur != nullptr) {
        LinkedNode<int>* nxt = cur -> next;
        cur -> next = prev;
        prev = cur;
        cur = nxt;
    }
    head = prev;

    for (LinkedNode<int>* c = head; c != nullptr; c = c -> next) cout << c -> data;
    cout << '\n';
    return 0;
}
