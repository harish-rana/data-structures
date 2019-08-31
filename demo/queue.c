#include "dsa.h"

void main()  {
	Queue* s = createQueue();
	s->push(s,1);
	s->push(s,2);
	s->push(s,3);
	s->push(s,4);
	printf("%d ",s->pop(s));
	printf("%d ",s->peek(s));
	printf("%d ",s->peek(s));
	printf("%d ",s->pop(s));
	printf("%d ",s->pop(s));
	printf("%d ",s->pop(s));
}
