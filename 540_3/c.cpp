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

int main()
{
    /*
     *  4
     *  1 8 8 1 2 2 2 2 2 2 2 2 1 8 8 1
     *
     *  3
     *  1 1 1 1 1 3 3 3 3
     *
     */

    int n, a;
    SCI(n);
    int mat[n][n];
    unordered_map<int,int> mp;
    for (int i = 0; i < n*n; i++) {
        SCI(a);
        mp[a]++;
    }
    
    priority_queue<PII> pq;
    priority_queue<PII> pq2;

    for(auto p : mp) {
        if(p.S >= 4){
            pq.push({p.S, p.F});
        }
        else {
            pq2.push({p.S, p.F});
        }
    }

   pq.push({-1,-1});
   pq2.push({-1,-1});

    bool flag = true;
    int i = 0;
    int j = n-1;

    while(i < j && flag) {
        int c1 = 0;
        int c2 = n-1;
        
        
        while(c1 < c2) {
            if(pq.empty()) {
                flag = false;
                break;
            } 
            PII p = pq.top(); pq.pop();
//            cout << p.F << " i != j "<< p.S   << endl;
            if(p.F < 4) {
  //              cout << "fg1 " << endl;
           //     cout << " i " << i << " "<< j << " "<< c1 << " "<< c2 << " p "<< p.F << " "<< p.S << endl;
                flag = false;
                break;
            } else if (p.F > 4) {
                if(p.F-4 >= 4){
                //cout << "inserting " << p.F-4 << " "<< p.S << endl;
                    pq.push({p.F-4, p.S});
                }else {
                    pq2.push({p.F-4, p.S});
                }
            }

            mat[i][c1] = mat[i][c2] = mat[j][c1] = mat[j][c2] = p.S;

            c1++;
            c2--;
        }


        if(c1 == c2) {
            PII p;
            if(pq2.top().F >= 2){
                p = pq2.top();
                pq2.pop();
            }else{
                p = pq.top(); pq.pop();
            }
            //cout << p.F << " c1 != c2 "<< p.S   << endl;  
            if(p.F < 2) {
    //            cout << "fg2" << endl;
                  flag = false;
              } else if (p.F  > 2) {
                  if(p.F-2 >= 4)
                    pq.push({p.F-2, p.S});
                  else pq2.push({p.F-2, p.S});
              }

              mat[i][c1] = mat[j][c1] = p.S;
        }
        i++;
        j--;
    }

    if(i == j) {
        int c1 = 0;
        int c2 = n-1;


        while(c1 < c2) {

            PII p;
            if(pq2.top().F >= 2){
                p = pq2.top();
                pq2.pop();
            }else{
                p = pq.top(); pq.pop();
            }
            //cout << p.F << " c1 != c2 "<< p.S   << endl;
            if(p.F < 2) {
      //          cout << "fg3" << endl;
                  flag = false;
              } else if (p.F  > 2) {
                  if(p.F-2 >= 4)
                    pq.push({p.F-2, p.S});
                  else pq2.push({p.F-2, p.S});
              }

            mat[i][c1] = mat[i][c2]  = p.S;
            c1++;
            c2--;
        }


        if(c1 == c2) {
            PII p;
            if(pq2.top().F >= 1){
                p = pq2.top();
                pq2.pop();
            }else{
                p = pq.top(); pq.pop();
            }
            
            if(p.F < 1) {
                  flag = false;
        //          cout << "fg4" << endl;
              } else if (p.F > 1) {
                  pq.push({p.F-2, p.S});
              }

              mat[i][c1] = mat[i][c1] = p.S;
        }
    }
    if(flag) {
        cout << "YES" << endl;
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                cout << mat[i][j] << " ";
            }
            cout << endl;
        }
    }else {
        cout << "NO" << endl;
    }

return 0;
}

