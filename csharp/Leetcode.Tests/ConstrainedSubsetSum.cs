namespace Leetcode.Tests;

using Xunit;
using Leetcode.Core;

public class ConstrainedSubsetSumTest
{
    [Fact]
    public void Test1()
    {
        var solution = new ConstrainedSubsetSum();
        var nums = new int[] { -1, -2, -3 };
        Assert.Equal(-1, solution.Solution(nums, 1));
    }

    [Fact]
    public void Test2()
    {
        var solution = new ConstrainedSubsetSum();
        var nums = new int[] { -8269, 3217, -4023, -4138, -683, 6455, -3621, 9242, 4015, -3790 };
        Assert.Equal(16091, solution.Solution(nums, 1));
    }
}
