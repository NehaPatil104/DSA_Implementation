#include <iostream>
#include <cmath>
using namespace std;

// Function to check if a number is a perfect square
bool isPerfectSquare(int num) {
    int sqrtNum = sqrt(num);
    return sqrtNum * sqrtNum == num;
}

int main() {
    int totalPlots;
    cin >> totalPlots;
    
    int plotAreas[totalPlots];
    
    for (int i = 0; i < totalPlots; i++) {
        cin >> plotAreas[i];
    }
    
    int squarePlotsCount = 0;
    for (int i = 0; i < totalPlots; i++) {
        if (isPerfectSquare(plotAreas[i])) {
            squarePlotsCount++;
        }
    }
    
    cout << squarePlotsCount << endl;
    
    return 0;
}
