#include<bits/stdc++.h>
#define ll long long int
using namespace std;

const int N = 1e5 + 9;
int a[N], tree[N];

int query(int idx){
    int sum = 0;
    while (idx > 0){
        sum += tree[idx];
        idx -= (idx & -idx);
    }
    return sum;
}

void update(int idx, int val, int n){
    while (idx <= n){
        tree[idx] += val;
        idx += (idx & -idx);
    }
}

void solve(int *a, int n) {
    for (int i = 1; i <= n; ++i) cout << a[i] << " ";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; 
    cin >> n;
    for (int i = 1; i <= n; ++i) { 
        cin >> a[i]; 
        update(i, a[i], n); 
    }

    cout << "input array:\t";
    solve(a, n);
    cout << "\n";

    cout << "tree array:\t";
    solve(tree, n);
    cout << "\n";

    cout << query(5) << "\n";

    return 0;
}