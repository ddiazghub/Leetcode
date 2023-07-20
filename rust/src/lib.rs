mod two_pointers;
mod dynamic_programming;
mod string;
mod backtracking;
mod bit_manipulation;
mod search;
mod tree;
mod array;
mod list;
mod stack;

pub fn add(left: usize, right: usize) -> usize {
    left + right
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn it_works() {
        let result = add(2, 2);
        assert_eq!(result, 4);
    }
}
