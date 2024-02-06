#include <iostream>
using namespace std;

int countWaysToClimbStairs(int n) {
    if (n <= 1) {
        return 1; // There is only one way to climb 0 or 1 stair.
    }

    return countWaysToClimbStairs(n - 1) + countWaysToClimbStairs(n - 2);
}

int main() {
    int n;
    cin >> n; // Input the number of stairs
    int ways = countWaysToClimbStairs(n);
    cout << "Number of ways to climb " << n << " stairs: " << ways << endl;
    return 0;
}
