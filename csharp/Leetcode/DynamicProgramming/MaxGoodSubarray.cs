public class MaximumScore
{
    int Score(int min, int start, int end) => (end - start) * min;

    public int Solution(int[] nums, int k)
    {
        int start = k;
        int end = k + 1;
        int min = nums[k];
        int max = Score(min, start, end);

        while (start > 0 || end < nums.Length)
        {
            int left = start > 0 ? nums[start - 1] : 0;
            int right = end < nums.Length ? nums[end] : 0;
            int score;

            if (left > right)
            {
                start--;
                min = Math.Min(min, left);
            }
            else
            {
                end++;
                min = Math.Min(min, right);
            }

            score = Score(min, start, end);
            max = Math.Max(max, score);
        }

        return max;
    }

    public int Solution2(int[] nums, int k)
    {
        int start = 0;
        int end = k + 1;
        var heap = new PriorityQueue<(int, int), int>();
        int score = 0;

        var getNext = () =>
        {
            if (heap.Peek().Item1 == start)
                heap.Dequeue();

            while (heap.Peek().Item1 < start)
                heap.Dequeue();

            return heap.Peek().Item2;
        };

        var add = () =>
        {
            heap.Enqueue((end, nums[end]), nums[end]);
            score = Score(heap.Peek().Item2, start, end + 1);
            end++;
        };

        var remove = () =>
        {
            score = Score(getNext(), start + 1, end);
            start++;
        };

        for (int i = 0; i < end; i++)
            heap.Enqueue((i, nums[i]), nums[i]);

        int max = Score(heap.Peek().Item2, start, end);

        while (start <= k || end < nums.Length)
        {
            if (start == end - 1)
                add();
            else if (end == nums.Length)
                remove();
            else
            {
                var min = heap.Peek();
                int addMin = Math.Min(min.Item2, nums[end]);
                int delMin = min.Item2;

                if (min.Item1 == start)
                {
                    delMin = getNext();
                    heap.Enqueue(min, min.Item2);
                }

                int adding = Score(addMin, start, end + 1);
                int deleting = Score(delMin, start + 1, end);

                if (deleting > adding)
                    remove();
                else
                    add();
            }

            max = Math.Max(max, score);
        }

        return max;
    }
}
