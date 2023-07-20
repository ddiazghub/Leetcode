use std::cmp::Ordering;

/// We are given an array asteroids of integers representing asteroids in a row.
/// 
/// For each asteroid, the absolute value represents its size, and the sign represents its direction (positive meaning right, negative meaning left). Each asteroid moves at the same speed.
/// 
/// Find out the state of the asteroids after all collisions. If two asteroids meet, the smaller one will explode. If both are the same size, both will explode. Two asteroids moving in the same direction will never meet.
pub fn asteroid_collision(asteroids: Vec<i32>) -> Vec<i32> {
    // Create a stack of asteroids
    let mut stack: Vec<i32> = Vec::new();

    for asteroid in asteroids {
        // If the asteroid is going right, push it into the stack
        if asteroid > 0 {
            stack.push(asteroid);
        } else {
            // If the asteroid is going left peek the top asteroid of the stack in a loop.
            let survives = loop {
                // Peek the top asteroid of the stack.
                match stack.last() {
                    // If the top asteroid is going right (In the opposite direction),
                    // compare the size of boths asteroids to find which one is destroyed.
                    Some(&collision) if collision > 0 => {
                        match asteroid.abs().cmp(&collision.abs()) {
                            // The asteroid traveling left is destroyed.
                            Ordering::Less => break false,
                            // The asteroid traveling right is destroyed.
                            Ordering::Greater => stack.pop(),
                            // Both are destroyed.
                            Ordering::Equal => {
                                stack.pop();
                                break false;
                            }
                        };
                    },
                    // If the stack is empty or all remaining asteroids are traveling left
                    // (Same direction), then the asteroid will never collide. Push it to the
                    // stack.
                    _ => break true
                }
            };

            // Push the asteroid to the stack at the end if it survives all collisions.
            if survives {
                stack.push(asteroid);
            }
        }
    }

    // Return the final state of the stack.
    stack
}
