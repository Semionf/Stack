#include <stdio.h>
#include <stdlib.h>

#pragma warning (disable:4996)

typedef struct Item {
	int id;
	int val;
	int val2;
	struct Item* next;
	struct Item* prev;
}Item;

void Push(int, int);
Item* Pop();
void PrintList();
void freeList();

int ID_COUNTER = 1;
Item* head = NULL, * tail = NULL;
int main()
{
	srand(time());
	char ch = 0;
	while (ch != 'E')
	{
		printf("I - push, P - Pop, L - PrintList, B - pust 100 random numbers.\n");
		ch = getch();
		switch (ch)
		{
		case 'I':
			Push(rand(), rand());
			break;
		case 'P':
		{
			Item* temp;
			temp = Pop();
			printf("Item id deleted: %d\n", temp->id);
		}
		break;
		case 'L':
			PrintList();
			break;
		case 'B':
			for (int i = 0; i < 100; i++)
			{
				Push(rand(), rand());
			}
			break;
		case 'E':
			break;
		default:
			printf("Wrong input\n");
			break;
		}
	}
	freeList();
}

void Push(int val, int val2)
{
	Item* temp = (Item*)malloc(sizeof(Item));
	temp->next = temp->prev = NULL;
	temp->val = val;
	temp->val2 = val2;
	temp->id = ID_COUNTER;
	ID_COUNTER++;
	if (!head)
	{
		head = tail = temp;
	}
	else {
		tail->next = temp;
		temp->prev = tail;
		tail = temp;
	}
}

Item* Pop()
{
	if (!tail)
	{
		tail = head = NULL;
		return NULL;
	}
	else if(!tail->prev) {
		Item* temp;
		temp = tail;
		tail->next = NULL;
		tail= head = NULL;
		return temp;
	}
	else{
		Item* temp;
		temp = tail;
		tail = tail->prev;
		tail->next = NULL;
		return temp;
	}
}

void PrintList()
{
	if (!head)
	{
		printf("The list is empty.\n");
	}
	else {
		Item* curr = (Item*)malloc(sizeof(Item));
		curr = head;
		while (curr)
		{
			printf("The first value is: %d, The second value is: %d, And the id is: %d\n", curr->val, curr->val2, curr->id);
			curr = curr->next;
		}
	}
}

void freeList()
{
	if (head)
	{
		Item* curr;
		while (head)
		{
			curr = head;
			head = head->next;
			free(curr);
		}
		tail = head = NULL;
	}
}