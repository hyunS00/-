# 1. 추상자료형 ADT

- 추상화
  - 핵심이나 개념을 간추리는 것
- 추상자료형이란
  - 구체적인 기능의 완성과정을 언급하지 않고, 순수하게 기능이 무엇인지를 나열한 것을 가리킴
  - 세부 구현으로부터 분리해 핵심 개념이나 기능을 간추려 낸 자료형
- 추상자료형과 자료구조의 차이점
  - 추상자료형
    - 문제를 해결하기 위해 필요한 자료의 형태 및 연산을 수학적으로 정의한 모델
    - 컨셉이나 아이디어를 구상하고 정의하는 것이 우선
  - 자료구조
    - 추상적 자료형이 정의한 연산들을 구현한 구현체
    - ADT를 구현하기 시작하는 단계
  | 개념       | 정의                                                                     | 예                              |
  | ---------- | ------------------------------------------------------------------------ | ------------------------------- |
  | 추상자료형 | 문제를 해결하기 위해 필요한 자료의 형태 및 연산을 수학적으로 정의한 모델 | 집합, 리스트, 스택, 큐, 트리 등 |
  | 자료구조   | 추상자료형이 정의한 연산들을 구현한 구현체                               | 콜 스택, 연결리스트, 배열 등    |
  [추상적 자료형, 자료구조, 알고리즘의 차이](https://baileyworld.tistory.com/16)

# 2. 리스트

- 리스트란
  - 데이터를 나란히 저장하는 구조
- 리스트의 종류
  - 순차리스트 : 배열을 기반으로 구현된 리스트
  - 연결리스트 : 메모리의 동적 할당을 기반으로 구현된 리스트
- 배열 리스트 ADT
  ```c
  void ListInit(List * plist) //리스트를 초기화
  void LInsert(List * plist, LData data) // 리스트에 데이터 삽입
  int LFirst(List * plist, LData * pdata) // 리스트의 첫번째 데이터 확인
  int LNext(List * plist, LData * pdata) // 리스트의 다음 데이터 확인
  LData LRemove(List * plist) // 리스트의 데이터 제거
  int LCount(List * plist) // 리스트에 저장된 데이터의 갯수 확인
  ```
- ADT 구현

```c
void ListInit(List * plist)
{
	(plist->numOfData) = 0;
	(plist->curPosition) = -1;
}

void LInsert(List * plist, LData data)
{
	if(plist->numOfData > LIST_LEN)
	{
		puts("저장이 불가능합니다.");
		return;
	}

	plist->arr[plist->numOfData] = data;
	(plist->numOfData)++;
}

int LFirst(List * plist, LData * pdata)
{
	if(plist->numOfData == 0)
		return FALSE;

	(plist->curPosition) = 0;
	*pdata = plist->arr[0];
	return TRUE;
}

int LNext(List * plist, LData * pdata)
{
	if(plist->curPosition >= (plist->numOfData)-1)
		return FALSE;

	(plist->curPosition)++;
	*pdata = plist->arr[plist->curPosition];
	return TRUE;
}

LData LRemove(List * plist)
{
	int rpos = plist->curPosition;
	int num = plist->numOfData;
	int i;
	LData rdata = plist->arr[rpos];

	for(i=rpos; i<num-1; i++)
		plist->arr[i] = plist->arr[i+1];

	(plist->numOfData)--;
	(plist->curPosition)--;
	return rdata;
}

int LCount(List * plist)
{
	return plist->numOfData;
}
```

```jsx
class ArrayList {
  constructor() {
    this.arr = [];
    this.count = 0;
    this.pos = -1;
  }

  ListInit() {
    this.count = 0;
    this.pos = -1;
  }

  LInsert(data) {
    this.arr[this.count] = data;
    this.count++;
  }

  LFirst(data) {
    if (this.count === 0) {
      return false;
    }
    this.pos = 0;
    data = this.arr[0];
    return true;
  }

  LNext(data) {
    if (this.pos >= this.count - 1) {
      return false;
    }
    this.pos++;
    data = this.arr[this.pos];
    return true;
  }

  LRemove() {
    const rpos = this.pos;
    const num = this.count;
    const rdata = this.arr[rpos];

    for (let i = rpos; i < num - 1; i++) {
      this.arr[i] = this.arr[i + 1];
    }
    this.count--;
    this.pos--;
    return rdata;
  }

  LCount() {
    return this.count;
  }
}
```
