mod two_pointers;
mod dynamic_programming;
mod backtracking;
mod bit_manipulation;
mod search;
mod tree;
mod list;
mod stack;
mod recursion;
mod binary_search;
mod basic_stuff;

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
