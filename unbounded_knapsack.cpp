#include <bits/stdc++.h>

using namespace std;
#define ll long long

int solve(){
         //the length of arr and taget sum
        int n, k;
        cin >> n >> k;

        //set to remove repeated numbers
        set <int> se;

        // check if target sum is divisible to any number
        bool ok  = false;

        //input array
        for (int i = 0; i < n; i++){
            int tmp;
            cin >> tmp;
            if (k % tmp == 0){
                ok = true;
            }
            se.insert(tmp);
        }
        //find the result(k)
        if (ok) return k;

        //remove mutiples 
        bool mark[2005];
        memset(mark, false, sizeof(mark));

        //contains number with maximum number of repetitions
        vector <int> v;

        for (int i : se){
            int interger_part = k / i;
            
            //if i is not mutiples of any number before
            if (mark[i] == false){
                for (int j = 0; j < interger_part; j++){
                v.push_back(i);
                }
                for (int j = i; j < 2005; j += i){
                    mark[j] = true;
                }
            }
        }
        
        //dp[i][j] is the maximum sum with limited sum j
        int dp[v.size() + 1][k + 1];
        memset(dp, 0, sizeof(dp));

        for (int i = 1; i <= v.size(); i++){
            for (int j = 1; j <= k; j++){
                dp[i][j] = dp[i - 1][j];

                //if can add up current value
                if (j >= v[i - 1]){
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - v[i - 1]] + v[i - 1]);
                }
            }
        }
        // for (int i = 0; i <= v.size(); i++){
        //     for (int j = 0; j <= k; j++){
        //         cout << dp[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        return dp[v.size()][k];
}

int main(){
    int t; cin >> t;
    while (t--){
        cout << solve() << endl;
    }
    
    return 0;
}