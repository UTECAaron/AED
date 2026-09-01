EXAMEN DE LISTAS ENLAZADAS - PRACTICA ENFOCADA EN LISTAS SIMPLES
====================================================================

Estos 6 problemas usan UNICAMENTE listas simplemente enlazadas
(un solo puntero "next", sin "prev" y sin estructuras circulares
dedicadas), siguiendo el mismo template LinkedNode<data_type> usado
por el profesor en el problema de Polinomios.

Cada archivo .cpp tiene el ENUNCIADO COMPLETO comentado al inicio,
junto con la IDEA CLAVE del algoritmo usado. Todos fueron probados
y compilan con:
    g++ -std=c++17 -O2 archivo.cpp -o solucion

Lista de archivos:
  S1_espejo_invertir.cpp       -> Invertir la lista (3 punteros: prev/cur/nxt)
  S2_sin_repetidos.cpp         -> Eliminar duplicados manteniendo orden (set + prev/cur)
  S3_kesimo_desde_final.cpp    -> K-esimo desde el final SIN saber el largo (2 punteros con distancia k)
  S4_suma_gigante.cpp          -> Suma de numeros grandes representados como digitos en listas (con acarreo)
  S5_particion_estable.cpp     -> Particion estable alrededor de un pivote (dos sub-listas auxiliares)
  S6_deteccion_ciclo.cpp       -> Deteccion de ciclo con el algoritmo de Floyd (tortuga y liebre)

Tecnicas de "lista simple" mas importantes que resumen estos 6:
  1) Reversion en el lugar con 3 punteros (prev, cur, nxt).
  2) Recorrido con un puntero auxiliar "prev" para poder eliminar/saltar
     nodos sin necesitar volver hacia atras (ya que no hay puntero prev
     en el nodo mismo).
  3) Tecnica de DOS PUNTEROS con distancia fija (fast adelantado k
     pasos) para encontrar posiciones relativas al final sin conocer n.
  4) Tecnica de DOS PUNTEROS con distinta velocidad (Floyd) para
     detectar ciclos o encontrar el punto medio, en una sola pasada.
  5) Construir listas auxiliares con push_back y reconectarlas al final
     (particion, merge, zigzag) reutilizando los nodos originales en vez
     de crear nuevos, cuando sea posible.
  6) Simular aritmetica (suma, resta, multiplicacion por digito) dígito
     a dígito con acarreo, cuando los numeros son demasiado grandes para
     un tipo entero normal.

NOTA: Estas son PREDICCIONES basadas en patrones de sus problemas de
practica y su examen anterior. Sirven para entrenar las tecnicas, no
para memorizar como si fueran a salir exactamente iguales.
