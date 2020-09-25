import sys
from collections import deque

##main
str = sys.stdin.readline().strip()
L = deque(str)
R = deque()
n = int(sys.stdin.readline())

for i in range(0, n):
    s = sys.stdin.readline().split()
    if (s[0] == 'L' and len(L) != 0):
        R.appendleft(L.pop())
    elif (s[0] == 'D' and len(R) != 0):
        L.append(R.popleft())
    elif (s[0] == 'B' and len(L) != 0):
        L.pop()
    elif (s[0] == 'P'):
        L.append(s[1])
str = ''.join(L) + ''.join(R)
print(str)