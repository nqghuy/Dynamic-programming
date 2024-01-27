#include <bits/stdc++.h>

using namespace std;
#define ll long long

//complexity O(N^2)
class Solution {
private:
public:
    int lengthOfLIS(vector<int>& nums) {
        int Size = nums.size();

        //size of longest increasing subsequece from 1 to i
        vector <int> L(Size, 1);

        for (int i = 0; i < Size; i++){
            for (int j = 0; j < i; j++){
                if (nums[j] < nums[i]){
                    L[i] = max(L[i], L[j] + 1);
                }
            }
        }
        return *(max_element(L.begin(), L.end()));
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