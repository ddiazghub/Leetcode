record struct SubSum(int index, int sum);

public class ConstrainedSubsetSum
{
    // int[] trim(int[] nums)
    // {
    //     var leftTrim = nums.SkipWhile(num => num < 0);
    //     var trimmed = leftTrim.Reverse().SkipWhile(num => num < 0);

    //     return trimmed.Reverse().ToArray();
    // }

    public int Solution(int[] nums, int k)
    {
        var comparer = Comparer<int>.Create((a, b) => b.CompareTo(a));
        var queue = new PriorityQueue<SubSum, int>(comparer);
        queue.Enqueue(new SubSum(0, nums[0]), nums[0]);
        int max = nums[0];

        for (int i = 1; i < nums.Length; i++)
        {
            while (i - queue.Peek().index > k)
                queue.Dequeue();

            int maxSum = queue.Peek().sum;
            int newSum = maxSum > 0 ? maxSum + nums[i] : nums[i];
            max = Math.Max(max, newSum);
            queue.Enqueue(new SubSum(i, newSum), newSum);
        }

        return max;
    }
}
