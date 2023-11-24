#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
 
#define _GLIBCXX_DEBUG 1
#define _GLIBCXX_DEBUG_PEDANTIC 1
#pragma GCC optimize("trapv")

#define dbg(TXTMSG) cerr << "\n" << TXTMSG
#define dbgv(VARN) cerr << "\n" << #VARN << " = "<< VARN << ", line: " << __LINE__ << "\n"

#define ll long long
#define ld long double
#define forn(i,j) for(ll i = 0; i < j; i++)
#define forrange(i,j,k) for(int i = j; i < k; ++i)
#define rof(i,j) rof(int i = j; i >= 0; --i)
#define pii pair<int,int>
#define vll vector<ll>
#define vi vector<int>
#define vvll vector<vll>
#define vvi vector<vi>
#define vb vector<bool>
#define pb push_back
#define p push
#define f first
#define s second
#define all(x) x.begin(), x.end()
#define eb emplace_back
#define qi queue<int>
#define qpii queue<pii>

#define MOD 1000000007

void setIO(string name = ""){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	if(!name.empty()){
		freopen((name + ".in").c_str(), "r", stdin);
		freopen((name + ".out").c_str(), "w", stdout);
	}
}

struct dsu{
	vi e;

	dsu(int m){ e = vi(m,-1);}

	int get(int x){
		return e[x] < 0 ? x : e[x] = get(e[x]);
	}

	int sze(int x){
		return -e[get(x)];
	}

	bool same_set(int a, int b){
		return get(a) == get(b);
	}

	bool unite(int a, int b){
		a = get(a);
		b = get(b);

		if(a == b){
			return false;
		}

		else{
			e[a] += e[b];
			e[b] = a;

			return true;
		}
	}
};

bool st(pair<int,int>& a, pair<int,int>& b){
	return a.f > b.f;
}

int main(){
	setIO("mootube");
	int n, q;
	cin >> n >> q;

	vector<pii> edgeval(n-1);
	vector<pii> edge(n-1);

	forn(i,n-1){
		int a,b, val;
		cin >> a >> b >> val;

		edge[i] = {a,b};
		edgeval[i] = {val,i};
	}

	sort(all(edgeval),st);

	vector<pii> query_val(q);
	vi vertex(q);
	vi ans(q);

	dsu d(n+1);

	forn(i,q){
		int a, b;
		cin >> a >> b;

		query_val[i] = {a,i};
		vertex[i] = b;
	}

	sort(all(query_val),st);

	int t = 0;

	forn(i,q){
		int j = query_val[i].f;

		if(t < n){
			while(edgeval[t].f >= j){
				int a = edge[edgeval[t].s].f;
				int b = edge[edgeval[t].s].s;

				bool g = d.unite(a,b);
    
				t++;
			}
		}
		int ind = query_val[i].s;

		int h = vertex[ind];
		ans[ind] = d.sze(h);
	}

	forn(i,q){
		cout << ans[i] - 1 << endl;
	}
}