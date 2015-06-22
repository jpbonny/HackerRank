# Basic email validation using regular expressions in Python
# usage: N number of test cases followed by N emails
# input:
# 2
# joe@aol.com
# notarealemail44@44.52w
# output:
#['joe@aol.com']

import re

if __name__ == "__main__":
    N = input()
    l = range(N)
    for i in range(N):
        l[i] = raw_input()
    pattern = re.compile("^[a-zA-Z][\w-]*@[a-zA-Z0-9]+\.[a-zA-Z]{1,3}$")
    l = list(filter(lambda x: re.match(pattern, x), l))
    print sorted(l)
