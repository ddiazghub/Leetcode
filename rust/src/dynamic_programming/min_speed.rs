use std::cmp::Ordering;

#[inline]
/// Rounds a floating point number by 2 decimal places.
fn round2(number: f64) -> f64 {
    (number * 100.0).round() / 100.0
}

#[inline]
/// Applies the time formula.
fn time(distance: i32, speed: i32) -> f64 {
    distance as f64 / speed as f64
}

#[inline]
/// Applies the speed formula.
fn speed(distance: i32, time: f64) -> i32 {
    round2(distance as f64 / time).ceil() as i32
}

/// Finds the total time a commute would take if all trains traveled at the given speed.
fn total_time(distances: &[i32], speed: i32) -> f64 {
    let total: f64 = distances.into_iter()
        .take(distances.len() - 1)
        .copied()
        .map(|dist| round2(time(dist, speed).ceil()))
        .sum();

    total + time(distances[distances.len() - 1], speed)
}

/// You are given a floating-point number hour, representing the amount of time you have to reach the office. To commute to the office, you must take n trains in sequential order. You are also given an integer array dist of length n, where dist[i] describes the distance (in kilometers) of the ith train ride.
/// 
/// Each train can only depart at an integer hour, so you may need to wait in between each train ride.
/// 
/// For example, if the 1st train ride takes 1.5 hours, you must wait for an additional 0.5 hours before you can depart on the 2nd train ride at the 2 hour mark.
/// Return the minimum positive integer speed (in kilometers per hour) that all the trains must travel at for you to reach the office on time, or -1 if it is impossible to be on time.
/// 
/// Tests are generated such that the answer will not exceed 107 and hour will have at most two digits after the decimal point.
pub fn min_speed_on_time(dist: Vec<i32>, hour: f64) -> i32 {
    if (hour.ceil() as usize) < dist.len() {
        return -1;
    }

    let stops = dist.len() as i32 - 1;
    let total_dist: i32 = dist.iter().copied().sum();
    let lower_bound = speed(total_dist, hour);
    let upper_bound = speed(total_dist, hour - stops as f64).max(lower_bound + stops).min(10e7 as i32);

    let mut start = lower_bound;
    let mut end = upper_bound;

    while start < end {
        let mid = start + (end - start) / 2;

        match total_time(&dist, mid).total_cmp(&hour) {
            Ordering::Less => end = mid,
            Ordering::Equal => return mid,
            Ordering::Greater => start = mid + 1
        };
    }

    start
}

#[cfg(test)]
mod tests {
    use super::min_speed_on_time;

    #[test]
    fn test1() {
        let dist = vec![1, 3, 2];
        let result = min_speed_on_time(dist, 6.0);
        assert_eq!(result, 1);
    }

    #[test]
    fn test2() {
        let dist = vec![1, 3, 2];
        let result = min_speed_on_time(dist, 2.7);
        assert_eq!(result, 3);
    }

    #[test]
    fn test3() {
        let dist = vec![1, 3, 2];
        let result = min_speed_on_time(dist, 1.9);
        assert_eq!(result, -1);
    }

    #[test]
    fn test4() {
        let dist = vec![1, 1, 100000];
        let result = min_speed_on_time(dist, 2.01);
        assert_eq!(result, 10000000);
    }
}
