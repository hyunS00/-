# 1. 연결리스트의 개념적인 이해

- 연결리스트란?
  - 각 노드를 한 줄로 연결되어 있는 방식으로 데이터를 저장하는 자료구조
- 노드란?
  - 데이터를 포함하며 다른 노드들과 링크되는 자료구조의 일부분?
- 노드 클래스(구조체)구현

```jsx
class Node {
  constructor(data) {
    this.data = data; //데이터를 담을 공간
    this.next = null; // 다음 노드를 연결할 도구
  }
}
```

![Untitled](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/d0495563-f064-435a-92d1-7b485e9859eb/Untitled.png)

- 노드를 바구니라 생각하면 바구니안에 물건을 넣고→data
- 바구니에서 다음 바구니를 가리키는 것을 →next

![Untitled](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/1d71df19-c4d1-478b-b3b5-391b5fbc709c/Untitled.png)

- 연결 리스트 클래스(구조체) 구현
  ```jsx
  class LinkedList {
    constructor() {
      this.head = null; //리스트의 머리부분 노드를 가리키는 변수
      this.count = 0; // 연결된 노드의 갯수변수
    }
  }
  ```
  - 초기 상태
  ![Untitled](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/901a8607-3485-4f70-9bc8-c0b48d879b86/Untitled.png)
  - 데이터를 추가
  ![Untitled](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/646ffc34-5570-4bb4-a449-cd900b781926/Untitled.png)
  - 데이터 조회
  ![Untitled](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/3d831221-2098-4465-ad82-19b47b09ead6/Untitled.png)
  - 데이터 삭제
  ![Untitled](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/0adbb32a-5a5c-4d16-b055-55d58a069d7c/Untitled.png)
  ![Untitled](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/b5ac0058-f270-422f-af88-6c63e1ef9244/Untitled.png)

# 2. 단순 연결 리스트의 ADT와 구현

- 단순 연결리스트 ADT

```jsx
ListInit(); // 리스트를 초기화하는 함수

LInsert(data); // 리스트에 테이터를 추가

LFirst(); // 리스트 첫번째 부분을 참조

LNext(); // 리스트 가리키는 노드 다음 노드르 참조

LRemove(); // 가리키는 노드를 삭제

LCount(); // 리스트의 개수 리턴
```

- 구현

```c
void ListInit(List* plist)
{
	plist->head = (Node*)malloc(sizeof(Node)); //더미 노드의 생성
	plist->head->next = NULL;
	plist->numOfData = 0;
}

void FInsert(List* plist, LData data)
{
	Node* newNode = (Node*)malloc(sizeof(Node)); // 새 노드의 생성
	newNode->data = data; // 새노드에 데이터 저장

	newNode->next = plist->head->next; // 새 노드가 다른 노드를 가리키게 함
	plist->head->next = newNode; // 더미 노드가 새 노드를 가리키게 함

	(plist->numOfData)++; // 저장된 노드의 수를 하나 증가시킴
}

int LFirst(List* plist, LData* pdata)
{
	if (plist->head->next == NULL) // 더미 노드가 NULL을 가리킨다면,
		return FALSE; // 반환할 데이터가 없다

	plist->before = plist->head; // before는 더미 노드를 가리키게함
	plist->cur = plist->head->next; // cur은 첫 번째 노드를 가리키게 함

	*pdata = plist->cur->data; // 첫 번째 노드의 데이터를 전달
	return TRUE; // 데잍터 반환 성공
}

int LNext(List* plist, LData* pdata)
{
	if (plist->cur->next == NULL) // cur이 NULL을 가리킨다면
		return FALSE; // 반환할 데이터가 없다

	plist->before = plist->cur; // cur이 가리키던 것을 before가 가리킴
	plist->cur = plist->cur->next; // cur은 그 다음 노드를 가리킴

	*pdata = plist->cur->data; // cur이 가리키는 노드의 데이터 전달
	return TRUE; // 데이터 반환 성공
}

LData LRemove(List* plist)
{
	Node* rpos = plist->cur; // 소멸 대상의 주소 값을 rpos에 저장
	LData rdata = rpos->data; // 소멸 대상의 데이터를 rdata에 저장

	plist->before->next = plist->cur->next; //소멸 대상을 리스트에서 제거
	plist->cur = plist->before; // cur이 가리키는 위치를 재조정

	free(rpos); // 리스트에서 제거된 노드 소멸
	(plist->numOfData)--; // 저장된 데이터의 수 하나 감소
	return rdata; // 제거된 노드의 데이터 반환
}

int LCount(List* plist)
{
	return plist->numOfData;
}
```

```jsx
class Node {
  constructor() {
    this.data = null;
    this.next = null;
  }
}

class LinkedList {
  constructor() {
    this.head = new Node();
    this.head.next = null;
    this.count = 0;
    this.before = null;
    this.cur = null;
  }

  ListInit() {
    this.head = new Node();
    this.head.next = null;
    this.count = 0;
    this.cur = null;
  }

  LInsert(data) {
    let newNode = new Node();
    newNode.data = data;

    newNode.next = this.head.next;
    this.head.next = newNode;

    this.count++;
  }

  LFirst() {
    this.before = this.head;
    this.cur = this.head.next;
    return this.cur.data;
  }

  LNext() {
    if (this.cur.next === null) {
      return false;
    }

    this.before = this.cur;
    this.cur = this.cur.next;

    return this.cur.data;
  }

  LRemove() {
    let rpos = this.cur;
    let rdata = rpos.data;

    this.before.next = this.cur.next;
    this.cur = this.before;

    this.count--;
    return rdata;
  }

  LCount() {
    return this.count;
  }
}

let LL = new LinkedList();
LL.ListInit();
LL.LInsert(1);
LL.LInsert(2);
LL.LInsert(3);

console.log(LL.LFirst());
console.log(LL.LNext());
console.log(LL.LNext());
console.log(LL.LNext());

console.log(LL.LRemove());
console.log(LL.LRemove());
console.log(LL.LRemove());
```

# 3. JS 프로토 타입

- prototype
  - js에는 ES6이전 class가 지원되기전 클래스처럼 사용 가능한 속성
  ```jsx
  function Person() {}
  Person.prototype.eye = 2;
  Person.prototype.nose = 1;

  let hyunsoo = new Person();

  console.log(hyunsoo.__proto__);
  ```
  ![Untitled](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/4f8b5095-e932-40b5-8c01-9f0ff54dc368/Untitled.png)
  ![Untitled](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/f2f264b9-e07b-4733-8b2f-cd6c88818c20/Untitled.png)
  [[Javascript ] 프로토타입 이해하기](https://medium.com/@bluesh55/javascript-prototype-%EC%9D%B4%ED%95%B4%ED%95%98%EA%B8%B0-f8e67c286b67)
