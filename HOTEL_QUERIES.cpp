/*Author :minhtuan ITK20 students of the high school for the gifted NBK*/
// Code full bignum (not optimize)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("Os")
#pragma GCC optimize("O2")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")

#include <bits/stdc++.h>
#include <assert.h>

using namespace std;
using ll = long long;

#define faster ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define oo LLONG_MAX
#define xx LLONG_MIN
#define ooo INt_MAX
#define xxx INt_MIN

/// EDIT

#define MAX 200001
#define MOD 1000000007
#define TASK "BIGNUM"
#define BASE 1000;
#define DIGIT 4

/// Shortcut

#define fast ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define FOR(i, l, r) for (ll i = l; i <= r; i++)
#define FOD(i, l, r) for (ll i = l; i >= r; i--)
#define FORAUTO(i, a) for (auto i : a)

/// Functions

#define fi first
#define se second
#define pb push_back
#define pf push_front
#define eb emplace_back
#define mp make_pair
#define mt make_tuple
#define upper upper_bound
#define lower lower_bound
#define itr iterator
#define rtr reverse_iterator
#define memset(a,x) memset(a, x, sizeof(a))
#define memsetf(a) memset(a, 0x3f, sizeof(a))

/// Data Structure

#define um unordered_map
#define us unordered_set
#define pq priority_queue

/// BIT

#define cntBit(n) __builtin_popcount(n)
#define cntBitll(n) __builtin_popcountll(n)

// CONST 

const ll eps = (ll)1e-9;
const ll mod = (ll)(1e9+7 - eps);
const ll base = 1e3+2;

// template
template <class T> void maximize(T &a, T b) {a = max(a,b);}
template <class T> void minimize(T &a, T b) {a = min(a,b);}

/// ================================ - BIGNUM - ================================

// hotel queries
/* 
optimize : segment_tree
ta xet res trong [l,r] voi mid = [l+r >> 1]
gia su neu max cua(al, al+1,....amid) >= m so phong free ma khach require -> kq thuoc[l,l+1..mid]
ngc lai thi no se nam trong doan [mid+1,mid+2..r]

ta se quy ra mo hinh cay phan doan va bat dau duyet dan xuong , den khi gap node co max(al,al+1,...mid ) >= tam(so phong free ma khach require) thi kq thuocj trong phamvi do

vay thi do sang trai if max(al,al+1,..mid) >= tam ,con ko thi do sang phai max(amid+1,mid+2..r) >= tam

complexity O(log^2 n ) or O(log n) if co the giam do phuc tap xuong thi cang tot
*/

ll n,q;
ll segment_tree[4*MAX+2]; 
ll query[MAX+2];

void build (ll low = 1, ll high = n, ll node = 1)
{
    if(low == high) segment_tree[node] = query[low];
    else
    {
        ll mid = (low + high) >> 1;
        build(low , mid , node << 1);
        build(mid + 1, high , (node << 1) + 1);
        segment_tree[node] = max(segment_tree[node << 1] , segment_tree[(node << 1) + 1]);
    }
    
}

void hotel_update(ll value,ll low = 1, ll high = n, ll node = 1)
{
    if(low == high)
    {
        segment_tree[node] -= value;
        cout << low << " ";
    }
    else
    {
        ll mid = (low + high) >> 1;
        if(segment_tree[node << 1] >= value) hotel_update(value,low,mid,node << 1);// left
        else hotel_update(value,mid + 1, high , (node << 1) + 1); //right
        
        segment_tree[node] = max(segment_tree[node << 1] , segment_tree[(node << 1) + 1]);
    }
}

int main(int argc,char*argv[])
{
    faster
    cin >> n >> q;
    for(ll i = 1; i <= n; i++) cin >> query[i];
    build();
    
     while(q-->0){
        ll m;
        cin >> m;
        if(segment_tree[1] < m) cout << "0 ";
        else hotel_update(m);
    }
    assert(true);
    return 0;
}