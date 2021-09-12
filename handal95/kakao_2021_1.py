import re
from sys import stdin


def run(testcase=1):
    for _ in range(int(testcase)):
        solve()


def inputs():
    str = stdin.readline()

    return str


def solve():
    str = inputs()

    str = str.lower()
    str = re.sub("[^a-z0-9\-_.]", "", str)
    str = re.sub("\.+", ".", str)
    str = re.sub("^[.]|[.]$", "", str)
    str = "a" if len(str) == 0 else str[:15]
    str = re.sub("^[.]|[.]$", "", str)
    str = str if len(str) > 2 else str + "".join([str[-1] for i in range(3 - len(str))])
    print(str)


run()
