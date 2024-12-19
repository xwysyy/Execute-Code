#include<bits/stdc++.h>
using ll = long long;

std::mt19937_64 rnd(std::chrono::steady_clock().now().time_since_epoch().count());

int rng(int l, int r) { // [l, r]
    return rnd() % (r - l + 1) + l;
}

void array(int n, int lim) { // Generates an array with n elements
    int m = lim;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        a[i] = rng(1, m);
        std::cout << a[i] << " \n"[i == n - 1];
    }
}

void cand(int m, int n) { // Generate m cands from 1 to n
    for (int i = 0; i < m; i++) {
        int l = rng(1, n);
        int r = rng(1, n);

        if (l > r) {
            std::swap(l, r);
        }

        std::cout << l << " " << r << "\n";
    }
}

void tree(int n) { // Generate a tree with n vertices
    int m = 1E9;
    for (int i = 1; i < n; i++) {
        int p = rng(0, i - 1);
        int v = rng(1, m);
        std::cout << p + 1 << " " << i + 1 << " " << v << "\n";
    }
}

void graph(int n, int m) {
// Generate an undirected graph with n vertices and m edges. There are no double edges or self-rings in the graph, and must be connected.
    std::vector<std::pair<int, int>> e;
    std::map<std::pair<int, int>, bool> f;

    std::cout << n << " " << m << "\n";

    for (int i = 1; i < n; i++) {
        int p = rng(0, i - 1);
        e.push_back(std::make_pair(p, i));
        f[std::make_pair(p, i)] = f[std::make_pair(i, p)] = true;
    }

    // debug(f);
    for (int i = n; i <= m; i++) {
        int x, y;
        do {
            x = rng(0, n - 1);
            y = rng(0, n - 1);
        } while (x == y || f.count(std::make_pair(x, y)));

        e.push_back(std::make_pair(x, y));
        f[std::make_pair(x, y)] = f[std::make_pair(y, x)] = true;
    }

    std::shuffle(e.begin(), e.end(), rnd);

    for (auto [x, y] : e) {
        std::cout << x + 1 << " " << y + 1 << "\n";
    }
}

int main(int argc, char* argv[]) {
    int data = std::atoi(argv[1]);
    int N = rng(1, data);
    int V = rng(1, data);
    array(N, data);
    array(N, data);
    return 0;
}