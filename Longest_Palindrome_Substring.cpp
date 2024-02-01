#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
    string s;
    cin >> s;
    int n = s.size();

    //index from 1 to n
    bool dp[n + 1][n + 1];

    memset(dp, false, sizeof(dp));

    //substring with length 1 is palindrome 
    for (int i = 1; i <= n; i++){
        dp[i][i] = true;
    }

    //index from 1 to n
    s = "x" + s; 

    //the first index of LPS and its length
    int index, Length = INT_MIN;

    //substring with len 2->n
    for (int len = 2; len <= n; len++){
        //the maximum first index
        for (int i = 1; i <= n - len + 1; i++){
            //the last index
            int j = i + len  - 1;

            //len = 2 -> not consider inner substring
            if (len == 2)  dp[i][j] = (s[i] == s[j]);

            //if inner substring is palindrome and the first char is the same as the last char
            else dp[i][j] = ((s[i] == s[j]) && dp[i + 1][j - 1]);

            //update result
            if (len > Length && dp[i][j]){
                Length = len;
                index = i;
            }
        }
    }
    
    //print result
    cout << Length << endl;
    for (int i = 0; i < Length; i++){
        cout << s[i + index];
    }
    return 0;
}