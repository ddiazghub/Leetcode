struct Combinations {
    options: Vec<Vec<u8>>,
    pointers: Vec<usize>,
    end: bool,
    len: usize
}

impl Combinations {
    fn new(digits: &str) -> Self {
        let options: Vec<_> = digits.as_bytes()
            .into_iter()
            .map(|&ch| Self::letters(ch as u8 - b'0'))
            .collect();

        Self {
            options,
            end: digits.len() == 0,
            len: digits.len(),
            pointers: vec![0; digits.len()]
        }
    }

    fn letters(number: u8) -> Vec<u8> {
        match number {
            2 => vec![b'a', b'b', b'c'],
            3 => vec![b'd', b'e', b'f'],
            4 => vec![b'g', b'h', b'i'],
            5 => vec![b'j', b'k', b'l'],
            6 => vec![b'm', b'n', b'o'],
            7 => vec![b'p', b'q', b'r', b's'],
            8 => vec![b't', b'u', b'v'],
            9 => vec![b'w', b'x', b'y', b'z'],
            _ => panic!("What?")
        }
    }
}

impl Iterator for Combinations {
    type Item = String;

    fn next(&mut self) -> Option<Self::Item> {
        if self.end {
            return None;
        }

        let current: String = self.pointers
            .iter()
            .copied()
            .enumerate()
            .map(|(i, pointer)| self.options[i][pointer] as char)
            .collect();

        self.end = self.pointers.iter()
            .zip(self.options.iter())
            .all(|(ptr, option)| *ptr == option.len() - 1);

        if !self.end {
            let mut i = self.len - 1;

            while self.pointers[i] == self.options[i].len() - 1 {
                i -= 1;
            }

            self.pointers[i] += 1;

            for j in i + 1..self.len {
                self.pointers[j] = 0;
            }
        }

        Some(current)
    }
}

pub fn letter_combinations(digits: String) -> Vec<String> {
    Combinations::new(&digits).collect()
}

#[cfg(test)]
mod tests {
    use std::collections::HashSet;

    use super::letter_combinations;

    #[test]
    fn test1() {
        let result: HashSet<_> = letter_combinations("23".to_string()).into_iter().collect();

        let expected = HashSet::from_iter([
            "ad",
            "ae",
            "af",
            "bd",
            "be",
            "bf",
            "cd",
            "ce",
            "cf"
        ].map(String::from));

        assert_eq!(result, expected);
    }
}
