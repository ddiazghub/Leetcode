class NAryLevelOrder {
    public IList<IList<int>> Solution(Node? root) {
        var traversal = new List<IList<int>>();
        var queue = new Queue<(Node, int)>();
        queue.Enqueue((root!, 0));

        if (root == null)
            return traversal;

        while (queue.Count > 0)
        {
            var (node, row) = queue.Dequeue();
            
            if (row == traversal.Count)
                traversal.Add(new List<int>{node.val});
            else
                traversal[row].Add(node.val);

            if (node.children is not null)
                foreach (var child in node.children)
                    queue.Enqueue((child, row + 1));
        }

        return traversal;
    }
}
