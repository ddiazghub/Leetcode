/// Validate a single row of a sudoku board, given an array which stores found values
/// for a row, column or square. Returns false if the cell contains a value which has
/// already been found on the row, column or square and false otherwise.
fn validate_cell(cell: char, found: &mut [bool; 9]) -> bool {
    match cell {
        '1'..='9' => {
            let index = (cell as u8 - b'1') as usize;

            if found[index] {
                return false;
            }

            found[index] = true;
        },
        _ => ()
    };

    true
}

/// Validate all rows of a sudoku board
fn validate_rows(board: &Vec<Vec<char>>) -> bool {
    for row in board {
        let mut found = [false; 9];

        for cell in row {
            if !validate_cell(*cell, &mut found) {
                return false;
            }
        }
    }

    true
}

/// Validate all columns of a sudoku board
fn validate_cols(board: &Vec<Vec<char>>) -> bool {
    for col in 0..board[0].len() {
        let mut found = [false; 9];

        for row in 0..board.len() {
            if !validate_cell(board[row][col], &mut found) {
                return false;
            }
        }
    }

    true
}

/// Validate a single square of a sudoku board
fn validate_square(board: &Vec<Vec<char>>, square_i: usize, square_j: usize) -> bool {
    let mut found = [false; 9];
    let start = (3 * square_i, 3 * square_j);

    for row in start.0..start.0 + 3 {
        for col in start.1..start.1 + 3 {
            if !validate_cell(board[row][col], &mut found) {
                return false;
            }
        }
    }

    true
}

/// Validate all squares of a sudoku board
fn validate_squares(board: &Vec<Vec<char>>) -> bool {
    for square_i in 0..3 {
        for square_j in 0..3 {
            if !validate_square(&board, square_i, square_j) {
                return false;
            }
        }
    }

    true
}

/// Determine if a 9 x 9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:
/// 
/// Each row must contain the digits 1-9 without repetition.
/// Each column must contain the digits 1-9 without repetition.
/// Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without repetition.
/// Note:
/// 
/// A Sudoku board (partially filled) could be valid but is not necessarily solvable.
/// Only the filled cells need to be validated according to the mentioned rules.
pub fn is_valid_sudoku(board: Vec<Vec<char>>) -> bool {
    validate_rows(&board) && validate_cols(&board) && validate_squares(&board)
}
