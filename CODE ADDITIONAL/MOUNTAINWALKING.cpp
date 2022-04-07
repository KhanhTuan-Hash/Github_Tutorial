// quá là spicy cú với bài này 
 

/* Code with ĐU */ 

#include <bits/stdc++.h>

#include <assert.h>  

int64_t  n , m ; 

#define MAX_N 101

using namespace std ;

int64_t Dx[] = {+1 , 0 , -1 , 0} ;
int64_t Dy[] = { 0 , +1, 0 , -1} ; 

int64_t Map[MAX_N][MAX_N] ; 
vector < vector < bool  > > mark(n + 1, vector < bool > (MAX_N , 0) ) ; 

// dfs 
// res = k + diff 
// bin with res in range 0 - > 110 

// map[x][y]  >= hmin   && map[x][y] <= hmin + diff

bool flag ; 

auto Check =[](int64_t u , int64_t v , int64_t high_min , int64_t diff) -> int64_t
{
    return ( Map[u][v] >= high_min and Map[u][v] <= high_min + diff) ; 
} ; 

auto pos_high =[](int64_t u , int64_t v) ->int64_t
{
    return (u > 0 and  v > 0 and u <= n and v <= n ); 
} ; 

function < void (int64_t, int64_t, int64_t , int64_t ) > DFS = [](int64_t u , int64_t v , int64_t high_min , int64_t diff) 
{
     // corner case  : 
     if(u == n or v == n ) 
     {
         flag = true ;
         return ; 
     }
     mark[u][v] = 1 ; 
     for(int64_t i = 0 ;i <= 3; i++)
     {
         int64_t x = u + Dx[i] ;
         int64_t y = v + Dy[i] ; 
         if(x < 0 or y < 0 or x > n or y > n) continue ;
         if(Check(x , y , high_min , diff) and pos_high(x , y) and !mark[x][y]) 
             DFS(x , y , high_min , diff) ; 
     }
} ; 


auto valid = [](int64_t diff) -> bool
{
  for(int64_t high_min = 0 ; high_min < 110  - diff ; high_min++)
  {
      for(int64_t i = 1; i <= n; i++)
      {
        for(int64_t j = 1; j <= n; j++) 
        mark[i][j] = 0 ;
      }
  flag = false ; 
  if(Check(1 , 1 , high_min , diff ))
  {
      DFS(1 , 1 , high_min , diff) ;
      if(flag) return true; 
      else
      {
          continue ;
      }
  } 

  } 
  return 0 ;
} ; 

int32_t main(int32_t argc,char*argv[])
{
    cin.tie(0)->sync_with_stdio(false); 
    cerr.tie(0)  ;
    
  //  assert(2 <= n && n <= 100) ;

    cin >> n ; 

    for(int64_t i = 1; i <= n; i++)
    {
        for(int64_t j = 1; j <=n ; j++)
        {
            cin >> Map[i][j] ;
        }
    }
  auto bin_sot = [&](int64_t l , int64_t r) -> int64_t
{
        int64_t mid ; 
        while(true)
        {
            mid = (l + r) >> 1; 
            if(l == mid or mid == r) break ;
            if(valid(mid) ) 
            {
                r = mid ;
            }
            else 
            {
                l = mid ;
            }
        }
        for(int64_t mid = l ; mid <= r; mid++)
        {
            if(valid(mid)) 
            {
                return mid; 
            }
        }
} ;
     bin_sot( 0 ,110) ; 
     assert(true) ;
     return 0 ;
}

 