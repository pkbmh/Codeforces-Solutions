// C
#ifndef _GLIBCXX_NO_ASSERT
#include <cassert>
#endif
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <cmath>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>

#if __cplusplus >= 201103L
#include <ccomplex>
#include <cfenv>
#include <cinttypes>
//#include <cstdalign>
#include <cstdbool>
#include <cstdint>
#include <ctgmath>
#include <cwchar>
#include <cwctype>
#endif

// C++
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>

#if __cplusplus >= 201103L
#include <array>
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <initializer_list>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <thread>
#include <tuple>
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#endif
using namespace std;

//i/o
#define SCI(a) scanf("%d", &a)
#define SCLL(a) scanf("%lld", &a)
#define PRI(a) printf("%d\n", a)
#define PRLL(a) printf("%lld\n", a)
#define gc getchar_unlocked

/*void fastRead_int(int *a)
{
register char c=0;
while (c#include<33) c=getchar_unlocked();
*a=0;
while (c>33)
{
*a=*a*10+c-'0';
c=getchar_unlocked();
}
}*/

//stl function
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define TR(c , it) for(typeof(c.begin()) it = c.begin(); it != c.end(); it++)
#define LB(v , a) lower_bound (v.begin(), v.end(), a)
#define UP(v , a) upper_bound (v.begin(), v.end(), a)
#define ALL(a) a.begin() , a.end()
#define RALL(a) a.rbegin(), a.rend()

//data type
#define LLI long long int
#define LLU long long unsigned
#define PII pair<int,int>
#define PLLI pair<LLI,LLI>
#define PDD pair<double double>
#define VI vector<int>
#define VF vector<float>
#define VD vector<double>
#define VLLI vector<LLI>
#define VPII vector<PII>
#define PSI pair<string,int>
#define PSS pair<string,string>
#define VS vector<string>
#define VVI vector<vector<int> >

//Initialization
#define SET0(a) memset(a , 0 , sizeof(a))
#define COPY(d , s) memcpy(d , s , sizeof(s))
#define SET1(a) memset(a , 1 , sizeof(a))
#define SETN1(a) memset(a , -1 , sizeof(a))

#define FOR(i ,s, e) for(int i = s; i <= e; i++)
#define RFOR(i,s, e) for(int i = s; i >= e; i--)
#define LOOP(n) for(int i = 0; i < n; ++i)

template<class T> void swaper(T &a , T &b) {T c = a; a = b; b = c;}
template<class T> T GCD(T a , T b) {if(b == 0)return a; else return GCD(b , a%b);}
template<class T>  T MulMod(T a , T b , T mod) {T x,y;x = 0;y = a;while(b > 0) {if(b&1) x = (x+y)%mod; y = (y<<1)%mod;b >>= 1;}return x;}
template<class T>  T PowMod(T a , T b, T mod) {T x,y;x = 1;y = a;while(b > 0) {if(b&1) x = (x*y)%mod;y = (y*y)%mod;b >>= 1;}return x;}
template<class T>  T Multiply(T a , T b) {T x,y;x = 0;y = a;while(b > 0) {if(b&1) x = (x+y);y = (y<<1);b >>= 1;}return x;}
template<class T>  T Power(T a , T b) {T x,y;x = 1;y = a;while(b > 0) {if(b&1) x = (x*y);y = (y*y);b >>= 1;}return x;}

const int MAX = 3*1e5+10;
const LLI MOD7 = 1e9+7;
const LLI MOD9 = 1e9+9;

VI g[MAX];
VI col;
LLI g_cnt_0, g_cnt_1;
bool dfs(int u, vector<bool> &vis, int c) {
    vis[u] = true;
    col[u] = c;
    g_cnt_0 += (c == 0);
    g_cnt_1 += (c == 1);

    bool res = true;
    for(int v : g[u]) {
        if(!vis[v]) {
            res = res & dfs(v, vis, 1-c);
        }else if(col[v] == col[u]) return false;

        if(!res) return res;
    }
    return res;
}

int main() {
ios::sync_with_stdio(0); cin.tie(0);

    int t,n,m, u,v;
    cin >> t;

    col.clear();
    col.resize(MAX);

    while(t--) {
        g_cnt_0 = g_cnt_1 = 0;
        cin >> n >> m;
        for(int i = 0; i < n; ++i) g[i].clear();

      //  cout << "---------" << endl;
        //cout << n << endl;
        LOOP(m) {
            cin >> u >> v;
            u--;
            v--;
          //  cout << u << " "<< v << endl;
            g[u].PB(v);
            g[v].PB(u);
        }

    vector<bool> vis(n, false);
    LLI md = 998244353;
    LLI ans = 1;
    for(int i = 0; i < n; ++i) {
        if(!vis[i]){
            int cnt_0 = g_cnt_0;
            int cnt_1 = g_cnt_1;
            if(dfs(i, vis, 0)) {
                LLI d_0 = g_cnt_0 - cnt_0;
                LLI d_1 = g_cnt_1 - cnt_1;

                if(d_0 + d_1 == 1) ans = ans * 3;
                else ans = ans * (PowMod(2LL, d_0, md)  + PowMod(2LL, d_1, md));
                ans %= md;
            }else {
                ans = 0;
                break;
            }
        }
    }
    cout << ans << endl;
    //cout << "-------------" << endl;
    }
return 0;
}

