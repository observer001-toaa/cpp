#include<bits/stdc++.h>
using namespace std;
class Solution{
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int num=0;
        for(int i=0;i<nums.size();i++)
            num+=nums[i];
        int target=num/k;
        if(num%k||nums[0]>target)return false;
        sort(nums.begin(),nums.end(),greater<int>());//降序
        vector<bool> used(nums.size(),false);
        return dfs(nums,used,k,0,target,0);
    }
    bool dfs(vector<int>&nums,vector<bool>&used,int k,int cursum,int target,int start){
        if(k==1)return true;
        if(cursum==target)return dfs(nums,used,k-1,0,target,0);
        for(int i=start;i<nums.size();i++){
            if(used[i]==true)continue;
            if(cursum+nums[i]>target)continue;
            used[i]=true;
            if(dfs(nums,used,k,cursum+nums[i],target,i+1))return true;
            used[i]=false;
            while(i<nums.size()-1&&nums[i]==nums[i+1])i++;//不成功进行减枝；
        }
        return false;
    }
};
int main(){

    return 0;
}