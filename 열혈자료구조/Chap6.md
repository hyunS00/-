# 1. 스택의 이해와 ADT 정의

- 스택이란?
  - 데이터를 위로 쌓는것 위로 쌓으면 물건을 뺄 때는 위에서부터 하나씩 제거
  - 나중에 들어간건이 먼저 나오는 후입선출 방식의 자료구조
  - LIFO(Last-In,First-Out)구조의 자료구조

![Untitled](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/b483dbdc-a13d-4972-a4fc-bc17309ecac6/Untitled.png)

- 스택ADT

```jsx
function StackInit() //스택을 초기화하는 함수

function isEmpty() // 스택이 비어있는지 확인하는 함수 비어있으면1 그렇지않으면 0을 리턴

function push(data) // 스택에 매개변수 data를 저장

function pop() //스택에 저장된 데이터를 삭제, 삭제된 데이터는 리턴하는 변수

function peek() // 가장 위에 저장된 변수를 리턴하는 변수
```

# 2. 스택 배열 기반 구현

- 스택ADT구현

```jsx
class ArrayStack {
  constructor() {
    this.arr = [];
  }

  StackInit() {
    this.arr = [];
  }

  isEmpty() {
    if (this.arr.length === 0) {
      return 1;
    } else {
      return 0;
    }
  }

  Spush(data) {
    this.arr.push(data);
  }

  Spop() {
    if (!this.isEmpty()) {
      return this.arr.pop();
    } else {
      console.log("Stack Memory Error");
    }
  }

  peek() {
    return this.arr[this.arr.length - 1];
  }
}
```

# 3. 스택 연결리스트 기반 구현

- 스택 ADT구현

```jsx
class Node {
  constructor(data) {
    this.data = data;
    this.next = null;
  }
}

class ListStack {
  constructor() {
    this.top = null;
  }

  StackInit() {
    this.top = null;
  }

  isEmpty() {
    if (this.top === null) {
      return 1;
    } else {
      return 0;
    }
  }

  Spush(data) {
    let newNode = new Node(data);
    newNode.next = this.top;
    this.top = newNode;
  }

  Spop() {
    if (!this.isEmpty()) {
      let removeData = this.top.data;
      this.top = this.top.next;
      return removeData;
    } else {
      console.log("메모리에러용");
    }
  }

  peek() {
    if (!this.isEmpty()) {
      return this.top.data;
    } else {
      console.log("메모리에러용");
    }
  }
}
```

# 4. 계산기 프로그램 구현

- 컴퓨터 같은 경우는 5 + 2 / 7을 보고 +가가 먼저인지 /가 먼저인지 구분할수가 없다 그래서 표기법을 바꿔 우선순위를 알수있게 바꾸고 나서 연산을 수행한다

- 수식 표기법

  - 전위 표기법(prefix notation): 연산자를 먼저 표시하고 연산에 필요한 피연산자를 나중에 표시하는 방법
    - 예) + 5 / 2 7
  - 후위 표기법(postfix notation): 피연산자를 먼저 표시하고 연산자를 나중에 표시하는 방법
    - 예) 5 2 7 / +
  - 중위 표기법(infix notation): 연산자를 두 피연산자 사이에 표기하는 방법
    - 예) 5 + 2 / 7

- 표기법을 우휘 표기법으로 바꿨다면

  - 5 2 7 / +
  - 5 2 7 op1 op2 를 보고 컴퓨터는 가장 먼저 오는 op1을 먼저 수행하고 op2를 수행한다

- 중위 표기법을 후위 표기법으로 바꾸는 규칙
  1. 피연산자는 그대로 옮긴다
  2. 연산자는 비교연산을 위해 스택에 쌓는다
  ### 3. 연산자가 스택에 쌓였을때 스택에 있는 연산자들과 우선순위를 비교하여 처리방법을 결정한다
  1. 스택에 쌓여있는 연산자들을 순서대로 꺼내어 옮긴다

### 스택으로 이동한 연산자는 우선 순위가 낮은 연산자보다 위에 쌓여있어야 한다 즉 옮길 연산자와 스택 최상단에 있는 연산자중 스택 연산자가 높다면 스택을 꺼내고나서 스택으로 옮긴다 아닌 경우에는 스택에 쌓는다

### 연산자의 우선순위가 동일하면 먼저 스택에 있던 연산자를 먼저 진행 한다

### “ ( ” 연산자는 “ ) “ 연산자가 등장할때까지 스택에 남아있어야 하기 때문에 우선순위가 가장 낮다

- 연산자 우선순위
  ### 3번 : \* /
  ### 2번 : + -
  ### 1번 : (
  ### ) 연산자는 만나는 순간 스택에 있는 연산을 수행하기 때문에 우선순위부여X

## ( 1 + 2 \* 3 ) / 4 연산 후위표기법으로 변환 과정

- 초기상태

![Untitled](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/17163a53-2561-4690-b80a-f2bf113ee567/Untitled.png)

- “ ( ” 연산자를 스택에 push

![Untitled](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/f479195f-e784-4a37-8c58-b2cbfe2fd379/Untitled.png)

- 피연산1을 그대로 옮김

![Untitled](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/b46a9e85-bb35-475b-b0f9-c3aecf019175/Untitled.png)

- - 연산자와 스택 최상단 ” ( “연산자와 우선순위를 비교
- +가 우선순위가 높으니 스택에 push

![Untitled](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/26622a0f-616b-4b8e-b706-e0c3f8e5423f/Untitled.png)

- 피연산2를 그대로 옮김

![Untitled](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/96e2b7a0-b614-4dc0-b7ab-51b11a288099/Untitled.png)

- - 연산자와 스택 최상단 + 연산자와 우선순위를 비교
- \*가 우선순위가 높으니 스택에 push

![Untitled](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/dc62d14d-9922-47e8-894b-e71f7a8526ce/Untitled.png)

- 피연산자 3을 그대로 옮김

![Untitled](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/3eee755b-ca05-4df7-9f7b-931a1e92e7cd/Untitled.png)

- 연산자 “ ) “ 를 만나면 스택에 쌓인 “ ( ”를 제외한 모든 연산자들을 순서대로 pop하고 옮김
- ( 는 그냥 pop만 진행

![Untitled](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/b548ecf5-3bea-4f02-aa21-c349a34f5876/Untitled.png)

- 연산자 / 를 스택에 push

![Untitled](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/0483288d-c96e-4df7-8ac8-a5fed88fd83f/Untitled.png)

- 피연산자 4를 그대로 옮김

![Untitled](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/1ebd12a3-b757-4db4-ab6c-cf1df3bad25d/Untitled.png)

- 모든 연산이 끝났다면 스택에있는 모든 연산자들을 순서대로 pop

![Untitled](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/c2f2ead8-51a1-4d7e-ae28-0bc08336b80f/Untitled.png)

- 중위 표기법 → 후위 표기법 변환 코드

```jsx
//연산자 우선순위 반환 함수
function getOpPrec(op) {
  switch (op) {
    case "*":
    case "/":
      return 3;
    case "+":
    case "-":
      return 2;
    case "(":
      return 1;
    default:
      return -1;
  }
}

//연산자 우선순운위 확인 함수
function whoPrecOp(op1, op2) {
  op1prec = getOpPrec(op1);
  op2prec = getOpPrec(op2);
  if (op1prec > op2prec) {
    return 1;
  } else if (op1prec < op2prec) {
    return -1;
  } else {
    return 0;
  }
}

let stack = [];
let input = "(1+2*3)/4";
let output;
let postfix = [];
let tok;
let popOp;
for (let i = 0; i < input.length; i++) {
  tok = input[i];
  if (!isNaN(tok)) {
    postfix.push(+tok);
  } else {
    switch (tok) {
      case "(":
        stack.push(tok);
        break;
      case ")":
        while (1) {
          popOp = stack.pop();
          if (popOp === "(") break;
          postfix.push(popOp);
        }
        break;
      case "+":
      case "-":
      case "*":
      case "/":
        while (
          stack.length !== 0 &&
          whoPrecOp(stack[stack.length - 1], tok) >= 0
        ) {
          postfix.push(stack.pop());
        }
        stack.push(tok);
        break;
    }
  }
}

while (stack.length !== 0) {
  postfix.push(stack.pop());
}

console.log(input, postfix);
```

### 후위 표기법으로 변환된 1 2 \* 3 + 4 / 계산 과정

- 초기상태

![Untitled](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/10dc6a7e-b5f5-4ed2-b555-76c05ca4c980/Untitled.png)

- 피연산자이면 스택에 push

![Untitled](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/f737774e-cff2-46df-bb46-cd549e8423cc/Untitled.png)

- 연산자면 스택에서 피연산자 두개를 pop
- pop된 두개의 피연산자 2와 3을 연산자 \*대로 계산
- 계산 후 스택에 push

![Untitled](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/97270f98-072b-4c6b-92bd-911a69e23a36/Untitled.png)

- 연산자면 스택에서 피연산자 두개를 pop
- pop된 두개의 피연산자 1과 6을 연산자 +대로 계산
- 계산 후 스택에 push

![Untitled](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/185af1a4-eb73-4ae5-8699-f15419aa2c2b/Untitled.png)

- 피연산자 4를 스택에 push

![Untitled](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/d57c23a6-c300-4a68-a170-34dced9ddc3a/Untitled.png)

- 연산자면 스택에서 피연산자 두개를 pop
- pop된 두개의 피연산자 7과 4를 연산자 /대로 계산
- 계산 후 스택에 push

![Untitled](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/800a42c7-e86d-45cb-a84b-16ad260e1ddd/Untitled.png)

- 연산이 끝난다면 스택에서 pop하여 옮김

![Untitled](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/eb659987-49d8-4a0a-8426-537b1b838d75/Untitled.png)

- 후위 표기법 계산 코드

```jsx
function calculatePostfix(postfix) {
  for (let i = 0; i < postfix.length; i++) {
    tok = postfix[i];
    if (!isNaN(tok)) {
      stack.push(tok);
    } else {
      op2 = stack.pop();
      op1 = stack.pop();
      switch (tok) {
        case "+":
          stack.push(op1 + op2);
          break;
        case "-":
          stack.push(op1 - op2);
          break;
        case "*":
          stack.push(op1 * op2);
          break;
        case "/":
          stack.push(op1 / op2);
          break;
      }
    }
  }
  return stack.pop();
}
```
