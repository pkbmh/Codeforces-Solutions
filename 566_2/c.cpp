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
#define nl '\n'
template<class T> void swaper(T &a , T &b) {T c = a; a = b; b = c;}
template<class T> T GCD(T a , T b) {if(b == 0)return a; else return GCD(b , a%b);}
template<class T>  T MulMod(T a , T b , T mod) {T x,y;x = 0;y = a;while(b > 0) {if(b&1) x = (x+y)%mod; y = (y<<1)%mod;b >>= 1;}return x;}
template<class T>  T PowMod(T a , T b, T mod) {T x,y;x = 1;y = a;while(b > 0) {if(b&1) x = (x*y)%mod;y = (y*y)%mod;b >>= 1;}return x;}
template<class T>  T Multiply(T a , T b) {T x,y;x = 0;y = a;while(b > 0) {if(b&1) x = (x+y);y = (y<<1);b >>= 1;}return x;}
template<class T>  T Power(T a , T b) {T x,y;x = 1;y = a;while(b > 0) {if(b&1) x = (x*y);y = (y*y);b >>= 1;}return x;}

const int MAX = 1e6+10;
const LLI MOD7 = 1e9+7;
const LLI MOD9 = 1e9+9;


int count_match(string &str) {
    int cnt = 0;
    set<char> st = {'a', 'e', 'o', 'i', 'u'};
    for(char c : str) {
        if(st.count(c)) cnt++;
    }
    return cnt;
}

struct node {
    string s;
    int cnt;
    char c;
};

int get_last_v(string &s) {
    char l = s[0];
    set<char> st = {'a', 'e', 'o', 'i', 'u'};
    for(char c : s) if (st.count(c)) l = c;
    return l;
}

int main() {
ios::sync_with_stdio(0); cin.tie(0);

    int n;
    cin >> n;
    node a[n];
    string s;
    
    LOOP(n) {
        cin >> s;
        a[i].s = s;
        a[i].cnt = count_match(s);
        a[i].c = get_last_v(s);
    }
    map<int, VI> mp;
    map<PII, VI> mp_lst;
    LOOP(n) {
        mp_lst[{a[i].cnt, a[i].c}].PB(i);
    }
    struct node_ans {
        int i1, i2;
        int j1,j2;
        node_ans(int a, int b, int c, int d) {
            i1 = a;
            i2 = b;
            j1 = c;
            j2 = d;
        }
        node_ans(){}
    };
    vector<node_ans> ans;
    // remove single pairs
    VPII need_remove;
    for(auto mi : mp_lst) {
        if(mi.S.size() % 2 == 1) {
            need_remove.PB(mi.F);       
        }
    }

    for(PII p: need_remove) {
        int i = mp_lst[p].back();
        mp[p.F].PB(i);
        mp_lst[p].pop_back();
        if(mp_lst[p].size() == 0) mp_lst.erase(p);
    }
    VI need_remove_cnt;
    for(auto mi : mp) {
        if(mi.S.size() % 2 == 1) {
            need_remove_cnt.PB(mi.F);
        }
    }
    for(int i: need_remove_cnt) {
        mp[i].pop_back();
        if(mp[i].size() == 0) mp.erase(i);
    }
    for(auto mi : mp) {
        if(mp_lst.size() == 0) break;
        for(int i = 0; mp_lst.size() > 0 && i < mi.S.size(); i += 2) {  
            auto tmp = mp_lst.begin();
            int j1 = tmp->S.back();
            tmp->S.pop_back();
            ans.PB(node_ans(mi.S[i], j1, mi.S[i+1], tmp->S.back()));
            tmp->S.pop_back();
            if(tmp->S.size() == 0) mp_lst.erase(tmp);
        }
    } 
    auto it = mp_lst.begin();
    while(it != mp_lst.end()) {
        if(it->S.size() >= 4) {            
            node_ans tmp;
            tmp.i1 = it->S.back(); it->S.pop_back();
            tmp.i2 = it->S.back(); it->S.pop_back();//it1->S.back();
            tmp.j1 = it->S.back(); it->S.pop_back();
            tmp.j2 = it->S.back(); it->S.pop_back();//it1->S.back()
            ans.PB(tmp);
        }else if(it->S.size() >= 2){
            auto it1 = it;
            it++;
            if(it == mp_lst.end()) break;
            else {
                node_ans tmp;
                tmp.i1 = it->S.back(); it->S.pop_back();
                tmp.i2 = it1->S.back(); it1->S.pop_back();
                tmp.j1 = it->S.back(); it->S.pop_back();
                tmp.j2 = it1->S.back();
                ans.PB(tmp);
            }
        }else it++;
    }
    cout << ans.size() << endl;
    for(auto i : ans) {
        cout << a[i.i1].s << " "<< a[i.i2].s << endl;
        cout << a[i.j1].s << " "<< a[i.j2].s << endl;
    }
return 0;
}

