// This problem was asked by Jane Street.
//
// cons(a, b) constructs a pair, and car(pair) and cdr(pair) returns the first
// and last element of that pair. For example, car(cons(3, 4)) returns 3, and
// cdr(cons(3, 4)) returns 4.
//
// Given this implementation of cons:
//
// def cons(a, b):
//     return lambda f : f(a, b)
// Implement car and cdr.

function cons(a, b) {
  return f => f(a, b);
}

function car(pair) {
  // Pair is a function that takes a function and calls it on two values a and
  // b. Therefore, call pair with a function that takes a and b and returns a.
  return pair((a, b) => a);
}

function cdr(pair) {
  // Same as car, except the lambda function we pass returns b instead of a.
  return pair((a, b) => b);
}