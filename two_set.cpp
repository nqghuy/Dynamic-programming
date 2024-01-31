#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int MOD = 1e9 + 7;

int main(){
    int n; cin >> n;

    //if not exist two equal set sum (sum of 1->n is odd)
    if ((n * (n + 1) / 2) & 1)  {
        cout << 0;
        return 0;
    }

    //two set have equal sum
    int sum = n * (n + 1) / 4;

    //dp[i] is the number of ways creating sum i with 1->n
    ll dp[sum + 1];

    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    for (int i = 1; i <= n; i++){
        for (int j = sum; j >= i; j--){
            dp[j] = (dp[j] % MOD + dp[j - i] % MOD);
        }
    }

    //a way contains two equal sums
    cout << dp[sum] / 2;
    return 0;
}