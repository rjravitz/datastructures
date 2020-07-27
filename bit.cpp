#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;


#define pb push_back
#define mp make_pair
#define all(v) v.begin(), v.end()
#define sz(v) (int)v.size()
 
#define Fl(i, a, b) for(int i=a; i<b; i++)
#define Fle(i, a, b) for(int i=a; i<=b; i++)
#define Flz(i, a) for(int i=0; i<a; i++)
#define Fld(i,a,b) for(int i = (b)-1; i >= a; i--)
#define Fldz(i,a) for(int i = (a)-1; i>=0; i--)
 
#define FAST ios::sync_with_stdio(0); cin.tie(0);
#define finish(x) return cout << x << '\n', 0;
#define dbg(x) cerr << ">>> " << #x << " = " << x << "\n";
#define _ << " _ " <<

#define llfill(v, n)  while(n--){ll x; cin >> x; v.push_back(x);}
 
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int,int> pi;
typedef pair<ld,ld> pd;
typedef complex<ld> cd;

const ll inf = 1e9 + 7;

//Binary Indexed Tree

int size = 10;
vi b(size + 1, 0);

void add(int i, int val){
    i++;
    for(; i <= size; i += (i & -i)) b[i] += val;
}

int psum(int i){
    int ans = 0; i++;
    for(; i > 0; i -= (i & - i)) ans += b[i];
    return ans;
}

int sum(int l, int r){
    return psum(r) - psum(l - 1);
}


int main(){ FAST
    vi v; int s = 0;
    cout << "Initial array: ";
    for(int i = 1; i <= 10; i++){s += i; cout << s << " "; v.push_back(s);}
    cout << "\n";
    cout << "Initial BIT: ";
    for(int i = 0; i < 10; i++){add(i, v[i]); cout << b[i] << " ";}
    cout << b[size] << " \n";
    cout << "sum[5, 7] = " << sum(5, 7) << "\n";
}
