class BstFromPreorder
{
    public TreeNode? Solution(int[] preorder)
    {
        // Root is null
        if (preorder.Length == 0)
            return null;

        // First node in preorder array will always be the root
        int root = preorder[0];

        // Find the array index where the tree is split in left and right
        // Subtrees.
        int partitionIndex = 1 + preorder.Skip(1).Count(node => node < root);

        // Find left and right slices by slicing the preorder array.
        // Build left and right subtrees using left and right slices.
        var left = Solution(preorder[1..partitionIndex]);
        var right = Solution(preorder[partitionIndex..]);

        // Return current subtree's root.
        return new TreeNode(root, left, right);    }
}
