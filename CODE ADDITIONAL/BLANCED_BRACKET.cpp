#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>
using namespace std ;

template < class T , class Y > inline bool  maximize(T &a, Y b)
{
    if(a >= b) return false ;
    a = b ;
    return true ; 
}
template <class T , class Y > inline bool minimize(T &a , Y b)
{
     if(a <= b) return false ;
     a = b ;
     return true ; 
}

char X ;  
inline bool check(string Brackets)
{
    stack <char > St ; 
    for(char Br :  Brackets)
    {
        if(Br == '(' or Br == '{' or Br == '[')
        {
            St.push(Br) ; 
          //  continue ; 
        }
        else
        {
            
            if(St.empty()) return false ; 
            if(St.top() == '(' and Br != ')') return false ; // case ')'
            if(St.top() == '[' and Br != ']') return false; // case ']'
            if(St.top() == '{' and Br != '}') return false ; // case '}'
            St.pop() ; 

         /* switch (Br) 
          {
              case ')' : 
              St.pop() ;
              if(St.top() == '[' || St.top() == '{') return false ;
              break ; 
              case '}' : 
              St.pop() ; 
              if(St.top() == '(' || St.top() == '[') return false; 
              break ;
              case ']' : 
              St.pop() ;
              if(St.top() == '(' || St.top() == '{') return false ;
              break ; 
          }*/

    }
    } 
    return (St.empty()) ; 
}
int32_t main(int32_t argc,char*argv[])
{
    cin.tie(0)->sync_with_stdio(false) ;
    int64_t N ; 
    for(cin >> N ; N-- ; )
    {
        string Br ; 
        cin >> Br ; 
        cout << ( check(Br) ? "YES\n" : "NO\n" ) ; 
    }
    return 0 ; 
}