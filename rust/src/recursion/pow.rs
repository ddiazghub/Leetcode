/// Implement pow(x, n), which calculates x raised to the power n (i.e., xn).
pub fn my_pow(x: f64, n: i32) -> f64 {
    if n < 0 {
        1.0 / pow(x, (-n) as u32)
    } else {
        pow(x, n as u32)
    }
}

/// Raises the number x to the nth power
fn pow(x: f64, n: u32) -> f64 {
    match n {
        0 => 1.0,
        1 => x,
        _ if n % 2 == 0 => pow(x * x, n / 2),
        _ => x * pow(x * x, (n - 1) / 2)
    }
}

#[cfg(test)]
mod tests {
    use super::my_pow;

    #[test]
    fn test1() {
        let result = (my_pow(2.0, 10) * 100.0).round() / 100.0;
        assert_eq!(result, 1024.0);
    }
    
    #[test]
    fn test2() {
        let result = (my_pow(2.1, 3) * 1000.0).round() / 1000.0;
        assert_eq!(result, 9.261);
    }

    #[test]
    fn test3() {
        let result = (my_pow(2.0, -2) * 100.0).round() / 100.0;
        assert_eq!(result, 0.25);
    }
}
