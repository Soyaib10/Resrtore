#include<bits/stdc++.h>
#define ll long long int
using namespace std;

const int N = 1e5 + 9;
int a[N], tree[N * 4];

void build(int node, int b, int e) {
    if (b == e) { 
        tree[node] = a[b];
        return;
    }
    int l = node * 2, r = node * 2 + 1;
    int mid = (b + e) / 2;
    build(l, b, mid);
    build(r, mid + 1, e);
    tree[node] = min(tree[l], tree[r]); // change here
}

void update(int node, int b, int e, int i, int new_value) {
    if (i > e or i < b) return;
    if (b >= i and e <= i) {
        tree[node] = new_value;
        return;
    }
    int l = node * 2, r = node * 2 + 1;
    int mid = (b + e) / 2;
    update(l, b, mid, i, new_value);
    update(r, mid + 1, e, i, new_value);
    tree[node] = min(tree[l], tree[r]); // change here
}

ll query(int node, int b, int e, int i, int j) { 
    if (i > e or j < b) return INT_MAX; // change here
    if (b >= i and e <= j) return tree[node]; 
    int l = node * 2, r = node * 2 + 1; 
    int mid = (b + e) / 2;
    ll x = query(l, b, mid, i, j);
    ll y = query(r, mid + 1, e, i, j);
    return min(x, y); // change here
}

void solve(int n, int q) {
    while (q--) {
        int x, k, l;
        cin >> x >> k >> l;
        if (x == 1) update(1, 1, n, k + 1, l);
        else cout << query(1, 1, n, k + 1, l) << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> a[i];

    build(1, 1, n);
    solve(n, q);
    return 0;
}