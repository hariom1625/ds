// 3.	Write a C program to implement a queue using arrays and linked list
// in which insertions, deletions and display can be performed.

#include <bits/stdc++.h>

using namespace std;

struct Queue {

	int size;
	int front;
	int rear;
	int *Q;
};


void Create(struct Queue *q, int size) {

	q->size = size;
	q->front = q->rear = -1;
	q->Q = new int;

}

void enqueue(struct Queue *q, int x) {

	if (q->rear == q->size - 1) {
		cout << "Queue is Full \n";
	}
	else {
		q->rear++;
		q->Q[q->rear] = x;
	}


}

int dequeue(struct Queue *q) {

	int x = -1;
	if (q->front == q->rear) {
		cout << "Queue is Empty \n";
	}
	else {
		q->front++;
		x = q->Q[q->front];
	}

	return x;
}

void Display(struct Queue *q) {

	int i;

	for (i = q->front + 1; i <= q->rear; i++) {

		cout << q->Q[i] << " ";
	}

	cout << endl;

}
int main() {

	int i = 0, c, num, p, d, l;
	struct Queue q;
	int n;

	do {
		cout << "Enter the index of the operation to be performed: " << endl << "1.Insert"
		     << endl << "2.Delete" << endl << "3.Display" << endl <<
		     endl;
		cin >> c;
		switch (c) {
		case 1:
			cout << "Enter number of elements to be entered: ";
			cin >> n;
			Create(&q, n);
			cout << "Enter the numbers to be stored: " << endl;
			for (int i = 0; i < n; i++) {
				int a;
				cin >> a;
				enqueue(&q, a);
			}

			break;

		case 2:
			dequeue(&q);
			break;

		case 3:
			Display(&q);
			break;

		default:
			cout << "Enter valid choice." << endl;
		}
		cout << "Do you want to quit ?" << "Enter 1 to continue & 0 to quit. " << endl;
		cin >> p;
		cout << endl;

	} while (p != 0);








}
