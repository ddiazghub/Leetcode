const MOD: u64 = 1e9 as u64 + 7;

/// Your music player contains n different songs. You want to listen to goal songs (not necessarily different) during your trip. To avoid boredom, you will create a playlist so that:
/// 
/// Every song is played at least once.
/// A song can only be played again only if k other songs have been played.
/// Given n, goal, and k, return the number of possible playlists that you can create. Since the answer can be very large, return it modulo 109 + 7.
pub fn num_music_playlists(n: i32, goal: i32, k: i32) -> i32 {
    let [n, goal, k] = [n, goal, k].map(|x| x as usize);

    let mut table = vec![vec![0; n + 1]; goal + 1];
    table[0][0] = 1;

    for size in 1..goal + 1 {
        for unique in 1..(n + 1).min(size + 1) {
            table[size][unique] = (table[size - 1][unique - 1] * (n - unique + 1) as u64) % MOD;

            if unique > k {
                table[size][unique] = (table[size][unique] + table[size - 1][unique] * (unique - k) as u64) % MOD;
            }
        }
    }

    table[goal][n] as i32
}
