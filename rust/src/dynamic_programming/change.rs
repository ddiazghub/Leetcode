/// Recursively find the number of coin combinations to pay for the specified amount of change.
fn change_recursive(coins: &[i32], current: usize, amount: i32, memory: &mut [Vec<i32>]) -> i32 {
    match amount {
        0 => return 1,
        ..=-1 => return 0,
        1.. => {
            if current == coins.len() {
                return 0;
            }

            let a = amount as usize;

            if memory[current][a] != -1 {
                return memory[current][a];
            }

            let change = change_recursive(coins, current + 1, amount, memory) + change_recursive(coins, current, amount - coins[current], memory);
            memory[current][a] = change;

            change
        }
    }
}

/// You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.
/// 
/// Return the number of combinations that make up that amount. If that amount of money cannot be made up by any combination of the coins, return 0.
/// 
/// You may assume that you have an infinite number of each kind of coin.
/// 
/// The answer is guaranteed to fit into a signed 32-bit integer.
pub fn change(amount: i32, coins: Vec<i32>) -> i32 {
    let amount_usize = amount as usize;
    let mut memory = vec![vec![-1; amount_usize + 1]; coins.len()];

    change_recursive(&coins, 0, amount, &mut memory)
}
