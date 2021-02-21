/* Priyansh Agarwal*/
#include<stdlib.h>
#include<iostream>
#include<time.h>
#include<vector>
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<stack>
#include<unordered_set>
#include<cmath>
#include<numeric>
#include<iterator>
#include<set>
#include<unordered_map>
#include<map>
#include<queue>
#include<cstring>
#include<stdio.h>
#include<fstream>
#include<iomanip>
#include<functional>
#include<bitset>
#include<chrono>
#include<climits>
#include<assert.h>

using namespace std;
using namespace chrono;

#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MOD 1000000007
#define MOD1 998244353
#define INF 1e18
#define nline "\n"
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define ff first
#define ss second
#define PI 3.141592653589793238462
#define set_bits __builtin_popcountll
#define sz(x) (int)(x.size())

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x<<" "; _print(x); cerr << endl;
#else
#define debug(x);
#endif

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;

void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}


template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

//#include<ext/pb_ds/assoc_container.hpp>
//#include<ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
//typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update > pbds; // find_by_order, order_of_key
//void _print(pbds v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

/*---------------------------------------------------------------------------------------------------------------------------*/
ll gcd(ll a, ll b) {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}
ll expo(ll a, ll b, ll mod) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
void extendgcd(ll a, ll b, ll*v) {if (b == 0) {v[0] = 1; v[1] = 0; v[2] = a; return ;} extendgcd(b, a % b, v); ll x = v[1]; v[1] = v[0] - v[1] * (a / b); v[0] = x; return;} //pass an arry of size1 3
ll mminv(ll a, ll b) {ll arr[3]; extendgcd(a, b, arr); return arr[0];} //for non prime b
ll mminvprime(ll a, ll b) {return expo(a, b - 2, b);}
bool revsort(ll a, ll b) {return a > b;}
void swap(int &x, int &y) {int temp = x; x = y; y = temp;}
ll combination(ll n, ll r, ll m, ll *fact, ll *ifact) {ll val1 = fact[n]; ll val2 = ifact[n - r]; ll val3 = ifact[r]; return (((val1 * val2) % m) * val3) % m;}
void google(int t) {cout << "Case #" << t << ": ";}
vector<ll> sieve(int n) {int*arr = new int[n + 1](); vector<ll> vect; for (int i = 2; i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for (int j = 2 * i; j <= n; j += i)arr[j] = 1;} return vect;}
ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
ll mod_div(ll a, ll b, ll m) {a = a % m; b = b % m; return (mod_mul(a, mminvprime(b, m), m) + m) % m;}  //only for prime m
ll phin(ll n) {ll number = n; if (n % 2 == 0) {number /= 2; while (n % 2 == 0) n /= 2;} for (ll i = 3; i <= sqrt(n); i += 2) {if (n % i == 0) {while (n % i == 0)n /= i; number = (number / i * (i - 1));}} if (n > 1)number = (number / n * (n - 1)) ; return number;} //O(sqrt(N))
/*--------------------------------------------------------------------------------------------------------------------------*/
const int value = 101;
struct pizza{
    ll size;
    vector<string> ingrediants;
    ll index;
    bitset<value> hash_value;
};
struct delivery{
    int team_size;
    vector<int> pizzas_to_be_delivered;
};
bool compare(pizza &a, pizza &b){
      return a.ingrediants.size() > b.ingrediants.size();
}
ll score = 0;
vector<pizza> pizzas;
vector<delivery> ans;
vector<bitset<value>> sets;
void solve() {
      int n, a, b, c;
      cin >> n >> a >> b >> c;
      set<string> ingrediants;
      int max1 = 0;
      int p = 0;
      for(int i = 0; i < n; i++){
            int m;
            cin >> m;
            vector<string> v1(m);
            for(int j = 0; j < m; j++) {
                  cin >> v1[j];
                  ingrediants.insert(v1[j]);
            }
            max1 = max(max1, m);
            p += m;
            bitset<value> v;
            pizzas.pb({m, v1, i, v});
      }
      sort(pizzas.begin(), pizzas.end(), compare);
      int count = 0;
      map<string, int> m1;
      debug((int)ingrediants.size());
      for(auto i : ingrediants){
            m1[i] = count++;
      }
      for(int i = 0; i < n; i++){
            bitset<value> new_set;
            for(auto j : pizzas[i].ingrediants){
                  new_set.set(m1[j]);
            }
            sets.pb(new_set);
            pizzas[i].hash_value = new_set;
      }
      sort(pizzas.begin(), pizzas.end(), compare);
      while(true){
            while(a > 0 && pizzas.size() >= 2){
                  int n = pizzas.size();
                  vector<int> v1;
                  bitset<value> v;
                  for(int i = 0; i < 2; i++){
                        v1.pb(pizzas[n-1].index);
                        v |= pizzas[n-1].hash_value;
                        n--;
                        pizzas.pop_back();
                  }
                  ans.pb({2, v1});
                  ll p = v.count();
                  p *= p;
                  score += p;
                  a--;
            }
            while(b > 0 && pizzas.size() >= 3){
                  int n = pizzas.size();
                  vector<int> v1;
                  bitset<value> v;
                  for(int i = 0; i < 3; i++){
                        v1.pb(pizzas[n-1].index);
                        v |= pizzas[n-1].hash_value;
                        n--;
                        pizzas.pop_back();
                  }
                  ans.pb({3, v1});
                  ll p = v.count();
                  p *= p;
                  score += p;
                  b--;
            }
            debug((int)pizzas.size());
            while(c > 0 && pizzas.size() >= 4){
                  int n = pizzas.size();
                  vector<int> v1;
                  bitset<value> v;
                  for(int i = 0; i < 4; i++){
                        v1.pb(pizzas[n-1].index);
                        v |= pizzas[n-1].hash_value;
                        n--;
                        pizzas.pop_back();
                  }
                  ans.pb({4, v1});
                  ll p = v.count();
                  p *= p;
                  score += p;
                  c--;
            }
            break;
      }
      cout << ans.size() << nline;
      debug(score);
      for(auto i : ans){
            cout << i.team_size << " ";
            for(auto j : i.pizzas_to_be_delivered)
                  cout << j << " ";
            cout << nline;
      }

}
int main() {
      fastio();
      #ifndef ONLINE_JUDGE
      freopen("Input.txt", "r", stdin);
      freopen("Output.txt", "w", stdout);
      freopen("Error.txt", "w", stderr);
      #endif
      auto start1 = high_resolution_clock::now();
      solve();
      auto stop1 = high_resolution_clock::now();
      auto duration = duration_cast<microseconds>(stop1 - start1);
      #ifndef ONLINE_JUDGE
      cerr << "Time: " << duration.count() / 1000 << endl;
      #endif
}