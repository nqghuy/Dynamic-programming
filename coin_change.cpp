#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
    //the amount to change and the number of coin
    int n, m;

    //input
    cin >> n >> m;
    vector <int> c(m + 1, 0);
    for (int i = 1; i <= m; i++){
        int tmp;
        cin >> tmp;
        c[i] = tmp;
    }

    //dp[i] is the number of ways of changing money i
    ll dp[n + 1];
    memset(dp, 0, sizeof(dp));

    //0d have one way
    dp[0] = 1;
    
    for (int i = 1; i <= m; i++){
        for (int j = 1; j <= n; j++){
            if (j >= c[i]){
                dp[j] = dp[j] + dp[j - c[i]];
            }
        }
    }
    cout << dp[n];

    return 0;
}