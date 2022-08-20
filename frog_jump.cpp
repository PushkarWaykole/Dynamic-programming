/*
The energy cost in ine jump is the absolute difference of the heights

The frog can jump 1 or 2 steps at one point

eg 10 20 30 10

*/

#include <bits/stdc++.h>
using namespace std;

const int n = 10;

int arr[n];

// Recursive

int f(int n)
{
    if (n == 0)
    {
        return 0;
    }
    int left = f(n - 1) + abs(arr[n] - arr[n - 1]);
    int right = INT_MAX;
    if (n > 1)
    {
        right = f(n - 2) + abs(arr[n] - arr[n - 2]);
    }
    return min(left, right);
}

// Memoization

int dp[n + 1];

// Base case

// dp[0]=0;

int f(int n)
{
    if (n == 0)
    {
        return 0;
    }
    if (dp[n] != -1)
    {
        return dp[n];
    }
    int left = f(n - 1) + abs(arr[n] - arr[n - 1]);
    int right = INT_MAX;
    if (n > 1)
    {
        right = f(n - 2) + abs(arr[n] - arr[n - 2]);
    }
    return dp[n] = min(left, right);
}

// Tabulation

int dp[n];
int f(int n)
{
    dp[0] = 0;

    for (int i = 1; i < n; i++)
    {
        int left = dp[i - 1] + abs(arr[n] - arr[n - 1]);
        int right = INT_MAX;
        if (n > 1)
        {
            right = dp[i - 2] + abs(arr[n] - arr[n - 2]);
        }
        dp[i] = max(left, right);
    }
}


//Space optimization 

int f(int n)
{
    dp[0] = 0;
    int prev=arr[0],prev2=0,curr=0;
    for (int i = 1; i < n; i++)
    {
        int left = prev + abs(arr[n] - arr[n - 1]);
        int right = INT_MAX;
        if (n > 1)
        {
            right = prev2 + abs(arr[n] - arr[n - 2]);
        }
        
        curr=min(left, right);
        prev2=prev;
        prev=curr;
    }
}
