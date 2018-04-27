def main():
    n=3
    intervals=[[None,None]for i in range(n)]
    intervals[0]=[1,2]
    intervals[1]=[2,3]
    intervals[2]=[1,3]
    intervals=sorted(intervals,key=lambda finish:intervals[2])
    print(intervals)
if __name__ == '__main__':
    main()