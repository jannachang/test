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
struct Node *insertToFront();

int printList(struct Node *l)
{
	struct Node *n=l;

	printf("The list: [ ");

	while (n != NULL) {
		printf("%d ", n->d);
		n = n->next;
	}
	printf("]\n");
	return 0;
}

//
// insert data to the front of the list
// return the new list
//
struct Node *insertToFront(struct Node *l, int data)
{
	struct Node *h = (struct Node *)malloc(sizeof(struct Node));

	h->d = data;
	h->next = l;
	return(h);
}


int main()
{
	struct Node *list = NULL;
	int data=-1;

	printf("create a simple linke list\n");

	while (1) {
		printf("node value: ");
		scanf("%d", &data);
		if (data == -1) {
		       	break;  
		} else {
			list = insertToFront(list, data);
		}
	}

	printList(list);
	return 0;
}
