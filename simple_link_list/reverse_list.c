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
struct Node *insertToFront(struct Node *list, int data)
{
	struct Node *h = (struct Node *)malloc(sizeof(struct Node));

	h->d = data;
	h->next = list;
	return(h);
}


//
// give a linked list
// return a list with all node reversed
//
struct Node *reverseList(struct Node *list)
{
	struct Node *cur = list;
	struct Node *pre = NULL;
	struct Node *next = NULL;

	while (cur != NULL) {
		next = cur->next; // remember next before break the link
		cur->next = pre; // rever the node

		// repositon the cursers
		pre = cur;
	        cur = next;
	}

	list = pre;
	return(list);
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

	list = reverseList(list);
	printf("reversed list: ");
	printList(list);

	return 0;
}
