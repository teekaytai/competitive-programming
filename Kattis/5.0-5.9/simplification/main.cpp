#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
#define forn(i, n) for (int i = 0; i < (n); ++i)
#define forn1(i, n) for (int i = 1; i <= (n); ++i)
#define all(x) begin(x), end(x)
#define len(x) int(size(x))
#define eb emplace_back

template<class T>
struct Point {
	typedef Point P;
	T x, y;
	explicit Point(T x=0, T y=0) : x(x), y(y) {}
	bool operator<(P p) const { return tie(x,y) < tie(p.x,p.y); }
	bool operator==(P p) const { return tie(x,y)==tie(p.x,p.y); }
	P operator+(P p) const { return P(x+p.x, y+p.y); }
	P operator-(P p) const { return P(x-p.x, y-p.y); }
	P operator*(T d) const { return P(x*d, y*d); }
	P operator/(T d) const { return P(x/d, y/d); }
	T dot(P p) const { return x*p.x + y*p.y; }
	T cross(P p) const { return x*p.y - y*p.x; }
	T cross(P a, P b) const { return (a-*this).cross(b-*this); }
	T dist2() const { return x*x + y*y; }
	double dist() const { return sqrt((double)dist2()); }
	// angle to x-axis in interval [-pi, pi]
	double angle() const { return atan2(y, x); }
	P unit() const { return *this/dist(); } // makes dist()=1
	P perp() const { return P(-y, x); } // rotates +90 degrees
	P normal() const { return perp().unit(); }
	// returns point rotated 'a' radians ccw around the origin
	P rotate(double a) const {
		return P(x*cos(a)-y*sin(a),x*sin(a)+y*cos(a)); }
	friend ostream& operator<<(ostream& os, P p) {
		return os << "(" << p.x << "," << p.y << ")"; }
};

template<class T>
T polygonArea2(vector<Point<T>>& v) {
	T a = v.back().cross(v[0]);
	forn(i, len(v)-1) a += v[i].cross(v[i+1]);
	return a;
}

typedef Point<ll> P;

void solve() {
    int n, m; cin >> n >> m;
    m = n - m;
    ++n;
    vector<P> pts;
    forn(_, n) {
        ll x, y; cin >> x >> y;
        pts.eb(x, y);
    }
    vi nxts(n);
    vi prevs(n);
    iota(all(nxts), 1);
    iota(all(prevs), -1);
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> pq;
    vector<P> tri(3);
    vll ds(n);
    auto f = [&] (int i) {
        if (i == 0 || i == n - 1) return;
        tri[0] = pts[prevs[i]];
        tri[1] = pts[i];
        tri[2] = pts[nxts[i]];
        ll area = abs(polygonArea2(tri));
        ds[i] = area;
        pq.emplace(area, i);
    };
    forn1(i, n - 2) f(i);
    while (m > 0) {
        auto [area, i] = pq.top();
        pq.pop();
        if (ds[i] != area) continue;
        --m;
        ds[i] = -1;
        cout << i << "\n";
        nxts[prevs[i]] = nxts[i];
        prevs[nxts[i]] = prevs[i];
        f(prevs[i]);
        f(nxts[i]);
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    solve();
}
