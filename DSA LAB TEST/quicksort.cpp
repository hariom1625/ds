
// 4.  (a) Write a program to sort a sequence of n integers using Quick sort technique and then search for a key in the
// sorted array using Binary search, linear search techniques.



#include <iostream>

using namespace std;

void swap(int* a, int* b)
{
    int z = *a;
    *a = *b;
    *b = z;
}

int divide (int a[], int low, int high)
{
    int pivot = a[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++)
    {
        if (a[j] < pivot)
        {
            i++;
            swap(&a[i], &a[j]);
        }
    }
    swap(&a[i + 1], &a[high]);

    return (i + 1);
}

void sorting(int a[], int low, int high)
{
    if (low < high)
    {

        int d = divide(a, low, high);

        sorting(a, low, d - 1);
        sorting(a, d + 1, high);
    }
}

void Display(int a[], int n)
{
    cout << endl;
    for (int i = 0; i < n; ++i)
        cout << a[i] << " ";
    cout << endl;
}

void linearSearch(int a[], int n) {

    int key = n, flag = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == key) {
            flag = 1;
            cout << "The element " << key << " is present in the list." << endl;
        }
    }
    if (flag == 0) {
        cout << "The element " << key << " is not present in the list." << endl;
    }

}

void binarySearch(int a[], int l, int h, int key) {

    int mid = 0, flag = 0;
    if (l <= h)
    {
        mid = (l + h) / 2;
        if (key == a[mid]) {
            flag = 1;
            cout << "The element " << key << " is present in the list.";
        }
        else if (key < a[mid])
            return binarySearch(a, l, mid - 1, key);
    }
    else
        return binarySearch(a, mid + 1, h, key);

    if (flag == 0) {
        cout << "The element " << key << " is not present in the list.";
    }



}


int main() {

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


    sorting(a, 0 , n - 1);

    cout << "The elements after Quick sorting are: ";
    Display(a, n);

    int key, c;
    cout << "Enter the number before the option for the type of search to be performed: 1.Linear Search" << "\t" << "2. Binary Search" << endl;
    cin >> c;
    cout << "Enter the number to search: ";
    cin >> key;
    switch (c) {

    case 1:
        linearSearch(a, key);
        break;
    case 2:
        binarySearch(a, 0, n - 1, key);
        break;

    default:
        cout << "Enter valid choice: ";

    }




}