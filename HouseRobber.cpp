#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];

        int prev = 0;  
        int prev2 = 0;      

        for (int i = 0; i < n; i++) {
            int current = max(prev, prev2 + nums[i]);
            prev2= prev;
            prev = current;
        }

        return prev;
    }
};
