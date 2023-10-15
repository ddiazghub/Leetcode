public interface MountainArray
{
    public int Get(int index);
    public int Length();
}

public class MountainArrayImpl : MountainArray
{
    private int[] array;
    private int count;

    public MountainArrayImpl(int[] array)
    {
        this.array = array;
        this.count = 0;
    }

    public int Get(int index)
    {
        count++;

        return array[index];
    }

    public int Length() => array.Length;
}

public class FindInMountainArray
{
    public int? Search(int target, MountainArray array, int?[] cache, int start, int end, Func<int, int, int>? comparator = null)
    {
        var cmp = comparator ?? ((a, b) => a.CompareTo(b));

        while (start < end)
        {
            int mid = start + (end - start) / 2;
            int value = Get(array, cache, mid);

            if (value == target)
                return mid;
            else if (cmp(value, target) > 0)
                end = mid;
            else
                start = mid + 1;
        }

        return null;
    }

    public int Get(MountainArray array, int?[] cache, int index) {
        int value = cache[index] ?? array.Get(index);
        cache[index] = value;

        return value;
    }

    public int Solution(int target, MountainArray mountainArr)
    {
        int?[] cache = Enumerable.Repeat<int?>(null, mountainArr.Length()).ToArray();
        int start = 0;
        int end = mountainArr.Length() - 1;

        while (start < end)
        {
            int mid = start + (end - start) / 2;
            int value = Get(mountainArr, cache, mid);
            int next = Get(mountainArr, cache, mid + 1);

            if (value < next)
            {
                if (value == target)
                    return mid;
                else if (next == target)
                    return mid + 1;

                start = mid + 1;
            }
            else
                end = mid;
        }

        int peak = start + (end - start) / 2;
        Console.WriteLine($"Peak: {peak}");

        if ((cache[peak] ?? mountainArr.Get(peak)) == target)
        {
            return peak;
        }

        return Search(target, mountainArr, cache, 0, peak)
            ?? Search(target, mountainArr, cache, peak + 1, mountainArr.Length(), (a, b) => -a.CompareTo(b))
            ?? -1;
    }
}
