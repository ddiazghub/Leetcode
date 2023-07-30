/// I couldn't solve this :(
///
/// There is a strange printer with the following two special properties:
/// 
/// The printer can only print a sequence of the same character each time.
/// At each turn, the printer can print new characters starting from and ending at any place and will cover the original existing characters.
/// Given a string s, return the minimum number of turns the printer needed to print it.
pub fn strange_printer(s: String) -> i32 {
    let string = s.as_bytes();
    let n = s.len();
    let mut memory = vec![vec![0 as i32; n]; n];

    for left in (0..n).rev() {
        memory[left][left] = 1;

        for right in left + 1..n {
            memory[left][right] = memory[left][right - 1] + 1;

            for i in left..right {
                if string[i] == string[right] {
                    let right_steps = if i + 1 < right {
                        memory[i + 1][right - 1]
                    } else {
                        0
                    };

                    memory[left][right] = memory[left][right].min(memory[left][i] + right_steps)
                }
            }
        }
    }

    memory[0][n - 1]
}
