///Author: Chung Nguyen Huy Hoang
///Topics: Greedy Problems
///Problem: 9 - UVA11369 - Shopaholic
///Language: C++

/*<--------------------------------------------------------------------------------------->*/

///    First, note that we will get discount for exactly [n/3] item(s), which is/are the cheapest in its trio.
///    Secondly, we will have to pay for the 1st & 2nd most expensive items and get discount for 1 item,
///  to maximize the discount we can get, we will get the most expensive item left for free.
///    The greedy solution is to pick 3 most expensive items, get the cheapest for free and repeat again.

#include <cstdio>
#include <algorithm>
using namespace std;

int a[20001], n;

/* =============================================================== */
int input()
{
    scanf("%i", &n);
    for(int i=1; i<=n; i++)
        scanf("%i", &a[i]);
}
/* =============================================================== */
int solve()
{
    sort(a+1,a+n+1);
    int res = 0; /// The result - the maximum discount we can get
    while (n>=3) /// While we can still get 3 items
    {
        res += a[n-2];  /// Get the cheapest for free,
        n -= 3;         /// then eliminate the trio
    }
    printf("%i\n", res);
}
/* =============================================================== */
int main()
{
    int test;
    scanf("%i", &test);
    while (test--)
    {
        input();
        solve();
    }
}
