/// There are two types of soup: type A and type B. Initially, we have n ml of each type of soup. There are four kinds of operations:
/// 
/// Serve 100 ml of soup A and 0 ml of soup B,
/// Serve 75 ml of soup A and 25 ml of soup B,
/// Serve 50 ml of soup A and 50 ml of soup B, and
/// Serve 25 ml of soup A and 75 ml of soup B.
/// When we serve some soup, we give it to someone, and we no longer have it. Each turn, we will choose from the four operations with an equal probability 0.25. If the remaining volume of soup is not enough to complete the operation, we will serve as much as possible. We stop once we no longer have some quantity of both types of soup.
/// 
/// Note that we do not have an operation where all 100 ml's of soup B are used first.
/// 
/// Return the probability that soup A will be empty first, plus half the probability that A and B become empty at the same time. Answers within 10-5 of the actual answer will be accepted.
pub fn soup_servings(n: i32) -> f64 {
    if n > 4800 {
        return 1.0;
    }

    let servings = (n as f64 / 25.0).ceil() as usize;
    let mut memory = vec![vec![0.0; servings + 4]; servings + 4];

    for servs in servings..servings + 4 {
        memory[servs][servs] = 0.5;

        for i in 0..servs{
            memory[servs][i] = 1.0;
        }
    }

    for i in (0..servings).rev() {
        for j in (0..servings).rev() {
            memory[i][j] = 0.25 * [
                memory[i + 4][j] +
                memory[i + 3][j + 1] +
                memory[i + 2][j + 2] +
                memory[i + 1][j + 3]
            ].into_iter().sum::<f64>();
        }
    }

    memory[0][0]
}


#[cfg(test)]
mod tests {
    use super::soup_servings;

    #[test]
    fn test1() {
        let result = soup_servings(50);
        assert_eq!(result, 0.625);
    }

    #[test]
    fn test2() {
        let result = soup_servings(100);
        assert_eq!(result, 0.71875);
    }
}
