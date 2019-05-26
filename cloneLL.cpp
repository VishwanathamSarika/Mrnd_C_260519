#include<stdio.h>
#include<stdlib.h>

struct Node{
	int data;
	struct Node *next;
	struct Node *random;
};

struct Node* createNewNode(int x){
	struct Node *p = (struct Node*)malloc(sizeof(struct Node));
	p->data = x;
	p->next = NULL;
	p->random = NULL;
	return p;
}

void display(struct Node *p){
	while (p != NULL){
		printf("\nData: %d ", p->data);
		printf("Random data: %d", p->random->data);
		p = p->next;
	}
}

struct Node* clone(struct Node *head){
	struct Node *p1 = head,*p2,*newHead;
	struct Node *temp;
	while (p1 != NULL){
		temp = createNewNode(p1->data);
		temp->next = p1->next;
		p1->next = temp;
		p1 = p1->next->next;
	}
	p1 = head;
	while (p1 != NULL){
		p2 = p1->next;
		p2->random = p1->random->next;
		p1 = p1->next->next;
	}
	p1 = head;
	p2 = newHead = head->next;
	while (p2->next != NULL){
		p1->next = p1->next->next;
		p2->next = p2->next->next;
		p1 = p1->next;
		p2 = p2->next;
	}
	p1->next = NULL;
	return newHead;
}

void test_clonell(){
	struct Node *head = createNewNode(1);
	struct Node *p = head;
	int i;
	for (i = 0; i < 4; i++){
		p->next = createNewNode(i + 2);
		p = p->next;
	}
	p->next = NULL;
	p = head;
	p->random = head->next->next;
	p->next->random = head;
	p->next->next->random = head->next->next->next->next;
	p->next->next->next->random = head->next->next->next->next;
	p->next->next->next->next->random = head->next;
	printf("Original list data is:");
	display(head);
	printf("\nCloned list data is:");
	display(clone(head));
	printf("\nOriginal list data after cloning is:");
	display(head);
	scanf_s("%s");
}
