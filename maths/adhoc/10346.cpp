///Author: Pham Viet An
///Topics: Mathematics - Ad hoc Problems
///Problem: 3 - UVA10346 - Peter's Smokes
///Language: C++

#include <bits/stdc++.h>

using namespace std;

///Maximum number of cigarretes
///=> Smoke all and then exchange for more and then smoke and continue to do so

int solve(int cigar, int k) {
    int buttNow = 0, res = 0;
    while (cigar) {
        ///Smoke all the cigar currently have
        res += cigar;
        buttNow += cigar;
        cigar = 0;

        ///Exchange butt for more cigar
        cigar += buttNow / k;
        buttNow %= k;
    }
    return res;
}

int main() {
	int n, k;
    while (cin >> n >> k) ///Forever loop until the end of file
        cout << solve(n,k) << endl;
	return 0;
}
