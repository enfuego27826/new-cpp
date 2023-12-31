#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
 
// #define _GLIBCXX_DEBUG 1
// #define _GLIBCXX_DEBUG_PEDANTIC 1
// #pragma GCC optimize("trapv")

// #define dbg(TXTMSG) cerr << "\n" << TXTMSG
// #define dbgv(VARN) cerr << "\n" << #VARN << " = "<< VARN << ", line: " << __LINE__ << "\n"

#define ld long double
#define int long long
#define forn(i,j) for(int i = 0; i < j; i++)
#define forrange(i,j,k) for(int i = j; i < k; ++i)
#define rof(i,j) rof(int i = j; i >= 0; --i)
#define pii pair<int,int>
#define vi vector<int>
#define vpii vector<pii>
#define vvi vector<vi>
#define vvpii vector<vector<pii>>
#define vb vector<bool>
#define pb push_back
#define p push
#define f first
#define s second
#define all(x) x.begin(), x.end()
#define eb emplace_back
#define qi queue<int>
#define qpii queue<pii>
#define pqpii priority_queue<pii>
#define pqi priority_queue<int>

#define MOD 1000000007

void printvec(vi a){
	forn(i,a.size()){
		cerr << a[i] << " ";
		cerr << endl;
	}
}

void setIO(string name = ""){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	if(!name.empty()){
		freopen((name + ".in").c_str(), "r", stdin);
		freopen((name + ".out").c_str(), "w", stdout);
	}
}

struct Query{
	int diameter,height,index;
};

bool comp(Query &a, Query &b){
	if(a.diameter == b.diameter){
		return a.height > b.height;
	}

	return a.diameter > b.diameter;
}

bool comp1(pii &a, pii &b){
	if(a.f == b.f){
		return a.s > b.s;
	}

	return a.f > b.f;
}

signed main(){
	setIO("input");
	int n,q;
	cin >> n >> q;

	vpii a(n);

	forn(i,n){
		cin >> a[i].f >> a[i].s;
	}

	vector<Query> Q(q);

	forn(i,q){
		cin >> Q[i].diameter >> Q[i].height;
		Q[i].index = i;
	}

	sort(all(Q),comp);
	sort(all(a),comp1);

	int j = 0;
	vi dp;
	vi ans(q);

	forn(i,q){
		while(j < n && a[j].f >= Q[i].diameter){
			int ind = upper_bound(all(dp),-a[j].s) - dp.begin();

			if(ind == dp.size()){
				dp.pb(-a[j].s);
			}

			else{
				dp[ind] = -a[j].s;
			}

			j++;
		}

		int d = upper_bound(all(dp),-Q[i].height) - dp.begin();
		if(dp[d-1] == -Q[i].height){
			ans[Q[i].index] = d-1;
		}
		
		ans[Q[i].index] = dp.size() - d;	
	}

	printvec(dp);

	forn(i,q){
		cout << ans[i] << endl;
	}
}