///Author: Chung Nguyen Huy Hoang
///Topics: Greedy Problems
///Problem: 4 - UVA10440 - Ferry Loading II
///Language: C++

/*<--------------------------------------------------------------------------------------->*/

///     To minimize the maximum time, we need need to deliver the last car as soon as possible
///     If we have n cars, we have to wait until the n-th car arrived, so the time is a[n]+t
///     If we have 2n cars, to deliver the 2n-th car quick, we have to deliver the first n cars quick,
/// and that is right after either 'the n-th car arrives' or 'the ferry comes back'
///     So, if we have k*n cars, we will take n cars across the river for k times
///     Finally, if we have k*n+r cars, to deliver k*n cars quick, we will deliver the first r cars.

#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
const int N = 1450;
int a[N], m;  /// a: the array of arrival time of m car(s)
int t, n;     /// t: the time need to cross the river; n: the number of car(s) the ferry can load

/* =============================================================== */
int input()
{
    scanf("%i%i%i", &n, &t, &m);
    for(int i=1; i<=m; i++)
        scanf("%i", &a[i]);
}
/* =============================================================== */
int solve()
{
    int del = m%n;                      /// Cars delivered. We'll deliver the first m%n cars
    int time = (del? a[del]+2*t : 0);   /// The time after delivered m%n cars
    while (del < m)                     /// While all cars are not delivered
    {
        del += n;                       /// Deliver n cars in a row
        time = max(time,a[del]) + 2*t;
    }
    time -= t;                          /// The final delivery only consume t minutes
    printf("%i %i\n", time, (int)ceil(1.0*m/n));
}
/* =============================================================== */
int main()
{
    int test;   /// the number of test cases
    scanf("%i", &test);
    while (test--)
    {
        input();
        solve();
    }
}
