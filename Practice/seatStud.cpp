#include <iostream>

using namespace std;

// Function to calculate factorial
long long factorial(int n) {
    if (n <= 1) return 1;
    return n * factorial(n - 1);
}

// Function to calculate the number of ways to seat n students
long long calculateWaysToSeatStudents(int n) {
    long long numerator = factorial(n * n);
    long long denominator = factorial(n);
    return numerator / denominator;
}

int main() {
    int n;
    cin >> n; // Input the number of students
    long long ways = calculateWaysToSeatStudents(n);
    
    // Output
    cout << "Number of ways to seat " << n << " students: " << ways << endl;

    return 0;
}
