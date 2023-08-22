pub fn repeated_substring_pattern(s: String) -> bool {
    let string: Vec<_> = s.chars().collect();
    let size = string.len();

    for len in 1..=size / 2 {
        let substring = &string[..len];
        let rest = &string[len..];

        if rest.chunks(len).all(|chunk| chunk == substring) {
            return true;
        }
    }

    false
}

#[cfg(test)]
mod tests {
    use super::repeated_substring_pattern;

    #[test]
    fn test1() {
        let result = repeated_substring_pattern(String::from("abab"));
        assert_eq!(result, true);
    }

    #[test]
    fn test2() {
        let result = repeated_substring_pattern(String::from("aba"));
        assert_eq!(result, false);
    }

    #[test]
    fn test3() {
        let result = repeated_substring_pattern(String::from("abcabcabcabc"));
        assert_eq!(result, true);
    }
}
