public class MinCostClimbingStairs
{
    public int Recursive(int[] cost, int current)
    {
        if (current >= cost.Length)
        {
            return 0;
        }

        int minCost = Math.Min(Recursive(cost, current + 1), Recursive(cost, current + 2));

        return cost[current] + minCost;
    }

    public int SolutionRecursive(int[] cost)
    {
        return Math.Min(Recursive(cost, 0), Recursive(cost, 1));
    }

    public int Solution(int[] cost)
    {
        int[] next = { cost.Last(), 0 };

        for (int i = cost.Length - 2; i > -1; i--)
        {
            int current = cost[i] + Math.Min(next[0], next[1]);
            next[1] = next[0];
            next[0] = current;
        }

        return Math.Min(next[0], next[1]);
    }
}
