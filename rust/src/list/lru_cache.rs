use std::collections::HashMap;

/// LRU Cache node. These are basically doubly linked list nodes where the elements
/// are ordered based on how recently they were used.
struct CacheNode {
    /// Data contained in the node.
    value: i32,
    /// Next node. The first node which was used after the current node.
    previous: Option<i32>,
    /// Previous node. The last node which was used before the current node.
    next: Option<i32>
}

impl CacheNode {
    /// Creates a new node.
    fn new(value: i32, previous: Option<i32>, next: Option<i32>) -> Self {
        Self {
            value,
            previous,
            next
        }
    }
}

/// A LRU (Least recently used) cache. It is based on a linked HashMap (Combination of
/// a doubly linked list and a HashMap) where the elements are ordered by how recently
/// they where used based on their position in the linked list (The list's head is the
/// least recently used element while the list's tail is the most recently used element)
/// Each hashmap value is a list node having keys belonging to the next and previous element
/// in the linked list.
struct LRUCache {
    /// Maximum number of elements that the cache can store.
    capacity: usize,
    /// Least recently used element.
    head: Option<i32>,
    /// Most recently used element.
    tail: Option<i32>,
    /// HashMap which stores keys and list nodes.
    cache: HashMap<i32, CacheNode>
}

impl LRUCache {
    /// Creates a new cache with the given capacity.
    fn new(capacity: i32) -> Self {
        Self {
            capacity: capacity as usize,
            head: None,
            tail: None,
            cache: HashMap::new()
        }
    }
    
    /// Removes an element from the cache and returns the value.
    /// Removing an element may mean it is being used and needs to be moved
    /// to the end of the list as the most recently used element.
    fn remove(&mut self, key: i32) -> Option<i32> {
        self.cache.remove(&key).map(|node| {
            match (node.previous, node.next) {
                (None, None) => {
                    self.head = None;
                    self.tail = None;
                },
                (Some(previous), None) => {
                    self.tail = Some(previous);
                    self.cache.get_mut(&previous).unwrap().next = None;
                },
                (None, Some(next)) => {
                    self.head = Some(next);
                    self.cache.get_mut(&next).unwrap().previous = None;
                },
                (Some(previous), Some(next)) => {
                    self.cache.get_mut(&previous).unwrap().next = node.next;
                    self.cache.get_mut(&next).unwrap().previous = node.previous;
                }
            }

            node.value
        })
    }

    /// Adds an element to the cache as the most recently used element.
    fn add(&mut self, key: i32, value: i32) {
        if self.cache.contains_key(&key) {
            self.remove(key);
        } else if self.cache.len() == self.capacity {
            self.remove(self.head.unwrap());
        }

        let previous = if self.cache.len() == 0 {
            self.head = Some(key);

            None
        } else {
            let tail = self.tail.unwrap();
            self.cache.get_mut(&tail).unwrap().next = Some(key);

            Some(tail)
        };

        let node = CacheNode::new(value, previous, None);
        self.tail = Some(key);
        self.cache.insert(key, node);
    }

    /// Gets an element from the LRU cache. This first moves the element to the end of the list
    /// before returning it.
    fn get(&mut self, key: i32) -> i32 {
        match self.remove(key) {
            Some(value) => {
                self.add(key, value);
                value
            },
            None => -1
        }
    }
    
    /// Adds an element to the cache.
    fn put(&mut self, key: i32, value: i32) {
        self.add(key, value);
    }
}

#[cfg(test)]
mod tests {
    use super::LRUCache;

    #[test]
    fn test1() {
        let mut cache = LRUCache::new(2);
        cache.put(2, 1);
        cache.put(2, 2);
        assert_eq!(cache.get(2), 2);
        cache.put(1, 1);
        cache.put(4, 1);
        assert_eq!(cache.get(2), -1);
    }
}
