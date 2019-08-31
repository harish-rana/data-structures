#include "dsa.h"

void main()  {
 SLL* s = createSLL();
 s->pushAtEnd(s,1);
 s->pushAtEnd(s,2);
 s->pushAtEnd(s,3);
 s->pushAtEnd(s,4);
 s->pushAtEnd(s,5);
 s->print(s);
 printf("\n");
 printf("%d\n",s->popAtStart(s));
 printf("%d\n",s->popAtStart(s));
 printf("%d\n",s->popAtStart(s));  
 printf("%d\n",s->popAtStart(s)); 
 printf("%d\n",s->popAtStart(s));
}
