#include <iostream>
#include <cstdio>
#include <cstdlib>
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
#include <cctype>
#include <complex>
#include <string>
#include <cstring>
#include <sstream>

using namespace std;

#define all(c) c.begin(),c.end()

typedef long long ll;
typedef complex<double> point;
typedef pair<int,int> pii;

const int dx[] = {1,0,-1,0};
const int dy[] = {0,-1,0,1};

const double EPS = 1e-9;

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

template<typename T>
string to_s(T v){
    stringstream ss;
    ss << v;
    return ss.str();
}

int to_i(string s){
    stringstream ss;
    int ret;
    ss << s;
    ss >> ret;
    return ret;
}

struct Card {
    int number;
    char suit;
    Card(int number,char suit) : number(number),suit(suit) {}

    bool operator<(const Card& left){
        if(number != left.number) return number < left.number;
        else return suit < left.suit;
    }
};

typedef vector<Card> Hand;
map<int,int> number_count(const Hand& hand){
    map<int,int> ret;
    for(const Card& c : hand){
        ret[c.number]++;
    }
    return ret;
}

bool compare_high_card(const Hand& first,const Hand& second){
    for(int i=first.size()-1;i>=0;i--){
        if(first[i].number != second[i].number){
            return first[i].number > second[i].number;
        }
    }
    return false;
}
int high_card(const Hand& hand){
    int ret = -1;
    for(const Card& c : hand){
        ret = max(ret,c.number);
    }
    return ret;
}


bool one_pair(const Hand& hand){
    for(const pair<int,int>& p : number_count(hand)){
        if(p.second == 2) return true;
    }
    return false;
}

bool two_pairs(const Hand& hand){
    int pair_count = 0;
    for(const pair<int,int>& p : number_count(hand)){
        if(p.second == 2) pair_count++;
    }
    return pair_count == 2;
}

bool three_of_a_kind(const Hand& hand){
    for(const pair<int,int>& p : number_count(hand)){
        if(p.second == 3) return true;
    }
    return false;
}

bool straight(const Hand& hand){
    int m = hand[0].number;
    for(int i=0;i<hand.size();i++){
        if(hand[i].number != m+i) return false;
    }
    return true;
}

bool flush(const Hand& hand){
    int suit = hand[0].suit;
    for(const Card& c : hand){
        if(c.suit != suit) return false;
    }
    return true;
}

bool full_house(const Hand& hand){
    bool tpair=false,three_kind=false;
    for(const pair<int,int>& p : number_count(hand)){
        if(p.second == 2) tpair = true;
        else if(p.second == 4) three_kind = true;;
    }
    return tpair and three_kind;
}

bool four_of_a_kind(const Hand& hand){
    for(const pair<int,int>& p : number_count(hand)){
        if(p.second == 4) return true;
    }
    return false;
}

bool straight_flush(const Hand& hand){
    int m = hand[0].number;
    char suit = hand[0].suit;
    for(int i=0;i<hand.size();i++){
        if(hand[i].number != m+i or
           hand[i].suit != suit) return false;
    }
    return true;
}

bool royal_flush(const Hand& hand){
    char suit = hand[0].suit;
    for(int i=0;i<hand.size();i++){
        if(hand[i].number != 10+i or 
           hand[i].suit != suit) return false;
    }
    return true;
}

int hand_power(const Hand& hand){
    if(royal_flush(hand)) return 10;
    else if(straight_flush(hand)) return 9;
    else if(four_of_a_kind(hand)) return 8;
    else if(full_house(hand)) return 7;
    else if(flush(hand)) return 6;
    else if(straight(hand)) return 5;
    else if(three_of_a_kind(hand)) return 4;
    else if(two_pairs(hand)) return 3;
    else if(one_pair(hand)) return 2;
    else return 1;
}

bool first_win(const Hand& first,const Hand& second){
    int f = hand_power(first);
    int s = hand_power(second);
    if(f != s) {
        return f > s;
    } else {
        return compare_high_card(first,second);
    }
}

Card make_card(char number,char suit){
    int cnumber = 0;
    if(number == 'J') cnumber = 11;
    else if(number == 'Q') cnumber = 12;
    else if(number == 'K') cnumber = 13;
    else if(number == 'A') cnumber = 14;
    else cnumber = number - '0';
    return Card(cnumber,suit);
}

int main(){
    int cnt = 0;
    for(int i=0;i<1000;i++){
        Hand first,second;
        for(int j=0;j<5;j++){
            char number,suit;
            cin >> number >> suit;
            first.push_back(make_card(number,suit));
        }
        for(int j=0;j<5;j++){
            char number,suit;
            cin >> number >> suit;
            second.push_back(make_card(number,suit));
        }
        if(first_win(first,second)) {
            cout << "first win" << endl;
            cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}
