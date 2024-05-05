#include <iostream>
using namespace std;

int countWays(int coins[], int n, int s) {
    int dp[n + 1][s + 1];
    for (int i = 0; i <= n; i++)
        dp[i][0] = 1;
    for (int j = 1; j <= s; j++)
        dp[0][j] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= s; j++) {
            dp[i][j] = dp[i - 1][j];
            if (coins[i - 1] <= j) {
                dp[i][j] += dp[i][j - coins[i - 1]];
            }
        }
    }
    return dp[n][s];
}

int main() {
    int coins[] = {1, 5,10};
    int n = sizeof(coins) / sizeof(coins[0]);
    int sum = 10;
    cout << "Number of ways to make sum " << sum << " is: " << countWays(coins, n, sum) << endl;
    return 0;
}
