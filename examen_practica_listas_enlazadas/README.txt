EXAMEN DE LISTAS ENLAZADAS - EJERCICIOS DE PRACTICA (predicciones)
====================================================================

Estos 9 problemas fueron creados imitando el estilo del profesor
(mismo template de structs DoublyLinkedNode / LinkedNode /
CircularLinkedList, mismo formato de enunciado con limites y
ejemplos) a partir de:
  - Los 5 problemas de lista enlazada que dejo como practica
    (Doubly Linked List, Round Robin, Polinomios, Josephus, Cajas).
  - Las 3 preguntas de su examen anterior (Inserciones/DEL,
    El mas popular, Diferencia maxima).

Cada archivo .cpp tiene el ENUNCIADO COMPLETO comentado al inicio,
junto con la IDEA CLAVE de la solucion. Todos compilan con:
    g++ -std=c++17 -O2 archivo.cpp -o solucion

Lista de archivos:
  01_editor.cpp                          -> Doubly Linked List + cursor
  02_circulo_josephus_k.cpp              -> Circular Linked List (Josephus con paso k)
  03_zigzag_intercalar.cpp               -> Singly Linked List (merge intercalado)
  04_lru_cache.cpp                       -> Doubly Linked List + hashmap (LRU)
  05_deque.cpp                           -> Doubly Linked List (deque basico)
  06_rotar_lista_circular.cpp            -> Circular Linked List (rotacion)
  07_merge_listas_ordenadas.cpp          -> Singly Linked List (merge ordenado real)
  08_palindromo.cpp                      -> Doubly Linked List (dos punteros)
  09_inserciones_eliminaciones_lista.cpp -> Doubly Linked List (INS/DEL por posicion, O(min(pos,n-pos)))

Patrones clave a repasar antes del examen:
  - Simple enlazada : head/tail; insertar/quitar requiere el nodo anterior.
  - Doble enlazada  : detach() generico + insertBefore/insertAfter reusables.
  - Circular        : tail->next = head; usar send_front_to_back() para
                       "rotar" en vez de recorrer toda la lista.
  - Doble circular  : combina lo anterior + flag "reversed" para invertir
                       en O(1) (como en el problema de Cajas).
  - Acceso indexado : arreglo/hashmap de punteros paralelo, indexado por
                       ID/valor, no por posicion (como boxOf[] en Cajas
                       o el unordered_map en el LRU).

NOTA: Estas son PREDICCIONES basadas en patrones observados, no son
los problemas reales del examen. Usalas para practicar las tecnicas,
no las memorices como si fueran a salir exactamente iguales.
