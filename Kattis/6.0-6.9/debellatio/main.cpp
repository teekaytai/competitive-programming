#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
#define forn(i, n) for (int i = 0; i < (n); ++i)
#define len(x) (int) x.size()
#define eb emplace_back

const ll mod = 1000000007;

ll modpow(ll b, ll e) {
	ll ans = 1;
	for (; e; b = b * b % mod, e /= 2)
		if (e & 1) ans = ans * b % mod;
	return ans;
}

int matInv(vector<vector<ll>>& A) {
	int n = len(A); vi col(n);
	vector<vector<ll>> tmp(n, vector<ll>(n));
	forn(i,n) tmp[i][i] = 1, col[i] = i;

	forn(i,n) {
		int r = i, c = i;
		for(int j=i; j<n; ++j) for(int k=i; k<n; ++k) if (A[j][k]) {
			r = j; c = k; goto found;
		}
		return i;
found:
		A[i].swap(A[r]); tmp[i].swap(tmp[r]);
		forn(j,n)
			swap(A[j][i], A[j][c]), swap(tmp[j][i], tmp[j][c]);
		swap(col[i], col[c]);
		ll v = modpow(A[i][i], mod - 2);
		for(int j=i+1; j<n; ++j) {
			ll f = A[j][i] * v % mod;
			A[j][i] = 0;
			for(int k=i+1; k<n; ++k) A[j][k] = (A[j][k] - f*A[i][k]) % mod;
			forn(k,n) tmp[j][k] = (tmp[j][k] - f*tmp[i][k]) % mod;
		}
		for(int j=i+1; j<n; ++j) A[i][j] = A[i][j] * v % mod;
		forn(j,n) tmp[i][j] = tmp[i][j] * v % mod;
		A[i][i] = 1;
	}

	for (int i = n-1; i > 0; --i) forn(j,i) {
		ll v = A[j][i];
		forn(k,n) tmp[j][k] = (tmp[j][k] - v*tmp[i][k]) % mod;
	}

	forn(i,n) forn(j,n)
		A[col[i]][col[j]] = tmp[i][j] % mod + (tmp[i][j] < 0)*mod;
	return n;
}

vector<pii> generalMatching(int N, vector<pii>& ed) {
	vector<vector<ll>> mat(N, vector<ll>(N)), A;
	for (pii pa : ed) {
		int a = pa.first, b = pa.second, r = rand() % mod;
		mat[a][b] = r, mat[b][a] = (mod - r) % mod;
	}

	int r = matInv(A = mat), M = 2*N - r, fi, fj;
	assert(r % 2 == 0);

	if (M != N) do {
		mat.resize(M, vector<ll>(M));
		forn(i,N) {
			mat[i].resize(M);
			for(int j=N; j<M; ++j) {
				int r = rand() % mod;
				mat[i][j] = r, mat[j][i] = (mod - r) % mod;
			}
		}
	} while (matInv(A = mat) != M);

	vi has(M, 1); vector<pii> ret;
	forn(it,M/2) {
		forn(i,M) if (has[i])
			for (int j=i+1; j<M; ++j) if (A[i][j] && mat[i][j]) {
				fi = i; fj = j; goto done;
		} assert(0); done:
		if (fj < N) ret.emplace_back(fi, fj);
		has[fi] = has[fj] = 0;
		forn(sw,2) {
			ll a = modpow(A[fi][fj], mod-2);
			forn(i,M) if (has[i] && A[i][fj]) {
				ll b = A[i][fj] * a % mod;
				forn(j,M) A[i][j] = (A[i][j] - A[fi][j] * b) % mod;
			}
			swap(fi,fj);
		}
	}
	return ret;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int n, m; cin >> n >> m;
    vector<pii> edges;
    forn(i, m) {
        int u, v; cin >> u >> v;
        edges.eb(u-1, v-1);
    }
    auto matches = generalMatching(n, edges);
    vi choices(n, -1);
    for (auto [u, v] : matches) {
        choices[u] = v;
        choices[v] = u;
    }
    int x = -1;
    forn (i, n) {
        if (choices[i] == -1) {
            x = i;
            break;
        }
    }
    if (x == -1) cout << 2 << endl;
    else cout << 1 << endl << x+1 << endl;
    int c; cin >> c;
    while (c) {
        cout << choices[c-1]+1 << endl;
        cin >> c;
    }
}
