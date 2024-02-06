#include <bits/stdc++.h>
using namespace std;
int computeXOR(int n)
{
	if (n == 0)
		return 0; // base case
	int uni = 0;
    int sum = 0;
	for (int i = 1; i <= n; i++) {
		uni = uni ^ i; // calculate XOR
        sum += uni;
	}
	return sum;
}
int main()
{
	int n = 1;
	int result = computeXOR(n);
	cout << result << endl;
	return 0;
}
/* This code is contributed by Rishab Dugar */
