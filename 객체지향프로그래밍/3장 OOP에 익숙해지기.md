## 인라인에서 아웃라인으로

```cpp
#include<stdio.h>
class Cpoint{
private:
	int m_ix;
	int m_iy;
public:
	void Assign(int x, int y); //함수 추상화
	int Add(); // 함수 추상화
};

void Cpoint::Assign(int x, int y) { //아웃라인함수
	m_ix = x;
	m_iy = y;
}
int Cpoint::Add() { //아웃라인함수
	return m_ix + m_iy;
}

Cpoint gildong;
void main() {
	gildong.Assign(2, 3);
	int iResult = gildong.Add();
	printf("두 값을 더한결과: %d\n", iResult);
}
```

- 클래스 내부에 작성된 함수를 인라인(in-line)함수
- 클래스 외부에 작성된 함수를 아웃오브라인(out-of-line)함수라고한다

## 생성자와 소멸자

- 생성자 함수는 객체가 실행될 때 자동으로 실행되는 멤버 함수다.
- 소멸자 함수는 객체가 제거될 때 자동으로 실행되는 함수다.

```cpp
#include<stdio.h>
class Cpoint{
private:
	int m_ix;
	int m_iy;

public:
	Cpoint() { // 생성자함수
		m_ix = 0;
		m_iy = 0;
	}

	~Cpoint() { // 소멸자함수
		printf("소멸자 함수!\n");
	}
	void Assign(int x, int y);
	int Add();
};

void Cpoint::Assign(int x, int y) {
	m_ix = x;
	m_iy = y;
}

int Cpoint::Add() {
	return m_ix + m_iy;
}

Cpoint gildong;

void main() {
	gildong.Assign(2, 3);

	int iResult = gildong.Add();
	printf("두 값을 더한결과: %d\n", iResult);
}
```

## 멤버 함수는 멤버 함수나 멤버 변수를 직접 엑세스할 수 있다.

## 전클항멤멤멤클

- 전역변수는 아무데나 막 접근할수있다
- 클래스는 객체를 만들라고있는것이다
- 항상 객체가 언제 어디에서 만든어지는건지 생각하라
- 멤버는 멤버를 직접 엑세스할 수 있다
- 멤버로 정의되어 있겠지
- 멤버로 정의하라
- 클래스를 보지 말고 객체를 봐라 객체 위주로 생각하라
