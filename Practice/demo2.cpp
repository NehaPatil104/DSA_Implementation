#include <iostream>
#include <vector>
#include <unordered_map>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> arr(n);

    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }

    std::unordered_map<int, int> frequency;
    int smallest_odd = -1;
    int max_frequency = 0;

    for (int i = 0; i < n; ++i) {
        if (arr[i] % 2 != 0) { // Check if the number is odd
            frequency[arr[i]]++;

            if (frequency[arr[i]] > max_frequency || (frequency[arr[i]] == max_frequency && (smallest_odd == -1 || arr[i] < smallest_odd))) {
                max_frequency = frequency[arr[i]];
                smallest_odd = arr[i];
            }
        }
    }

    if (max_frequency == 0) {
        std::cout << -1 << std::endl;
    } else {
        std::cout << smallest_odd << std::endl;
    }

    return 0;
}
