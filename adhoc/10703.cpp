///Author: Pham Viet An
///Topics: Ad hoc Problems
///Problem: 17 - UVA10703 - Free spots
///Language: C++

/*<-------------------------------------------------------------------------------------->*/

///Go through all points on the board
///With each point, call it (x;y)
///If (x;y) is inside 1 or more rectangle
///=> Do not increase result, else increase result

#include <bits/stdc++.h>

using namespace std;

int X1[105], Y1[105], X2[105], Y2[105];
int w, h, n;

bool coorInsideRect(int x, int y, int index) {
    int lx = min(X1[index],X2[index]), rx = max(X1[index],X2[index]);
    int ly = min(Y1[index],Y2[index]), ry = max(Y1[index],Y2[index]);
    //The property below must true for (x;y) inside the index-th rectangle
    if (x >= lx && x <= rx && y >= ly && y <= ry) return true;
    return false;
}

bool isInAnyRectangle(int x, int y) {
    for (int i = 0; i < n; ++i) //Go through all rectangle to check
        if (coorInsideRect(x,y,i)) //Check if this (x;y) is inside the i-th rectangle
            return true; //If yes, return true immediately
    return false;
}

int solve() {
    int res = 0;

    for (int i = 1; i <= w; ++i)
    for (int j = 1; j <= h; ++j)
        if (!isInAnyRectangle(i,j)) //Check if this point is inside any rectangle
            res++; //If not, increase result by 1

    return res;
}

int main() {
    //freopen("input.txt","r",stdin);
    for (;;) {
        scanf("%d%d%d",&w,&h,&n);
        if (w==0 && h==0 && n==0) break;
        for (int i = 0; i < n; ++i)
            scanf("%d%d%d%d",&X1[i],&Y1[i],&X2[i],&Y2[i]);
        int k = solve();
        if (k==0) cout << "There is no empty spots." << endl;
        else if (k==1) cout << "There is one empty spot." << endl;
        else cout << "There are " << k << " empty spots." << endl;
    }
    return 0;
}
