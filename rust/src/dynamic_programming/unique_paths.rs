/// You are given an m x n integer array grid. There is a robot initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.
/// 
/// An obstacle and space are marked as 1 or 0 respectively in grid. A path that the robot takes cannot include any square that is an obstacle.
/// 
/// Return the number of possible unique paths that the robot can take to reach the bottom-right corner.
/// 
/// The testcases are generated so that the answer will be less than or equal to 2 * 109.
pub fn unique_paths_with_obstacles(obstacle_grid: Vec<Vec<i32>>) -> i32 {
    let rows = obstacle_grid.len();
    let cols = obstacle_grid[0].len();
    let mut memory: Vec<Vec<i32>> = vec![vec![0; cols + 1]; rows + 1];
    memory[rows][cols - 1] = 1;

    for row in (0..rows).rev() {
        for col in (0..cols).rev() {
            memory[row][col] = match obstacle_grid[row][col] {
                1 => 0,
                _ => memory[row + 1][col] + memory[row][col + 1]
            };
        }
    }

    memory[0][0]
}
