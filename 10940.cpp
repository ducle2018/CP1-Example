///Author: Pham Viet An
///Topics: Mathematic - Ad hoc Problems
///Problem: 4 - UVA10940 - Throwing cards away II
///Language: C++

/*<--------------------------------------------------------------------------------------->*/

///After bruteforcing, the answer has a unique pattern
///You can check the pattern using the bruteForce function below

#include <bits/stdc++.h>

using namespace std;

int a[1000000];

int getBrute(int n) {
    for (int i = 1; i <= n; ++i) ///init the deck
        a[i] = i;
    int bot = 1, top = n;
    while (top-bot >= 1) { ///Implement exactly as the problem statement
        bot++; ///Remove the top card
        a[++top] = a[bot++]; ///Add top card (now) to the bottom of the deck
    }
    return a[top]; ///After bot=top, it means the deck now has 1 card only, return it
}

void bruteForce() {
    for (int i = 1; i <= 1000; ++i)
        cout << i << " " << getBrute(i) << endl;
}

int solve(int n) {
    if (n==1) return 1;
    int start = 1;
    for (start = 1; start*2 < n; start *= 2);
    return (n-start)*2;
}

int main() {
    for (;;) { ///Forever loop until n = 0
        int n; cin >> n;
        if (n==0) break;
        cout << solve(n) << endl;
    }
    return 0;
}
