///Author: Chung Nguyen Huy Hoang
///Topics: Greedy Problems
///Problem: 7 - UVA11054 - Wine trading in Gergovia
///Language: C++

/*<--------------------------------------------------------------------------------------->*/

/// ***Note that the result for each test case could exceed 'int' limit
/// Solution: Starting from the left, we will get the first positive a - a[i], and the first negative - a[j],
/// transport as many bottle as possible, then find the next pair (i,j) until all a[x] = 0
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int N = 1e5+1;
int a[N], n;    /// input array with n is the number of inhabitants

/* =============================================================== */
int input()
{
    for(int i=1; i<=n; i++)
        scanf("%i", &a[i]);
}
/* =============================================================== */
int solve()
{
    int i = 1, j = 1;
    long long res = 0;
    while (i<=n)
    {
        /// Find the next pair (i,j) - (positive,negative)
        while (i<=n && a[i]<=0) i++;
        while (j<=n && a[j]>=0) j++;
        int x = min(a[i],-a[j]);
        res += (long long)x * abs(i-j);
        a[i] -= x;  a[j] += x;
    }
    printf("%lld\n", res);
}
/* =============================================================== */
int main()
{
    while (1)               /// repeat
    {
        scanf("%i", &n);
        if (!n) return 0;   /// until get n = 0
        input();
        solve();
    }
}
