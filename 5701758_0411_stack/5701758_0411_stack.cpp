#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_STACK_SIZE 5

typedef int element;
typedef struct Stacktype {
	element stack[MAX_STACK_SIZE];//스택에 현재 들어간 아이템의 수 최솟값은 -1
	element* data;
	//int capacity=10;
	int top=-1;
}Stacktype;

Stacktype s1;
Stacktype s2;
//typedef int element;
//element stack2[MAX_STACK_SIZE];
//int top2 = -1;

// create : 이미 만듬, Stacktype의 변수를 선언하면 만들어짐
// delete : 할 수 없음
// 
// init 
void init(Stacktype* sptr) {
	//sptr->data = malloc()
	sptr->top = -1;
}

// is_empty
int is_full(Stacktype* sptr) {
	// return 대신
	// if(sptr->top == sptr->capacity - 1) {
	//sptr->capacity = sptr->capacity*2;
	//sptr->data = (element*)realloc(sptr->data, sptr->capacity*sizeof(element));
	//}
	return (sptr->top == MAX_STACK_SIZE - 1);
}

int is_empty(Stacktype* sptr) {
	return(sptr->top == -1);
}

// push
void push(Stacktype* sptr, element item) {
	if (is_full(sptr)) { //stack 풀
		fprintf(stderr, "stack Overflow\n");
		return;
	}
	else {
		sptr->top = sptr->top + 1;
		sptr->stack[sptr->top] = item;
	}
}

element pop(Stacktype* sptr) {
	//element r;
	if (is_empty(sptr)) {
		fprintf(stderr, "stack Underflow\n");
		return -1;
	}
	else {
		/*r = sptr->stack[sptr->top];
		sptr->top = sptr->top - 1;
		return r;*/
		return (sptr->stack[sptr->top--]);
	}
}

element peek(Stacktype* sptr) {

	srand((unsigned)time(NULL));
	//element r;
	if (is_empty(sptr)) {
		fprintf(stderr, "stack Underflow\n");
		return -1;
	}
	else {
		/*r = stack[top];
		top = top - 1;
		return r;*/
		return (sptr->stack[sptr->top]);
	}
}
int main() {
	Stacktype s;
	element e;
	srand((unsigned int)time(NULL));
	//is_full(&s);
	init(&s);
	int rand_num;
	rand_num = rand() % 100 + 1;
	int numOfStack=0;


	int data;
	for (int i = 0; i < 30; i++) {
		//printf("%d \n", rand_num);
		if (rand_num % 2 == 0) {
			printf("current rand_num : %d | Even\n", rand_num = rand() % 100 + 1);
			push(&s, rand_num);
			printf("Push : %d\n", rand_num);
			printf("Stack elemnets: ");
			for (int i = 0; i < s.top + 1; i++) {
				printf(" %d ", s.stack[i]);
			}
			printf("\n");
		}
		else {
			printf("current rand_num : %d | Odd\n", rand_num = rand() % 100 + 1);
			data = pop(&s);
			printf("Pop : %d\n", data);
			printf("Stack elemnets: ");
			for (int i = 0; i < s.top + 1; i++) {
				printf(" %d ", s.stack[i]);
			}
			data = 0;
			printf("\n");
		}

		//if (is_full(s->top)==1) {
		//	printf("Stack Overflow\n");
		//}
		//else if (is_empty(s.top) == 1) {
		//	printf("Stack Underflow\n");
		//	printf("Stack is empty\n");
		//	printf("\n");
		//}
		//}
	}
	/*e = rand() % 100 + 1;
	for (int i = 0; i < 5; i++) {
		if (e % 2 == 0) {
			push(e);
			printf("Push %d\n", e);
		}
		else {
			e = pop();
			printf("Pop %d\n", e);
		}
	}*/
}