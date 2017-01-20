///Author: Pham Viet An
///Topics: Ad hoc Problems
///Problem: 6 - UVA661	Blowing Fuses
///Language: C++

/*<-------------------------------------------------------------------------------------->*/

///You only need to simulate the problem statement

#include <bits/stdc++.h>

using namespace std;

int a[30], b[100000], turn[30];

int solve(int n, int m, int k) {
    memset(turn, 0, sizeof turn); ///turn array is for checking whether the device is on or off
    int maxC = 0, currentC = 0;

    for (int i = 1; i <= m; ++i) {
        int now = b[i];

        if (turn[now]==1) { ///if it is turning on
            turn[now] = 0; ///turn it off
            currentC -= a[now];
        }
        else { ///if it is turning off
            turn[now] = 1; ///turn it on
            currentC += a[now];
        }

        maxC = max(maxC,currentC); ///update maximum C
    }

    if (maxC > k) return -1; ///obviously blown
    return maxC;
}

int main() {
    int numSeq = 0; ///To count the number of Sequence

    while (true) {
        int n, m, k;
        cin >> n >> m >> k;
        if (n==0 && m==0 && k==0) break;

        for (int i = 1; i <= n; ++i)
            cin >> a[i];
        for (int i = 1; i <= m; ++i)
            cin >> b[i];

        cout << "Sequence " << ++numSeq << endl; ///Add 1 into numSeq and print out
        int res = solve(n,m,k); ///if res = -1 then it is blown, else it is the max power consumption
        if (res==-1) cout << "Fuse was blown." << endl;
        else {
            cout << "Fuse was not blown." << endl;
            cout << "Maximal power consumption was " << res << " amperes." << endl;
        }
        cout << endl;
    }
    return 0;
}
