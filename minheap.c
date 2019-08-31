#include "dsa.h"

void main()  {
  int heap[100] = { 1, 3, 5, 4, 6, 13, 10, 9, 8, 15, 17};
  int n = 11;
  MinHeap* m = createMinHeap(heap,n);
  m->build(m);
  m->print(m);
  printf("%d\n",m->pop(m));
  printf("%d\n",m->pop(m));
  printf("%d\n",m->pop(m));
  printf("%d\n",m->pop(m));
  m->print(m);
}
