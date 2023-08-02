/// Quickperm LOL
fn quickperm(nums: &mut Vec<i32>) -> Vec<Vec<i32>> {
    let mut perms = vec![nums.clone()];
    let mut pointers: Vec<_> = (0..nums.len() + 1).collect();
    let mut i = 1;

    while i < nums.len() {
        pointers[i] -= 1;
        let j = if i % 2 == 0 { 0 } else { pointers[i] };
        nums.swap(i, j);
        perms.push(nums.clone());
        i = 1;

        while pointers[i] == 0 {
            pointers[i] = 1;
            i += 1;
        }
    }

    perms
}

/// Recursively finds all permutations for an array of numbers.
fn permutations(nums: &mut Vec<i32>, start: usize, perms: &mut Vec<Vec<i32>>) {
    if start == nums.len() {
        perms.push(nums.clone());

        return 
    }

    for i in start..nums.len() {
        nums.swap(start, i);
        permutations(nums, start + 1, perms);
        nums.swap(start, i);
    }
}

/// Given an array nums of distinct integers, return all the possible permutations.
/// You can return the answer in any order.
pub fn permute(mut nums: Vec<i32>) -> Vec<Vec<i32>> {
    let mut perms = Vec::new();
    permutations(&mut nums, 0, &mut perms);

    return perms;
}
