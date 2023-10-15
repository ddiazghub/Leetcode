namespace Leetcode.Tests;

using Xunit;
using Leetcode.Core;

public class UnitTest1
{
    [Fact]
    public void Test1()
    {
        var me = new Person("David", 23, 1001779895);
        Assert.Equal(me.name, "David");
    }
}
