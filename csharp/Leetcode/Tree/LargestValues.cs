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

IList<int> LargestValues(TreeNode? root)
{
    List<int> largestValues = new List<int>();
    Traverse(root, 0, largestValues);
    
    return largestValues;
}

/**
 * Definition for a binary tree node.
 */
public record TreeNode(int val = 0, TreeNode? left = null, TreeNode? right = null);
