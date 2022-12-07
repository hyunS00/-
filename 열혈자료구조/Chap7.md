# 1. 큐의 이해와 ADT 정의

- 큐란?
  - 먼저 들어간 것이 먼저 나오는 선입 선출 구조
  - FIFO (First-In, First-Out)구조의 자료구조
    ![Untitled](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/4e522aa9-9b4b-440f-b370-75841dd49332/Untitled.png)

![Untitled](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/db1c15d5-043d-4987-beaa-41eb67a459e2/Untitled.png)

![Untitled](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/49c4fe12-6309-448b-87e4-dc84bf4d3e64/Untitled.png)

![Untitled](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/92a0ddca-082a-47d7-a242-41dfc0937653/Untitled.png)

![Untitled](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/1ddd5632-759c-4ac3-999f-2457cf014140/Untitled.png)

![Untitled](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/a2c94ec4-3319-45e8-97fc-4b9182021300/Untitled.png)

![Untitled](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/c2e9aaf6-0a6b-4940-9df7-3f1daf135ace/Untitled.png)

# 2. 큐의 배열 기반 구현

- 배열로 구현한 큐

![Untitled](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/8b2d375d-e349-451c-94ce-12fdc3f93435/Untitled.png)

- 배열 끝에 데이터가 저장된다면 더이상 사용을 못하기 때문에 원형 배열을 사용하여 구현 한다

![Untitled](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/32b30c87-db4c-4866-ab79-f96285954b43/Untitled.png)

- dequeue를 한번 더 진행하면 F가 R보다 한칸 앞에 있게된다

![Untitled](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/ca24489f-f173-4eda-93bc-2871177a2e03/Untitled.png)

- 원형큐가 꽉찼거나 비었을때 F가 R보다 한칸 앞에있는 상태이기 때문에 full과 empty를 구분하지 못한다
- 그래서 배열을 모두 채우지 않고 최대 n-1개만 채운다

![Untitled](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/d1c10c4e-4cf7-46a3-97fc-b3713177f7c6/Untitled.png)

- 원형 큐가 텅 빈 상태 → F와 R이 동일한 위치를 가리킨다
- 원형 큐가 꽉 찬 상태 → R이 가리키는 위치의 앞을 F가 가리킨다

- 연결리스트기반의 큐 ADT

```jsx
qIsEmpty() {} // 큐가 비었는지확인하는 함수
enQueue(data) {} // 큐에 데이터를 추가하는 함수
deQueue() {} // 큐에 가장 먼저 들어온 데이터를 제거하는 함수
qPeek() {} // 큐에있는 가장 먼저들어온 데이터를 확인하는함수
```

- 원형 큐의 구현

```jsx
const QueLength = 4;
class Queue {
  constructor() {
    this.arr = Array(QueLength);
    this.front = 0;
    this.rear = 0;
  }

  queueInit() {
    this.front = 0;
    this.rear = 0;
  }

  qIsEmpty() {
    if (this.front === this.rear) {
      return 1;
    } else {
      return 0;
    }
  }

  nextPosIdx(pos) {
    if (pos === QueLength - 1) {
      return 0;
    } else {
      return pos + 1;
    }
  }

  enQueue(data) {
    if (this.nextPosIdx(this.rear) === this.front) {
      console.error("메모리 꽉참");
    }
    this.rear = this.nextPosIdx(this.rear);
    this.arr[this.rear] = data;
  }

  deQueue() {
    if (this.qIsEmpty()) {
      console.error("에렁");
    }
    this.front = this.nextPosIdx(this.front);
    return this.arr[this.front];
  }
}
```

# 3. 큐의 연결 리스트 기반 구현

- 연결리스트기반의 큐 ADT

```jsx
qIsEmpty() {} // 큐가 비었는지확인하는 함수
enQueue(data) {} // 큐에 데이터를 추가하는 함수
deQueue() {} // 큐에 가장 먼저 들어온 데이터를 제거하는 함수
qPeek() {} // 큐에있는 가장 먼저들어온 데이터를 확인하는함수
```

- 연결리스트기반의 큐 ADT구현

```jsx
class Node {
  constructor(data) {
    this.data = data;
    this.next = null;
  }
}

class Queue {
  constructor() {
    this.front = null;
    this.rear = null;
  }

  qIsEmpty() {
    if (this.front === null) {
      return 1;
    } else {
      return 0;
    }
  }

  enQueue(data) {
    let newNode = new Node(data);

    if (this.qIsEmpty()) {
      this.front = newNode;
      this.rear = newNode;
    } else {
      this.rear.next = newNode;
      this.rear = newNode;
    }
  }

  deQueue() {
    let delNode = new Node();
    let rData;

    if (this.qIsEmpty()) {
      console.error("메모리 에러");
    }

    delNode = this.front;
    rData = delNode.data;
    this.front = this.front.next;

    return rData;
  }

  qPeek() {
    if (this.qIsEmpty()) {
      console.error("에렁");
    }
    return this.front.data;
  }
}
```

# 4. 큐의 활용

- 햄버거가게 시뮬레이션

```jsx
const CUS_COME_TERM = 15;

const CHE_TERM = 12;
const BUL_TERM = 15;
const DUB_TERM = 24;

let makeProcess = 0;
let cheOrder = (bulOrder = dubOrder = 0);
let sec;

let q = new Queue();

for (sec = 0; sec < 3600; sec++) {
  if (sec % CUS_COME_TERM === 0) {
    switch (Math.floor(Math.random() * 3)) {
      case 0:
        q.enQueue(CHE_TERM);
        cheOrder++;
        break;
      case 1:
        q.enQueue(BUL_TERM);
        bulOrder++;
        break;
      case 2:
        q.enQueue(DUB_TERM);
        dubOrder++;
        break;
    }
  }

  if (makeProcess <= 0 && !q.qIsEmpty()) {
    makeProcess = q.deQueue();
  }
  makeProcess--;

  console.log(cheOrder, bulOrder, dubOrder);
}
```

# 5. 덱의 이해와 구현

- 덱이란?
  - double-ended queue DEQUE
  - 앞으로 넣고 앞으로 빼고 뒤로 넣고 뒤로 뺄 수 있는 자료구조
- ADT

```jsx
DequeInit() {}
DQIsEmpty() {}
DQAddFirst(data) {}
DQAddLast(data) {}
DQRemoveFirst() {}
DQRemoveLast() {}
DQGetFirst() {}
DGetLast() {}
```

- ADT구현

```jsx
class Node {
  constructor(data) {
    this.data = data;
    this.next = null;
    this.prev = null;
  }
}

class Deque {
  constructor() {
    this.head = null;
    this.tail = null;
  }

  DequeInit() {
    this.head = null;
    this.tail = null;
  }

  DQIsEmpty() {
    if (this.head === null) {
      return 1;
    } else {
      return 0;
    }
  }

  DQAddFirst(data) {
    let newNode = new Node(data);
    newNode.next = this.head;

    if (this.DQIsEmpty()) {
      this.tail = newNode;
    } else {
      this.head.prev = newNode;
    }

    newNode.prev = null;
    this.head = newNode;
  }

  DQAddLast(data) {
    let newNode = new Node(data);
    newNode.prev = this.tail;

    if (this.DQIsEmpty()) {
      this.head = newNode;
    } else {
      this.tail.next = newNode;
    }
    newNode.next = null;
    this.tail = newNode;
  }

  DQRemoveFirst() {
    let rnode = this.head;
    let rdata;
    if (this.DQIsEmpty()) console.error("에러");
    rdata = this.head.data;

    this.head = this.head.next;

    if (this.head === null) {
      this.tail = null;
    } else {
      this.head.prev = null;
    }

    return rdata;
  }

  DQRemoveLast() {
    let rnode = this.tail;
    let rdata;
    if (this.DQIsEmpty()) console.error("에러");
    rdata = this.tail.data;

    this.tail = this.tail.prev;

    if (this.tial === null) {
      this.head = null;
    } else {
      this.tial.next = null;
    }

    return rdata;
  }

  DQGetFirst() {
    if (this.DQIsEmpty()) console.error("에러");

    return this.head.data;
  }

  DGetLast() {
    if (this.DQIsEmpty()) console.error("에러");

    return this.tail.data;
  }
}
```
