#include <bits/stdc++.h>

using namespace std;
#define ll long long

//complexity O(NlogN)
class Solution {
private:
    //find the position x >= value
    int findPos (vector <int> dp, int value){
        int left = 0;
        int right = dp.size() - 1;
        while (left <= right){
            int mid = (right + left) / 2;
            if (dp[mid] < value){
                left = mid + 1;
            }
            else if (dp[mid] >= value){
                right = mid - 1;
            }
        }
        return left;
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        int Size = nums.size();

        // //size of longest increasing subsequece from 1 to i
        // vector <int> L(Size, 1);

        // for (int i = 0; i < Size; i++){
        //     for (int j = 0; j < i; j++){
        //         if (nums[j] < nums[i]){
        //             L[i] = max(L[i], L[j] + 1);
        //         }
        //     }
        // }
        // return *(max_element(L.begin(), L.end()));

        vector <int> dp;

        for (int i = 0; i < (int)nums.size(); i++){
            int pos = findPos(dp, nums[i]);
            if (pos == dp.size()){
                dp.push_back(nums[i]);
            }
            else dp[pos] = nums[i];
        }
        
        return dp.size();
    }
};

int main(){
    int n;
    cin >> n;
    vector <int> nums;
    for (int i = 0; i < n; i++){
        int tmp;
        cin >> tmp;
        nums.push_back(tmp);
    }
    Solution a;
    cout << a.lengthOfLIS(nums);
    return 0;
}