use std::cmp;

/// Recursively finds out the game's score using the minimax algorithm.
/// Returns the final score given that both players played optimally.
pub fn minimax_recursive(nums: &Vec<i32>, first: usize, last: usize, player1: bool, score: i32) -> i32 {
    if first == last {
        return score + if nums.len() % 2 == 0 {
            -nums[first]
        } else {
            nums[first]
        };
    }

    let left = nums[first];
    let right = nums[last];

    let (new_scores, min_max): ([i32; 2], Box<dyn Fn(i32, i32) -> i32>) = if player1 {
        ([score + left, score + right], Box::new(cmp::max))
    } else {
        ([score - left, score - right], Box::new(cmp::min))
    };

    let next = !player1;

    min_max(
        minimax_recursive(nums, first + 1, last, next, new_scores[0]),
        minimax_recursive(nums, first, last - 1, next, new_scores[1])
    )
}

/// Iteratively finds out the game's score with the minimax algorithm by using dynamic programming.
/// Returns the final score given that both players played optimally.
pub fn minimax(nums: &Vec<i32>) -> i32 {
    let last_turn = nums.len() % 2 > 0;
    let mut memory: Vec<Vec<i32>> = Vec::new();

    for i in 0..nums.len() {
        let size = nums.len() - i;
        memory.push(vec![0; size]);
        memory[i][0] = if last_turn { nums[i] } else { -nums[i] };
    }

    for i in (0..nums.len() - 1).rev() {
        let mut player1 = !last_turn;

        for j in 1..memory[i].len() {
            let left = memory[i + 1][j - 1];
            let right = memory[i][j - 1];
            
            memory[i][j] = if player1 {
                (left + nums[i]).max(right + nums[j + i])
            } else {
                (left - nums[i]).min(right - nums[j + i])
            };

            player1 = !player1;
        }
    }

    memory[0][nums.len() - 1]

}

/// You are given an integer array nums. Two players are playing a game with this array: player 1 and player 2.
/// 
/// Player 1 and player 2 take turns, with player 1 starting first. Both players start the game with a score of 0. At each turn, the player takes one of the numbers from either end of the array (i.e., nums[0] or nums[nums.length - 1]) which reduces the size of the array by 1. The player adds the chosen number to their score. The game ends when there are no more elements in the array.
/// 
/// Return true if Player 1 can win the game. If the scores of both players are equal, then player 1 is still the winner, and you should also return true. You may assume that both players are playing optimally.
pub fn predict_the_winner(nums: Vec<i32>) -> bool {
    // minimax_recursive(&nums, 0, nums.len() - 1, true, 0) >= 0
    minimax(&nums) >= 0
}

#[cfg(test)]
mod tests {
    use super::predict_the_winner;

    #[test]
    fn test1() {
        let nums = vec![1, 5, 2];
        let result = predict_the_winner(nums);
        assert_eq!(result, false);
    }

    #[test]
    fn test2() {
        let nums = vec![1, 5, 233, 7];
        let result = predict_the_winner(nums);
        assert_eq!(result, true);
    }

    #[test]
    fn test3() {
        let nums = vec![1, 5, 2, 4, 6];
        let result = predict_the_winner(nums);
        assert_eq!(result, true);
    }
}
