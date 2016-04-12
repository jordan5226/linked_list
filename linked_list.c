/*
  Name: Linked list practice
  Copyright: Jordan Yeh
  Author: Jordan Yeh (jordan5226@gmail.com)
  Date(DD/MM/YYYY): 07/04/2016 16:22
  Description: A practice of linked list operation.
*/

#include <stdio.h>

typedef struct list_node{
	char data;
	struct list_node *next;
}Node;

#define SWAP(a, b) {struct list_node *t=a; a=b; b=t;}


void insertNode(Node **ptr, char data)
{
	Node *newNode;
	if(*ptr == NULL) // �Y��C���� 
	{ // �إ߷s�`�I�A�ç��C�Y���w���V�s�`�I 
		newNode = (Node*)malloc(sizeof(Node));
		*ptr = newNode;
	}
	else
	{
		newNode = *ptr;
		while(newNode->next != NULL) // �`���M��list���� 
		{
			newNode =  newNode->next;
		}
		newNode->next = (Node*)malloc(sizeof(Node)); // �b���ݫإ߷s��Node
		newNode = newNode->next;
	}
	newNode->data = data;
	newNode->next = NULL;
}


int deleteNode(Node **ptr, char data)
{
	Node *node, *preNode;
	if(*ptr == NULL)
		return 0;
	node = *ptr;
	while(node != NULL) // �`���j�Mlist�`�I 
	{
		if(node->data == data) // �Y�d���֦��Ӽƾڪ��`�I 
		{ // �R���Ӹ`�I 
			if(node == *ptr) // �Y�Ӹ`�I�Olist�Y 
				*ptr = node->next; //list�Y�]�m����@�Ӹ`�I  
			else
				preNode->next = node->next; // ��e�@�Ӹ`�I�P��@�Ӹ`�I�۳s 
			free(node); // �R���`�I 
			return 1;
		}
		// �M��U�@�Ӹ`�I  
		preNode = node;
		node = node->next;
	}
	return 0; // �S���`�I 
}


void printList(Node *ptr)
{
	while(ptr != NULL)
	{
		printf("%c->", ptr->data);
		ptr = ptr->next;
	}
	printf("NULL\n");
}


int swapNode(Node **ptr, char data1, char data2)
{
	Node *n1, *n2, *pre_n1, *pre_n2;
	Node *node;
	int found_n1=0, found_n2=0;
	
	if(*ptr == NULL)
		return 0;
	node=n1=n2=*ptr;
	
	// �M��data1�Bdata2���`�In1,n2 
	while(node != NULL)
	{
		if(node->data == data1) // ���n1 
			found_n1 = 1;
		else if(node->data == data2) // ���n2 
			found_n2 = 1;
			
		if(!found_n1) // �Yn1�S��� 
		{ // ���U�j�M 
			pre_n1 = node;
			n1 = node->next;
		}
		if(!found_n2) // �Yn2�S��� 
		{ // ���U�j�M 
			pre_n2 = node;
			n2 = node->next;
		}
		node = node->next;
	}
	if(!found_n1 || !found_n2) // �Y������@�Ӹ`�I�S���A�h���� 
		return 0;
	
	if(n1 != n2)
	{
		// preNode->next���� 
		if(n1 == *ptr) // n1�O�Y
		{
			*ptr = n2;
			pre_n2->next = n1;
		}
		else if(n2 == *ptr) // n2�O�Y
		{
			*ptr = n1;
			pre_n1->next = n2;
		}
		else
		{
			SWAP(pre_n1->next, pre_n2->next)
		}
		// �洫Node->next 
		SWAP(n1->next, n2->next)
		
		return 1;
	}
	
	return 0;
}


int main()
{
	Node *head = NULL;
	char in, data1, data2;
	
	while(1)
	{
		printf("\n(1)insert\n");
		printf("(2)delete\n");
		printf("(3)print\n");
		printf("(4)swap\n");
		printf("(5)exit\n");
		printf(">>");
		fflush(stdin);
		scanf("%c", &in);
		switch(in)
		{
		case '1':
			fflush(stdin);
			scanf("%c", &data1);
			insertNode(&head, data1);
			break;
		case '2':
			fflush(stdin);
			scanf("%c", &data1);
			if(deleteNode(&head, data1))
				printf("Delete successful!\n");
			else
				printf("Delete failed!\n");
			break;
		case '3':
			printList(head);
			break;
		case '4':
			fflush(stdin);
			scanf("%c %c", &data1, &data2);
			if(swapNode(&head, data1, data2))
				printf("Swap successful!\n");
			else
				printf("Swap failed!\n");
			break;
		case '5':
			return 0;
		}
		printList(head);
	}
	return 0;
}
