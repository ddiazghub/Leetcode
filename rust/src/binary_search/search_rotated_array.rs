use std::cmp::Ordering;

/// Uses binary search to find a value using the given search function.
fn binary_search(nums: &[i32], mut start: usize, mut end: usize, search_function: impl Fn(usize) -> Ordering) -> Option<usize> {
    while start < end {
        let mid = start + (end - start) / 2;

        match search_function(mid) {
            Ordering::Less => start = mid + 1,
            Ordering::Equal => return Some(mid),
            Ordering::Greater => end = mid
        };
    }

    (search_function(start) == Ordering::Equal)
        .then_some(start)
}

fn find_pivot(nums: &[i32], last: i32, mid: usize) -> Ordering {
    match nums[mid].cmp(&last) {
        Ordering::Less | Ordering::Equal if nums[mid - 1] > nums[mid] => Ordering::Equal,
        Ordering::Less | Ordering::Equal => Ordering::Greater,
        _ => Ordering::Less
    }
}

fn pivot_search(nums: &[i32]) -> usize {
    binary_search(
        &nums,
        1,
        nums.len() - 1,
        |mid| find_pivot(&nums, nums[nums.len() - 1], mid)
    ).unwrap()
}

fn index_range(nums: &[i32], target: i32) -> (usize, usize) {
    let last = nums.len() - 1;

    if nums[0] < nums[last] {
        (0, last)
    } else {
        let pivot = pivot_search(&nums);

        if (nums[pivot]..=nums[last]).contains(&target) {
            (pivot, last)
        } else {
            (0, pivot - 1)
        }
    }
}

/// There is an integer array nums sorted in ascending order (with distinct values).
/// 
/// Prior to being passed to your function, nums is possibly rotated at an unknown pivot index k (1 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].
/// 
/// Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.
/// 
/// You must write an algorithm with O(log n) runtime complexity.
pub fn search(nums: Vec<i32>, target: i32) -> i32 {
    if nums.len() < 3 {
        return nums.into_iter()
            .take(2)
            .position(|num| num == target)
            .map(|index| index as i32)
            .unwrap_or(-1)
    }

    let (start, end) = index_range(&nums, target);

    binary_search(&nums, start, end, |mid| nums[mid].cmp(&target))
        .map(|index| index as i32)
        .unwrap_or(-1)
}

pub fn search2(nums: Vec<i32>, target: i32) -> bool {
    nums.into_iter().any(|num| num == target)
}

#[cfg(test)]
mod tests1 {
    use super::search;

    #[test]
    fn test1() {
        let nums = vec![4,5,6,7,0,1,2];
        let result = search(nums, 0);
        assert_eq!(result, 4);
    }

    #[test]
    fn test2() {
        let nums = vec![4,5,6,7,0,1,2];
        let result = search(nums, 3);
        assert_eq!(result, -1);
    }

    #[test]
    fn test3() {
        let nums = vec![1];
        let result = search(nums, 0);
        assert_eq!(result, -1);
    }

    #[test]
    fn test4() {
        let nums = vec![2,3,4,5,6,7,8,1];
        let result = search(nums, 3);
        assert_eq!(result, 1);
    }
}


#[cfg(test)]
mod tests2 {
    use super::search2;

    #[test]
    fn test1() {
        let nums = vec![1,1,1,1,1,1,1,1,1,1,1,1,1,2,1,1,1,1,1];
        let result = search2(nums, 2);
        assert_eq!(result, true);
    }
}
