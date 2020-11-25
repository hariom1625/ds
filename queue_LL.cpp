#include <bits/stdc++.h>

using namespace std;

struct Node {

	int data;
	struct Node *next;
}*front = NULL, *rear = NULL;

void enqueue (int x) {

	struct Node *t;
	t = (struct Node *)malloc(sizeof(struct Node));
	if (t == NULL) {
		cout << "Queue is Full \n";
	}
	else {
		t->data = x;
		t->next = NULL;
		if (front == NULL) {
			front = t;
			rear = t;

		}
		else {
			rear->next = t;
			rear = t;
		}


	}
}

int dequeue() {

	int x = -1;

	struct Node *t;

	if (front == NULL) {
		cout << "Queue is Empty \n";
	}
	else {
		x = front->data;
		t = front;
		front = front ->next;
		free(t);
	}
	return x;
}

void Display() {

	struct Node *p = front;

	while (p) {
		cout << p->data << " ";
		p = p->next;

	}
}
int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n, a;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a;
		enqueue(a);
	}
	Display();

}
