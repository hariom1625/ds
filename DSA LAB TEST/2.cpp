

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *next;
}*Head;


void create(int A[], int n)
{
	int i;
	struct Node *t, *last;
	Head = new Node;
	Head->data = A[0];
	Head->next = Head;
	last = Head;
	for (i = 1; i < n; i++)
	{
		t = new Node;
		t->data = A[i];
		t->next = last->next;
		last->next = t;
		last = t;
	}
}

void Display(struct Node *h)
{
	cout << "The entered Numbers are: " << endl;
	do
	{
		cout << h->data << " ";
		h = h->next;
	} while (h != Head);
	cout << endl;

}

int Length(struct Node *p)
{
	int len = 0;
	do
	{
		len++;
		p = p->next;
	} while (p != Head);
	return len;
}

void Insert(struct Node *p, int index, int x)
{
	struct Node *t;
	int i;

	if (index == 0)
	{
		t = new Node;
		t->data = x;
		if (Head == NULL)
		{	Head = t;
			Head->next = Head;
		}
		else
		{
			while (p->next != Head)p = p->next;
			p->next = t;
			t->next = Head;
			Head = t;
		}
	}
	else
	{
		for (i = 0; i < index - 1; i++)p = p->next;
		t = new Node;
		t->data = x;
		t->next = p->next;
		p->next = t;
	}
}
int Delete(struct Node *p, int index)
{
	struct Node *q;
	int i, x;
	if (index < 0 || index > Length(Head))
		return -1;
	if (index == 1)
	{
		while (p->next != Head)p = p->next;
		x = Head->data;
		if (Head == p)
		{
			free(Head);
			Head = NULL;
		}
		else {
			p->next = Head->next;
			free(Head);
			Head = p->next;
		}
	}
	else
	{
		for (i = 0; i < index - 2; i++)
			p = p->next;
		q = p->next;
		p->next = q->next;
		x = q->data;
		free(q);
	}
	return x;
}
int main()
{

	int i = 0, c, num, p, d, l;

	do {
		cout << "Enter the index of the operation to be performed: " << endl << "1.Insert a Node"
		     << endl << "2.Delete a Node" << endl << "3.Count Number of Node" << endl << "4.Display" << endl <<
		     endl;
		cin >> c; switch (c) {
		case 1:
			cout << "Enter the Number to be inserted: ";
			cin >> num;
			Insert(Head, i, num);
			break;

		case 2:
			cout << "Enter the index of the number to be deleted: ";
			cin >> d;
			Delete(Head, d);
			break;
		case 3:
			l = Length(Head);
			cout << "The number of Nodes are: " << l << endl;
			break;
		case 4:
			Display(Head);
			break;

		default:
			cout << "Enter valid choice." << endl;
		}
		cout << "Do you want to quit ?" << "Enter 1 to continue & 0 to quit. " << endl;
		cin >> p;
		cout << endl;

	} while (p != 0);



	return 0;
}
