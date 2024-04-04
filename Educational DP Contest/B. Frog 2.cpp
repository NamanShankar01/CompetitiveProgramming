// Problem: B - Frog 2
// Contest: AtCoder - Educational DP Contest
// URL: https://atcoder.jp/contests/dp/tasks/dp_b
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
int const mod = 1e9 + 7; // 998244353
#define setbits(x) __builtin_popcountll(x)
#define msb(x) (63 - __builtin_clzll(x))
#define lsb(x) (__builtin_ffsll(x) - 1)
#define f(i, n) for (int i = 0; i < n; i++)
#define f1(i, n) for (int i = 1; i <= n; i++)
const long double eps = 1e-9;
long double pie = 3.14159265358979323846264338327950;
#define ff first;
#define ss second;
#define fsort(v) sort(v.begin(), v.end())
#define rsort(v) sort(v.begin(), v.end(), greater<int>())
#define rev(v) reverse(v.begin(), v.end())
#define max_ele(v) *max_element(v.begin(), v.end())
#define min_ele(v) *min_element(v.begin(), v.end())

/*----------------------------------------------------------------------------------------------*/

int hcf(int a, int b)
{
    if (a % b == 0)
        return b;
    return hcf(b, a % b);
}

int lcm(int a, int b)
{
    return (a * b) / (hcf(a, b));
}

/*----------------------------------------------------------------------------------------------*/
/*  DSU  */

class DSU
{
    vector<int> par, sz;

public:
    DSU(int n)
    {
        par.resize(n + 1);
        sz.resize(n + 1, 1);
        for (int i = 0; i <= n; i++)
            par[i] = i;
    }

    int findUpar(int node)
    {
        if (par[node] == node)
            return node;
        return par[node] = findUpar(par[node]);
    }

    void unionbysize(int u, int v)
    {
        int upar_u = findUpar(u);
        int upar_v = findUpar(v);
        if (upar_u == upar_v)
            return;
        if (sz[upar_u] >= sz[upar_v])
        {
            par[upar_v] = upar_u;
            sz[upar_u] += sz[upar_v];
        }
        else
        {
            par[upar_u] = upar_v;
            sz[upar_v] += sz[upar_u];
        }
    }
};

/*----------------------------------------------------------------------------------------------*/

int binexp(int a, int b)
{
    if (b == 0)
        return 1;
    int res = binexp(a, b / 2);
    if (b % 2 == 0)
        return res * res;
    else
        return res * res * a;
}

int binexpm(int a, int b, int M)
{
    if (b == 0)
        return 1;
    int res = binexpm(a, b / 2, M);
    if (b % 2 == 0)
        return ((res % M) * (res % M)) % M;
    else
        return (((res % M) * (res % M) % M) * (a % M)) % M;
}

int moduloMultiplication(int a, int b, int mod) {
    int res = 0;
    a %= mod;
    while (b) {
        if (b & 1)
            res = (res + a) % mod;
        b >>= 1;
        a = (a * 2) % mod;
    }
    return res;
}
 
int powermod(int x, int y, int p) {
    int res = 1;
    x = x % p;
    if (x == 0) return 0;
    while (y > 0) {
        if (y & 1)
            res = (res * x) % p;
        y = y >> 1;
        x = (x * x) % p;
    }
    return res;
}
 
string decToBinary(int n) {
    string s = "";
    while (n > 0) {
        s = to_string(n % 2) + s;
        n = n / 2;
    }
    return s;
}
 
int binaryToDecimal(string n) {
    int dec_value = 0;
    int base = 1;
    int len = n.length();
    for (int i = len - 1; i >= 0; i--) {
        if (n[i] == '1')
            dec_value += base;
        base = base * 2;
    }
    return dec_value;
}
 
bool binarysearch(int arr[], int l, int h, int x) {
    while (l <= h) {
        int mid = l + (h - l) / 2;
        if (arr[mid] == x)
            return true;
        else if (arr[mid] > x)
            h = mid - 1;
        else
            l = mid + 1;
    }
    return false;
}
 

/*----------------------------------------------------------------------------------------------*/
// for ncr and factorial with modulo M
// const int N1=3*1e5;
// int fact[N1+1];
// int inv[N1+1];
// int ncr(int n, int r){
//     if(r>n) return 0;
//     int temp = fact[n];
//     temp = (temp*inv[r]) % mod;
//     temp = (temp*inv[n-r]) % mod;
//     return temp;
// }
/*----------------------------------------------------------------------------------------------*/

int32_t main()
{

    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // Sieve approach:

    // int N=1e6;
    // int spf[N+1];
    // f(i,N+1) spf[i]=i;
    // for(int i=2;i<N+1;i++){
    //     if(spf[i]==i){
    //         for(int j=i*i;j<N+1;j+=i){
    //            if(spf[j] == j) spf[j]=i;
    //         }
    //     }
    // }

    // int N=1e6;
    // bool isprime[N+1];
    // isprime[0]=0;
    // isprime[1]=0;
    // for(int i=2; i*i<=N; i++)
    // {
    //   if(isprime[i]==1){
    //      for(int j=i*i; j<=N; j+=i)
    //        {
    //           isprime[j]=0;
    //        }
    //    }
    //}

    // vector<int> primes;
    // for(int i=2;i<N+1;i++) if(isprime[i]) primes.push_back(i);

    // fact[0]=1;
    // f1(i,N1) fact[i] = (fact[i-1]*i) % mod;
    // f(i,N1+1) inv[i] = binexpm(fact[i], mod-2, mod);

    /* Code Starts here */

    /*
            be carefull at the time of coding.......
                first think what's your logic.......
                    keep in mind about time complexity and keep patience.....
                        patience is more important than your practice........
    */
    int t=1;
    //cin >> t;
    while (t--)
    {
	        int n, k;
     			cin>>n>>k;
     			vector<int> vec(n+1, 0);
     			for(int i = 1; i <= n; i++)
     				cin>>vec[i];
     				
     			vector<int> dp(n+1, 1e9);
     			dp[1]=0;
     			
     			for (int i = 1; i <= n; i++) 
     			{ // i represents the stone the frog is currently at.
    		        for (int j = i + 1; j <= i + k; j++) 
    		        { // j represents a potential stone for the frog to jump to.
    		            if (j <= n) // We have to check if the stone we want to jump to is not out of bounds.
    		                // Storing the total minimum cost to reach stone j from stone i.
    		                dp[j] = min(dp[j], dp[i] + abs(vec[j] - vec[i]));
            		}	
    			}
    			
    			cout<<dp[n]<<endl;
    }
    return 0;
}
