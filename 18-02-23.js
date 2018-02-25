// This problem was asked by Uber.
//
// Given an array of integers, return a new array such that each element at
// index i of the new array is the product of all the numbers in the original
// array except the one at i. Solve it without using division and in O(n) time.
//
// For example, if our input was [1, 2, 3, 4, 5], the expected output would be
// [120, 60, 40, 30, 24]. If our input was [3, 2, 1], the expected output would
// be [2, 3, 6].

// Division solution
function solution1(arr) {
  const result = new Array(arr.length);
  const total = arr.reduce((product, num) => product *= num, 1);
  for (let num of arr) {
    result.push(total / num);
  }
  return result;
}

// O(n^2) solution
function solution2(arr) {
  const result = new Array(arr.length);
  for (let i = 0; i < arr.length; i++) {
    let product = 1;
    for (let j = 0; j < arr.length; j++) {
      if (i !== j) {
        product *= arr[j];
      }
    }
    result.push(product);
  }
  return result;
}

// Forward and backward pass O(n) solution
function solution(arr) {
  console.log('input', arr);
  const result = new Array(arr.length);

  // Forward pass:
  let before = 1;
  for (let i = 0; i < arr.length; i++) {
    result[i] = before;
    before *= arr[i];
  }

  console.log('result', result);

  // Backward pass:
  let after = 1;
  let afterArr = new Array();
  for (let i = arr.length - 1; i >= 0; i--) {
    afterArr.unshift(after);
    result[i] *= after;
    after *= arr[i];
  }
  console.log('after', afterArr);
  return result;
}

// console.log(solution([1,2,3,4,5]));
console.log(solution([3,2,1]));
console.log(solution([2,3,4]));