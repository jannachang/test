#include <stdio.h>
#include <stdlib.h>

//
// global data structure declaration
//
struct Node {
	int d;
	struct Node *next;
};

//
// function declaration 
//
int printList();
struct Node *insertFront();

int printList(struct Node *l)
{
	struct Node *n=l;

	while (n != NULL) {
		printf("\t%d\n", n->d);
		n = n->next;
	}
	return 0;
}

struct Node *insertFront(struct Node *l, int data)
{
	struct Node *h = (struct Node *)malloc(sizeof(struct Node));

	h->d = data;
	h->next = l;
	return(h);
}


int main(int argc, char *argv[])
{
	int r; //return value
	struct Node *head = NULL;
	struct Node *second = NULL;
	struct Node *third = NULL;

	printf("create a simple linke list\n");

	head = (struct Node *)malloc(sizeof(struct Node));
	second = (struct Node *)malloc(sizeof(struct Node));
	third = (struct Node *)malloc(sizeof(struct Node));

	head->d = 1;
	head->next = second;

	second->d = 2;
	second->next = third;

	third->d = 3;
	third->next = NULL;

	r = printList(head);

	printf("insert to front\n");
	head = insertFront(head, 0);
	r = printList(head);

	return r;
}
