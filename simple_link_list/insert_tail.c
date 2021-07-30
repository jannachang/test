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
struct Node *traverseList(); 
int insertToTail();

int printList(struct Node *l)
{
	struct Node *n=l;

	while (n != NULL) {
		printf("\t%d\n", n->d);
		n = n->next;
	}
	return 0;
}

//
// insert data to the front of the list
//
struct Node *insertToFront(struct Node *l, int data)
{
	struct Node *h = (struct Node *)malloc(sizeof(struct Node));

	h->d = data;
	h->next = l;
	return(h);
}


//
// traverse the list, return pointer to the last node
//
struct Node *traverseList(struct Node *node)
{
	if (node != NULL) {
		while (node->next != NULL) {
			node = node->next; 
		}
	}
	return (node);
}


//
// insert to list tail
// return 1, if fail
// return 0, when success
//
int insertToTail(struct Node *list, int data){
	struct Node *last_node = NULL;
	struct Node *new_node = NULL;

	if ((last_node = traverseList(list)) != NULL){  
		new_node = (struct Node *)malloc(sizeof(struct Node));
		new_node->d = data;
		new_node->next = NULL;

		last_node->next = new_node;
		return 0;
	} else {
		return 1;
	}
}


int main(int argc, char *argv[])
{
	int r; //return value
	int new_data;
	struct Node *head = NULL;
	struct Node *second = NULL;
	struct Node *third = NULL;
	struct Node *last_node = NULL;

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

	//
	// insert a node to the front
	//
	printf("insert to front\n");
	head = insertToFront(head, 0);
	r = printList(head);

	//
	// insert a node to the tail
	// 
	printf("insert to tail: ");
	scanf("%d", &new_data);
 	insertToTail(head, new_data);
	r = printList(head);

	return r;
}
