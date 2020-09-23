import sys

queue = list()


def push(input):
    queue.append(input)


def pop():
    if (len(queue) == 0):
        print(-1)
    else:
        print(queue.pop(0))


def size():
    print(len(queue))


def empty():
    if (len(queue) == 0):
        print(1)
    else:
        print(0)


def front():
    if (len(queue) != 0):
        print(queue[0])
    else:
        print(-1)


def back():
    if (len(queue) != 0):
        print(queue[len(queue) - 1])
    else:
        print(-1)

##main
n = int(sys.stdin.readline())
for i in range(0, n):
    str = sys.stdin.readline().split()
    if (str[0] == "pop"):
        pop()
    elif (str[0] == "size"):
        size()
    elif (str[0] == "back"):
        back()
    elif (str[0] == "empty"):
        empty()
    elif (str[0] == "front"):
        front()
    elif (str[0] == "push"):
        push(int(str[1]))
