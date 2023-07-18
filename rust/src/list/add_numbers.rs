use std::ops::Add;

#[derive(PartialEq, Eq, Clone, Debug)]
pub struct ListNode {
    pub val: i32,
    pub next: Option<Box<ListNode>>
}

impl ListNode {
    #[inline]
    fn new(val: i32) -> Self {
        ListNode {
            next: None,
            val
        }
    }
}

/// A linked list.
struct List {
    /// First node of the list.
    head: Option<Box<ListNode>>,
    /// Number of nodes in the list.
    len: usize
}

impl List {
    /// Creates a new list with the given head.
    fn new(head: Option<Box<ListNode>>) -> Self {
        let len = Self::len(&head, 0);

        Self {
            head,
            len
        }
    }

    /// Counts the number of nodes in a linked list.
    fn len(list: &Option<Box<ListNode>>, current: usize) -> usize {
        match list {
            None => current,
            Some(list) => Self::len(&list.next, current + 1)
        }
    }

    /// Adds left padding to a linked list by prepending it with nodes filled with zeroes.
    /// The parameter <zeroes> specifies the length of the padding.
    fn pad(self, zeroes: usize) -> Self {
        if zeroes == 0 {
            return self;
        }

        let new_len = self.len + zeroes;
        let mut padding = Some(Box::new(ListNode::new(0)));
        let mut current = padding.as_mut().unwrap();

        for _ in 1..zeroes {
            current.next = Some(Box::new(ListNode::new(0)));
            current = current.next.as_mut().unwrap();
        }

        current.next = self.head;

        Self {
            head: padding,
            len: new_len
        }
    }

    /// Recursively adds 2 nodes in a linked list.
    /// Returns a tuple which contains the result of adding the 2 nodes and any nodes after them as another list1
    /// and the carry amount.
    fn recursive_add(node1: &Option<Box<ListNode>>, node2: &Option<Box<ListNode>>) -> (i32, Option<Box<ListNode>>) {
        match (node1, node2) {
            (Some(node1), Some(node2)) => {
                let (old_carry, result) = Self::recursive_add(&node1.next, &node2.next);

                let mut sum = node1.val + node2.val + old_carry;
                let carry = sum / 10;
                sum -= carry * 10;

                let mut node = ListNode::new(sum);
                node.next = result;

                (carry, Some(Box::new(node)))
            },
            _ => (0, None)
        }
    }
}

impl Add for List {
    type Output = Self;

    fn add(self, rhs: Self) -> Self::Output {
        match Self::recursive_add(&self.head, &rhs.head) {
            (0, Some(sum)) => Self {
                head: Some(sum),
                len: self.len
            },
            (carry, Some(sum)) => {
                let mut result = ListNode::new(carry);
                result.next = Some(sum);

                Self {
                    head: Some(Box::new(result)),
                    len: self.len + 1
                }
            },
            _ => Self {
                head: None,
                len: 0
            }
        }
    }
}

/// You are given two non-empty linked lists representing two non-negative integers. The most significant digit comes first and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.
/// 
/// You may assume the two numbers do not contain any leading zero, except the number 0 itself.
pub fn add_two_numbers(l1: Option<Box<ListNode>>, l2: Option<Box<ListNode>>) -> Option<Box<ListNode>> {
    let list1 = List::new(l1);
    let list2 = List::new(l2);

    let (longest, shortest) = if list1.len > list2.len {
        (list1, list2)
    } else {
        (list2, list1)
    };

    let padding = longest.len - shortest.len;
    let shortest = shortest.pad(padding);
    let sum = longest + shortest;

    sum.head
}
