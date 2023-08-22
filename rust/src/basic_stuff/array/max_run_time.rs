use std::cmp::Reverse;

/// You have n computers. You are given the integer n and a 0-indexed integer array batteries where the ith battery can run a computer for batteries[i] minutes. You are interested in running all n computers simultaneously using the given batteries.
/// 
/// Initially, you can insert at most one battery into each computer. After that and at any integer time moment, you can remove a battery from a computer and insert another battery any number of times. The inserted battery can be a totally new battery or a battery from another computer. You may assume that the removing and inserting processes take no time.
/// 
/// Note that the batteries cannot be recharged.
/// 
/// Return the maximum number of minutes you can run all the n computers simultaneously.
pub fn max_run_time(n: i32, mut batteries: Vec<i32>) -> i64 {
    let size = n as usize;
    batteries.sort_unstable_by_key(|item| Reverse(*item));

    let mut runtimes: Vec<_> = batteries.iter()
        .take(size)
        .copied()
        .map(i64::from)
        .collect();

    let mut power: i64 = batteries.into_iter()
        .skip(size)
        .map(i64::from)
        .sum();

    if runtimes[0] != runtimes[size - 1] {
        for start in (1..size).rev() {
            let target = runtimes[start - 1] - runtimes[start];

            if target == 0 {
                continue;
            }

            let split = power as i64 / (size - start) as i64;

            if split < target {
                return runtimes[size - 1] + split
            }

            for i in start..size {
                power -= runtimes[i - 1] - runtimes[i];
                runtimes[i] = runtimes[i - 1];
            }
        }
    }

    runtimes[size - 1] + power / n as i64
}

#[cfg(test)]
mod tests {
    use super::max_run_time;

    #[test]
    fn test1() {
        let batteries = vec![3, 3, 3];
        let result = max_run_time(2, batteries);
        assert_eq!(result, 4);
    }
    
    #[test]
    fn test2() {
        let batteries = vec![1, 1, 1, 1];
        let result = max_run_time(2, batteries);
        assert_eq!(result, 2);
    }

    #[test]
    fn test3() {
        let batteries = vec![10, 10, 3, 5];
        let result = max_run_time(3, batteries);
        assert_eq!(result, 8);
    }

    #[test]
    fn test4() {
        let batteries = vec![10, 10, 6, 9, 3];
        let result = max_run_time(3, batteries);
        assert_eq!(result, 12);
    }
}
