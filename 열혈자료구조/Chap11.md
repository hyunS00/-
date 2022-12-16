# 1. 탐색의 이해와 보간 탐색

## 탐색

- 데이터를 찾는 방법

## 보간 탐색

- 이진 탐색은 중앙에 위치한 데이터를 탐색한 후, 이를 기준으로 탐색대상을 반씩 줄여나가면서 탐색을 진행하는 알고리즘
- 보간 탐색은 이진 탐색의 비효율성을 개선시킨 알고리즘
- 탐색대상이 있을곳 같은데 부터 탐색 시작

### 이진탐색

![Untitled](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/11731f7a-625e-4047-8437-9ed9d5b6b932/Untitled.png)

### 보간탐색

![Untitled](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/f4e4f8ac-696f-43d2-a1a3-177cda896a11/Untitled.png)

- 데이터의 값과 그 데이터가 저장된 위치의 인덱스 값이 비례한다고 가정한 비례식
  $A:Q=(high-low):(s-low)$
- s에 대한 비례식
  $s=\frac{Q}{A}(high-low)+low$
- arr[s]를 x라하고 Q와 A에 arr대입
  $s=\frac{x-arr[low]}{arr[high]-arr[low]}(high-low)+low$

### 보간탐색의 단점

- 오차율을 최소화하기 위해서 정수형 나눗셈이 아닌 실수형 나눗셈을 진행한다

```jsx
function iSearch(arr, first, last, target) {
  let mid;

  if (arr[first] > target || arr[last] < target) {
    return -1;
  }

  mid =
    Math.floor((target - arr[first]) / (arr[last] - arr[first])) *
      (last - first) +
    first;

  if (arr[mid] == target) {
    return mid;
  } else if (target < arr[mid]) {
    return iSearch(arr, first, mid - 1, target);
  } else {
    return iSearch(arr, mid + 1, last, target);
  }
}

let arr = [1, 3, 5, 7, 9];
let idx;

idx = iSearch(arr, 0, arr.length - 1, 7);
console.log(idx);
idx = iSearch(arr, 0, arr.length - 1, 10);
console.log(idx);
idx = iSearch(arr, 0, arr.length - 1, 2);
console.log(idx);
```

```jsx
function interpolationSearch(arr, key) {
  const length = arr.length - 1;
  let low = 0;
  let high = length;
  let position = -1;
  let delta = -1;

  // Because the array is sorted the key must be between low and high
  while (low <= high && key >= arr[low] && key <= arr[high]) {
    delta = (key - arr[low]) / (arr[high] - arr[low]);
    position = low + Math.floor((high - low) * delta);

    // Target found return its position
    if (arr[position] === key) {
      return position;
    }

    // If the key is larger then it is in the upper part of the array
    if (arr[position] < key) {
      low = position + 1;
      // If the key is smaller then it is in the lower part of the array
    } else {
      high = position - 1;
    }
  }

  return -1;
}
```

## 시간 복잡도

- Best case : O(1)
- Worst case : O(n)
- 데이터가 균일하게 분포한 경우 O(log(log(n))

# 이진 탐색 트리

## 조건

- 이진 탐색 트리의 노드에 저장된 키는 유일
- 루트 노드의 키가 왼쪽 서브 트리를 구성하는 어떠한 노드의 키보다 크다
- 루트 노드의 키가 오른쪽 서브 트리를 구성하는 어떠한 노드의 키보다 작다
- 왼쪽과 오른쪽 서브 트리도 이진 탐색 트리다

![Untitled](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/6379d810-f8ef-49da-943f-9fec84fbbcfc/Untitled.png)

### 왼쪽 자식 노드의 키 < 부모 노드의 키 < 오른쪽 자식 노드의 키

## 삽입과 탐색

![Untitled](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/ca13ee98-1aed-4ff9-b0d5-b487e950fc95/Untitled.png)

## 삭제

### 삭제 상황

- 상황1 : 삭제할 노드가 단말 노드인 경우
- 상황2 : 삭제할 노드가 하나의 자식 노드를 갖는 경우
- 상황3 : 삭제할 노드가 두 개의 자식 노드를 갖는 경우

```jsx
/* Binary Search Tree!!
 *
 * Nodes that will go on the Binary Tree.
 * They consist of the data in them, the node to the left, the node
 * to the right, and the parent from which they came from.
 *
 * A binary tree is a data structure in which an element
 * has two successors(children). The left child is usually
 * smaller than the parent, and the right child is usually
 * bigger.
 */

// class Node
const Node = (function Node() {
  // Node in the tree
  function Node(val) {
    this.value = val;
    this.left = null;
    this.right = null;
  }

  // Search the tree for a value
  Node.prototype.search = function (val) {
    if (this.value === val) {
      return this;
    } else if (val < this.value && this.left !== null) {
      return this.left.search(val);
    } else if (val > this.value && this.right !== null) {
      return this.right.search(val);
    }
    return null;
  };

  // Visit a node
  Node.prototype.visit = function (output = (value) => console.log(value)) {
    // Recursively go left
    if (this.left !== null) {
      this.left.visit();
    }
    // Print out value
    output(this.value);
    // Recursively go right
    if (this.right !== null) {
      this.right.visit();
    }
  };

  // Add a node
  Node.prototype.addNode = function (n) {
    if (n.value < this.value) {
      if (this.left === null) {
        this.left = n;
      } else {
        this.left.addNode(n);
      }
    } else if (n.value > this.value) {
      if (this.right === null) {
        this.right = n;
      } else {
        this.right.addNode(n);
      }
    }
  };

  // remove a node
  Node.prototype.removeNode = function (val) {
    if (val === this.value) {
      if (!this.left && !this.right) {
        return null;
      } else {
        if (this.left) {
          const leftMax = maxVal(this.left);
          this.value = leftMax;
          this.left = this.left.removeNode(leftMax);
        } else {
          const rightMin = minVal(this.right);
          this.value = rightMin;
          this.right = this.right.removeNode(rightMin);
        }
      }
    } else if (val < this.value) {
      this.left = this.left && this.left.removeNode(val);
    } else if (val > this.value) {
      this.right = this.right && this.right.removeNode(val);
    }
    return this;
  };

  // find maximum value in the tree
  const maxVal = function (node) {
    if (!node.right) {
      return node.value;
    }
    return maxVal(node.right);
  };

  // find minimum value in the tree
  const minVal = function (node) {
    if (!node.left) {
      return node.value;
    }
    return minVal(node.left);
  };
  // returns the constructor
  return Node;
})();

// class Tree
const Tree = (function () {
  function Tree() {
    // Just store the root
    this.root = null;
  }

  // Inorder traversal
  Tree.prototype.traverse = function () {
    if (!this.root) {
      // No nodes are there in the tree till now
      return;
    }
    this.root.visit();
  };

  // Start by searching the root
  Tree.prototype.search = function (val) {
    const found = this.root.search(val);
    if (found !== null) {
      return found.value;
    }
    // not found
    return null;
  };

  // Add a new value to the tree
  Tree.prototype.addValue = function (val) {
    const n = new Node(val);
    if (this.root === null) {
      this.root = n;
    } else {
      this.root.addNode(n);
    }
  };

  // remove a value from the tree
  Tree.prototype.removeValue = function (val) {
    // remove something if root exists
    this.root = this.root && this.root.removeNode(val);
  };

  // returns the constructor
  return Tree;
})();
```
