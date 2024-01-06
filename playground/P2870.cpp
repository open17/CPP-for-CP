#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ios ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define For(w, a, n) for(int w=(a);w<(n);++w)
#define _For(a,b,c) for(int a=(b);a>(c);a--)
#define all(x) (x).begin(),x.end()
#define inf 0x3f3f3f3f
#define endl '\n'
//输入流修改
#define fo1 freopen("data.in","r",stdin);freopen("res.out","w",stdout);
#define fo2 freopen("data.in","r",stdin);freopen("ans.out","w",stdout);
//打印
#define printA(a,b,c) cout<<'\n'<<"debug start"<<'\n';for(int i=a;i<=b;i++){cout<<c[i]<<' ';}cout<<'\n'<<"debug over"<<'\n'<<'\n';
template <typename T>void print(const T & t){cout << t << endl;}
template <typename T, typename... Args>void print(const T &t ,const Args... args){cout << t << ' ';print(args...);}
template <typename T>void println(const T & t){cout << t << endl;}
template <typename T, typename... Args>void println(const T &t ,const Args... args){cout << t << endl;println(args...);}
typedef unsigned long long ull;
typedef pair<int, int> pii;
int read();
void write(int);
const int N=5e5+5;
const int MOD=1e9+7;
const int MAXN=1e6+5;
char s[MAXN];   
int rk[MAXN << 1], sa[MAXN << 1], tmp[MAXN << 1], cnt[MAXN], rkt[MAXN];
void init_sa(int n) { // 1-index
    if (n == 1) return void(rk[1] = sa[1] = 1);

    int m = 128;
    for (int i = 1; i <= n; ++i)
        ++cnt[rk[i] = s[i]];
    for (int i = 1; i <= m; ++i)
        cnt[i] += cnt[i - 1];
    for (int i = n; i >= 1; --i)
        sa[cnt[rk[i]]--] = i;

    for (int w = 1;; w <<= 1) {
        for (int i = n; i > n - w; --i)
            tmp[n - i + 1] = i;
        for (int i = 1, p = w; i <= n; ++i)
            if (sa[i] > w) tmp[++p] = sa[i] - w;
        fill(cnt + 1, cnt + m + 1, 0);
        for (int i = 1; i <= n; ++i)
            cnt[rkt[i] = rk[tmp[i]]]++;
        for (int i = 1; i <= m; ++i)
            cnt[i] += cnt[i - 1];
        for (int i = n; i >= 1; --i)
            sa[cnt[rkt[i]]--] = tmp[i];
        m = 0;
        auto rp = [&](int x) { return make_pair(rk[x], rk[x + w]); };
        for (int i = 1; i <= n; ++i)
            tmp[sa[i]] = rp(sa[i - 1]) == rp(sa[i]) ? m : ++m;
        copy(tmp + 1, tmp + n + 1, rk + 1);
        if (n == m) break;
    }
}

void solve(){
    ios
    int n;
    cin>>n;
    For(i,1,n+1){
        cin>>s[i];
    }
    s[n+1]='0';
    /*
    n n+1 2n+1
    */
    For(i,1,n+1){
        s[2*n+2-i]=s[i];
    }
    init_sa(2*n+1);
    int l=1,r=n,cnt=0;
    while(l<=r){
        if (s[l]<s[r] || (s[l]==s[r] && rk[l]<=rk[2*n+2-r])){
            cout<<s[l];
            l++;
        }
        else{
           cout<<s[r];
            r--;
        }
        cnt++;
        if(cnt==80){
            cout<<endl;
            cnt=0;
        }
    }
}

signed main() {
    solve();
    return 0;
}




inline int read() {
    int x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x * f;
}
inline void write(int x)
{
    if (x < 0) { putchar('-'); x = -x; }
    if (x > 9) write(x / 10);
    putchar(x % 10 + '0');
}