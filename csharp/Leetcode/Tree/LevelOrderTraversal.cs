class LevelOrder
{
    void Traversal(TreeNode? root, int row, IList<IList<int>> traversal)
    {
        if (root == null)
            return;

        if (row == traversal.Count)
            traversal.Add(new List<int> { root.val });
        else
            traversal[row].Add(root.val);

        Traversal(root.left, row + 1, traversal);
        Traversal(root.right, row + 1, traversal);
    }

    IList<IList<int>> Solution(TreeNode? root)
    {
        var traversal = new List<IList<int>>();
        Traversal(root, 0, traversal);

        return traversal;
    }

    void ResizeList<T>(IList<IList<T>> list, int newLength, T append)
    {
        for (int i = 0; i < newLength - list.Count; i++)
            list.Add(new List<T>());

        list.Last().Add(append);
    }

    IList<IList<int>> BottomUpTraversal(TreeNode? root)
    {
        var traversal = new List<IList<int>>();
        var queue = new Queue<(TreeNode, int)>();
        queue.Enqueue((root!, 0));

        if (root == null)
            return traversal;

        while (queue.Count > 0)
        {
            var (node, row) = queue.Dequeue();

            if (row == traversal.Count)
                traversal.Add(new List<int> { node.val });
            else
                traversal[row].Add(node.val);

            if (node.left is not null)
                queue.Enqueue((node.left, row + 1));

            if (node.right is not null)
                queue.Enqueue((node.right, row + 1));
        }

        traversal.Reverse();

        return traversal;
    }

    IList<IList<int>> Solution2(TreeNode? root)
    {
        return BottomUpTraversal(root);
    }
}
