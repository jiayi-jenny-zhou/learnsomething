import timeit
import math

def disasterCode():
    primes = []
    
    for i in range (2,2500):
        isprime = True
        for j in range (2,math.ceil(math.sqrt(i))):
            if i%j ==0:
                isprime = False
                break
        if isprime:
            primes.append(i)


    for i in range(2,2500):
        totest = i
        primeslist = []
        for j in primes:
            if totest<j:
                break
            if totest%j==0:
                primeslist.append(j)
                while totest%j==0:
                    totest = totest/j
        





# Benchmark the code
if __name__ == "__main__":
    benchmark_code = "disasterCode()"
    setup_code = "from __main__ import disasterCode"

    # Measure the execution time of disasterCode function
    times = []
    for i in range(0,5):
        times.append(timeit.timeit(benchmark_code, setup=setup_code, number=1))

    res = sum(times)/5

    print(f"Average execution time after 5 runs: {res:.6f} seconds")
