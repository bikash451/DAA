#include <iostream>
#include <string.h>
using namespace std;
int dp[1000][1000];

int lcs(string s1, string s2, int n, int m)
{
    if(dp[n][m]!=-1)
    {
        return dp[n][m];

    }
    else{
    if(n == 0 || m == 0)
        return 0;
        
    if(s1[n-1] == s2[m-1])
        return 1 + lcs(s1, s2, n - 1, m - 1);
    else
        return max(lcs(s1, s2, n - 1, m), lcs(s1, s2, n, m - 1));
    }
    return dp[n][m];
}

int main() 
{
    string s1 = "AGGTAB", s2 = "GXTXAYB";
    int n = s1.length(), m = s2.length();
    memset(dp,-1,sizeof(dp)); //TO SET EACH VALUE IN THE DP AS -1
    cout << "The longest common subsequence is " << lcs(s1, s2, n, m);
    return 0;
}
