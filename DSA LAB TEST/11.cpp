//1.	Write an interactive C program to create a linear linked list of customer names and their telephone numbers. The program should be menu-driven and include features for adding a new customer, deleting an existing customer and for displaying the list of all customers.

#include <iostream>

#include <bits/stdc++.h>

using namespace std;

struct Node
{
	string name;
	long long int num;
	struct Node *next;
}*first = NULL;

void create(int A[], int n)
{
	int i;
	struct Node *t, *last;

	first = new Node;
	first->num = A[0];
	first->next = NULL;
	last = first;
	for (i = 1; i < n; i++)
	{
		t = new Node;
		t->num = A[i];
		t->next = NULL;
		last->next = t;
		last = t;
	}
}

void Display(struct Node *p)
{
	while (p != NULL)
	{
		cout << "Customer Name: " << p->name << endl;
		cout << "Telephone Number: " << p->num << endl;
		p = p->next;
	}
}

int count(struct Node *p)
{
	int len = 0;
	while (p)
	{
		len++;
		p = p->next;
	}
	return len;
}

void Insert(struct Node *p, int index, long long int x, string s)
{
	struct Node *t;
	int i;
	if (index < 0 || index > count(p))
		return;
	t = new Node;
	t->name = s;
	t->num = x;
	if (index == 0)
	{
		t->next = first;
		first = t;
	}
	else
	{
		for (i = 0; i < index - 1; i++)
			p = p->next;
		t->next = p->next;
		p->next = t;
	}
}

int Delete(struct Node *p, int index)
{
	struct Node *q = NULL;
	int x = -1, i;
	string s;
	if (index < 1 || index > count(p))
		return -1;
	if (index == 1)
	{
		q = first;
		x = first->num;
		s = first->name;
		first = first->next;
		free(q);
		return x;
	}
	else
	{
		for (i = 0; i < index - 1; i++)
		{
			q = p;
			p = p->next;
		}
		q->next = p->next;
		x = p->num;
		s = p->name;
		free(p);
		return x;
	}
}

int main()
{

	int c, i = 0;
	string s;
	long long int num;
	int d, p;

	do {
		cout << "Enter the index of the operation to be performed: " << endl << "1.Insert"
		     << endl << "2.Delete" << endl << "3.Display" << endl;
		cin >> c;
		switch (c) {
		case 1:
			cout << "Enter Customer Name: ";
			cin >> s;
			cout << "Enter Telephone Number: ";
			cin >> num;
			Insert(first, i++, num, s);
			break;
		case 2:
			cout << "Enter the index of the number to be deleted: ";
			cin >> d;
			Delete(first, d);
			break;
		case 3:
			Display(first);
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
