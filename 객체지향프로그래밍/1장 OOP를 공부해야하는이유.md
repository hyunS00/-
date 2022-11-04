## 객체지향프로그래밍(oop)

## 간단한코드

```cpp
#includ<stdio.h>

void main(){
	printf("Hello,World\n");
}
```

## 조금 복잡한코드

```cpp
#include<stdio.h>

	int ix; // 전역변수
	int iy; // 전역변수

void main(){
	ix = 2;
	iy = 3;
	int iResult = ix + iy;
	printf("두개의 값을 더한 결과 : %d\n", iResult);
}
```

### 전역변수 특징

- 사용범위(scope)가 넓어진다
- 생명주기(Life time)이 길어진다

### 추상화(Abstract)

- 간단히 묶어서, 줄여서 표현하는 것을 의미한다.
- 작성한 함수를 나중에 재사용할 수 있다

```cpp
#include<stdio.h>

int ix;
int iy;

void Assign(int i, int j) {//코드추상화
	ix = i;
	iy = j;
}

int Add() {//코드추상화
	return ix + iy;
}

void main() {
	Assign(2, 3);
	int iResult = Add();
	printf("두개의 값을 더한 결과 : %d\n", iResult);
}
```

## 100개의 변수와 1000개의 함수로 구성된 경우

- 오류가 발생할 경우 오류 수정이 어렵다.
- 잘못된 접근 방지할 수 있는 장치가 없다.
- 코드 재사용이 어렵다.
- 소프트웨어 위기가 발생한다
  ### 소프트웨어 위기가 발생하는 이유
  - 어떤 함수가 어떤 변수를 엑세스하는지 쉽게 알 수 없다.
  - 어떤 함수가 어떤 함수를 호출하는지 쉽게 알 수없다.
  - 함수와 변수가 기준없이 섞여있어 재사용시 어디까지 사용해야 할지 쉽게 알 수없다.
  - 반드시 호출해야 하는 함수를 쉽게 알 수없다.

### 객체지향은 이 구조화 프로그램의 문제를 해결할 수 있다.
