///Author: Chung Nguyen Huy Hoang
///Topics: Greedy Problems
///Problem: 5 - UVA10670 - Work Reduction
///Language: C++

/*<--------------------------------------------------------------------------------------->*/

/// Note that if the solutoin is to use x plan A and y plan B, use y plan B first will always more efficient.
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
struct agency    {
    char name[17];
    int A, B, cost;
};
agency a[101];   int l;  /// l: the number of agencies
int n, m;   /// n: starting workload; m: target workload

/* =============================================================== */
int input()
{
    cin >> n >> m >> l; cin.ignore();
    for(int i=1; i<=l; i++)
    {
        cin.getline(a[i].name,17,':');
        cin >> a[i].A;  cin.ignore();
        cin >> a[i].B;  cin.ignore();
    }
}
/* ----------------------------- */
int print(int casenum)
{
    cout << "Case " << casenum << "\n";
    for(int i=1; i<=l; i++)
        cout << a[i].name << " " << a[i].cost << "\n";

}
/* =============================================================== */
int cmp(agency x, agency y)
{
    if (x.cost==y.cost)                     /// If same cost,
        return strcmp(x.name,y.name) < 0;   /// sort by agency name
    return x.cost < y.cost;
}
/* ----------------------------- */
int solve()
{
    for(int i=1; i<=l; i++)
    {
        int N = n;
        a[i].cost = 0;
        while (N/2 >= m && a[i].B <= a[i].A*(N-N/2))    /// Still can use B & the cost is more efficient
            a[i].cost += a[i].B,   N /= 2;
        a[i].cost += a[i].A*(N-m);                      /// Use A for the rest
    }
    sort(a+1,a+l+1,cmp);    /// Sort by cost and name
}
/* =============================================================== */
int main()
{
    int test;   /// the number of test cases
    cin >> test;
    for(int i=1; i<=test; i++)
    {
        input();
        solve();
        print(i);
    }
}
