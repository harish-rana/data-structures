//this headerfile is free to use, modify and redistribute

#include<stdio.h>
#include<stdlib.h>

typedef struct sllNode SLLNode;
typedef struct sll SLL;
typedef struct stack Stack;
typedef struct queue Queue;
typedef struct bstNode BSTNode;
typedef struct bst BST;
typedef struct avlnode AVLNode;
typedef struct avl AVL;
typedef struct maxheap MaxHeap;
typedef struct minheap MinHeap;
typedef struct dllNode DLLNode;
typedef struct dll DLL;

struct sllNode {
 int data;
 SLLNode *next;
};

struct dllNode {
 int data;
 DLLNode *next;
 DLLNode *prev;
};

struct bstNode {
	int key; 
	int height;
	struct bstNode *left;
	struct bstNode *right;
};

struct sll  {
    SLLNode* head;
    SLLNode* tail;
   	void (*print)(SLL*);
   	void (*printreverse)(SLL*);
   	void (*pushAtStart)(SLL*, int);
   	void (*pushAtEnd)(SLL*, int);
   	void (*pushAtPosition)(SLL*, int, int);
    int  (*popAtStart)(SLL*);
    int  (*popAtEnd)(SLL*);
   	void (*reverse)(SLL*);
   	int  (*isEmpty)(SLL*);
   	int  (*peek)(SLL*);
};

struct dll  {
    DLLNode* head;
    DLLNode* tail;
   	void (*print)(DLL*);
   	void (*pushAtStart)(DLL*, int);
   	void (*pushAtEnd)(DLL*, int);
    int  (*popAtStart)(DLL*);
    int  (*popAtEnd)(DLL*);
   	int  (*isEmpty)(DLL*);
   	int  (*peek)(DLL*);
};

struct stack {
  SLLNode* head;
  SLLNode* tail;
	void (*push)(Stack*,int);
	int  (*pop)(Stack*);
	int  (*peek)(Stack*);
	int  (*isEmpty)(Stack*);
};

struct queue {
  SLLNode* head;
  SLLNode* tail;
	void (*push)(Queue*,int);
	int  (*pop)(Queue*);
	int  (*peek)(Queue*);
	int  (*isEmpty)(Queue*);
};

struct bst {
	BSTNode* root;
	void (*push)(BST*,int);
	void (*inOrder)(BST*);
	void (*preOrder)(BST*);
	void (*postOrder)(BST*);
};

struct avl {
	BSTNode* root;
	void (*push)(AVL*,int);
	void (*inOrder)(AVL*);
	void (*preOrder)(AVL*);
	void (*postOrder)(AVL*);
};

struct maxheap {
  int* heap;
  int n;
  void (*build)(MaxHeap*);
	void (*push)(MaxHeap*,int);
	int  (*pop)(MaxHeap*);
	int  (*peek)(MaxHeap*);
	void (*print)(MaxHeap*);
};

struct minheap {
  int* heap;
  int n;
  void (*build)(MinHeap*);
	void (*push)(MinHeap*,int);
	int  (*pop)(MinHeap*);
	int  (*peek)(MinHeap*);
	void (*print)(MinHeap*);
};

SLLNode* sllNewNode(int data)  {  
 SLLNode* nn = malloc(sizeof(SLLNode));
 nn->data = data;
 nn->next = NULL;
 return nn;
}

DLLNode* dllNewNode(int data)  { 
 DLLNode* nn = malloc(sizeof(DLLNode));
 nn->data = data;
 nn->prev = NULL;
 nn->next = NULL;
 return nn;
}

BSTNode *bstNewNode(int item) {
	BSTNode *temp = (BSTNode *)malloc(sizeof(BSTNode)); 
	temp->key = item; 
	temp->left = temp->right = NULL;
	return temp; 
}

int sllIsEmpty(SLLNode* head)	{
  if(head == NULL)
	return 1;
	else
	return 0;
}		

int sllPeek(SLLNode* head) 	{
	return head->data;
}	
void sllPrint(SLLNode* head)  { 
 SLLNode* p = head;
 while(p!=NULL)  {
  printf("%d  ",p->data);
  p = p->next;
  }
  printf("\n");
}
   	
void sllPrintInReverse(SLLNode* head)     
{ 
    if (head == NULL) 
     return; 
    sllPrintInReverse(head->next); 
    printf("%d  ",head->data); 
} 
   
void sllPushAtEnd(SLLNode** head, SLLNode** tail, int data)  { 
   SLLNode* newNode = sllNewNode(data); 
    
   if((*head) == NULL)  {
    (*head) = newNode;
    (*tail) = (*head);
   } 
   else if((*head)->next == NULL)	{
    (*head)->next = newNode;
    (*tail)->next = (*head)->next;
    (*tail) = (*tail)->next;
   }
   else {
   	(*tail)->next = newNode;
   	(*tail) = (*tail)->next;
   }	 
}

void sllPushAtStart(SLLNode** head, SLLNode** tail, int data)  {
   if((*head) == NULL)  {
    (*head) = sllNewNode(data);
    (*tail) = (*head);
   } 
   else  {
    SLLNode* p = sllNewNode(data);
    p->next = (*head);
    (*head) = p;
    }
}

void sllPushAtPosition(SLLNode** head, SLLNode** tail, int data, int pos)	{
 SLLNode* newNode = sllNewNode(data);
 if(pos==1)  {
   if((*head) == NULL)  {
    (*head) = newNode;
    (*tail) = (*head);
   }
   else {
    newNode->next = (*head);
    (*head) = newNode;
    }
 }
 else  {
   SLLNode* p = (*head);
   for(int i=1; i<pos-1; i++)
    p = p->next;
   newNode->next = p->next;
   if(p->next == NULL)
   	(*tail) = newNode;
   p->next = newNode; 
 }
}

int sllPopAtEnd(SLLNode** head, SLLNode** tail)  {
	int res = 0;
	if(*head == NULL) {
	}	
	else if(*head == *tail)	{
		res = (*head)->data;
		(*head) = NULL;
		(*tail) = NULL;
	}
	else if((*head)->next == (*tail))  {
		res = (*tail)->data;
		(*head)->next = NULL;
		(*tail) = (*head);
	}
	else	{
		res = (*tail)->data;
		SLLNode* p = (*head);
		while(p->next->next != NULL)
			p = p->next;
		(*tail) = p;
		(*tail)->next = NULL;	
	}
	return res;
}	
	
int sllPopAtStart(SLLNode** head, SLLNode** tail)	{
	int res = 0;
	if((*head) == NULL)	{
	}	
	else if(*head == *tail)	{
		res = (*head)->data;
		(*head) = NULL;
		(*tail) = NULL;
	}
	else  {
		res = (*head)->data;
		(*head) = (*head)->next;
	}	
	return res;	 		
}				
	
void sllReverse(SLLNode** head)  {
	SLLNode* currn = (*head); 
	SLLNode* prevn = NULL; 
	SLLNode* nextn = NULL; 
	while(currn != NULL) 
	{ 
		nextn = currn->next; 
		currn->next = prevn; 
		prevn = currn; 
		currn = nextn; 
	} 
	(*head) = prevn;
}

int dllIsEmpty(DLLNode* head)	{
  if(head == NULL)
	return 1;
	else
	return 0;
}		


int dllPeek(DLLNode* head) 	{
	return head->data;
}	
void dllPrint(DLLNode* head)  { 
 DLLNode* p = head;
 while(p!=NULL)  {
  printf("%d  ",p->data);
  p = p->next;
  }
  printf("\n");
}
   
void dllPushAtEnd(DLLNode** head, DLLNode** tail, int data)  { 
   DLLNode* newNode = dllNewNode(data);
    
   if((*head) == NULL)  {
    (*head) = newNode;
    (*tail) = (*head);
   } 
   else if((*head)->next == NULL)	{
     newNode->prev = *head;
    (*head)->next = newNode;
    //(*tail)->next = (*head)->next;
    (*tail) = (*tail)->next;
   }
   else {
   	newNode->prev = *tail;
   	(*tail)->next = newNode;
   	(*tail) = (*tail)->next;
   }	 
}

void dllPushAtStart(DLLNode** head, DLLNode** tail, int data)  {
   if((*head) == NULL)  {
    (*head) = dllNewNode(data);
    (*tail) = (*head);
   } 
   else  {
    DLLNode* p = dllNewNode(data);
    p->next = (*head);
    (*head) = p;
    }
}
int dllPopAtEnd(DLLNode** head, DLLNode** tail)  {
	int res = 0;
	if(*head == NULL) {
	}
	else if(*head == *tail)	{
		res = (*head)->data;
		(*head) = NULL;
		(*tail) = NULL;
	}
	else if((*head)->next == (*tail))  {
		res = (*tail)->data;
		(*head)->next = NULL;	
		(*tail) = (*tail)->prev;
		(*tail)->next = NULL;
	}
	else	{
		res = (*tail)->data;
		(*tail) = (*tail)->prev;
		(*tail)->next = NULL;
		
	}
	return res;
}	
	
int dllPopAtStart(DLLNode** head, DLLNode** tail)	{
	int res = 0;
	if((*head) == NULL)	{
	}	
	else if(*head == *tail)	{
		res = (*head)->data;
		(*head) = NULL;
		(*tail) = NULL;
	}
	else  {
		res = (*head)->data;
		(*head) = (*head)->next;
		(*head)->prev = NULL;
	}	
	return res;	 		
}				


void bstPush(BSTNode** Node, int key)  { 
	if (*Node == NULL) 
	     (*Node) = bstNewNode(key); 
	else if (key < (*Node)->key) 
		bstPush(&((*Node)->left), key); 
	else 
		bstPush(&((*Node)->right), key);
}
void bstInOrder(BSTNode *root) { 
	if (root != NULL) { 
		bstInOrder(root->left); 
		printf("%d ", root->key); 
		bstInOrder(root->right); 
	} 
} 
void bstPreOrder(BSTNode *root) { 
	if (root != NULL) { 
	 printf("%d ", root->key); 
		bstPreOrder(root->left); 
		bstPreOrder(root->right); 
	} 
} 
void bstPostOrder(BSTNode *root) { 
	if (root != NULL) { 
		bstPostOrder(root->left); 
		bstPostOrder(root->right); 
		printf("%d ", root->key); 
	} 
}

int avlHeight(BSTNode *N) 
{ 
	if (N == NULL)
		return 0; 
	return N->height;
} 

int max(int a, int b) 
{ 
	return (a > b)? a : b; 
} 

int avlGetBalance(BSTNode *N) 
{ 
	if (N == NULL) 
		return 0; 
	return avlHeight(N->left) - avlHeight(N->right); 
} 

BSTNode *avlNewNode(int item) { 
	BSTNode *temp = (BSTNode *)malloc(sizeof(BSTNode)); 
	temp->key = item;
	temp->height = 1;
	temp->left = temp->right = NULL;
	return temp; 
} 

void avlRightRotate(BSTNode** N) 
{ 
    BSTNode *Nl = (*N)->left;  
    BSTNode *Nlr = Nl->right; 
    Nl->right = (*N); 
    (*N)->left = Nlr;
    (*N) = Nl;
  
    Nl->height = max(avlHeight(Nl->left), avlHeight(Nl->right))+1;
    (*N)->height = max(avlHeight((*N)->left), avlHeight((*N)->right))+1;  
} 
  
void avlLeftRotate(BSTNode** N) 
{ 
    BSTNode *Nr = (*N)->right; 
    BSTNode *Nrl = Nr->left; 
    Nr->left = (*N); 
    (*N)->right = Nrl;
    (*N) = Nr; 
  
    Nr->height = max(avlHeight(Nr->left), avlHeight(Nr->right))+1; 
    (*N)->height = max(avlHeight((*N)->left), avlHeight((*N)->right))+1;   
} 
void avlPush(BSTNode** Node, int key)  { 
	if (*Node == NULL) 
	     (*Node) = avlNewNode(key); 
	else if (key < (*Node)->key) 
		avlPush(&((*Node)->left), key); 
	else 
		avlPush(&((*Node)->right), key);
		
  (*Node)->height = 1 + max(avlHeight((*Node)->left), avlHeight((*Node)->right)); 
  int balance = avlGetBalance(*Node); 

  if (balance > 1 && key < (*Node)->left->key)  {
      //printf("ll\n");
      avlRightRotate(Node);
  }    
  if (balance < -1 && key > (*Node)->right->key) {
  		//printf("rr\n");
      avlLeftRotate(Node); 
  }
  if (balance > 1 && key > (*Node)->left->key)
  { 
  		//printf("lr\n");
      avlLeftRotate(&((*Node)->left)); 
      avlRightRotate(Node); 
  } 
  if (balance < -1 && key < (*Node)->right->key) 
  { 
    	//printf("rl\n");
      avlRightRotate(&((*Node)->right)); 
      avlLeftRotate(Node);
  } 
}

void swap(int* a, int *b)  {
  int temp = *a;
  *a = *b;
  *b = temp;
}

void maxHeapUp(int* heap, int c )  {
	if(c == 0)
		return;
	int p = (c-1)/2;
	if(heap[c]>heap[p])
		swap(&heap[c],&heap[p]);
	maxHeapUp(heap, p);
}
void maxHeapDown(int* heap,int n,int c)  {
  int l = 2*c+1;
  int r = 2*c+2;
  if(l<n) {
		if((r<n) && (heap[r]>heap[l])) {
			if(heap[r]>heap[c])  {
		  	swap(&heap[r],&heap[c]);
		  }
		  maxHeapDown(heap,n,r);
		}  	
		else	{
		if(heap[l]>heap[c])  {
		  	swap(&heap[l],&heap[c]);
		  }
		  maxHeapDown(heap,n,l);
		}
	}
	else
		return;		
}
void maxHeapBuild(int* arr, int n)	{
    for (int i = n/2-1; i >= 0; i--) 
        maxHeapDown(arr, n, i);
}
  
void arrayPrint(int* arr, int n)  {
	for(int i=0; i<n; i++) {
		printf("%d ",arr[i]);
	}
	printf("\n");
}

void maxHeapPush(int* heap, int* n, int data)  {
  heap[(*n)++] = data;
  maxHeapUp(heap,(*n)-1);
}

int maxHeapPop(int* heap, int* n)  {
	int temp = heap[0];
	heap[0] = heap[(*n)-1];
	(*n)--;
	maxHeapDown(heap,*n,0);
	return temp;
}	

void minHeapUp(int* heap, int c )  {
	if(c == 0)
		return;
	int p = (c-1)/2;
	if(heap[c]<heap[p])
		swap(&heap[c],&heap[p]);
	minHeapUp(heap, p);
}
void minHeapDown(int* heap,int n,int c)  {
  int l = 2*c+1;
  int r = 2*c+2;
  if(l<n) {
		if((r<n) && (heap[r]<heap[l])) {
			if(heap[r]<heap[c])  {
		  	swap(&heap[r],&heap[c]);
		  }
		  minHeapDown(heap,n,r);
		}  	
		else	{
		if(heap[l]<heap[c])  {
		  	swap(&heap[l],&heap[c]);
		  }
		  minHeapDown(heap,n,l);
		}
	}
	else
		return;		
}
void minHeapBuild(int* arr, int n)	{
    for (int i = n/2-1; i >= 0; i--) 
        minHeapDown(arr, n, i);
}

void minHeapPush(int* heap, int* n, int data)  {
  heap[(*n)++] = data;
  minHeapUp(heap,(*n)-1);
}

int minHeapPop(int* heap, int* n)  {
	int temp = heap[0];
	heap[0] = heap[(*n)-1];
	(*n)--;
	minHeapDown(heap,*n,0);
	return temp;
}	


void wrap_sll_print(struct sll* s)  {
	sllPrint(s->head);	
}
void wrap_sll_rprint(struct sll* s)	{
	sllPrintInReverse(s->head);
}
void wrap_sll_istart(struct sll* s,int data)	{
	sllPushAtStart(&(s->head),&(s->tail),data);
}
void wrap_sll_iend(struct sll* s,int data)	{
	sllPushAtEnd(&(s->head),&(s->tail),data);
}
void wrap_sll_ipos(struct sll* s,int data,int pos)	{
	sllPushAtPosition(&(s->head),&(s->tail),data,pos);
}
void wrap_sll_reverse(struct sll* s)		{
	sllReverse(&(s->head));
}	
int wrap_sll_pop_start(struct sll* s)  {
   return sllPopAtStart(&(s->head), &(s->tail));
}
int wrap_sll_pop_end(struct sll* s)  {
   return sllPopAtEnd(&(s->head), &(s->tail));
}
int wrap_sll_is_empty(struct sll* s)  {
   return sllIsEmpty(s->head);
}
int wrap_sll_peek(struct sll* s)	{
	 return sllPeek(s->head);
}	 

	
void wrap_dll_print(struct dll* s)  {
	dllPrint(s->head);	
}
void wrap_dll_istart(struct dll* s,int data)	{
	dllPushAtStart(&(s->head),&(s->tail),data);
}
void wrap_dll_iend(struct dll* s,int data)	{
	dllPushAtEnd(&(s->head),&(s->tail),data);
}

int wrap_dll_pop_start(struct dll* s)  {
   return dllPopAtStart(&(s->head), &(s->tail));
}
int wrap_dll_pop_end(struct dll* s)  {
   return dllPopAtEnd(&(s->head), &(s->tail));
}
int wrap_dll_is_empty(struct dll* s)  {
   return dllIsEmpty(s->head);
}
int wrap_dll_peek(struct dll* s)	{
	 return dllPeek(s->head);
}	 


void wrap_stack_push(struct stack* s, int data)  {
	 sllPushAtStart(&(s->head),&(s->tail),data);
}
int wrap_stack_pop(struct stack* s) {
   return sllPopAtStart(&(s->head), &(s->tail));
}
int wrap_stack_peek(struct stack* s)  {
	 return sllPeek(s->head);
}
int wrap_stack_is_empty(struct stack* s)	{ 
   return sllIsEmpty(s->head);
}	 

void wrap_queue_push(struct queue* s, int data)  {
	 sllPushAtEnd(&(s->head),&(s->tail),data);
}
int wrap_queue_pop(struct queue* s) {
   return sllPopAtStart(&(s->head), &(s->tail));
}
int wrap_queue_peek(struct queue* s)  {
	 return sllPeek(s->head);
}
int wrap_queue_is_empty(struct queue* s)	{ 
   return sllIsEmpty(s->head);
}	 

void wrapBstPush(BST* b,int data)  {
	return bstPush(&(b->root),data);
}
void wrapBstInOrder(BST* b) {
	return bstInOrder((b->root));
}
void wrapBstPreOrder(BST* b)  {
	return bstPreOrder((b->root));
}
void wrapBstPostOrder(BST* b)  {
	return bstPostOrder((b->root));
}

void wrapAvlPush(AVL* a,int data)  {
	return avlPush(&(a->root),data);
}
void wrapAvlInOrder(AVL* a) {
	return bstInOrder((a->root));
}
void wrapAvlPreOrder(AVL* a)  {
	return bstPreOrder((a->root));
}
void wrapAvlPostOrder(AVL* a)  {
	return bstPostOrder((a->root));
} 

void wrapMaxHeapBuild(MaxHeap* m)	{
	return maxHeapBuild(m->heap,m->n);
}
void wrapMaxHeapPush(MaxHeap* m,int data) {
	return maxHeapPush(m->heap,&(m->n),data);
}
int wrapMaxHeapPop(MaxHeap* m)	{
	return maxHeapPop(m->heap,&(m->n));
}
int wrapMaxHeapPeek(MaxHeap* m)	{
	return *(m->heap);
}
void wrapMaxHeapPrint(MaxHeap* m)	{
	return arrayPrint(m->heap,m->n);
}

void wrapMinHeapBuild(MinHeap* m)	{
	return minHeapBuild(m->heap,m->n);
}
void wrapMinHeapPush(MinHeap* m,int data) {
	return minHeapPush(m->heap,&(m->n),data);
}
int wrapMinHeapPop(MinHeap* m)	{
	return minHeapPop(m->heap,&(m->n));
}
int wrapMinHeapPeek(MinHeap* m)	{
	return *(m->heap);
}
void wrapMinHeapPrint(MinHeap* m)	{
	return arrayPrint(m->heap,m->n);
}


 
SLL* createSLL()  {
     SLL* s = (SLL*)malloc(sizeof(SLL));
     s->head = NULL;
     s->tail  = NULL;
     s->print = wrap_sll_print;
     s->printreverse = wrap_sll_rprint;
     s->pushAtStart = wrap_sll_istart;
     s->pushAtEnd = wrap_sll_iend;
     s->pushAtPosition = wrap_sll_ipos;
		 s->popAtStart = wrap_sll_pop_start;
		 s->popAtEnd = wrap_sll_pop_end;
     s->reverse = wrap_sll_reverse;
     s->isEmpty = wrap_sll_is_empty;
     s->peek = wrap_sll_peek;
     return s;
}


DLL* createDLL()  {
     DLL* s = (DLL*)malloc(sizeof(DLL));
     s->head = NULL;
     s->tail  = NULL;
     s->print = wrap_dll_print;
     s->pushAtStart = wrap_dll_istart;
     s->pushAtEnd = wrap_dll_iend;
		 s->popAtStart = wrap_dll_pop_start;
		 s->popAtEnd = wrap_dll_pop_end;
     s->isEmpty = wrap_dll_is_empty;
     s->peek = wrap_dll_peek;
     return s;
}


Stack* createStack()	{
		Stack* s = (Stack*)malloc(sizeof(Stack));
		s->head = NULL;
		s->tail = NULL;
		s->push = wrap_stack_push;
		s->pop  = wrap_stack_pop;
		s->peek = wrap_stack_peek;
		s->isEmpty = wrap_stack_is_empty;
		return s;
}

Queue* createQueue()	{
		Queue* s = (Queue*)malloc(sizeof(Queue));
		s->head = NULL;
		s->tail = NULL;
		s->push = wrap_queue_push;
		s->pop  = wrap_queue_pop;
		s->peek = wrap_queue_peek;
		s->isEmpty = wrap_queue_is_empty;
		return s;
}

BST* createBST()  {
    BST *b = (BST*)malloc(sizeof(BST));
    b->root = NULL;
    b->push = &wrapBstPush;
    b->inOrder = &wrapBstInOrder;
    b->preOrder = &wrapBstPreOrder;
    b->postOrder = &wrapBstPostOrder;
    return b;
}

AVL* createAVL()  {
    AVL *a = (AVL*)malloc(sizeof(AVL));
    a->root = NULL;
    a->push = &wrapAvlPush;
    a->inOrder = &wrapAvlInOrder;
    a->preOrder = &wrapAvlPreOrder;
    a->postOrder = &wrapAvlPostOrder;
    return a;
}

MaxHeap* createMaxHeap(int* heaparray, int count)  {
	MaxHeap* m = (MaxHeap*)malloc(sizeof(MaxHeap));
	m->heap = heaparray;
	m->n = count;
	m->build = wrapMaxHeapBuild;
	m->push = wrapMaxHeapPush;
	m->pop = wrapMaxHeapPop;
	m->peek = wrapMaxHeapPeek;
	m->print = wrapMaxHeapPrint;
	return m;
}


MinHeap* createMinHeap(int* heaparray, int count)  {
	MinHeap* m = (MinHeap*)malloc(sizeof(MinHeap));
	m->heap = heaparray;
	m->n = count;
	m->build = wrapMinHeapBuild;
	m->push = wrapMinHeapPush;
	m->pop = wrapMinHeapPop;
	m->peek = wrapMinHeapPeek;
	m->print = wrapMinHeapPrint;
	return m;
}
		
