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
	if(*ptr == NULL) // 若串列為空 
	{ // 建立新節點，並把串列頭指針指向新節點 
		newNode = (Node*)malloc(sizeof(Node));
		*ptr = newNode;
	}
	else
	{
		newNode = *ptr;
		while(newNode->next != NULL) // 循環尋找list尾端 
		{
			newNode =  newNode->next;
		}
		newNode->next = (Node*)malloc(sizeof(Node)); // 在尾端建立新的Node
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
	while(node != NULL) // 循環搜尋list節點 
	{
		if(node->data == data) // 若查找到擁有該數據的節點 
		{ // 刪除該節點 
			if(node == *ptr) // 若該節點是list頭 
				*ptr = node->next; //list頭設置為後一個節點  
			else
				preNode->next = node->next; // 把前一個節點與後一個節點相連 
			free(node); // 刪除節點 
			return 1;
		}
		// 尋找下一個節點  
		preNode = node;
		node = node->next;
	}
	return 0; // 沒找到節點 
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
	
	// 尋找data1、data2的節點n1,n2 
	while(node != NULL)
	{
		if(node->data == data1) // 找到n1 
			found_n1 = 1;
		else if(node->data == data2) // 找到n2 
			found_n2 = 1;
			
		if(!found_n1) // 若n1沒找到 
		{ // 往下搜尋 
			pre_n1 = node;
			n1 = node->next;
		}
		if(!found_n2) // 若n2沒找到 
		{ // 往下搜尋 
			pre_n2 = node;
			n2 = node->next;
		}
		node = node->next;
	}
	if(!found_n1 || !found_n2) // 若有任何一個節點沒找到，則失敗 
		return 0;
	
	if(n1 != n2)
	{
		// preNode->next先換 
		if(n1 == *ptr) // n1是頭
		{
			*ptr = n2;
			pre_n2->next = n1;
		}
		else if(n2 == *ptr) // n2是頭
		{
			*ptr = n1;
			pre_n1->next = n2;
		}
		else
		{
			SWAP(pre_n1->next, pre_n2->next)
		}
		// 交換Node->next 
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
