#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){ 
    string s1, s2;
    cin >> s1 >> s2;
    int n = s1.size();
    int m = s2.size();

    //index start from 1 to n
    s1 = "x" + s1;
    s2 = "x" + s2;

    int dp[n + 1][m + 1];
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            //if two chars are the same
            if (s1[i] == s2[j]) dp[i][j] = dp[i - 1][j - 1] + 1;

            //if two chars are not the same, value is max of 2 LCB
            else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    string res = "";
    for (int i = m; i >= 1; i--){
        if (dp[n][i] != dp[n][i - 1])   res += s2[i];
    }
    cout << dp[n][m] << endl;
    reverse(res.begin(), res.end());
    cout << res;
    return 0;
}