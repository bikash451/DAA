#include <iostream>
using namespace std;

void PrintSubsetSum(int set[], int n, int targetSum, int subset[], int subsetSize, int index) {
    if (targetSum == 0) {
        cout << "[ ";
        for (int i = 0; i < subsetSize; i++) {
            cout << subset[i] << " ";
        }
        cout << "]" << endl;
        return;
    }

    for (int i = index; i < n; i++) {
        if (set[i] <= targetSum) {
            subset[subsetSize] = set[i];
            PrintSubsetSum(set, n, targetSum - set[i], subset, subsetSize + 1, i + 1);
        }
    }
}

int main() {
    int set[] = {1, 2, 1};
    int n = sizeof(set) / sizeof(set[0]);

    int sum;
    cout << "Enter the target sum: ";
    cin >> sum;

    int subset[n]; 
    cout << "Subsets with sum equal to " << sum << " are:\n";
    PrintSubsetSum(set, n, sum, subset, 0, 0);

    return 0;
}
