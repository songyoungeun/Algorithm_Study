from collections import deque
def solution(begin, target, words):
    def bfs(s):
        de =deque()
        de.append(s)
        while de:
            x= de.popleft()
            print("x",x)
            if x == target:
                break
            for i in words:
                c = 0
                # print(dict(zip(x,i)))
                for be, wo in zip(x,i):
                    
                    if be == wo:
                        c +=1
                if c == len(x)-1 and di[i] == 0:
                    di[i]=di[x]+1
                    de.append(i)
    di =dict()
    di[begin] = 0
    print("di",di)
    for i in words:
        di[i] = 0
    print("di2",di)

    bfs(begin)
    try:
        if di[target] != 0:
            return di[target]
    except:
        return 0