def right(p):
    stack = []
    for i in p:
        if i == "(":
            stack.append(i)
        else:
            if len(stack) == 0:
                return False
            stack.pop()
    if len(stack) != 0:
        return False
    return True            
def balance(p):
    num = 0

    for idx, value in enumerate(p):
        if value == ")":
            num -=1
        if value =="(":
            num +=1
        if num == 0:
            return idx

def solution(p):
    if p== "" or right(p): #1.문자열 비었고 올바른 괄호 문자열이면 그대로 출력
        return p
    #2.문자열을 균형잡힌 괄호 문자열로 분리
    u, v = p[:balance(p)+1],p[balance(p)+1:]   
    #3.문자열 u가 올바른 괄호 문자열이라면
    if right(u):
        #3.문자열 v를 1단계부터 수행
        string = solution(v)
        #수행 결과를 u에 붙여 
        return u + string
    #4.올바른 괄호 문자 아니면
    else:
        #4.1 빈문자열에 (추가
        t ="("
        #4.2 v를 재귀적으로 수행후 이어붙여
        t += solution(v)
        #4.3
        t += ")"
        # 4-4. u의 첫 번째와 마지막 문자를 제거하고
        u = list(u[1:-1])
     
        #  나머지 문자열의 괄호 방향을 뒤집어서 뒤에 붙입니다.
        for i in range(len(u)):
            if u[i] == '(':
                u[i] = ')'
            elif u[i] == ')':
                u[i] = '('  
        t +="".join(u)
        return t
        #4-5. 생성된 문자열을 반환합니다.
p =")("

print(solution(p))
# solution("(()())()")
# solution(")(")	
# solution("()))((()")