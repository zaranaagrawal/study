
#include <iostream>
using namespace std;

struct Node
{
	int data;
	Node *next;
};

Node* SortMerge(Node* L1, Node* L2)
{
	Node dummy;
	Node* tail = &dummy;
	dummy.next = NULL;
	while(1)
	{
		if(L1 == NULL)
		{
			tail->next = L2;
			break;
		}
		else if(L2 == NULL)
		{
			tail->next = L1;
			break;
		}
		else if( L1->data > L2->data)
		{
			tail->next= L2;
			L2= L2->next;
		}
		else
		{
			tail->next= L1;
			L1 = L1->next;
		}
		tail=tail->next;
	}
	return dummy.next;
}

void PrintList(Node *head)
{
	while(head != NULL)
	{
		cout << head->data << "--";
		head = head->next;
	}
}
void AddNode(Node **head, int data)
{
	Node* newnode = (Node*)malloc(sizeof(Node));
	newnode->data = data;
	newnode->next = *head;

    *head = newnode; 
}
int main()
{
	Node* L1 = NULL;
	Node* L2 = NULL;

	AddNode(&L1, 100);
	AddNode(&L1, 90);
	AddNode(&L1, 70);
	AddNode(&L1, 50);
	AddNode(&L1, 10);

	cout << "list 1:"<<endl;
	PrintList(L1);

	AddNode(&L2, 80);
	AddNode(&L2, 60);
	AddNode(&L2, 40);
	AddNode(&L2, 30);
	AddNode(&L2, 20);

	cout << "list 2 :"<<endl;
	PrintList(L2);

	Node* sortedlist = SortMerge(L1, L2);
	cout<<" Sorted Lsit :"<<endl;
	PrintList(sortedlist);
	return 0;
}