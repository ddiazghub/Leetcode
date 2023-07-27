/// Given an integer array nums, return the number of longest increasing subsequences.
///
/// Notice that the sequence has to be strictly increasing.
pub fn find_number_of_lis(nums: Vec<i32>) -> i32 {
    let size = nums.len();
    let mut lengths = vec![1; size];
    let mut counts = vec![1; size];

    for i in 1..size {
        for j in 0..i {
            if nums[i] > nums[j] {
                let new_len = lengths[j] + 1;

                if lengths[i] == new_len {
                    counts[i] += counts[j];
                } else if lengths[i] < new_len {
                    lengths[i] = new_len;
                    counts[i] = counts[j];
                }
            }
        }
    }

    let max_len = lengths.iter()
        .copied()
        .max()
        .unwrap();

    lengths.into_iter()
        .zip(counts.into_iter())
        .filter(|&(length, _)| length == max_len)
        .map(|(_, count)| count)
        .sum()
}
