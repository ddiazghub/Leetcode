public class EndAtSamePlace {
    static int MOD = 1000000007;

    public static int Recursive(int startPos, int endPos, int steps, int length, int?[,] cache)
    {
        int distance = Math.Abs(startPos - endPos);

        if (distance > steps)
            return 0;
        
        if (cache[distance, steps] is not null)
            return cache[distance, steps] ?? -1;

        var left = startPos - 1 > -1 ? Recursive(startPos - 1, endPos, steps - 1, length, cache) : 0;
        var right = startPos + 1 < length ? Recursive(startPos + 1, endPos, steps - 1, length, cache) : 0;
        var staying = Recursive(startPos, endPos, steps - 1, length, cache);

        var result = ((left + right) % MOD + staying) % MOD;

        cache[distance, steps] = result;

        return result;
    }

    public int Solution(int steps, int length) {
        var maxDistance = (steps + 1) / 2;
        var cache = new int?[maxDistance + 1, steps + 1];

        for (int i = 0; i <= maxDistance; i++)
        {
            cache[i, 0] = 0;
            cache[i, i] = 1;
        }

        return Recursive(0, 0, steps, length, cache);
    }
}
