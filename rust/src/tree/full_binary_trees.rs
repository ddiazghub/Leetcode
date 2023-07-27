use std::{rc::Rc, cell::RefCell};

#[derive(Debug, PartialEq, Eq)]
pub struct TreeNode {
    pub val: i32,
    pub left: Option<Rc<RefCell<TreeNode>>>,
    pub right: Option<Rc<RefCell<TreeNode>>>,
}

impl TreeNode {
    #[inline]
    pub fn new(val: i32) -> Self {
        TreeNode {
            val,
            left: None,
            right: None
        }
    }
}

/// Given an integer n, return a list of all possible full binary trees with n nodes. Each node of each tree in the answer must have Node.val == 0.
/// 
/// Each element of the answer is the root node of one possible tree. You may return the final list of trees in any order.
/// 
/// A full binary tree is a binary tree where each node has exactly 0 or 2 children.
pub fn all_possible_fbt(n: i32) -> Vec<Option<Rc<RefCell<TreeNode>>>> {
    if n % 2 == 0 {
        Vec::new()
    } else {
        let mut memory: Vec<_> = (0..(n + 1) / 2)
            .map(|_| None)
            .collect();

        let node = Rc::new(RefCell::new(TreeNode::new(0)));
        memory[0] = Some(vec![Some(node)]);

        all_possible_trees(n, &mut memory)
    }
}

/// Finds all possible trees of size n.
fn all_possible_trees(n: i32, memory: &mut Vec<Option<Vec<Option<Rc<RefCell<TreeNode>>>>>>) -> Vec<Option<Rc<RefCell<TreeNode>>>> {
    let tree_index = ((n - 1) / 2) as usize;

    if let Some(trees) = &memory[tree_index] {
        return trees.clone();
    }

    let mut trees = Vec::new();
    let remaining = n - 1;

    for i in (1..n).step_by(2) {
        let left = all_possible_trees(i, memory);
        let right = all_possible_trees(remaining - i, memory);

        for left_child in left {
            for right_child in right.iter() {
                let mut root = TreeNode::new(0);
                root.left = left_child.clone();
                root.right = right_child.clone();
                trees.push(Some(Rc::new(RefCell::new(root))));
            }
        }
    }

    memory[tree_index] = Some(trees.clone());

    trees
}
