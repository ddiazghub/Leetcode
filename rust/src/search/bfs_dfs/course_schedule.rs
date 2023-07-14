#[derive(Clone)]
struct Node {
    safe: bool,
    edges: Vec<usize>
}

impl Node {
    fn new() -> Self {
        Self {
            safe: false,
            edges: Vec::new()
        }
    }
}

fn is_safe(graph: &mut Vec<Node>, current: usize, visited: &mut Vec<bool>) -> bool {
    if graph[current].safe {
        return true;
    }

    if visited[current] {
        return false;
    }

    for i in 0..graph[current].edges.len() {
        visited[current] = true;

        if !is_safe(graph, graph[current].edges[i], visited) {
            return false;
        }

        visited[current] = false;
    }

    graph[current].safe = true;

    return true;
}

pub fn can_finish(num_courses: i32, prerequisites: Vec<Vec<i32>>) -> bool {
    let courses = num_courses as usize;
    let mut graph: Vec<Node> = vec![Node::new(); courses];

    for pre in prerequisites {
        graph[pre[0] as usize].edges.push(pre[1] as usize);
    }

    for i in 0..courses {
        if !is_safe(&mut graph, i, &mut vec![false; courses]) {
            return false;
        }
    }

    true
}

#[cfg(test)]
mod tests {
    use super::can_finish;

    #[test]
    fn test1() {
        let prerequisites = vec![vec![2, 0], vec![1, 0], vec![3, 1], vec![3, 2], vec![1, 3]];
        let result = can_finish(4, prerequisites);
        assert!(!result);
    }
}
