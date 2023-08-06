use std::collections::HashMap;
use std::rc::Rc;
use std::cell::RefCell;

/// Tree type alias.
type Tree = Option<Rc<RefCell<TreeNode>>>;

#[derive(Debug, PartialEq, Eq)]
/// Tree node.
pub struct TreeNode {
    /// Node value.
    pub val: i32,
    /// Left child.
    pub left: Tree,
    /// Right child.
    pub right: Tree,
}

impl TreeNode {
    #[inline]
    /// Creates a new node with the given value.
    pub fn new(val: i32) -> Self {
        TreeNode {
            val,
            left: None,
            right: None
        }
    }
}

/// Wraps a node into its respective smart pointers.
fn wrap_node(node: TreeNode) -> Tree {
    Some(Rc::new(RefCell::new(node)))
}

/// Given an integer n, return all the structurally unique BST's (binary search trees),
/// which has exactly n nodes of unique values from 1 to n.
fn unique_trees(start: i32, end: i32, memory: &mut HashMap<(i32, i32), Vec<Tree>>) -> Vec<Tree> {
    if start > end {
        return vec![None];
    }

    let range = (start, end);

    match memory.get(&range) {
        Some(trees) => trees.clone(),
        None => {
            let mut trees = Vec::new();

            for root_value in start..=end {
                let left = unique_trees(start, root_value - 1, memory);
                let right = unique_trees(root_value + 1, end, memory);

                for left_child in left {
                    for right_child in right.iter() {
                        let mut root = TreeNode::new(root_value);
                        root.left = left_child.clone();
                        root.right = right_child.clone();
                        trees.push(wrap_node(root));
                    }
                }
            }

            memory.insert(range, trees.clone());

            trees
        }
    }
}

/// Given an integer n, return all the structurally unique BST's (binary search trees),
/// which has exactly n nodes of unique values from 1 to n.
/// Return the answer in any order.
pub fn generate_trees(n: i32) -> Vec<Tree> {
    let mut memory: HashMap<(i32, i32), Vec<Tree>> = HashMap::new();

    unique_trees(1, n, &mut memory)
}
