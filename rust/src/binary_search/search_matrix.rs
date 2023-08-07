use std::cmp::Ordering;

/// You are given an m x n integer matrix matrix with the following two properties:
/// 
/// Each row is sorted in non-decreasing order.
/// The first integer of each row is greater than the last integer of the previous row.
/// Given an integer target, return true if target is in matrix or false otherwise.
/// 
/// You must write a solution in O(log(m * n)) time complexity.
pub fn search_matrix(matrix: Vec<Vec<i32>>, target: i32) -> bool {
    let (n, m) = (matrix.len(), matrix[0].len());

    let mut start = 0;
    let mut end = n - 1;

    // First, search the row where the target may be in.
    let row = loop {
        if start == n - 1 {
            break n - 1;
        } else if start == end {
            return false;
        }

        let mid = start + (end - start) / 2;

        match (matrix[mid][0].cmp(&target), matrix[mid + 1][0].cmp(&target)) {
            (Ordering::Less, Ordering::Less) => start = mid + 1,
            (Ordering::Less, Ordering::Greater) => break mid,
            (Ordering::Equal, Ordering::Greater) | (Ordering::Less, Ordering::Equal) => return true,
            _ => end = mid
        };
    };

    let mut start = 0;
    let mut end = m;

    // Then, search the target in the row.
    while start < end {
        let mid = start + (end - start) / 2;

        match matrix[row][mid].cmp(&target) {
            Ordering::Less => start = mid + 1,
            Ordering::Equal => return true,
            Ordering::Greater => end = mid
        }; };

    false
}

#[cfg(test)]
mod tests {
    use super::search_matrix;

    #[test]
    fn test1() {
        let matrix = vec![vec![1,3,5,7], vec![10,11,16,20], vec![23,30,34,60]];
        let result = search_matrix(matrix, 3);
        assert_eq!(result, true);
    }

    #[test]
    fn test2() {
        let matrix = vec![vec![1], vec![3]];
        let result = search_matrix(matrix, 0);
        assert_eq!(result, false);
    }
}
