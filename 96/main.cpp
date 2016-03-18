#include <iostream>
#include <iomanip>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <bitset>
#include <stack>
#include <utility>
#include <numeric>
#include <algorithm>
#include <functional>
#include <complex>
#include <string>
#include <sstream>

#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cstring>

using namespace std;

#define all(c) c.begin(),c.end()
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << endl

typedef long long ll;
typedef vector<int> vi;


template<typename T>
ostream& operator<<(ostream& os,const vector<T>& val){
    os << "[ ";
    for(typename vector<T>::const_iterator it=val.begin();
        it != val.end();++it){
        os << *it << " ";
    }
    os << "]";
    return os;
}

const int empty = 0;
vector<vector<int> > go(vector<vector<int> > &field,int y,int x){
    if(y == 9) return field;
    int ny,nx;
    if(x == 8){
        ny=y+1;nx=0;
    }else{
        ny=y;nx=x+1;
    }
    if(field[y][x] != empty){
        return go(field,ny,nx);
    }else{
        for(int c=1;c<=9;c++){
            field[y][x] = c;
            bool ok = true;
            // tate check.
            {
                vector<int> cnt(10);
                for(int i=0;i<9;i++){
                    if(field[i][x] != empty) cnt[field[i][x]]++;
                }
                if(*max_element(all(cnt)) >= 2) ok = false;
            }
            // yoko check.
            {
                vector<int> cnt(10);
                for(int i=0;i<9;i++){
                    if(field[y][i] != empty) cnt[field[y][i]]++;
                }
                if(*max_element(all(cnt)) >= 2) ok = false;;
            }
            // sikaku check
            {
                int bx = x/3,by = y/3;
                vector<int> cnt(10);
                for(int i=0;i<3;i++){
                    for(int j=0;j<3;j++){
                        int a = bx * 3 + i;
                        int b = by * 3 + j;
                        if(field[b][a] != empty) cnt[field[b][a]]++;
                    }
                }
                if(*max_element(all(cnt)) >= 2) ok = false;
            }
            if(ok){
                return go(field,ny,nx);
            }
            field[y][x] = empty;
        }
    }
    return field;
}

vector<vector<int> > solve(const vector<vector<int> >& field){
    vector<vector<int> > ret = field;
    go(ret,0,0);
    return ret;
}
int main(){
    string s;
    getline(cin,s);
    vector<string> input(9);
    for(int i=0;i<9;i++) cin >> input[i];

    vector<vector<int> > v(9,vector<int>(9));
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            v[i][j] = input[i][j] - '0';
        }
    }
    cout << solve(v) << endl;
    return 0;
}
