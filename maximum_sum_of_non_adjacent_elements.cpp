/*

Return the max sum of the subsequence such thaat no two elements are adjacent in the given array

*/

#include<bits/stdc++.h>
using namespace std;

int arr[100];


// Recursive

const int n=10;

// index=n-1
int solve(int index){
    if(index==0){
        return arr[index];
    }
    if(index<0) {
        return 0;
    }

    int pick=arr[index]+solve(index-2);
    int not_pick=0+solve(index-1);

    return max(pick,not_pick);
}



// Memoization
int dp[n];

int solve(int index){
    if(index==0){
        return arr[index];
    }
    if(index<0) {
        return 0;
    }

    if(dp[index]!=-1){
        return dp[index];
    }
    int pick=arr[index]+solve(index-2);
    int not_pick=0+solve(index-1);

    return dp[index]=max(pick,not_pick);
}



// Tabulation

// Base case dp[0]=0

// for(int i=1;i<n;i++){
//     int take=arr[i];
//     if(i>1){
//         take+=dp[i-2];
//     }

//     int not_pick=0+dp[i-1];
//     dp[i]=max(take,not_pick);
// }

// ans is dp[n-1]