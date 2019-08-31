#include<stdio.h>
#include<stdlib.h>
#include "dsa.h"

void main()  {
 DLL* s = createDLL();
 s->pushAtEnd(s,1);
 s->pushAtEnd(s,2);
 s->pushAtEnd(s,3);
 s->pushAtEnd(s,4);
 s->pushAtEnd(s,5);
  s->pushAtStart(s,6);
   s->pushAtStart(s,7);
 s->print(s);
 printf("%d\n",s->popAtStart(s));
 printf("%d\n",s->popAtEnd(s));
 printf("%d\n",s->popAtEnd(s));  
 printf("%d\n",s->popAtStart(s)); 
 printf("%d\n",s->popAtStart(s));
}

