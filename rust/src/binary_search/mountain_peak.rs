/// An array arr a mountain if the following properties hold:
/// 
/// arr.length >= 3
/// There exists some i with 0 < i < arr.length - 1 such that:
/// arr[0] < arr[1] < ... < arr[i - 1] < arr[i] 
/// arr[i] > arr[i + 1] > ... > arr[arr.length - 1]
/// Given a mountain array arr, return the index i such that arr[0] < arr[1] < ... < arr[i - 1] < arr[i] > arr[i + 1] > ... > arr[arr.length - 1].
/// 
/// You must solve it in O(log(arr.length)) time complexity.
pub fn peak_index_in_mountain_array(arr: Vec<i32>) -> i32 {
    let mut start = 0;
    let mut end = arr.len();
    
    while start < end {
        let mid = start + (end - start) / 2;

        if mid == 0 || mid == arr.len() {
            return mid as i32;
        }

        let descent_left = arr[mid - 1] < arr[mid];
        let descent_right = arr[mid + 1] < arr[mid];

        if descent_left && descent_right {
            return mid as i32;
        } else if descent_left {
            start = mid + 1;
        } else {
            end = mid;
        }
    }

    start as i32
}

#[cfg(test)]
mod tests {
    use super::peak_index_in_mountain_array;

    #[test]
    fn test1() {
        let result = peak_index_in_mountain_array(vec![0, 1, 0]);
        assert_eq!(result, 1);
    }
    
    #[test]
    fn test2() {
        let result = peak_index_in_mountain_array(vec![0, 2, 1, 0]);
        assert_eq!(result, 1);
    }

    #[test]
    fn test3() {
        let result = peak_index_in_mountain_array(vec![0, 10, 5, 2]);
        assert_eq!(result, 1);
    }
}
