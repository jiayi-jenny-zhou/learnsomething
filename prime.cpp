// import timeit
// import math
#include <chrono>
#include <numeric>
#include <vector>
#include <iostream>
using namespace std;


// def disasterCode():
//     spf = [i for i in range(2500)]
//     for i in range(2,2500):
//         if spf[i] == i:
//             for j in range(i*i, 2500, i):
//                 spf[j] = i

//         num = i
//         while(num>1):
//             num = num // spf[num]
        
void disasterCode(){
    vector<int> spf(2500);
    iota(spf.begin(),spf.end(),1);

    for(int i = 0; i<2500; i++){
        vector<int> primes;
        if(spf[i]==i){
            for(int j = i*i; j<2500; j+=i){
                spf[j] = i;
            }
        }

        int num = i;
        while(num>=2){
            primes.push_back(spf[num]);
            num = num/ spf[num];
        }
    }
}


// # Benchmark the code
// if __name__ == "__main__":
//     benchmark_code = "disasterCode()"
//     setup_code = "from __main__ import disasterCode"

//     # Measure the execution time of disasterCode function
//     times = []
//     for i in range(0,5):
//         times.append(timeit.timeit(benchmark_code, setup=setup_code, number=1))

//     res = sum(times)/5

//     print(f"Average execution time after 5 runs: {res:.6f} seconds")


int main(){
    
    
    double total = 0;
    for(int i =0; i<5; i++){
        auto start = std::chrono::steady_clock::now();
        disasterCode();
        auto end = std::chrono::steady_clock::now();
        auto elapsed = end - start;
        total+= elapsed.count();
    }
    
    cout << total/5 << '\n';
}