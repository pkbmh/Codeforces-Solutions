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
#define LOOP(n) for(int = 0; i < n; ++i)

template<class T> void swaper(T &a , T &b) {T c = a; a = b; b = c;}
template<class T> T GCD(T a , T b) {if(b == 0)return a; else return GCD(b , a%b);}
template<class T>  T MulMod(T a , T b , T mod) {T x,y;x = 0;y = a;while(b > 0) {if(b&1) x = (x+y)%mod; y = (y<<1)%mod;b >>= 1;}return x;}
template<class T>  T PowMod(T a , T b, T mod) {T x,y;x = 1;y = a;while(b > 0) {if(b&1) x = (x*y)%mod;y = (y*y)%mod;b >>= 1;}return x;}
template<class T>  T Multiply(T a , T b) {T x,y;x = 0;y = a;while(b > 0) {if(b&1) x = (x+y);y = (y<<1);b >>= 1;}return x;}
template<class T>  T Power(T a , T b) {T x,y;x = 1;y = a;while(b > 0) {if(b&1) x = (x*y);y = (y*y);b >>= 1;}return x;}

const int MAX = 1e6+10;
const LLI MOD7 = 1e9+7;
const LLI MOD9 = 1e9+9;

VVI g;
VI vis, dist, dist_from_v1, dist_from_v2;
int comp;

int cv;
int ch;

void dfs(int u, VI &dist, int h, int p = -1) {
    if(ch < h) {
        ch = h;
        cv = u;
    }
    dist[u] = h;
    vis[u] = comp;
    for(int v : g[u]) if(v != p) dfs(v,dist, h+1, u);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n,m;
    cin >> n >> m;
    int u, v;
    g.resize(n);
    for(int i = 0; i < m; ++i)  {
        cin >> u >> v;
        u--;
        v--;
        g[u].PB(v);
        g[v].PB(u);
    }
    
    vis.clear(); vis.resize(n, -1);
    dist.clear(); dist.resize(n, INT_MAX);

    VPII center;
    int md = -1;
    int md_c = -1;

    for(int i = 0; i < n; ++i) {
        if(vis[i] == -1){
        
            cv = ch = -1;
            dfs(i, dist, 0);
            
            int v1 = cv;

            // also mark dist_from_v1
            
            dist_from_v1.clear(); dist_from_v1.resize(n, -1);
            dist_from_v2.clear(); dist_from_v2.resize(n, -1);
           
            cv = ch = -1;
            dfs(v1, dist_from_v1, 0);    
            
            int v2 = cv;

            dfs(v2, dist_from_v2, 0);
            
            int d = dist_from_v1[v2];
            
            
            int c = -1;
            for(int j = 0; j < n; ++j) {
                if(dist_from_v1[j] != -1 && dist_from_v1[j] == d/2 && dist_from_v2[j] == d - d/2) {
                    c = j;
                }
            }
            
            if(md < d) {
                md = d;
                md_c = c;
            }

            center.PB({c, d});

            comp++;
        }
    }
    
    VPII edges;
    int di = md;
    for(auto p : center) {
        if(p.F != md_c) {
           edges.PB({md_c+1, p.F+1});
           
           g[md_c].PB(p.F);
           g[p.F].PB(md_c);

           di = max(di, p.S/2 + (p.S % 2 == 1) + md/2 + (md%2 == 1)+1); 
           // cout << md_c+1 << " " << p.F+1 << endl;
        }
    }
    cv = ch = -1;
    
    dfs(md_c, dist, 0);
    ch = -1;
    dfs(cv, dist, 0);
    
    cout << ch << endl;
    for(auto p : edges) cout << p.F << " "<< p.S << endl;


return 0;
}
