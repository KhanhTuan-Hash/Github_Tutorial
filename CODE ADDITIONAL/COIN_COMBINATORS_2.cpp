#pragma GCC optimize("Ofast")
#pragma GCC tatget("avx,avx2,fma")
#include <bits/stdc++.h>
#include <assert.h>
using namespace std ;
 // 3 7
 // 1 3 4 
// basic dp (knapsack ) ; 
//-> kq = {1 + 3 + 3} , {1 + 1 + 1 + 1 + 1 + 1 + 1} , { 4  + 3} , {1 + 1 + 4 + 1}  , {1 + 1 + 3  + 1 + 1} ; 
//-> kq = 5 ; 
// j - a[i] >= 0 res = res + dp[ j - a[i] ] 
// j > i

template < class T  , class TR > inline bool maximize(T &A , TR B)
{
      if(A >= B) return false; 
      A = B; 
      return true;  
}
template < class T , class TR > inline bool minimize(T &A , TR B)
{
    if(A <= B ) return false; 
    A = B ;
    return true ;
}

const int64_t mod = (int64_t)(1e9 + 7) ; 

int64_t Way[1000001];

int main(int argc,char*argv[]){
    cin.tie(0)->sync_with_stdio(false) ;
	int64_t  n , sum  ;
    cin >> n >> sum ; 
	vector < int64_t > flip(n) ; 
	for (int32_t i = 0; i < n; i++) {
		cin >> flip[i];
	}
	Way[0] = 1;
	for (int32_t i = 0; i <= sum; i++) {
		for (int32_t j = 1; j <= n; j++) {
            int64_t diff = i - flip[j - 1] ;
            if(diff >= 0)
            {
                Way[i] = (Way[i] + Way[diff]) % mod ; 
            }
		}
	}
	cout << Way[sum] << '\n';
}