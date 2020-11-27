// 5.	Write a C program to construct a binary tree and do inorder, preorder and postorder traversals, printing the sequence of nodes visited in each case.

#include <iostream>

using namespace std;

class Node {

public:
	Node *lchild;
	int data;
	Node *rchild;
};

class Queue
{
private:
	int front;
	int rear;
	int size;
	Node **Q;
public:
	Queue() {front = rear = -1; size = 10; Q = new Node*[size];}
	Queue(int size) {
		front = rear = -1; this -> size = size; Q = new Node*[this->size];
	}
	void enqueue(Node* x);
	Node* dequeue();
	void Display();
	int isEmpty() {return front == rear;}
};

void Queue::enqueue(Node *x)
{
	if (rear == size - 1)
		cout << "Queue Full\n";
	else
	{
		rear++;
		Q[rear] = x;
	}
}
Node* Queue::dequeue()
{
	Node* x = NULL;
	if (front == rear)
		cout << "Queue is Empty\n";
	else {
		x = Q[front + 1];
		front++;
	}
	return x;
}
void Queue::Display()
{
	for (int i = front + 1; i <= rear; i++)
		cout << Q[i];
	cout << endl;
}


class Tree
{
	Node *root;
public:
	Tree() {root = NULL;}
	void CreateTree();
	void Preorder() {Preorder(root);}
	void Preorder(Node *p);
	void Postorder() {Postorder(root);}
	void Postorder(Node *p);
	void Inorder() {Inorder(root);}
	void Inorder(Node *p);
};


void Tree::CreateTree()
{
	Node *p, *t;
	int x;
	Queue q(100);
	cout << "Enter root value: " << " ";
	cin >> x;
	root = new Node;
	root->data = x;
	root->lchild = root->rchild = NULL;
	q.enqueue(root);
	while (!q.isEmpty()) {
		p = q.dequeue();
		cout << "Enter left child of " << p->data << ": ";
		cin >> x;
		if (x != -1)
		{
			t = new Node;
			t->data = x;
			t->lchild = t->rchild = NULL;
			p->lchild = t;
			q.enqueue(t);
		}
		cout << "Enter right child of " << p->data << ": ";
		cin >> x;
		if (x != -1)
		{
			t = new Node;
			t->data = x;
			t->lchild = t->rchild = NULL;
			p->rchild = t;
			q.enqueue(t);
		}
	}
}
void Tree::Preorder(struct Node *p)
{
	if (p)
	{
		cout << p->data << " ";
		Preorder(p->lchild);
		Preorder(p->rchild);
	}
}
void Tree::Inorder(struct Node *p)
{
	if (p)
	{	Inorder(p->lchild);
		cout << p->data << " ";
		Inorder(p->rchild);
	}
}
void Tree::Postorder(struct Node *p)
{
	if (p)
	{
		Postorder(p->lchild);
		Postorder(p->rchild);
		cout << p->data << " ";
	}
}

int main()
{
	cout << "Enter -1 if no left or right child is present." << endl;
	Tree t;
	t.CreateTree();
	cout << "Preorder Traversal is: ";
	t.Preorder();
	cout << endl;
	cout << "Inorder Traversal is: ";
	t.Inorder();
	cout << endl;
	cout << "Postorder Traversal is: ";
	t.Postorder();
	cout << endl << endl;
	return 0;
}
