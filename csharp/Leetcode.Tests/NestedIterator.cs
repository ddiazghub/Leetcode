namespace Leetcode.Tests;

using Xunit;
using Leetcode.Core;

public class NestedIteratorTest
{
    [Fact]
    public void Test1()
    {
        // ??????
        var iter = new NestedIterator(
            new List<NestedInteger>
            {
                new NestedIntImpl(
                    new IntList(
                        new List<NestedInteger>
                        {
                            new NestedIntImpl(new Int(1)),
                            new NestedIntImpl(new Int(1))
                        }
                    )
                ),
                new NestedIntImpl(new Int(2)),
                new NestedIntImpl(
                    new IntList(
                        new List<NestedInteger>
                        {
                            new NestedIntImpl(new Int(1)),
                            new NestedIntImpl(new Int(1))
                        }
                    )
                ),
            }
        );

        List<int> output = new List<int>();

        while (iter.HasNext())
            output.Add(iter.Next());

        Assert.True(output is [1, 1, 2, 1, 1]);
    }

    [Fact]
    public void Test2()
    {
        var array = new object[]
        {
            new object[] { },
            new object[] { new object[] { } },
            -4,
            new object[] { new object[] { new object[] { } } },
            new object[]
            {
                new object[] { },
                2,
                new object[] { new object[] { }, },
                new object[] { new object[] { -3 }, 1 },
                new object[] { new object[] { }, -1 }
            }
        };

        var iter = new NestedIterator(NestedIntImpl.From(array));
        List<int> output = new List<int>();

        while (iter.HasNext())
            output.Add(iter.Next());

        Assert.Equal(new List<int> { -4, 2, -3, 1, -1 }, output);
    }
}
