public class ReachPosition
{
    static int MOD = 1000000007;

    public static int Recursive(int startPos, int endPos, int k, int?[,] cache)
    {
        int distance = Math.Abs(startPos - endPos);

        if (distance > k)
            return 0;
        
        if (cache[distance, k] is not null)
            return cache[distance, k] ?? -1;

        var left = Recursive(startPos - 1, endPos, k - 1, cache);
        var right = Recursive(startPos + 1, endPos, k - 1, cache);
        var result = (left + right) % MOD;

        cache[distance, k] = result;

        return result;
    }

    public int Solution(int startPos, int endPos, int k)
    {
        if (Math.Abs(startPos - endPos) > k)
            return 0;

        var cache = new int?[k + 1, k + 1];

        for (int i = 0; i < k + 1; i++)
        {
            cache[i, 0] = 0;
            cache[i, i] = 1;

            if (i % 2 > 0)
                cache[0, i] = 0;
        }

        return Recursive(startPos, endPos, k, cache);
    }

    public int EpicFail(int startPos, int endPos, int k)
    {
        var distance = Math.Abs(startPos - endPos);

        if (distance > k)
            return 0;

        var cache = new int[k + 1, k + 2];

        for (int i = 0; i <= k; i++)
            cache[i, i] = 1;

        for (int i = 1; i <= k; i++)
            for (int j = 0; j < i; j++)
                cache[i, j] = (cache[i - 1, Math.Abs(j - 1)] + cache[i - 1, j + 1]) % MOD;

        return cache[k, distance];
    }
}
