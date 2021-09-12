def find_primes(n):
    a = [False, False] + [True] * (n - 1)
    primes = []

    for i in range(2, n + 1):
        if a[i]:
            primes.append(i)
            for j in range(2 * i, n + 1, i):
                a[j] = False

    return primes


def find_prime(primes, n):
    for p in primes:
        if n % p == 0:
            return p
    return 1


def shuffle(array, steps):
    end = len(array)
    if len(array) == 1:
        return array

    splited = list([] for _ in range(steps))

    index = 0
    while index < end:
        for s in range(steps):
            splited[s].append(array[index + s])
        index += steps

    return splited


def solution(n):
    length = n
    primes = find_primes(length)

    array = [x for x in range(1, length + 1)]

    while True:
        merged = []
        prime = find_prime(primes, length)

        pivot = 0
        for index in range(n // length):
            splited = shuffle(array[index * length : (index + 1) * length], prime)

            for arr in splited:
                merged += arr

            pivot += length * prime

        length = length // prime
        array = merged
        if length == 1:
            break

    return array


print(solution(4))
