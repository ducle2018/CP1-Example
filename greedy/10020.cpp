///Author: Chung Nguyen Huy Hoang
///Topics: Greedy Problems
///Problem: 2 - UVA10020 - Minimal Coverage
///Language: C++

/*<--------------------------------------------------------------------------------------->*/

///    *Important note: Print a blank line between each test case, so there shouldn't be a blank line printed
/// after the last test case.
///     First, we need to sort the left end of segments in increasing order.
///     In all segments contain 0 (position 1 - pos_1), choose the segment has the farthest right end,
/// and call it position_2 (pos_2). Keep repeating that, in all segments that contain pos_2, choose the
/// segment which has the farthest right end then call it pos_3, until you get the first pos_t >= M.
///     t is the minimum number of segment(s) you need to cover [0,M].

#include <cstdio>
#include <algorithm>
using namespace std;

struct seg  {   /// segment with:
    int l, r;   /// left end & right end
};
const int N = 100002;
seg a[N];   int n, M;
int index[N], t;    /// index[1..t] is the index of chosen segments sorted by their left end
int test;   /// the number of test case(s)

/* =============================================================== */
int input()
{
    n = 0;
    scanf("%i", &M);    /// We need to cover [0..M]
    while(1)
    {
        int x, y;
        scanf("%i %i", &x, &y);
        if (!x && !y)    break;   /// if x = y = 0, stop reading input
        a[++n].l = x;   a[n].r = y;
    }
}
/* ---------------------------- */
int print()
{
    printf("%i", t);    /// The minimum number of segments to cover [0..M]
    for(int i=1; i<=t; i++)
        printf("\n%i %i", a[index[i]].l, a[index[i]].r);    /// t chosen segments sorted by their left end
    if (test)           /// If this is not the last test case,
        printf("\n\n"); /// print a blank line to seperate test cases.
}
/* =============================================================== */
bool cmp(seg a, seg b)
{
    return a.l < b.l;
}
/* ---------------------------- */
int solve()
{
    /// Init
    sort(a+1,a+n+1,cmp);    /// Sort the left end of segments in increasing order.

    ///
    t = 1;  /// the result - we need t minimum segments to cover [0..M] or 0 if can't cover [0..M]
    int pos = 0, nextPos = 0;   /// pos: pos_t; nextPos: pos_t+1

    for(int i=1; i<=n; i++)
    {
        if (a[i].l > nextPos)   return t = 0;   /// There is no segment cover from nextPos to a[i].l < M
        if (a[i].l > pos)       /// We have examined every segment whose left end 'not greater than' pos
            pos = nextPos, t++; /// so we will move to the next pos
        if (nextPos < a[i].r)   {   /// Maximize the next pos
            nextPos = a[i].r;
            index[t] = i;           /// Mark the one with the farthest right end for later output
            if (nextPos >= M)   return t;   /// If we found the final segment to cover [0..M], exit function
        }
    }
    return t = 0; /// After examining all segments, we still can't cover [0..M]
}
/* =============================================================== */
int main()
{
    scanf("%i", &test);
    while (test--)
    {
        input();
        solve();
        print();
    }
}
