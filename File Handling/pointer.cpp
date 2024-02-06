#include <iostream>

using namespace std;

int main()
{
    int a = 500;
    int *b = &a;
    cout<<*b<<" : ";
    int arr[5] = {1, 2, 3, 4, 5};
    int *ptr = &arr[0];

    ptr++; // Moves the pointer to the next element (points to arr[1])
    cout<<*ptr<<"\t";
    ptr++; // Moves the pointer to the previous element (points to arr[0] again)
    cout<<*ptr<<" \t";
    ptr = ptr + 2;
    cout<<*ptr<<" \t";
}