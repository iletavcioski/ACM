if __name__ == "__main__":
    t = int(input())
    while t > 0:
        t-=1
        ss = input()
        tt = [int(x) for x in ss.split()]
        print(max(tt[0]*tt[2] + (7-tt[0])*tt[3], 7*tt[1]))