#%%
print("프로그램 시작")

# while의 조건이 True일 동안 반복적으로
# while의 안에 있는 코드를 실행
# 1. 조건을 만나면 조건을 확인
# 2. 조건이 True면, while 안에 있는 코드 실행
# 3. 조건이 False면, while을 건너뜀
# 4. while의 끝을 만나면 다시 ( 1 )  로 돌아감.

# while True:
#     print("Hello World~!")
    
print("프로그램 종료")

# %%
# 변수 i의 변화를 메모리를 그려서 확인해보세요.
# i가 0부터 
i = 0

# 10 미만일 동안
while i < 10:
    # 하나씩 증가하면서 while 내 코드를 반복한다.
    i += 1
    print("Hello World~!")
print(i)

# %%

# 우리가 지금까지 사용한 i, num 변수의 특징
# 단순하게 반복횟수를 지정하는데 사용

num = 10
cnt = 0
while num >=1:
    print(f"{num}. Hello, World~!")
    num -= 1
    cnt += 1
    
print(cnt, "번 반복 실행 후 num:", num,"이 된다.")

# %%
# 코드의 패턴을 파악
# 이 코드의 패턴은 ? 반복적으로 덧셈 연산을 하고 있다.
# 반복되는 코드를 반복문으로 바꾸려면 두 가지 패턴을 찾아야함.
# 패턴 1. 변하는 부분
# 패턴 2. 변하지 않는 부분

sum = 1
sum += 2
sum += 3 
sum += 4
sum += 5
sum += 6
sum += 7
sum += 8
sum += 9
sum += 10
#%%
sum = 1
num = 2
while num <= 10:
    sum = sum + num

    num = num + 1
print(sum)
# %%

# 아래의 코드를 반복문으로 해결하세요.
# 1. 분석 (반복되는 코드에서 변하는 부분 / 변하지 않는 부분을 찾아야함)
# 2. 분석에 따라서 반복문을 구성해야함
# 반드시 / 무조건은 아니지만 대부분 변하는 부분이 조건 자리로 옴

sum = 1
num = 2
while num <= 5:
    sum *= num
    num += 1
print(f"sum = {sum}")

# %%
# 이제부터 코드가 반복되네? 라는 생각이 들거나
# 복사(Ctrl + C), 붙여넣기 (Ctrl + V)를 하면
# 무조건 반복문으로 해결해야함
# 반복문으로 해결하기 위해서는 반복되는 패턴을 찾아야하므로
# 우선은 직접 반복하고 / 그 다음에 패턴을 찾아서 반복문으로 해결해야함

print(f"2 * 1 = {2 * 1}")
print(f"2 * 2 = {2 * 2}")
print(f"2 * 3 = {2 * 3}")
print(f"2 * 4 = {2 * 4}")
print(f"2 * 5 = {2 * 5}")
print(f"2 * 6 = {2 * 6}")
print(f"2 * 7 = {2 * 7}")
print(f"2 * 8 = {2 * 8}")
print(f"2 * 9 = {2 * 9}")

# %%
# 반복횟수가 정해진 반복문
num = 1
while num <= 9:
    print(f"2 * {num} = {2 * num}")
    num += 1

# %%
import random

# 우리가 이 프로그램을 통해서 반복문 하나만 본 게 아니고
# 프로그램을 구조적으로 개발하는 방법적인것도 같이 봤음.

dice = 0

# 1 ~6 까지 있는 정육면체 주사위를 4가 나올 때까지 굴리는 프로그램을 개발
while dice != 4:
    dice = random.randint(1, 6)
    print(f"주사위를 굴려서 나온 수는 {dice} 입니다.")

print("end")


# # 1 ~ 6 까지 있는 정육면체 주사위를 굴린다.
# dice = random.randrange(1, 7)
# print(f"주사위를 굴려서 나온 수는 {dice} 입니다.")

# #randint(시작, 끝) -> 시작 수 이상 끝 수 이하 사이의 수 하나를 무작위로 뽑아줌.
# dice = random.randint(1, 6)
# print(f"주사위를 굴려서 나온 수는 {dice} 입니다.")

#while()

# %%
import random

# 주사위를 굴려서 나올 수 있는 숫자
dice = [1, 2, 3, 4, 5, 6]

# 주사위를 굴려서 나온 숫자
number = 0

while number != 4:
    # random.choice -> 시퀀스 객체 내 임의의 요소를 골라주는 기능
    number = random.choice(dice)

    print(f"dice - {number}")


# %%
# 열 번 찍어 안 넘어 가는 나무 없다 라는 속담 구현
import random

# 도끼질을 했을 때 나무가 넘어갈 확률
chance = [False, True, False, False, False, False, False, False, False, False]

# 도끼질을 했을 때 나무가 넘어갔는지 여부
cut = False

# 도끼질 횟수
hit = 0

# 나무가 넘어가지 않았다면
# 또는 나무를 10번 찍지 않았다면
# (나무를 쓰러트리지 않았거나 도끼질을 10번하지 않았다면)
while not cut and hit < 10:
    hit += 1
    print(f"나무를 {hit}번 찍었다.")

    cut = random.choice(chance)
    # if hit == 10:
    #     print(f"나무를 {hit}번 찍어도 넘어가지 않았다.")
    #     break
    if cut == True:
        print(f"나무를 {hit}번 찍으니 넘어갔다.")

    # break를 if와 활용하면 우리가 지정한 조건이 됐을 때 반복문을 빠져나가라
    # 라고 구현할 수 있음.
    if hit < 10:
        break       # break를 만나면 break를 감싸고 있는 반복문을 빠져나간다.

    


# %%
#ex10
print("충전 금액: ", end="")
money = int(input())
price = 1350

remain = money
count = 0

while True:
    count += 1
    remain -= price

    if remain < price:
        break

print(f"{money}원으로는 {count}회 이용할 수 있습니다.")
# %%
# 열 번 찍어 안 넘어 가는 나무 없다 라는 속담 구현
import random
chance = [False, True, False, False, False, False, False, False, False, False]

cut = False

hit = 0

while True:
    hit += 1
    print(f"나무를 {hit}번 찍었다.")

    cut = random.choice(chance)
    if cut:
        print("나무를 쓰러트렸다.")
        break

    if hit == 10:
        print("10번 찍어도 못 쓰러트렸다.")
        break
#%%
n = 1

while n <= 10:
    if n % 2 == 0:
        n += 1
        continue    # continue를 만나면 제어가 조건식 자리로 올라감
    
    print(n)
    n += 1

# %%
