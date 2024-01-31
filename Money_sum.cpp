#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
    //the number of coins
    int n; cin >> n;

    //contains n coins
    vector <int> coins(n + 1, 0);

    //the sum of all coins
    int maxSum =  0;
    for (int i = 1; i <= n; i++){
        int tmp;
        cin >> tmp;
        coins[i] = tmp;
        maxSum += tmp;
    }

    //dp[i] true if can create money sum i using these coins
    bool dp[maxSum + 1];
    memset(dp, false, sizeof(dp));

    //get the set of creatable money sums
    set <int> se;
    dp[0] = true;
    for (int i = 1; i <= n; i++){
        for (int j = maxSum; j >= 0; j--){
            if (j >= coins[i] && dp[j - coins[i]]){
                dp[j] = true;
                se.insert(j);
            }
        }
    }
    cout << se.size() << endl;
    for (int i : se)    cout << i << " ";
    return 0;
}