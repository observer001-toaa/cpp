#include<bits/stdc++.h>
using namespace std;
class Solution{
public:

    vector<bool> st;

    bool makesquare(vector<int>& matchsticks) {
        int sum = 0;
        for (auto x : matchsticks) sum += x;
        if (!sum || sum % 4) return false;

        sort(matchsticks.begin(), matchsticks.end());
        reverse(matchsticks.begin(), matchsticks.end());

        st = vector<bool>(matchsticks.size());
        return dfs(matchsticks, 0, 0, sum / 4);
    }

    bool dfs(vector<int>& matchsticks, int u, int cur, int length) {
        if (cur == length) u++, cur = 0;
        if (u == 3) return true;
        for (int i = 0; i < matchsticks.size(); i++) 
            if (!st[i] && cur + matchsticks[i] <= length) {
                st[i] = true;
                if (dfs(matchsticks, u, cur + matchsticks[i], length)) return true;
                st[i] = false;
                if (!cur) return false;
                if (cur + matchsticks[i] == length) return false;
                
                while (i + 1 < matchsticks.size() && matchsticks[i + 1] == matchsticks[i]) i++;

            }
        return false;
    }
};
int main(){
    
    return 0;
}