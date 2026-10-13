/**
 * Competitive Programming Template (C++23, GCC 13+; GCC 14+ recommended)
 * Local compile:
 *   g++ -std=gnu++23 -O2 -Wall -Wextra -DLOCAL template.cpp -o sol
 */

#pragma GCC optimize("O3,unroll-loops")
// Optional: only enable if the judge CPU supports AVX2 (otherwise "illegal instruction").
// If you enable it, keep it AFTER the includes to avoid always_inline errors on some GCC builds.
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

/* --- TYPE ALIASES --- */
using ll = long long;
using ld = long double;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vll = vector<ll>;
using vpii = vector<pii>;
using vpll = vector<pll>;

/* --- PBDS --- */
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15ULL;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9ULL;
        x = (x ^ (x >> 27)) * 0x94d049bb133111ebULL;
        return x ^ (x >> 31);
    }
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM =
            chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
template <typename K, typename V>
using gp_hash = gp_hash_table<K, V, custom_hash>;

/* --- MACROS --- */
#define sz(x)    int((x).size())
#define all(x)   (x).begin(), (x).end()
#define rall(x)  (x).rbegin(), (x).rend()
#define pb       push_back
#define eb       emplace_back
#define fi       first
#define se       second

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define F0R(i, a)    FOR(i, 0, a)
#define ROF(i, a, b) for (int i = (b) - 1; i >= (a); --i)
#define R0F(i, a)    ROF(i, 0, a)
#define TRAV(a, x)   for (auto& a : x)

/* --- CONSTANTS --- */
constexpr int MOD = 1'000'000'007;
constexpr int INF = 1'000'000'005;
constexpr ll LLINF = 1'000'000'000'000'000'005LL;
constexpr ld EPS = 1e-9L;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

/* --- CONTAINER I/O --- */
template <typename T, typename U>
istream& operator>>(istream& in, pair<T, U>& p) { return in >> p.fi >> p.se; }
template <typename T>
istream& operator>>(istream& in, vector<T>& v) { for (auto& x : v) in >> x; return in; }
template <typename T, typename U>
ostream& operator<<(ostream& out, const pair<T, U>& p) { return out << p.fi << " " << p.se; }
template <typename T>
ostream& operator<<(ostream& out, const vector<T>& v) {
    for (int i = 0; i < sz(v); ++i) out << v[i] << (i + 1 == sz(v) ? "" : " ");
    return out;
}

/* --- LOCAL DEBUG (prints to stderr, so it never pollutes output.txt) --- */
#ifdef LOCAL
template <typename... Ts>
void dbg_impl(const char* names, const Ts&... xs) {
    cerr << "[" << names << "] = [";
    size_t i = 0;
    ((cerr << (i++ ? ", " : "") << xs), ...);
    cerr << "]\n";
}
#define debug(...) dbg_impl(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) ((void)0)
#endif

/* --- MATH (std::gcd / std::lcm come from <numeric>, no custom versions needed) --- */
ll expo(ll base, ll exp, ll mod = MOD) {
    ll res = 1 % mod;
    base %= mod;
    while (exp > 0) {
        if (exp & 1) res = (__int128)res * base % mod;
        base = (__int128)base * base % mod;
        exp >>= 1;
    }
    return res;
}
ll modInverse(ll n, ll mod = MOD) { return expo(n, mod - 2, mod); }  // mod must be prime



/* --- CORE SOLVER --- */
void solve() {
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

#ifdef LOCAL
    (void)!freopen("input.txt", "r", stdin);
    (void)!freopen("output.txt", "w", stdout);
    auto start_time = chrono::high_resolution_clock::now();
#endif

    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; ++t) {
        solve();
    }

#ifdef LOCAL
    auto end_time = chrono::high_resolution_clock::now();
    chrono::duration<double> diff = end_time - start_time;
    cerr << "\n[Executed in: " << fixed << setprecision(4) << diff.count() << "s]\n";
#endif

    return 0;
}