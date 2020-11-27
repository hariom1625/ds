#include <iostream>

using namespace std;



void doheapify(int a[] , int , int);
void sorting(int a[] , int);

void sorting(int a[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        doheapify(a, n, i);


    for (int i = n - 1; i > 0; i--) {

        swap(a[0], a[i]);


        doheapify(a, i, 0);
    }
}

void doheapify(int a[], int n, int m)
{
    int max = m;
    int l = 2 * m + 1;
    int r = 2 * m + 2;

    if (l < n && a[l] > a[max])
        max = l;


    if (r < n && a[r] > a[max])
        max = r;

    if (max != m) {
        swap(a[m], a[max]);


        doheapify(a, n, max);
    }
}

void Display(int a[], int n)
{
    for (int i = 0; i < n; ++i)
        cout << a[i] << " ";
    cout << endl;
}


int main()
{

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cout << "Enter number of elements: ";

    cin >> n;
    int a[n];

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }


    sorting(a, n);

    cout << "The sorted elements are: ";
    Display(a, n);

}