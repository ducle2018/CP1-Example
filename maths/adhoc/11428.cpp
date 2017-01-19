///Author: Pham Viet An
///Topics: Mathematics - Ad hoc Problems
///Problem: 8 - UVA11428 - Cubes
///Language: C++

/*<--------------------------------------------------------------------------------------->*/

///x^3 - y^3 = n
///(x-y) * (x^2 + xy + y^2) = n
///x and y are integers and x > 0 and y > 0
///=> x-y and x^2 + xy + y^2 are integers
///=> x-y and x^2 + xy + y^2 are divisor of n
///Lets call x-y = a; and x^2 + xy + y^2 = b; (a <= b)
///Because x = a+y. Substitute it into x^2 + xy + y^2 = b
///It becomes: 3y^2 + 3ay + a^2 = b

#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> ii;

vector <ii> res;

bool isPerfectSquare(int n) {
    int k = sqrt(n);
    return k*k == n;
}

vector <int> squareEquation(int a, int b, int c) { ///solve Square Equation
    vector <int> res;
    int delta = b*b - 4*a*c;
    if (delta < 0 || !isPerfectSquare(delta))
        return res; ///There are no solution

    delta = sqrt(delta);
    if ((-b - delta) % (2*a) == 0) ///To make sure the solution is integer
        res.push_back((-b - delta) / (2*a));
    if ((-b + delta) % (2*a) == 0 && delta != 0) ///To make sure the solution is integer and the solution does not repeat
        res.push_back((-b + delta) / (2*a));

    return res;
}

void updateEquation(int a, int b) {
    vector <int> solution = squareEquation(3,3*a,a*a-b); ///Get the solution for the equation

    for (int i = 0; i < (int)solution.size(); ++i) { ///iterate through all solution and check
        int y = solution[i];
        int x = a+y;
        if (x > 0 && y > 0) ///Make sure they are positive
            res.push_back(ii(x,y)); ///Store them in in order to get the minimum y result
    }
}

void solve(int n) {
    res.clear(); ///reset the result
    int k = sqrt(n); ///iterate through all divisors of n
    for (int i = 1; i <= k; ++i) {
        if (n%i!=0) continue;
        int a = i, b = n/i; ///Get all the possible x, y result and
        updateEquation(a,b);  ///store them inside vector res with the following a, b
    }
    if (res.size()==0) cout << "No solution" << endl; ///No result
    else {
        int minY = res[0].second; ///get minimum y among all results
        for (int i = 0; i < (int)res.size(); ++i)
            minY = min(minY,res[i].second);
        for (int i = 0; i < (int)res.size(); ++i)
            if (minY==res[i].second) {
                cout << res[i].first << " " << res[i].second << endl;
                break;
            }
    }
}

int main() {
    for (;;) {
        int n;
        cin >> n;
        if (n==0) break;
        solve(n);
    }
	return 0;
}
