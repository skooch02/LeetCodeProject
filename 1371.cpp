#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int findTheLongestSubstring(string s) {
        vector<int> position(32, -1);
        position[0] = 0;
        int ans = 0, status = 0, n = s.length();
        for (int i = 0; i < n; i++) {
            if (s[i] == 'a') status ^= 1 << 0;
            else if (s[i] == 'e') status ^= 1 << 1;
            else if (s[i] == 'i') status ^= 1 << 2;
            else if (s[i] == 'o') status ^= 1 << 3;
            else if (s[i] == 'u') status ^= 1 << 4;
            if (~position[status]) 
                ans = max(ans, i + 1 - position[status]);
            else 
                position[status] = i + 1;
        }
        return ans;
    }
};