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
struct pizza{
    int size;
    vector<string> ingrediants;
    int index;
    int hash_value;
};
struct delivery{
    int team_size;
    vector<int> pizzas_to_be_delivered;
};
bool compare(pizza &a, pizza &b){
      return a.ingrediants.size() < b.ingrediants.size();
}
ll score = 0;
vector<pizza> pizzas;
vector<delivery> ans;
pair<int, delivery> select_two(){
      int n = pizzas.size();
      pair<int, int> optimal = {-1e9, 1e9};
      vector<int> to_be_used;
      for(int i = n-1; i >= 1; i--){
            for(int j = i - 1; j >= 0; j--) {
                  int sum = pizzas[i].hash_value | pizzas[j].hash_value;
                  sum = set_bits(sum);
                  int used = pizzas[i] . size + pizzas[j] . size;
                  if (optimal . ff < sum || (optimal . ff == sum && used < optimal . ss)) {
                        optimal = {sum , used};
                        to_be_used = {i , j};
                  }
            }
      }
      vector<int> actual_indices;
      for(auto i : to_be_used){
            actual_indices.pb(pizzas[i].index);
      }
      ll val = optimal.ff * optimal.ff;
      debug(val);
      pair<int, delivery> a = {val, {2, actual_indices}};
      return a;
}
pair<int, delivery> select_three(){
      int n = pizzas.size();
      pair<int, int> optimal = {-1e9, 1e9};
      vector<int> to_be_used;
      srand(time(0));
      int counter = 0;
      unordered_set<string> s1;
      for(int i = n-1; i >= 2; i--){
            for(int j = i - 1; j >= 1; j--) {
                  for (int k = j - 1; k >= 0; k--) {
                        int sum = pizzas[i].hash_value | pizzas[j].hash_value | pizzas[k].hash_value;
                        sum = set_bits(sum);
                        int used = pizzas[i] . size + pizzas[j] . size + pizzas[k] . size;
                        if (optimal . ff < sum || (optimal . ff == sum && used < optimal . ss)) {
                              optimal = {sum , used};
                              to_be_used = {i , j , k};
                              counter = 1;
                        }
                  }
            }
      }
      vector<int> actual_indices;
      for(auto i : to_be_used){
            actual_indices.pb(pizzas[i].index);
      }
      ll val1 = optimal.ff * optimal.ff;
      debug(val1);
      pair<int, delivery> a = {val1, {3, actual_indices}};
      return a;
}
pair<int, delivery> select_four(){
      int n = pizzas.size();
      pair<int, int> optimal = {-1e9, 1e9};
      vector<int> to_be_used;
      int counter = 0;
      srand(time(0));
      for(int i = n-1; i >= 3; i--){
            for(int j = i - 1; j >= 2; j--) {
                  for (int k = j - 1; k >= 1; k--) {
                        for (int l = k - 1; l >= 0; l--) {
                              int sum = pizzas[i] . hash_value | pizzas[j] . hash_value | pizzas[k] . hash_value |
                                        pizzas[l] . hash_value;
                              sum = set_bits(sum);
                              int used = pizzas[i] . size + pizzas[j] . size + pizzas[k] . size + pizzas[l] . size;
                              if (optimal . ff < sum || (optimal . ff == sum && used < optimal . ss)) {
                                    optimal = {sum , used};
                                    counter = 1;
                                    to_be_used = {i , j , k , l};
                              }
                        }
                  }
            }
      }
      vector<int> actual_indices;
      for(auto i : to_be_used){
            actual_indices.pb(pizzas[i].index);
      }
      ll val2 = optimal.ff * optimal.ff;
      debug(val2);
      pair<int, delivery> a = {val2, {4, actual_indices}};
      return a;
}
void remove1(vector<int> v1){
      int n = pizzas.size();
      for(int j = 0; j < v1.size(); j++) {
            for (int i = 0; i < n; i++) {
                  if (pizzas[i] . index == v1[j]){
                        pizzas.erase(pizzas.begin() + i);
                        break;
                  }
            }
      }
}
void solve() {
      int n, a, b, c;
      cin >> n >> a >> b >> c;
      set<string> ingrediants;
      for(int i = 0; i < n; i++){
            int m;
            cin >> m;
            vector<string> v1(m);
            for(int j = 0; j < m; j++) {
                  cin >> v1[j];
                  ingrediants.insert(v1[j]);
            }
            pizzas.pb({m, v1, i, 0});
      }
      map<string, int> m1;
      int count = 0;
      for(auto i : ingrediants){
            m1[i] = count++;
      }
      for(int i = 0; i < n; i++){
            int value = 0;
            for(auto j : pizzas[i].ingrediants){
                  value |= (1 << m1[j]);
            }
            pizzas[i].hash_value = value;
      }
      sort(pizzas.begin(), pizzas.end(), compare);
      srand(time(0));
      while(a + b + c > 0){
            vector<int> v1;
            pair<int, delivery> a1 = {0, {2, v1}};
            pair<int, delivery> b1 = {0, {3, v1}};
            pair<int, delivery> c1 = {0, {4, v1}};
            if(b > 0 && pizzas.size() >= 3) {
                  b1 = select_three();
            }
            if(b1.ff != 100) {
                  if (a > 0 && pizzas . size() >= 2) {
                        a1 = select_two();
                  }
                  if (a1 . ff != 100 && c > 0 && pizzas . size() >= 4) {
                        c1 = select_four();
                  }
            }
            if(a1.ff == 0 && b1.ff == 0 && c1.ff == 0)
                  break;
            int max1 = max(a1.ff, max(b1.ff, c1.ff));
            score += max1;
            if(a1.ff == max1){
                  debug(2);
                  ans.pb(a1.ss);
                  a--;
                  remove1(a1.ss.pizzas_to_be_delivered);
            }else if(b1.ff == max1){
                  debug(3);
                  ans.pb(b1.ss);
                  b--;
                  remove1(b1.ss.pizzas_to_be_delivered);
            }else{
                  debug(4);
                  ans.pb(c1.ss);
                  c--;
                  remove1(c1.ss.pizzas_to_be_delivered);
            }
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