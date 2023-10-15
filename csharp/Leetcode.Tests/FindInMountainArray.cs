namespace Leetcode.Tests;

using Xunit;
using Leetcode.Core;

public class MountainArrayTest
{
    [Fact]
    public void Test1()
    {
        var array = new MountainArrayImpl(new int[] { 0, 5, 3, 1 });
        var solution = new FindInMountainArray();
        Assert.Equal(2, solution.Solution(3, array));
    }
}
