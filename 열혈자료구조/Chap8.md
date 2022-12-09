# 1. 트리의 개요

- 트리란?
  - 계층적 관계를 표현하는 자료구조
  - 예) 컴퓨터 디렉터리
  ![Untitled](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/b9558c07-654c-4983-aad4-988220b7e5d9/Untitled.png)
- 트리의 조건
  1. 트리에는 루트(root)라고 부르는 특별한 노드가 있다
  2. 루트노드를 제외한 다른 노드들은 원소가 중복되지 않는 n개의 서브트리로 구성된다
  ![Untitled](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/2864d70e-4b48-42bd-b007-c53ca8f9a3d6/Untitled.png)
  - 노드: 트리의 구성요소
    - ex) A, B, C, D, E, F
  - 간선: 노드와 노드를 연결하는 연결선
  - 루트노드: 트리 구조 최상위 노드
    - ex) A
  - 단말노드: 자식노드가 없는 노드
    - ex) E, F, C, D
  - 내부노드: 단말노드를 제외한 모든 노드

    - ex) A, B

  - 노드들 관의 관계

    - 부모노드: 서브트리를 가지는 노드
      - ex) E의 부모노드는 B, B의 부모노드는A
    - 자식노드: 부모 노드 밑에 연결된 노드
      - ex)A의 자식노드는 B, C, D B의 자식노드는 E,F
    - 형제노드: 부모가 같은 자식 노드들
      - ex) C의 형제 노드는 B, D

  - 서브트리: 큰트리의 속하는 작은 트리
  ![Untitled](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/02b638c7-2fea-4f94-b200-d5f46159cef3/Untitled.png)
- 이진트리란?
  - 각 노드가 최대 두개의 자식노드를 갖는 트리
  ![Untitled](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/a91191df-ea8d-46a6-a590-253c61d6efd6/Untitled.png)
  - 이건도 이진트리
  ![Untitled](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/f7111420-e044-4f9e-8640-ca0a077cd9af/Untitled.png)
  - 노드가 위치 할 수 있는 곳에 노드가 없으면 공집합이 있다고 생각한다
  ![Untitled](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/fc188f33-7243-48f6-95a1-4e8f320965ea/Untitled.png)
  ![Untitled](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/2b28eab7-159e-4e1c-b045-d4b44fae0dae/Untitled.png)
  - 레벨: 각 층별로 숫자를 매김
  - 높이: 트리 최고 레벨
  ![Untitled](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/80ab4817-bd94-4e64-a911-e8335bbdc44a/Untitled.png)
  - 포화 이진트리: 트리의 깊이가 k일때 $2^k-1$개의 노드를 가진 이진트리 즉, 모든 레벨이 꽉찬 이진트리
    ![Untitled](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/7b3c2cda-aef5-4301-bf5e-103e21c33bea/Untitled.png)
  - 완전 이진트리: 마지막 레벨을 제외하고 모든 레벨이 왼쪽부터 오른쪽으로 채워져 있는 이진트리
    ![Untitled](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/14b5494f-7965-4e2a-9cc1-c9ec7da99a87/Untitled.png)

# 2. 이진 트리의 구현

- 배열 기반 이진트리 구현

  - 트리를 매우 빈번히 탐색하는경우 주로 사용
  - 힙 구조에 사용

  ![Untitled](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/d3388d2b-37a8-4fe4-a361-6902965b0f34/Untitled.png)

- 연결리스트 기반 이진트리 구현
  - 트리를 표현하기엔 연결리스트 기반이 더 유연
  ![Untitled](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/c9f21ad5-5100-44c9-95a6-4a1fc6148a15/Untitled.png)
- 트리에 사용될 노드 구조

![Untitled](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/5f09be62-97e4-4860-8a4f-18b77ebae683/Untitled.png)

```jsx
class BTreeNode {
  constructor() {
    this.data = null;
    this.left = null;
    this.right = null;
  }
}
```

- 이진 트리 자료구조 ADT

```jsx
function makeBTreeNode() {} // 이진트리노드를 생성한다

function getData(bt) {} // 노드에 저장된 데이터를 리턴한다

function setData(bt, data) {} // 노드에 데이터를 data인자로 받아 저장한다

function getLeftSubTree(bt) {} // 노드의 왼쪽 서브트리 주소를 반환한다

function getRightSubTree(bt) {} // 노드의 오른쪽 서브트리 주소를 반환한다

function makeLeftSubTree(main, sub) {} // sub를main 왼쪽 서브트리로 연결함

function makeRightSubTree(main, sub) {} // sub를main 오른쪽 서브트리로 연결함
```

- 이진트리 구현

```jsx
class BTreeNode {
  constructor() {
    this.data = null;
    this.left = null;
    this.right = null;
  }
}

function makeBTreeNode() {
  let node = new BTreeNode();
  return node;
}

function getData(bt) {
  return bt.data;
}

function setData(bt, data) {
  return (bt.data = data);
}

function getLeftSubTree(bt) {
  return bt.left;
}

function getRightSubTree(bt) {
  return bt.right;
}

function makeLeftSubTree(main, sub) {
  main.left = sub;
}

function makeRightSubTree(main, sub) {
  main.right = sub;
}

let bt1 = new makeBTreeNode();
let bt2 = new makeBTreeNode();
let bt3 = new makeBTreeNode();
let bt4 = new makeBTreeNode();

setData(bt1, 1);
setData(bt2, 2);
setData(bt3, 3);
setData(bt4, 4);

makeLeftSubTree(bt1, bt2);
makeRightSubTree(bt1, bt3);
makeLeftSubTree(bt2, bt4);

console.log(getData(getLeftSubTree(bt1)));

console.log(getData(getLeftSubTree(getLeftSubTree(bt1))));
```

- 출력

```jsx
2;
4;
```

# 이진 트리의 순회

- 순회의 세가지 방법

  - 전위 순회 : 루트 노드를 가장 먼저 방문하는 순회
    - 방문순서: A → B → C

  ![Untitled](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/f273fb9d-7525-448a-8588-585eea4e0064/Untitled.png)

  - 중위순회: 루트노드를 중간에 방문하는 순회
    - 방문순서: B → A → C

  ![Untitled](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/b32ce1e2-c2f6-438f-a731-2544abc3b25f/Untitled.png)

  - 후위순회: 루트노드를 가장 마지막에 방문하는 순회
    - 방문순서: B → C → A

  ![Untitled](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/eb00ceec-17cf-47f4-b926-767eab8b9035/Untitled.png)

- 순회의 재귀적 표현
  - 노드가 3개 이상인 경우에는 재귀적으로 해결한다
  ![Untitled](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/ea760b20-8cba-4a98-8d99-aa31003ed27f/Untitled.png)
  - 중위순회 트리 방문 순서
  1.  왼쪽 서브트리 순회
  2.  루트노드 방문
  3.  오른쪽 서브트리 순회
  - 노드 방문순서
    - D → B → E → A → F → C → G
  - 재귀탈출 조건
    - 자식 노드가 null일때
- 중위순회 재귀코드 구현

```jsx
function inorderTraverse(bt) {
  if (bt === null) return;

  inorderTraverse(bt.left);
  console.log(bt.data);
  inorderTraverse(bt.right);
}
```

- 전위순회 재귀코드 구현

```jsx
function preorderTraverse(bt) {
  if (bt === null) return;

	console.log(bt.data);
  preorderTraverse(bt.left);
  preorderTraverse(bt.right);

```

- 후위순회 재귀코드 구현

```jsx
function postorderTraverse(bt) {
  if (bt === null) return;

  postorderTraverse(bt.left);
  postorderTraverse(bt.right);
  console.log(bt.data);
}
```

# 4. 수식트리의 구현

- 수식트리란?
  - 이진트리를 이용해 수식을 표현해 놓은 것
  ![Untitled](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/2878abd1-af0d-498d-82e8-2a845647c6d3/Untitled.png)
- 수식 계산 과정
  - 중위 표기법의 수식 → 후위 표기법의 수식 → 수식트리
- 후위 표기법의 수식을 수식 트리로 구성할때 두가지의 특징
  - 연산 순서대로 왼쪽에서 오른쪽으로 연산자가 나열된다
  - 해당 연산자의 두 피연산자는 연산자 앞에 나열된다
- 수식트리를 구성하는 방법
  - 피연산자를 스택으로 옮긴다
  - 연산자를 만나면 스택에서 pop을 두번하여 피연산자를 꺼내 자식노드로 연결
  - 자식노드를 연결해서 만들어진 트리는 다시 스택으로 push
- 수식트리 변환 코드

```jsx
function makeExpTree(exp) {
  let s = new ListStack();
  let pnode;

  for (let i = 0; i < exp.length; i++) {
    pnode = makeBTreeNode();

    if (!isNaN(exp[i])) {
      setData(pnode, exp[i] * 1);
    } else {
      makeRightSubTree(pnode, s.Spop());
      makeLeftSubTree(pnode, s.Spop());
      setData(pnode, exp[i]);
    }

    s.Spush(pnode);
  }
  return s.Spop();
}
```

- 수식트리 계산 코드

```jsx
function evaluateExpTree(bt) {
  let op1, op2;

  if (getLeftSubTree(bt) === null && getRightSubTree(bt) === null) {
    return getData(bt);
  }
  op1 = evaluateExpTree(getLeftSubTree(bt));
  op2 = evaluateExpTree(getRightSubTree(bt));

  switch (getData(bt)) {
    case "+":
      return op1 + op2;
    case "-":
      return op1 - op2;
    case "*":
      return op1 * op2;
    case "/":
      return op1 / op2;
  }
  return 0;
}
```

```jsx
let exp = "12+7*";
let eTree = makeExpTree(exp);

inorderTraverse(eTree);

console.log(evaluateExpTree(eTree));
```

결과

```jsx
1 + 2 * 7;
12;
```
