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


template<class T> void swaper(T &a , T &b) {T c = a; a = b; b = c;}
template<class T> T GCD(T a , T b) {if(b == 0)return a; else return GCD(b , a%b);}
template<class T>  T MulMod(T a , T b , T mod) {T x,y;x = 0;y = a;while(b > 0) {if(b&1) x = (x+y)%mod; y = (y<<1)%mod;b >>= 1;}return x;}
template<class T>  T PowMod(T a , T b, T mod) {T x,y;x = 1;y = a;while(b > 0) {if(b&1) x = (x*y)%mod;y = (y*y)%mod;b >>= 1;}return x;}
template<class T>  T Multiply(T a , T b) {T x,y;x = 0;y = a;while(b > 0) {if(b&1) x = (x+y);y = (y<<1);b >>= 1;}return x;}
template<class T>  T Power(T a , T b) {T x,y;x = 1;y = a;while(b > 0) {if(b&1) x = (x*y);y = (y*y);b >>= 1;}return x;}

const int MAX = 1e6+10;
const LLI MOD7 = 1e9+7;
const LLI MOD9 = 1e9+9;


class DSUCell {
public:
	DSUCell(int n, int m)  {
		this->n = n;
		this->m = m;
		init();
	}
	DSUCell(int n) : DSUCell(n,n){}

	pair<int,int> find(const pair<int,int> p) {
		if(cellGroup[p] != p) return cellGroup[p] = find(cellGroup[p]);
		return cellGroup[p];
	}

	void union1(pair<int,int> a, pair<int,int> b) {
		if(groupSize[a] >= groupSize[b]) {
			groupSize[a] += groupSize[b];
			cellGroup[b] = cellGroup[a];
		}else {
			groupSize[b] += groupSize[a];
			cellGroup[a] = cellGroup[b];
		}
	}
	vector<pair<int,int> > getAllInGroup(pair<int,int> g) {
		vector<pair<int,int> > res;
		for(int i = 0; i < n; ++i)
			for(int j = 0; j < m; ++j)
				if(find({i,j}) == g)
					res.push_back({i,j});

		return res;
	}
private:
	int n, m;
	map<pair<int,int>, int> groupSize;
	map<pair<int,int>, pair<int,int> > cellGroup;
	void init() {
		for(int i = 0; i < n; ++i)
			for(int j = 0; j < m; ++j) {
				cellGroup[{i,j}] = {i , j};
				groupSize[{i,j}] = 1;
			}
	}
};

int main()
{
    int n;
    PII s,d;
    
    SCI(n);

    SCI(s.F); SCI(s.S);
    SCI(d.F); SCI(d.S);

    vector<string> mat(n);

    for(int i = 0; i < n; ++i) {
        cin >> mat[i];
    }
        
    int dir_x[] = {1,-1,0,0};
    int dir_y[] = {0,0,1,-1};
    
    DSUCell dsu(n);
    
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            if(mat[i][j] == '0') {
                for(int d = 0; d < 4; ++d) {
                    PII g = dsu.find({i, j});

                    if(i+dir_x[d] >= 0 && i + dir_x[d] < n && j + dir_y[d] >= 0 && j+dir_y[d] < n  && mat[i+dir_x[d]][j+dir_y[d]] == '0') {
                        PII ng = dsu.find({i+dir_x[d], j+dir_y[d]});
                        
                        if(g != ng) {
                            dsu.union1(g, ng);
                        }
                    }
                }
            }
        }
    }

    s.F--;
    s.S--;
    d.F--;
    d.S--;


    PII sg = dsu.find(s);
    vector<PII> sgm = dsu.getAllInGroup(sg);

    PII dg = dsu.find(d);
    vector<PII> dgm = dsu.getAllInGroup(dg);
    
    int mn = INT_MAX;

    //cout << sg.F << " "<< sg.S << " sg "<< endl;
    //cout << dg.F << " "<< dg.S << " dg "<< endl;
    if(sg == dg) mn = 0;
    else {
        for(PII sp : sgm) {
            //cout << sp.F << " sp "<< sp.S << endl;
            for(PII dp : dgm) {
              //  cout << dp.F << " dp " << dp.S << endl;
                mn = min((sp.F-dp.F)*(sp.F-dp.F) + (sp.S-dp.S)*(sp.S-dp.S), mn);
            }
        }
    }
    cout << mn << endl;
return 0;
}

