use std::collections::HashSet;

fn validPairs(nums: &[i32], threshold: i32) -> i32 {
    let mut index = 0;
    let mut count = 0;

    while index < nums.len() - 1 {
        if nums[index + 1] - nums[index] <= threshold {
            count += 1;
            index += 1;
        }

        index += 1;
    }

    count
}

pub fn minimize_max(mut nums: Vec<i32>, p: i32) -> i32 {
    nums.sort_unstable();

    let mut start = 0;
    let mut end = nums[nums.len() - 1] - nums[0];

    while start < end {
        let mid = start + (end - start) / 2;

        if validPairs(&nums, mid) >= p {
            end = mid;
        } else {
            start = mid + 1;
        };
    }

    start
}

fn max_pair_difference(diffs: &[(i32, usize)], pairs: usize) -> i32 {
    let mut found = HashSet::new();
    let mut count = 0;

    for &(diff, index) in diffs {
        if !(found.contains(&index) || found.contains(&(index + 1)) || found.contains(&(index - 1))) {
            count += 1;
            found.insert(index);

            if count == pairs {
                return diff;
            }
        }
    }

    i32::MAX
}

pub fn minimize_max_fail(mut nums: Vec<i32>, p: i32) -> i32 {
    if p == 0 {
        return 0;
    }

    let pairs = p as usize;
    nums.sort_unstable();

    let mut diffs: Vec<_> = nums.windows(2)
        .enumerate()
        .map(|(i, pair)| ((pair[0] - pair[1]).abs(), i + 1))
        .collect();

    diffs.sort_unstable_by_key(|diff| diff.0);

    max_pair_difference(&diffs, pairs).min(max_pair_difference(&diffs[1..], pairs))
}

#[cfg(test)]
mod tests {
    use super::minimize_max;

    #[test]
    fn test1() {
        let nums = vec![10,1,2,7,1,3];
        let result = minimize_max(nums, 2);

        assert_eq!(result, 1);
    }

    #[test]
    fn test2() {
        let nums = vec![4,2,1,2];
        let result = minimize_max(nums, 1);

        assert_eq!(result, 0);
    }

    #[test]
    fn test3() {
        let nums = vec![3,4,2,3,2,1,2];
        let result = minimize_max(nums, 3);

        assert_eq!(result, 1);
    }

    #[test]
    fn test4() {
        let nums = vec![1,1,0,3];
        let result = minimize_max(nums, 2);

        assert_eq!(result, 2);
    }

    #[test]
    fn test5() {
        let nums = vec![6,2,8,5,2,4,5];
        let result = minimize_max(nums, 3);

        assert_eq!(result, 1);
    }
}
