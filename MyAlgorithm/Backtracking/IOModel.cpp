#include<bits/stdc++.h>
using namespace std;
int main(){
    //创建一个数组
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    int index_x,index_y;
    cin>>index_x>>index_y;
    vector<vector<int>> matrix(index_x,vector<int>(index_y,0));
    for(int i=0;i<index_x;i++){
        for(int j=0;i<index_y;j++){
            cin>>matrix[i][j];
        }
    }

    return 0;
}