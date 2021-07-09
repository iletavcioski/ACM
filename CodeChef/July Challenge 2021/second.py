import math

if __name__ == "__main__":
    t = int(input())
    while t > 0:
        t -= 1
        ss = [int(x) for x in input().split()]
        print(int((ss[1]**2)/(2*ss[0])))
