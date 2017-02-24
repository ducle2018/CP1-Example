///Author: Pham Viet An
///Topics: Graph - DFS
///Problem: 12 - UVA10926 - How Many Dependencies?
///Language: C++

/*<-------------------------------------------------------------------------------------->*/

///Iterate through all nodes
///Lets call the current node be the i-th node
///DFS to all of the nodes which can be reached when we go from i
///Store the result in a variable (here I store in cnt)
///Update result

#include <bits/stdc++.h>

using namespace std;

const int N = 105;

vector <int> adj[N];
int n, cnt;
bool visit[N]; ///Visit is for checking if the i-th node has been iterated through yet

void resets() { ///Clear the adjacent array for incoming new test
    for (int i = 1; i <= n; ++i)
        adj[i].clear();
}

void prepare() {
    for (int i = 1; i <= n; ++i) {
        int len;
        cin >> len;
        for (int j = 1; j <= len; ++j) {
            int k;
            cin >> k;
            adj[i].push_back(k); ///Connect an edge from i-th node to k-th node
        }
    }
}

void dfs(int u) {
    if (visit[u]) ///If this node has been visited
        return; ///Get out and dont do anything

    visit[u] = true; ///Check the i-th node has been visited
    ++cnt;

    for (int i = 0; i < (int)adj[u].size(); ++i) {
        ///Iterate through all nodes that the i-th node connect to
        int v = adj[u][i];
        dfs(v);
    }
}

int getMax() {
    int res = 0;
    for (int i = 1; i <= n; ++i) {
        ///Get the Dependencies for the i-th node
        memset(visit, false, sizeof visit);
        cnt = 0; ///Store number of Dependencies in the "cnt" variable
        dfs(i);

        ///Update the result
        res = max(res,cnt);
    }
    return res;
}

int solve() {
    int mx = getMax(); ///Get the maximum Dependencies
    for (int i = 1; i <= n; ++i) {
        ///Get the Dependencies for the i-th node
        memset(visit, false, sizeof visit);
        cnt = 0; ///Store number of Dependencies in the "cnt" variable
        dfs(i);

        if (mx==cnt) ///If this i-th node Dependencies equal to the maximum
            return i; ///Return the result
    }
}

int main() {
    for (;;) {
        cin >> n;
        if (n==0) break;
        resets();
        prepare();
        cout << solve() << endl;
    }
    return 0;
}
