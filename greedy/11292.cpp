///Author: Chung Nguyen Huy Hoang
///Topics: Greedy Problems
///Problem: 8 - UVA11292 - Dragon of Loowater
///Language: C++

/*<--------------------------------------------------------------------------------------->*/

/// Find the smallest dragon head, then find the shortest knight who can chop it off. Repeat n times.
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 2e4+1;
int d[N], k[N], n, m;

/* =============================================================== */
int input()
{
    scanf("%i%i", &n, &m);
    if (m==0)   return 1;   /// End of input file
    for(int i=1; i<=n; i++) scanf("%i", &d[i]); /// dragon head
    for(int i=1; i<=m; i++) scanf("%i" ,&k[i]); /// knight
    return 0;
}
/* =============================================================== */
int solve()
{
    sort(d+1,d+n+1);
    sort(k+1,k+m+1);
    int res = 0, j = 1;
    for(int i=1; i<=n; i++)
    {
        while(j<=m && k[j]<d[i])    j++;        /// Find the shortest knight can chop the head off
        if (j > m)    {                         /// There is no knight left
            printf("Loowater is doomed!\n");
            return 0;
        }
        res += k[j++];
    }
    printf("%i\n", res);
}
/* =============================================================== */
int main()
{
    while (1)
        if (input())    /// Get m = n = 0
            return 0;
        else
            solve();
}
