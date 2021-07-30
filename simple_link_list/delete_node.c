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
struct Node *deleteNode();

int printList(struct Node *l)
{
	struct Node *n=l;

	printf("The list: ");

	while (n != NULL) {
		printf(" %d", n->d);
		n = n->next;
	}

	printf("\n");
	return 0;
}


//
// given a link list pointed to by "l", 
// insert the data to the front of the list
// return new list pointed to by the head
//
struct Node *insertFront(struct Node *l, int data)
{
	struct Node *h = (struct Node *)malloc(sizeof(struct Node));

	h->d = data;
	h->next = l;
	return(h);
}


//
// delete all nodes with given "data"
// return the pointer to the new list
//
struct Node *deleteNode(struct Node *list, int data)
{
	struct Node *cur = list; // current node being visited
	struct Node *pre, *next = NULL; // pointers to previous and next nodes

	if (cur == NULL) { // empty list
		printf("empty list, nothing to delete\n");
		return NULL; 
	}
	if (cur->d == data) { // to delete the header node
		printf("delete head node %d\n", data);
		list = cur->next;
		free(cur);
		return(list);
	}

	pre = list;
	cur = pre->next;
	while (cur != ((struct Node *)NULL)) {
		if (cur->d == data) {
			// printf("delete value: %d\n", data);
			pre->next = cur->next;
			free(cur);
			cur = pre->next;
		} else {
			pre = cur;
			cur = cur->next;
		}
	}
	return(list);
}


int main(int argc, char *argv[])
{
	int r=0; //return value
	int new_data = -1;
	struct Node *head = NULL;

	printf("create a simple linke list\n");
	while (1) { 
		printf("new data: ");
		scanf("%d", &new_data);
		if (new_data != -1) {
			head = insertFront(head, new_data);
			new_data = -1;
		} else {
			break;
		}
	}

	printList(head);

	printf("delete value: ");
	scanf("%d", &new_data);
	if (new_data != -1){
		head = deleteNode(head, new_data);	
	}

	printList(head);

	return r;
}
