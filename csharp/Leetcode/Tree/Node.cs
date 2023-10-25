// Definition for a Node.
record Node(int val, IList<Node>? children = null);

/**
 * Definition for a binary tree node.
 */
class TreeNode
{
    public int val;
    public TreeNode? left;
    public TreeNode? right;

    public TreeNode(int val = 0, TreeNode? left = null, TreeNode? right = null)
    {
        this.val = val;
        this.left = left;
        this.right = right;
    }
}
