///Author: Pham Viet An
///Topics: Graph - DFS
///Problem: 15 - UVA11518 - Dominos 2
///Language: C++

/*<-------------------------------------------------------------------------------------->*/

///Iterate through all nodes that is pushed
///Lets call the current node be the i-th node
///DFS to all of the nodes which can be reached when we go from i
///Check the node which was reached from i become visited
///After the iteration, count the number of node that was visited

#include <bits/stdc++.h>

using namespace std;

const int N = 10005;

vector <int> adj[N];
bool visit[N];
int n, m, l;

void resets() {
    for (int i = 1; i <= n; ++i) ///Clear adjacent array for incoming new test
        adj[i].clear();
    memset(visit, 0, sizeof visit); ///Clear the check visit array
}

void prepare() {
    cin >> n >> m >> l;
    resets();
    for (int i = 1; i <= m; ++i) {
        int u, v;
        scanf("%d%d",&u,&v);
        adj[u].push_back(v); ///Connect node u to node v
    }
}

void dfs(int u) {
    if (visit[u]) ///If the u-th node was pushed
        return; ///Get out of the function and dont do anything

    visit[u] = true; ///Check that the u-th node was visited
    for (int i = 0; i < (int)adj[u].size(); ++i) {
        int v = adj[u][i]; ///Go to the v-th node that can be reached from u-th
        dfs(v);
    }
}

int solve() {
    for (int i = 1; i <= l; ++i) {
        int u;
        scanf("%d",&u);
        ///Push down the u-th node
        ///Iterate through all the node that can be reached from u
        dfs(u);
    }
    int res = 0;
    for (int i = 1; i <= n; ++i)
        if (visit[i])
            ++res;
    return res;
}

int main() {
    int t; cin >> t;
    while (t--) {
        prepare();
        cout << solve() << endl;
    }
    return 0;
}
