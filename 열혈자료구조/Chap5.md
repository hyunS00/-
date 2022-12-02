# 1.원형 연결리스트

- 원형 연결리스트란?
  - 마지막 노드가 첫번째 노드를 가리켜 리스트가 원형으로 연결된 리스트
  ![Untitled](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/1a3ce59b-367a-44d9-80a7-48d8844d3285/Untitled.png)
- 변형된 원형 연결리스트

  - 머리가 아닌 꼬리를 가리키는 원형 연결리스트
  - 꼬리를 가리키는 포인터 변수 : tail
  - 머리를 가리키는 포인터 변수: tail→next
  - 꼬리를 기준으로 원형 리스트를 구형하면 꼬리와 머리 둘 다 노드를 삽입하기 쉬워진다

  ![Untitled](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/b0aae5e2-cc51-41f3-ab68-ef83d2149322/Untitled.png)

- 첫번째 노드추가
  - next가 자기 자신을 가리키게함
  ![Untitled](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/0e4cb85c-d740-4e39-8a4d-a655e2ff2748/Untitled.png)
- 머리에 노드추가
  - tail→next에 newNode추가
  ![Untitled](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/0ce0a39c-95ce-4f33-87d6-d10f32bfd541/Untitled.png)
  ![Untitled](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/378b0c38-462f-4e1f-888e-19dac0f553fc/Untitled.png)
- 꼬리에 노드 추가

  - newNode가 tail→next를 가리키게함
  - tail→next가 newNode를 가리키게함
  - tail은 newNode

  ![Untitled](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/794882cc-8239-47b3-828a-fab824f166dd/Untitled.png)

  ![Untitled](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/94eecdf8-9520-4790-b6f2-dc1f0ca8987f/Untitled.png)

- 노드 참조
  - 현재 참조할 부분을 가리키는 변수 cur
  - cur이전 부분을 가리키는 변수 before
  - 단순 연결리스트와 동일
  ![Untitled](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/fad64c05-53b3-49f3-9ab0-2796bbf0425c/Untitled.png)
  ![Untitled](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/9d3344b6-755d-4efe-a4c2-99e2d6095188/Untitled.png)
- 노드 삭제

  - tail이 아닌 부분을 삭제
    - before→next가 cur→next를 가리키게함
    - cur는before
  - tail을 삭제
    - before→next가 cur→next를 가리키게함
    - cur는before
    - tail은 before

  ![Untitled](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/e2d12625-029d-4425-b229-8bcdf2e4c786/Untitled.png)

  ![Untitled](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/d53be0a8-c5f5-4fbd-8435-475cad4e38be/Untitled.png)

- 원형 연결 리스트 ADT

```c
typedef int Data;

typedef struct _node
{
	Data data;
	struct _node* next;
}Node;

typedef struct _CLL
{
	Node* tail;
	Node* cur;
	Node* before;
	int numOfData;
}CList;

typedef CList List;

void ListInit(List* plist); // 리스트 초기화
void LInsert(List* plist, Data data); // 꼬리부분에 노드 삽입
void LInsertFront(List* plist, Data data);  //  머리부분에 노드 삽입

int LFirst(List* plist, Data* pData); // 첫번째 노드 참조
int LNext(List* plist, Data* pData); // 가리키는 노드의 다음 노드 참조
Data LRemove(List* pList); // 노드를 삭제 후 노드를 리턴
int LCount(List* plist); // 노드의 갯수 리턴
```

- 원형 연결리스트 ADT 구현

```c
void ListInit(List* plist)
{
	plist->tail = NULL;
	plist->cur = NULL;
	plist->before = NULL;
	plist->numOfData = 0;
}

void LInsertFront(List* plist, Data data)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;

	if (plist->tail == NULL)
	{
		plist->tail = newNode;
		newNode->next = newNode;
	}
	else
	{
		newNode->next = plist->tail->next;
		plist->tail->next = newNode;
	}
	(plist->numOfData)++;
}

void LInsert(List* plist, Data data)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;

	if (plist->tail == NULL)
	{
		plist->tail = newNode;
		newNode->next = newNode;
	}
	else
	{
		newNode->next = plist->tail->next;
		plist->tail->next = newNode;
		plist->tail = newNode;
	}
	(plist->numOfData)++;
}

int LFirst(List* plist, Data *pdata)
{
	if (plist->tail == NULL)
		return FALSE;
	plist->before = plist->tail;
	plist->cur = plist->tail->next;

	*pdata = plist->cur->data;
	return TRUE;
}

int LNext(List* plist, Data* pdata)
{
	if (plist->tail == NULL)
		return FALSE;

	plist->before = plist->cur;
	plist->cur = plist->cur->next;

	*pdata = plist->cur->data;
	return TRUE;
}

Data LRemove(List* plist)
{
	Node* rpos = plist->cur;
	Data rdata = rpos->data;

	if (rpos == plist->tail)
	{
		if (plist->tail == plist->tail->next)
			plist->tail = NULL;
		else
			plist->tail = plist->before;
	}

	plist->before->next = plist->cur->next;
	plist->cur = plist->before;

	free(rpos);
	(plist->numOfData)--;
	return rdata;
}

int LCount(List* plist)
{
	return plist->numOfData;
}
```

# 2. 양방향 연결 리스트

- 양방향 연결리스트란?

  - 말 그대로 노드 양쪽이 연결되어 있는 리스트
  - 노드의 왼쪽 노드를 가리키는 변수 prev
  - 노드의 오른쪽 노드를 가리키는 변수 next
  - 양방향 참조 노드를 사용하면 before라는 이전을 참조하는 리스트변수를 사용 안해도 된다

  ![Untitled](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/fdc58ca9-1dd0-4bec-abab-3e9889a07ab1/Untitled.png)

- 첫번째 노드 추가
  - 노드의 prev와 next는 NULL
  - head는 newNode
  ![Untitled](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/f4444a01-610c-4d6a-b1d2-8a95d7e598b9/Untitled.png)
- 노드 추가

  - newNode→next가 head가 가리키는 노드를 가리키게하고
  - head→prev가 newNode를 가리키게하고
  - head는 newNode가 됨

  ![Untitled](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/77b7a9be-a74c-490c-8e18-00231135081e/Untitled.png)

- 노드 참조

  - cur를 cur→next를 가리기게함

  ![Untitled](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/7fc07bb1-488c-4fab-aaba-4c6edad38d6d/Untitled.png)

  - cur를 →prev를 가리키게함

  ![Untitled](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/7ef113c9-8948-497f-8b5d-e7ccf0b00368/Untitled.png)

- 양방향 연결 리스트 ADT

  ```c
  typedef struct _node
  {
  	Data data;
  	struct _node * next; // 오른쪽 노드를 가리키는 변수
  	struct _node * prev; // 왼쪽 노드를 가리키는 변수
  } Node;

  typedef struct _dbLinkedList
  {
  	Node * head;
  	Node * cur;
  	int numOfData;
  } DBLinkedList;

  typedef DBLinkedList List;

  void ListInit(List * plist); //리스트를 초기화
  void LInsert(List * plist, Data data); //리스트 head 부분에 삽입

  int LFirst(List * plist, Data * pdata); //첫번째 노드 참조
  int LNext(List * plist, Data * pdata); // 가리키는 노드의 오른쪽 노드를 참조
  int LPrevious(List * plist, Data * pdata); // 가리키는 노드의 왼쪽 노드를 참조

  int LCount(List * plist); // 노드의 갯수리턴
  ```

- 양방향 연결리스트 ADT 구현
  ```c
  void ListInit(List* plist)
  {
  	plist->head = NULL;
  	plist->numOfData = 0;
  }

  void LInsert(List* plist, Data data)
  {
  	Node* newNode = (Node*)malloc(sizeof(Node));
  	newNode->data = data;

  	newNode->next = plist->head;
  	if (plist->head != NULL)
  		plist->head->prev = newNode;
  	newNode->prev = NULL;
  	plist->head = newNode;

  	(plist->numOfData)++;
  }

  int LFirst(List* plist, Data pdata)
  {
  	if (plist->head == NULL)
  		return FALSE;

  	plist->cur = plist->head;
  	*pdata = plist->cur->data;

  	return TRUE;
  }

  int LNext(List* plist, Data* pdata)
  {
  	if (plist->cur->next == NULL)
  		return FALSE;

  	plist->cur = plist->cur->next;
  	*pdata = plist->cur->data;

  	return TRUE;
  }

  int LPrevious(List* plist, Data* pdata)
  {
  	if (plist->cur->prev == NULL)
  		return FALSE;

  	plist->cur = plist->cur->prev;
  	*pdata = plist->cur - data;

  	return TRUE;
  }

  int LCount(List* plist)
  {
  	return plist->numOfData;
  }
  ```
