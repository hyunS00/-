# 1. 단순한 정렬 알고리즘

### 버블 정렬(Bubble Sort)

- 인접한 두 개의 데이터를 비교해가면서 진행하는 방식

![Untitled](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/883777cc-fbf4-40cb-a2cd-23e25ffa7741/Untitled.png)

![Untitled](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/d45d07ba-76cb-44cb-90dd-4df7ff6a5e0c/Untitled.png)

![Untitled](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/583ef24b-2b6e-4ed0-8a31-671bab65536e/Untitled.png)

```jsx
function bubbleSort(arr, n) {
  let i, j;
  let tmp;

  for (i = 0; i < n - 1; i++) {
    for (j = 0; j < n - i - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        tmp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = tmp;
      }
    }
  }
}

let arr = [3, 2, 4, 1];
bubbleSort(arr, 4);
console.log(arr);
```

### 버블정렬 성능평가

- 비교횟수 : 두 데이터간의 비교연산의 횟수
  - ( n-1 ) + ( n-2 ) + ( n-3 ) + . . . + 2 + 1
  - $O(n^2)$
- 이동횟수 : 위치의 변경을 위한 데이터 이동횟수
  - 최선의 경우: 0번
  - 최악의 경우: $n^2$번
- 시간복잡도: $O(n^2)$

## 선택정렬

- 오름차순으로 정렬할경우 배열중에 제일 작은 값을 선택하여 옮기고 그다음 제일 작은 값을 선택하여 옮기는 과정을 반복
- 배열 두개를 이용
- 배열 한개로 이용

![Untitled](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/20199dbe-20e8-4636-b68b-fb32479d9e58/Untitled.png)

![Untitled](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/7b5fa0de-22e1-4c76-8618-067f798f2d28/Untitled.png)

```jsx
function selecSort(arr, n) {
  let i, j;
  let max;
  let tmp;
  for (i = 0; i < n - 1; i++) {
    max = i;

    //최솟값 탐색
    for (j = i + 1; j < n; j++) {
      if (arr[j] < arr[min]) min = j;
    }

    tmp = arr[i];
    arr[i] = arr[min];
    arr[min] = tmp;
  }
}

let arr = [3, 4, 2, 1];
selecSort(arr, 4);
console.log(arr);
```

### 선택정렬 성능평가

- 비교횟수 : 두 데이터간의 비교연산의 횟수
  - ( n-1 ) + ( n-2 ) + ( n-3 ) + . . . + 2 + 1
  - $O(n^2)$
- 이동횟수 : 위치의 변경을 위한 데이터 이동횟수
  - 최선의 경우: 0번
  - 최악의 경우: 3(n-1)번
- 시간복잡도: $O(n^2)$

## 삽입정렬

- 정렬 안된 부분의 첫번째 요소를 정렬된 부분의 요소와 비교하여 삽입 함

![Untitled](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/33865efa-39d1-41cc-b893-cf54495467b9/Untitled.png)

![Untitled](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/339233a1-85d9-455e-ac6c-925fe9e3650e/Untitled.png)

```jsx
function insertSort(arr, n) {
  let i, j;
  let insData;

  for (i = 1; i < n; i++) {
    insData = arr[i];

    for (j = i - 1; j >= 0; j--) {
      if (arr[j] > insData) {
        arr[j + 1] = arr[j];
      } else {
        break;
      }
    }

    arr[j + 1] = insData;
  }
}

let arr = [5, 3, 2, 4, 1];
insertSort(arr, arr.length);
console.log(arr);
```

### 삽입정렬 성능평가

- 비교횟수
  - 1 + 2 + 3 + . . . + ( n-2 ) + ( n-1 )
  - $O(n^2)$
- 이동횟수
  - 최선의 경우: 0번
  - 최악의 경우: j+2
    - $O(n^2)$
- 시간복잡도 : $O(n^2)$

# 2. 복잡하지만 효율적인 정렬 알고리즘

## 힙 정렬 (Heap Sort)

- 최대힙을 이용하여 데이터를 모두 넣고 모두 제거

```jsx
function heapSort(arr, n) {
  let maxheap = new MaxHeap();
  let i;
  for (i = 0; i < n; i++) {
    maxheap.HInsert(arr[i]);
  }

  for (i = 0; i < n; i++) {
    arr[i] = maxheap.HDelete();
  }
}

let arr = [3, 4, 5, 1];
heapSort(arr, arr.length);

console.log(arr);
```

### 힙정렬 성능평가

- $nlog_2n$

## 병합정렬

- 복잡한 문제를 복잡하지 않은 문제로 ‘분할’ 후 ‘정복’하는 방법
- 병합정렬 단계

1. 분할
   - 문제를 분할한다
2. 정복
   - 문제를 해결한다 문제를 해결할 만큼 작지 않으면 순환호출을 이용하여 다시 분할 정복 방법을 적용한다
3. 결합
   - 해결된 결과를 결합한다

![Untitled](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/80b3e1f8-8731-4f70-90b8-dd7b88b8eba9/Untitled.png)

```jsx
function mergeSort(arr) {
  if (arr.length < 2) return arr;
  let pivot = Math.floor(arr.length / 2);
  let left = arr.slice(0, pivot);
  let right = arr.slice(pivot, arr.length);
  return merge(mergeSort(left), mergeSort(right));
}

function merge(left, right) {
  let result = [];
  while (left.length && right.length) {
    if (left[0] <= right[0]) {
      result.push(left.shift());
    } else {
      result.push(right.shift());
    }
  }
  while (left.length) result.push(left.shift());
  while (right.length) result.push(right.shift());
  return result;
}

let a1 = mergeSort([5, 2, 4, 7, 6, 1]);
```

## 퀵 정렬(Quick Sort)

![Untitled](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/c4833b64-b0ab-429b-a4d2-16a77b4787d3/Untitled.png)

```jsx
function swap(arr, idx1, idx2) {
  let tmp = arr[idx1];
  arr[idx1] = arr[idx2];
  arr[idx2] = tmp;
}

function partition(arr, left, right) {
  let pivot = arr[left];
  let low = left + 1;
  let high = right;

  while (low <= high) {
    while (pivot >= arr[low] && low <= right) {
      low++;
    }

    while (pivot < arr[high] && high >= left + 1) {
      high--;
    }

    if (low <= high) {
      swap(arr, low, high);
    }
  }

  swap(arr, left, high);
  return high;
}

function quickSort(arr, left, right) {
  if (left <= right) {
    let pivot = partition(arr, left, right);
    quickSort(arr, left, pivot - 1);
    quickSort(arr, pivot + 1, right);
  }
}
```

- 분할횟수: $log_2n$
- 요소n개의 분할횟수 : $nlog_2n$
- 최악의 시간 복잡도 : $O(n^2)$ → 자료들이 이미 정렬되어있는경우

## 기수정렬(Radix Sort)

[3, 54, 7, 6103, 1045, 365, 356]

![Untitled](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/65245d93-721d-48da-99f8-e4069672b0c3/Untitled.png)

[3, 6103, 54, 1045, 365, 356, 7]

![Untitled](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/4be25c82-2309-4c2c-aae4-1a7f56a0ffdc/Untitled.png)

[3, 6103, 7, 1045, 54, 356, 365]

![Untitled](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/6bfd900f-6d8e-486f-94f0-13c0730097ad/Untitled.png)

[3, 7, 1045, 54, 6103, 356, 365]

![Untitled](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/8be853cb-284b-4db3-8a90-7362c1a43a51/Untitled.png)

[3, 7, 54, 356, 365, 1045, 6103]

```jsx
//자릿수 가져옴
function getDigit(num, i) {
  return Math.floor(Math.abs(num) / Math.pow(10, i)) % 10;
}

function digitCount(num) {
  return num.toString().length;
}

function mostDigits(nums) {
  let maxDigits = 0;
  for (let i = 0; i < nums.length; i++) {
    maxDigits = Math.max(maxDigits, digitCount(nums[i]));
  }
  return maxDigits;
}

function radixSort(nums) {
  const maxDigits = mostDigits(nums);

  for (let k = 0; k < maxDigits; k++) {
    let digitBuckets = Array.from({ length: 10 }, () => []);
    for (let i = 0; i < nums.length; i++) {
      let digit = getDigit(nums[i], k);
      digitBuckets[digit].push(nums[i]);
    }
    nums = [].concat(...digitBuckets);
  }
  [1, 12, 3];
  return nums;
}

let arr = [3, 6103, 7, 1045, 54, 356, 365];

console.log(radixSort(arr));
```

### 기수정렬 성능평가

- 데이터 연산 횟수
  - 최대 자릿수 \* 배열의 갯수
  - $O(ln)$
