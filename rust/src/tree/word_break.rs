use std::collections::HashMap;

struct Trie {
    is_word: bool,
    children: HashMap<char, Box<Trie>>
}

impl Trie {
    fn new(words: &[impl AsRef<str>]) -> Self {
        let mut root = Trie {
            children: HashMap::new(),
            is_word: false
        };

        for word in words {
            let mut current = &mut root;

            for ch in word.as_ref().chars() {
                current = current.children
                    .entry(ch)
                    .or_insert_with(|| Box::new(Trie::default()));
            }

            current.is_word = true;
        }

        root
    }

    fn next<'a>(&'a self, key: &char) -> Option<&'a Self> {
        self.children.get(&key).map(Box::as_ref)
    }
}

impl Default for Trie {
    fn default() -> Self {
        Self {
            is_word: false,
            children: HashMap::new()
        }
    }
}

/// Given a string s and a dictionary of strings wordDict,
/// return true if s can be segmented into a space-separated sequence of one or more dictionary words.
/// Note that the same word in the dictionary may be reused multiple times in the segmentation.
pub fn word_break(s: String, word_dict: Vec<String>) -> bool {
    let trie = Trie::new(&word_dict[..]);
    let word: Vec<_> = s.chars().collect();
    let mut dp = vec![false; word.len()];

    for i in 0..word.len() {
        if i == 0 || dp[i - 1] {
            let mut current = &trie;

            for j in i..word.len() {
                match current.next(&word[j]) {
                    Some(child) => current = child,
                    None => break
                }

                if current.is_word {
                    dp[j] = true;
                }
            }
        }
    }

    dp.pop().unwrap()
}

#[cfg(test)]
mod tests {
    use super::word_break;

    #[test]
    fn test1() {
        let result = word_break("leetcode".to_string(), vec!["leet".to_string(), "code".to_string()]);
        assert_eq!(result, true);
    }

    #[test]
    fn test2() {
        let result = word_break("applepenapple".to_string(), vec!["apple".to_string(), "pen".to_string()]);
        assert_eq!(result, true);
    }

    #[test]
    fn test3() {
        let result = word_break(
            "catsandog".to_string(),
            vec!["cats".to_string(), "dog".to_string(), "sand".to_string(), "and".to_string(), "cat".to_string()]
        );

        assert_eq!(result, false);
    }

    #[test]
    fn test4() {
        let result = word_break(
            "abcd".to_string(),
            vec!["a".to_string(), "abc".to_string(), "b".to_string(), "cd".to_string()]
        );

        assert_eq!(result, false);
    }
}
