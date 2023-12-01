// Write a class that allows getting and setting key-value pairs,
// however a time until expiration is associated with each key.
//
// The class has three public methods:
//
// set(key, value, duration): accepts an integer key, an integer value, and a duration in milliseconds.
// Once the duration has elapsed, the key should be inaccessible.
// The method should return true if the same un-expired key already exists and false otherwise.
// Both the value and duration should be overwritten if the key already exists.
//
// get(key): if an un-expired key exists, it should return the associated value. Otherwise it should return -1.
//
// count(): returns the count of un-expired keys.
class TimeLimitedCache {
  private cache: Map<number, [number, NodeJS.Timeout]> = new Map();

  set(key: number, value: number, duration: number): boolean {
    const existed = this.cache.has(key);

    if (existed)
      clearTimeout(this.cache.get(key)![1]);

    const timer = setTimeout(() => this.cache.delete(key), duration);
    this.cache.set(key, [value, timer]);

    return existed;
  }

  get(key: number): number {
    return this.cache.get(key)?.at(0) as number ?? -1;
  }

  count(): number {
    return this.cache.size;
  }
}

/**
 * const timeLimitedCache = new TimeLimitedCache()
 * timeLimitedCache.set(1, 42, 1000); // false
 * timeLimitedCache.get(1) // 42
 * timeLimitedCache.count() // 1
 */
