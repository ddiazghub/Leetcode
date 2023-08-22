const N: usize = 26;
const A: u8 = 'A' as u8;

/// Constant array containing all letters in the english alphabet.
const ALPHABET: [char; N] = {
    let mut alphabet = ['A'; N];
    let mut i = 1;

    while i < N {
        alphabet[i] = (A + i as u8) as char;
        i += 1;
    }
    
    alphabet
};

/// Given an integer columnNumber, return its corresponding column title as it appears in an Excel sheet.
/// 
/// For example:
/// 
/// A -> 1
/// B -> 2
/// C -> 3
/// ...
/// Z -> 26
/// AA -> 27
/// AB -> 28 
/// ...
pub fn convert_to_title(column_number: i32) -> String {
    if column_number == 1 {
        return String::from("A");
    }

    let mut column_number = column_number as usize;
    let mut digits: Vec<usize> = Vec::new();

    while column_number > 0 {
        column_number = column_number as usize - 1;
        digits.push(column_number % N);
        column_number /= N;
    }

    digits.into_iter()
        .rev()
        .map(|digit| ALPHABET[digit])
        .collect()
}
