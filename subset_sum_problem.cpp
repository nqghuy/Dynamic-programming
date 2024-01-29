#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
    //the size of subsequence and sum respectively 
    int n, s;

    //input n, s and arr
    cin >> n >> s;
    int arr[n + 1];
    memset(arr, 0, sizeof(arr));
    for (int i = 1; i <= n; i++){
        int tmp;
        cin >> tmp;
        arr[i] = tmp;
    }

    //dp[i][j] is the maximum sum created from arr[1] -> arr[i] with limited sum j 
    int dp[n + 1][s + 1];
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= s; j++){
            dp[i][j] = dp[i - 1][j];
            if (j >= arr[i]){
                dp[i][j] = max(dp[i][j], dp[i - 1][j - arr[i]] + arr[i]);
            }
        }
    }
    //if maximum sum is s
    if (dp[n][s] == s)  cout << 1 << endl;
    else cout << 0 << endl;

    //dp[j] is true if we can create sum j
    vector <bool> dp2(s + 1, false);
    dp2[0] = true;
    for (int i = 1; i <= n; i++){
        for (int j = s; j >= 1; j--){//do not use a number many times
            if (j >= arr[i] && dp2[j - arr[i]]){
                dp2[j] = true;
            }
        }
    }
    cout << dp2[s];
    return 0;
}