if __name__ == '__main__':
    N = int(input())
    arr = []
    for i in range(N):
        ar = []
        ar.append(input())
        if ar[0] == "insert":
            idx = int(input())
            num = int(input())
            arr.insert(idx, num)
        elif ar[0] == "print":
            print(arr)
        elif ar[0] == "append":
            num = int(input())
            arr.append(input())
        elif ar[0] == "sort":
            arr.sort()
        elif ar[0] == "reverse":
            arr.reverse()
        elif ar[0] == "pop":
            arr.pop()