// See https://aka.ms/new-console-template for more information
using Leetcode.Core;

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

while (iter.HasNext())
    Console.WriteLine(iter.Next());
