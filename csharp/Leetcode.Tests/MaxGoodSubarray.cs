namespace Leetcode.Tests;

using Xunit;
using Leetcode.Core;

public class MaximumScoreTest
{
    [Fact]
    public void Test1()
    {
        var array = new int[] { 1, 4, 3, 7, 4, 5 };
        var solution = new MaximumScore();
        int result = solution.Solution(array, 3);
        Assert.Equal(15, result);
    }
}
