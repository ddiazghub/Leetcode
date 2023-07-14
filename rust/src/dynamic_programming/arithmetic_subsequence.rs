use std::collections::HashMap;

/// Given an integer array arr and an integer difference,
/// return the length of the longest subsequence in arr which
/// is an arithmetic sequence such that the difference between
/// adjacent elements in the subsequence equals difference.
/// 
/// A subsequence is a sequence that can be derived from arr by
/// deleting some or no elements without changing the order of
/// the remaining elements.
pub fn longest_subsequence(arr: Vec<i32>, difference: i32) -> i32 {
    let mut subsequences: HashMap<i32, i32> = HashMap::new();

    for value in arr {
        match subsequences.get(&(value - difference)) {
            Some(&len) if *subsequences.get(&value).unwrap_or(&0) < len + 1 => subsequences.insert(value, len + 1),
            None => subsequences.insert(value, 1),
            _ => None
        };
    }

    subsequences.into_values()
        .map(|len| len as i32)
        .max()
        .unwrap()
}
