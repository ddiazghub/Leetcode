/// Given an array of intervals intervals where intervals[i] = [starti, endi],
/// return the minimum number of intervals you need to remove to make the rest
/// of the intervals non-overlapping.
pub fn erase_overlap_intervals(mut intervals: Vec<Vec<i32>>) -> i32 {
    intervals.sort_unstable();
    let mut removed = 0;
    let mut previous = i32::MIN..i32::MIN + 1;

    for current in intervals {
        match (previous.contains(&current[0]), previous.contains(&current[1])) {
            (true, true) => {
                removed += 1;
                previous = current[0]..current[1]
            },
            (true, false) => removed += 1,
            _ => previous = current[0]..current[1]
        };
    }

    removed
}
