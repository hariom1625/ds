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
	q->Q = (int *)malloc(q->size * sizeof(int ));

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




}
int main() {




#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	struct Queue q;
	int n;
	cin >> n;
	Create(&q, n);

	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		enqueue(&q, a);
	}
	Display(&q);

}