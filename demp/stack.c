#include "dsa.h"

void main()  {
	Stack* s = createStack();
	s->push(s,1);
	s->push(s,2);
	s->push(s,3);
	printf("%d ",s->pop(s));
	printf("%d ",s->peek(s));
	printf("%d ",s->peek(s));
	printf("%d ",s->pop(s));
	printf("%d ",s->pop(s));
	printf("%d ",s->pop(s));
}
