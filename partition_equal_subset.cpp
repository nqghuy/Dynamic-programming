#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (int i : nums){
            sum += i;
        }
        if (sum & 1)   return false;
        int equal_sum = sum / 2;
        bool dp[equal_sum + 1];
        memset(dp, false, sizeof(dp));
        dp[0] = true;
        for (int i : nums){
            for (int j = equal_sum; j >= i; j--){
                if (dp[j - i])  dp[j] = true;
                if (dp[equal_sum])  return true;
            }
        }
        return false;
    }
};

#define ll long long

int main(){
    vector <int> v;
    for (int i = 0; i < 6; i++){
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }
    Solution a;
    cout << a.canPartition(v);
    return 0;
}