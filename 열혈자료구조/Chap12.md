# 1. 균형 잡힌 이진 탐색 트리:AVL 트리의 이해

- 일반 이진 탐색 트리의 경우 $O(log_2n)$의 시간 복잡도를 가짐
- 일반 이진 탐색 트리의 경우 균형이 맞지 않을수록 $O(n)$에 가까움

![Untitled](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/31bf0e01-d872-4114-a1b6-668eeb84b393/Untitled.png)

- 균형을 조금만 맞춰도 높이가 낮아진다

![Untitled](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/4ba24bcd-76a1-4e5a-9b9e-f0e43063e1bf/Untitled.png)

## AVL트리란?

- AVL트리는 노드가 추가될 때, 삭제될 때 트리의 균형상태를 파악해서 스스로 그 구조를 변경하여 균형을 잡는 트리이다.
- 균형의 정도를 표현하기 위해 균형인수라는 것을 사용

<aside>
💡 균형 인수 = 왼쪽 서브 트리의 높이 - 오른쪽 서브 트리의 높이

</aside>

- 균형 인수의 절댓 값이 크면 클수록 그만큼 트리의 균형이 무너진 상태

![Untitled](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/f7b60407-347b-4fba-b5ac-0a90fdcc03de/Untitled.png)

### AVL트리는 균형 인수의 절댓 값이 2 이상인 경우에 균형을 잡기 위한 트리의 재조정을 진행 함

## 리벨런싱이 필요한 첫 번째 상태와 LL회전

![Untitled](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/991f0c96-73b7-485d-8a7f-c3f1f9263aa5/Untitled.png)

- LL회전이란 왼쪽으로 두 번 돌리는 회전을 의미하는 것이 아니고, LL상태에서 균형을 잡기 위해 필요한 회전을 의미 함
- LL회전의 핵심은 균형 인수가 +2인 노드를 균형 인수가 +1인 노드의 오른쪽 자식 노드가 되게 하는데 있다

![Untitled](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/f369d6e0-785b-417d-8b1b-d9d51d734a3b/Untitled.png)

- 이러한 간단한 트리를 보면 그저ChangeRightSubTree(cNode,pNode)를 하면 되지만 일반화를 하면 위의 한 문장으로만은 부족하다.

![Untitled](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/2202da67-0dd9-47c3-9b65-e0e863640b0a/Untitled.png)

- T1,2,3,4를 NULL로 치환하면 앞선 그림의 LL상태가 된다

![Untitled](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/a11a0918-8f83-42ba-bb1d-e822a2fb36ab/Untitled.png)

- T3의 자리는 다른 노드한테 양보해야한다
- 5가 저장된 노드의 왼쪽 서브트리로 연결한다

### cNode가 가리키는 오른쪽 서브 트리를 pNode가 가리키는 노드의 왼쪽 서브 트리로 옮기기 위해서는 다음 문장을 실행해야한다!

```
ChangeLeftSubTree(pNode,GetRightSubTree(cNode));
```

- LL회전을 위해서는다음 두 문장을 순서대로 실행해야한다.

```
ChangeLeftSubTree(pNode,GetRightSubTree(cNode));
ChangeRightSubTree(cNode,pNode);
```

## 리벨런싱이 필요한 두 번째 상태와 RR회전

- LL회전과 RR회전은 방향 차이

![Untitled](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/575c22bd-deb5-493b-8924-0e405cfea825/Untitled.png)

- PN을 CN의 왼쪽 자식 노드가 되게했다 - 연산 1
- CN의 왼쪽 서브 트리를 PN의 오른쪽 서브트리가 되게했다 - 연산 2

```
ChangeRightSubTree(pNode,GetLeftSubTree(cNode)); // 연산 2
ChangeLeftSubTree(cNode,pNode); // 연산 1
```

<aside>
💡 CN의 왼쪽 서브 트리의 이동이 우선이기에 연산2가 선행 되어야한다!그렇지 않다면 연산1에 의해서 CN의 왼쪽 서브트리의 주소 값을 잃게된다

</aside>

## 리벨런싱이 필요한 세 번째 상태와 LR회전

![Untitled](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/e7bd65c3-3304-4747-8703-e7fdcbb804e7/Untitled.png)

- LR상태를 한 번의 회전으로 균형이 잡히는 LL상태나 RR상태로 일단 바꾼다.

![Untitled](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/156050b1-e108-4e9f-8907-875d4841a4c7/Untitled.png)

### RR회전의 부수적인 효과

1. 부모 노드와 자식 노드의 관계가 바뀌었다.
2. 오른쪽으로 형성되었던 부모와 자식의 관계가 왼쪽으로 바뀌었다.

### LR상태를 RR회전 하는 과정

![Untitled](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/ddae258c-fbd8-4984-8257-a4b24c8f3aa1/Untitled.png)

### RR회전한 후 LL회전

![Untitled](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/cf2a365b-c98d-4629-aeeb-2e44831cb9d6/Untitled.png)

<aside>
💡 루트 노드에서 왼쪽 서브트리를 때고 RR회전을 시킨후 다시 붙이고 LL회전을 하는것이 끝이다

</aside>

## 리밸런싱이 필요한 네 번째 상태와 RL회전

- RL상태는 LR상태의 반대일 뿐

![Untitled](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/61026340-abe5-465f-b0f3-a006e0a39095/Untitled.png)

![Untitled](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/e4322f69-0d16-4f29-9107-f1cd228d5a1a/Untitled.png)

<aside>
💡 LR회전 : 부분적 RR회전에 이어서 LL회전
RL회전 : 부분적 LL회전에 이어서 RR회전

</aside>
