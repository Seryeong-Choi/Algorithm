import sys

deque = list()

def push_front(input):
    deque.insert(0, input)

def push_back(input):
    deque.append(input)

def pop_front():
    if(len(deque) == 0):
        print(-1)
    else:
        print(deque.pop(0))

def pop_back():
    if (len(deque) == 0):
        print(-1)
    else:
        print(deque.pop(len(deque)-1))

def size():
    print(len(deque))

def empty():
    if (len(deque) == 0):
        print(1)
    else:
        print(0)

def front():
    if (len(deque) != 0):
        print(deque[0])
    else:
        print(-1)

def back():
    if (len(deque) != 0):
        print(deque[len(deque) - 1])
    else:
        print(-1)

##main
n = int(sys.stdin.readline())
for i in range(0, n):
    str = sys.stdin.readline().split()
    if (str[0] == "pop_front"):
        pop_front()
    elif (str[0] == "pop_back"):
        pop_back()
    elif (str[0] == "size"):
        size()
    elif (str[0] == "back"):
        back()
    elif (str[0] == "empty"):
        empty()
    elif (str[0] == "front"):
        front()
    elif (str[0] == "push_front"):
        push_front(int(str[1]))
    elif (str[0] == "push_back"):
        push_back(int(str[1]))