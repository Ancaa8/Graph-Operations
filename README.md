# Graph-Operations
Graph operations in C

Graph.c

Funcția alloc_list primește ca parametri un pointer la o structură TGraphL și un număr întreg n. Ea alocă spațiu pentru listele de adiacență și inițializează structura.

Funcția free_list primește ca parametru un pointer la o structură TGraphL. Ea eliberează memoria ocupată de listele de adiacență și resetează structura la starea inițială.

Funcția insert_edge_list primește ca parametri un pointer la o structură TGraphL, două noduri v1 și v2, un cost c și un indicator tip. Ea inserează o muchie între nodurile v1 și v2 în lista de adiacență corespunzătoare nodului v1. Dacă tip este 0, înseamnă că graful este neorientat și va insera o muchie și în lista de adiacență a nodului v2.

Funcția Prim primește ca parametri o structură TGraphL, un nod de start și un vector visited. Ea implementează algoritmul Prim pentru determinarea arborelui minim de acoperire într-un graf neorientat. Returnează costul total al arborelui de acoperire și completează vectorul visited cu nodurile care fac parte din arbore.

Funcția dijkstra primește ca parametri o structură TGraphL, un nod de start s, și trei vectori depths, dist și parinti. Ea implementează algoritmul Dijkstra pentru găsirea celui mai scurt drum între nodul de start s și toate celelalte noduri din graf. Completează vectorul dist cu distanțele minime calculate, vectorul parinti cu nodurile antecessoare în cadrul drumurilor minime, și vectorul depths cu adâncimile nodurilor în cadrul arborelui de acoperire.

Graph.h

Se includ mai multe fișiere header necesare (stdio.h, stdlib.h, limits.h, "Heap.h").

Se definește tipul TCost ca un alias pentru tipul int, care reprezintă costul muchiilor grafului.

Structura TNode reprezintă un nod în lista de adiacență. Conține informații despre vârful nodului (v), costul muchiei (c), indicatorul de tip (tip) și un pointer la următorul nod în listă.

Structura TGraphL reprezintă un graf implementat sub forma de listă de adiacență. Conține numărul de noduri (nn) și un pointer la un vector de pointeri la noduri (adl).

Heap. c

Funcția newNode primește ca parametri un nod v și un cost d și creează un nou nod pentru heap. Se alocă spațiu pentru nod, se setează valorile membre și se returnează noul nod creat.

Funcția newQueue primește ca parametru o capacitate și creează o nouă structură MinHeap (heap). Se alocă spațiu pentru structură, pentru vectorul de poziții (pos), pentru vectorul de noduri (elem) și se setează valorile membre. Se returnează noul heap creat.

Funcția swap primește ca parametri două adrese de noduri și le interschimbă între ele.

Funcția SiftDown primește ca parametri un heap și un index (idx). Efectuează o operație de coborâre în heap, astfel încât să se respecte proprietatea de min-heap. Compara valorile dintre nodul la indexul idx și copiii săi, și le interschimbă dacă este necesar. Apoi, recursiv apelează funcția pentru copilul cel mai mic modificat.

Funcția isEmpty primește ca parametru un heap și verifică dacă heap-ul este gol, adică are dimensiunea (size) zero.

Funcția removeMin primește ca parametru un heap și elimină nodul cu valoarea minimă din heap. Returnează nodul eliminat. Se înlocuiește nodul cu valoarea minimă cu ultimul nod din heap, se actualizează pozițiile nodurilor, se scade dimensiunea heap-ului și se aplică operația de coborâre (SiftDown) pentru a menține proprietatea de min-heap.

Funcția SiftUp primește ca parametri un heap și un index (idx). Efectuează o operație de urcare în heap, astfel încât să se respecte proprietatea de min-heap. Compara valoarea nodului la indexul idx cu valoarea părintelui său și le interschimbă dacă este necesar. Apoi, recursiv apelează funcția pentru părintele modificat.

Heap.h

Structura MinHeapNode reprezintă un nod în heap și conține informații despre vârful nodului (v) și valoarea asociată (d).

Structura MinHeap reprezintă un heap de tip min-heap și conține informații despre dimensiunea heap-ului (size), capacitatea heap-ului (capacity), un vector de poziții (pos) și un vector de pointeri la noduri (elem).

main.c

Codul principal începe cu includerea fișierelor header necesare și definirea MAX cu valoarea 100.

Următoarea funcție crescator este un comparator utilizat pentru sortarea unui vector de întregi în ordine crescătoare.

Funcția readGraph primește un fișier de intrare (input) și citeste informațiile despre graful reprezentat de structura TGraphL. Se citesc nodurile și muchiile grafului, iar pentru fiecare muchie se găsește sau se adaugă în vectorul places locul corespunzător și se inserează muchia în graf utilizând funcția insert_edge_list.

Funcția readDephts primește un fișier de intrare (input) și citeste adâncimile asociate fiecărui nod din graf. Se utilizează vectorul places pentru a identifica nodul corespunzător numelui citit din fișier, iar apoi se atribuie adâncimea nodului în vectorul depths.

Funcția main este funcția principală care citește numărul de noduri și muchii din fișierul de intrare, alocă și inițializează structura TGraphL G utilizând alloc_list, apoi în funcție de primul argument al liniei de comandă (argv[1]), se efectuează operațiile corespunzătoare.

Dacă primul argument este '1', se efectuează algoritmul lui Prim pe graf pentru a găsi minimul costului arborelui de acoperire, se sortează costurile și se afișează în fișierul de ieșire.

Dacă primul argument este '2', se citesc graful și adâncimile utilizând funcțiile readGraph și readDephts, apoi se găsește drumul cel mai scurt utilizând algoritmul lui Dijkstra între două noduri specifice (sursa și destinația). Se calculează costul minim și se afișează informațiile relevante în fișierul de ieșire.

La final, se eliberează memoria alocată.
