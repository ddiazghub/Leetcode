#[derive(Clone, Copy)]
enum Partition {
    Value(i32, i32),
    Increasing(i32, i32)
}

pub fn valid_partition(nums: Vec<i32>) -> bool {
    let mut current = Partition::Value(nums[0], 1);

    for num in nums {
        current = match current {
            Partition::Value(value, count) => match true {
                _ if num == value => Partition::Value(value, count + 1),
                _ if num == value + 1 => Partition::Increasing(num, 2),
                _ => Partition::Value(num, 1)
            },
            Partition::Increasing(last, count) => match true {
                _ if num == last + 1 => Partition::Increasing(num, count + 1),
                _ if num == last => Partition::Value(num, 2),
                _ => Partition::Value(num, 1)
            }
        }
    }

    true
}
