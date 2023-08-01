/// Given two integers n and k, return all possible combinations of k numbers chosen from the range [1, n].
/// 
/// You may return the answer in any order.
pub fn combine(n: i32, k: i32) -> Vec<Vec<i32>> {
    if n == 1 {
        return (1..=k).map(|i| vec![i])
            .collect();
    }

    let mut numbers: Vec<_> = (1..=k).collect();
    let mut combinations = vec![numbers.clone()];

    if n == k {
        return combinations;
    }

    'outer: loop {
        let mut i = k - 1;

        while numbers[i as usize] == n - (k - i - 1) {
            i -= 1;
        }

        let first = i as usize;
        numbers[first] = numbers[first] + 1;

        for (i, value) in (i as usize + 1..k as usize).zip(numbers[first] + 1..numbers[first] + 1 + k) {
            numbers[i] = value;
        }

        combinations.push(numbers.clone());

        if numbers[0] == n - k + 1 {
            break;
        }
    }

    combinations
}

#[cfg(test)]
mod tests {
    use std::collections::HashSet;

    use super::combine;

    #[test]
    fn test1() {
        let result: HashSet<_> = combine(4, 2).into_iter().collect();

        let expected = HashSet::from_iter([
            vec![1, 2],
            vec![1, 3],
            vec![1, 4],
            vec![2, 3],
            vec![2, 4],
            vec![3, 4]
        ]);

        assert_eq!(result, expected)
    }
}
