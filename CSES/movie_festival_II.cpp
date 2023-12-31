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

void setIO(string name = ""){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	if(!name.empty()){
		freopen((name + ".in").c_str(), "r", stdin);
		freopen((name + ".out").c_str(), "w", stdout);
	}
}

bool comp(pii &a, pii &b){
	if(a.s == b.s){
		return a.f < b.f;
	}
	return a.s < b.s;
}

signed main(){
	setIO();
	int n,k; multiset<int> s;
	cin >> n >> k;
	vpii movies(n);
	forn(i,n){ cin >> movies[i].f >> movies[i].s;}
	sort(all(movies),comp); forn(i,k){ s.insert(0);}
	int res = 0;
	for(pii b : movies){
		auto it = s.upper_bound(b.f);
		if(it == s.begin()){ continue;}
		it--; s.erase(s.find(*it));
		s.insert(b.s);
		res++;
	}

	cout << res;
}