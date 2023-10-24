// This is the interface that allows for creating nested lists.
// You should not implement it, or speculate about its implementation
public interface NestedInteger
{
    // @return true if this NestedInteger holds a single integer, rather than a nested list.
    bool IsInteger();

    // @return the single integer that this NestedInteger holds, if it holds a single integer
    // Return null if this NestedInteger holds a nested list
    int? GetInteger();

    // @return the nested list that this NestedInteger holds, if it holds a nested list
    // Return null if this NestedInteger holds a single integer
    IList<NestedInteger>? GetList();
}

public abstract record Value(object value);

public record Int(int val) : Value(val);

public record IntList(List<NestedInteger> list) : Value(list);

public record NestedIntImpl(Value value) : NestedInteger
{
    public int? GetInteger() => value is Int ? (int)value.value : null;

    public bool IsInteger() => value is Int;

    IList<NestedInteger>? NestedInteger.GetList() =>
        value switch
        {
            IntList list => (IList<NestedInteger>)value.value,
            _ => null,
        };

    public static List<NestedInteger> From(object[] array) => array.Select(
        element => element switch
        {
            int value => new NestedIntImpl(new Int(value)) as NestedInteger,
            object[] value
                => new NestedIntImpl(
                    new IntList(NestedIntImpl.From(value).ToList())
                ) as NestedInteger,
            _ => throw new Exception("What?")
        }
    ).ToList();
}

public class ListIterator
{
    public IList<NestedInteger> list;

    public int current = 0;

    public ListIterator(IList<NestedInteger> list)
    {
        this.list = list;
    }

    public bool HasNext() => current < list.Count;

    public NestedInteger? Peek() => HasNext() ? list[current] : null;

    public NestedInteger? Next() => HasNext() ? list[current++] : null;
}

public class NestedIterator
{
    private Stack<ListIterator> stack = new Stack<ListIterator>();

    public NestedIterator(IList<NestedInteger> nestedList)
    {
        var iter = new ListIterator(nestedList);

        if (iter.HasNext())
            stack.Push(iter);
    }

    public bool HasNext()
    {
        while (true)
        {
            ListIterator? top;
            PopStack();
            stack.TryPeek(out top);

            if (top is not null && top.HasNext())
            {
                var next = top.Peek();

                if (next is null)
                    PopStack();
                else if (next.IsInteger())
                    return true;
                else
                {
                    var list = next.GetList()!;

                    top.Next();

                    if (list.Count > 0)
                        stack.Push(new ListIterator(list));
                }
            }
            else
                return false;
        }
    }

    public void PopStack()
    {
        while (stack.Count > 0 && !stack.Peek().HasNext())
            stack.Pop();
    }

    public int Next() => (int)stack.Peek().Next()!.GetInteger()!;
}

/**
 * Your NestedIterator will be called like this:
 * NestedIterator i = new NestedIterator(nestedList);
 * while (i.HasNext()) v[f()] = i.Next();
 */
