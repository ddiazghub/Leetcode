// COUNTER I
// Given an integer n, return a counter function. This counter function initially returns n and then returns
// more than the previous value every subsequent time it is called (n, n + 1, n + 2, etc).
function createCounter(n: number): () => number {
  return function () {
    return n++;
  };
}

/**
 * const counter = createCounter(10)
 * counter() // 10
 * counter() // 11
 * counter() // 12
 */

// COUNTER II
// Write a function createCounter. It should accept an initial integer init.
// It should return an object with three functions.
//
// The three functions are:
//
// increment() increases the current value by 1 and then returns it.
// decrement() reduces the current value by 1 and then returns it.
// reset() sets the current value to init and then returns it.
type ReturnObj = {
  increment: () => number;
  decrement: () => number;
  reset: () => number;
};

function createCounter(init: number): ReturnObj {
  let current = init;

  const increment = () => ++current;
  const decrement = () => --current;

  const reset = () => {
    current = init;

    return current;
  };

  return {
    increment,
    decrement,
    reset,
  };
}

/**
 * const counter = createCounter(5)
 * counter.increment(); // 6
 * counter.reset(); // 5
 * counter.decrement(); // 4
 */
