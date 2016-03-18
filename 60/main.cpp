#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <sstream>
#include <cmath>

//#include <omp.h>

using namespace std;


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

vector<bool> sieve(const int M){
    vector<bool> isPrime(M);
    for(int i=2;i<M;i++) {
        isPrime[i] = true;
    }
    for(int i=2;i*i < M;i++){
        if(not isPrime[i]) continue;
#pragma omp parallel for
        for(int j=i*i;j<M;j+=i){
            isPrime[j] = false;
        }
    }
    return isPrime;
}

struct State{
    vector<int> used;
    int index;
    int sum;
    State(vector<int> used,int index,int sum) : used(used),index(index),sum(sum) {}
};

bool operator<(const State& left,const State& right){
    return left.sum < right.sum;
}

bool operator>(const State& left,const State& right){
    return left.sum > right.sum;
}

const int FINDING = 5;
bool is_ok(const vector<int>& used,const int& new_int,
           const vector<bool>& isprime){
    string new_int_s = to_s(new_int);
    for(size_t i=0;i<used.size();i++){
        for(int j=0;j<=2;j++){
            unsigned int check = 0;
            if(j){
                check = to_i(to_s(used[i])+new_int_s);
                //check = to_i(tos.at(used[i])+tos.at(new_int));
            }else{
                check = to_i(new_int_s+to_s(used[i]));
                //check = to_i(tos.at(new_int)+tos.at(used[i]));
            }
            if(isprime.size() <= check or not isprime[check]){
                return false;
            }
        }
    }
    return true;
}

const int MAX_PRIME = 100000000;

int main(){
    vector<bool> isprime = sieve(MAX_PRIME);
    vector<int> primes;

    for(int i=0;i<MAX_PRIME;i++) {
        if(isprime[i]) {
            primes.push_back(i);
        }
    }
    priority_queue<State,vector<State>,greater<State> > que;
    que.push(State(vector<int>(),-1,0));

    //omp_lock_t writelock;
    //omp_init_lock(&writelock);

    int normal_range = lower_bound(primes.begin(),primes.end(),sqrt(MAX_PRIME)) 
                           - primes.begin();
    while(not que.empty()){
        State s = que.top();
        int index = s.index;
        int sum = s.sum;
        vector<int> used = s.used;
        que.pop();
        cerr << used << " " << sum << endl;

        if(used.size() == FINDING){
            cerr << used << endl;
            cout << sum << endl;
            break;
        }else{
            // int range = (used.size() != FINDING-1) ? normal_range : primes.size();
            int range = normal_range;
#pragma omp parallel for
            for(int i=index+1;i<range;i++){
                if(is_ok(used,primes[i],isprime)){
                    vector<int> ns = used;
                    ns.push_back(primes[i]);
                    //omp_set_lock(&writelock);
                    que.push(State(ns,i+1,sum+primes[i]));
                    //omp_unset_lock(&writelock);
                }
            }
        }
        //omp_destroy_lock(&writelock);
    }
    return 0;
}
