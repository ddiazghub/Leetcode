class LargestValues
{
    void Traverse(TreeNode? root, int row, List<int> largestValues)
    {
        if (root == null)
            return;

        if (row == largestValues.Count)
            largestValues.Add(int.MinValue);

        largestValues[row] = Math.Max(largestValues[row], root.val);

        Traverse(root.left, row + 1, largestValues);
        Traverse(root.right, row + 1, largestValues);
    }

    IList<int> Solution(TreeNode? root)
    {
        List<int> largestValues = new List<int>();
        Traverse(root, 0, largestValues);

        return largestValues;
    }
}
