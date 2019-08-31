#include "dsa.h" 

void main() { 
	AVL* a = createAVL();
	a->push(a, 6);
	a->push(a, 4);
	a->push(a, 5); 
	a->push(a, 8); 
	a->push(a, 7); 
	a->inOrder(a);
	printf("\n");
	a->preOrder(a);
	printf("\n");
	a->postOrder(a);
	printf("\n");
}
