import re
import math

BIG_NUM = 1000000

def find_k_primes(n, k):
    n = min(BIG_NUM, n)
    #    0      1         2 ...
    a = [False, False] + [True] * (n - 1)

    k_primes = []
    nums = [str(i) for i in range(1, k)]
    pattern = f"[^{''.join(nums)}]"

    for i in range(2, n + 1):
        if a[i]:
            if bool(re.search(pattern, str(i))) is False:
                k_primes.append(i)

            for j in range(2 * i, n + 1, i):
                a[j] = False
    
    return k_primes

def find_one_prime(x):
    for i in range(2, math.sqrt(x) + 1):
        if x % i == 0:
            return False
    return True

def convert_k(num_str, num, k) :
    d, m = divmod(num, k)
    k_str = f"{m}{num_str}"
    return k_str if d == 0 else convert_k(k_str, d, k)

def solution(n, k):
    k_num = str(convert_k('', n, k)) if k < 10 else str(n)

    answer = 0
    if '0' in k_num:
        maximum = 0
        subnums = k_num.split('0')
        for subnum in subnums:
            if subnum != '':
                maximum = max(maximum, int(subnum))
    else:
        maximum = int(k_num)
        
        
    primes = find_k_primes(maximum, k)
    
    
    if '0' not in k_num:
        if int(k_num) < BIG_NUM and int(k_num) not in primes:
            return 0

        if int(k_num) >= BIG_NUM and find_one_prime(int(k_num)) is False:
            return 0
        


    # 0P0
    for k_n in k_num.split('0'):
        if k_n == '':
            continue

        if int(k_n) < BIG_NUM:
            if int(k_n) in primes:
                answer += 1

        elif int(k_n) >= BIG_NUM:
            if find_one_prime(int(k_n)) is True:
                answer += 1

    return answer

print(solution(20212211210201011, 10))