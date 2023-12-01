function *flatten<T, I extends Iterable<T>>(array: I[]) {
  for (const iter of array) {
    for (const element of iter) {
      yield element;
    }
  }
}

function arrayStringsAreEqual(word1: string[], word2: string[]): boolean {
  const first = [...flatten(word1)];
  const second = [...flatten(word2)];

  if (first.length != second.length)
    return false;

  for (let i = 0; i < first.length; i++)
    if (first[i] != second[i])
      return false;

  return true;
}
