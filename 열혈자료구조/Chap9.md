# 1. 우선순위 큐의 이해

## 우선순위 큐란?

- 들어간 순서에 상관없이 우선순위가 높은 데이터가 먼저 나오는 자료구조

### 우선순위 큐의 구현방법

1. 배열을 기반으로 구현하는방법
2. 연결리스트를 기반으로 구현하는 방법
3. 힙을 이용하여 구현하는 방법

### 배열과 사용할 때의 단점

- 데이터를 삽입 삭제하는 과정에서 데이터를 한칸씩 밀거나 당기는 과정이 필요하다
- 최악의 경우 삽입의 위치를 찾기 위해 배열에 저장된 모든 데이터와 우선순위의 비교를 해야한다

![Untitled](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/5529828b-b5db-457e-b754-b65fae5681b0/Untitled.png)

### 연결리스트를 기반으로 구현할 때의 단점

- 최악의 경우 삽입의 위치를 찾기 위해 리스트에 저장된 모든 데이터와 우선순위의 비교를 해야한다

![Untitled](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/652cfbbd-8058-48dc-a957-967bf67129cd/Untitled.png)

## 힙(Heap)

- 부모노드가 자식노드보다 값이 큰 완전 이진 트리
- 반정렬 상태
    - 큰 값이 상위레벨에 있고 작은 값이 하위 레벨에 있는 정도
    - 부모 노드의 키 값이 자식 노드의 키 값보다 항상 큰(작은) 이진 트리
- 힙 트리는 중복된 값을 허용한다
- 영단어 Heap: 무엇인가 차곡차곡 쌓아 올린 더미
    
    ![Untitled](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/c50c8dbc-6b8a-4baf-80fc-1d6a6db7f030/Untitled.png)
    

### 힙의 종류

- 최대 힙 (max heap)
    - 루트 노드로 올라갈수록 저장된 값이 커지는 완전 이진트리

![Untitled](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/e1b1a76e-e8b1-476a-baf3-38078907b79a/Untitled.png)

- 최소 힙 (min heap)
    - 루트 노드로 올라갈수록 저장된 값이 작아지는 완전 이진 트리

![Untitled](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/b53bea67-5a30-47ee-b9db-ac034f3e912c/Untitled.png)

# 2. 힙의 구현과 우선순위 큐의 완성

## 최소 힙에서 무조건 성립하는 식

- 자식 노드 데이터의 우선순위 ≤ 부모 노드 데이터의 우선순위

## 데이터 추가 과정

1. 추가할 데이터가 제일 낮다고 가정하여 마지막 위치에 저장
2. 부모노드와 우선순위를 비교하여 위치를 바꿔야한다면 바꿈
3. 계속 1번부터 반복

![Untitled](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/3db3a4e8-1ebc-48e8-bd80-6fd40d2a8d87/Untitled.png)

![Untitled](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/6cb7a3ca-56ff-42b9-9af8-e57f2b065a69/Untitled.png)

![Untitled](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/a13a8fd0-5a4a-425c-bd84-fbe99fb37380/Untitled.png)

## 데이터 삭제 과정

1. 루트노드 삭제
2. 마지막 노드를 루트 노드로 옮김
3. 자식노드와 비교를하여 우선순위가 더 높은 자식노드와 교환
4. 자식노드보다 우선순위가 클 때까지 2번부터 반복

![Untitled](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/7b37aee3-24f0-49c1-a697-d1f9c453f0a4/Untitled.png)

![Untitled](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/3a490184-3d60-4195-836a-e899bb8a18d2/Untitled.png)

![Untitled](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/ef816bb4-9074-4abe-9b82-b21d8bbed5b5/Untitled.png)

![Untitled](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/e336c149-94f6-4436-b12b-3393609d4eaa/Untitled.png)

![Untitled](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/b5c8d422-0663-4f60-9075-90cd25e11cea/Untitled.png)

![Untitled](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/abd21538-d90d-4709-9cc8-0187ef70dacd/Untitled.png)

## 시간복잡도

### 배열 기반

- 삽입 : $O(n)$
- 삭제 : $O(1)$

### 연결리스트 기반

- 삽입 : $O(n)$
- 삭제 : $O(1)$

### 힙 기반

- 삽입 : $O$($log_2n$)
- 삭제 : $O$($log_2n$)