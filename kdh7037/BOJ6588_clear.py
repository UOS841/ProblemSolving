max = 1000000

sieve = [False, False] + [True] * (max - 1)
for i in range(2, int(max ** 0.5 + 1)):
    if sieve[i]:
        sieve[i*2::i] = [False] * ((max - i) // i)

while True:
    n = int(input())
    if n == 0:
        break
    for i in range(3, max, 2):
        if sieve[i] == True:
            if sieve[n - i] == True:
                print("{} = {} + {}".format(n, i, n - i))
                break
        if i == 1:
            print("Goldbach's conjecture is wrong.")

