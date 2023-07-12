use std::collections::HashSet;

/// Enumerates all possible types of states and their safety.
#[derive(Clone, Copy)]
enum State {
    Safe,
    Unsafe,
    Unknown
}

/// A node in the graph.
struct Node {
    /// Array of edges that the node has.
    edges: Vec<i32>,
    /// Safety of the node.
    state: State
}

type Graph = Vec<Node>;

/// Recursively finds out if a node in the graph is safe. The results are memoized in the graph
/// directly in order to speed up future computations.
fn is_safe(graph: &mut Graph, node: usize, explored: &mut HashSet<usize>) -> bool {
    match graph[node].state {
        State::Safe => true,
        State::Unsafe => false,
        State::Unknown => {
            let safe = !explored.contains(&node) && {
                explored.insert(node);
                let mut safe = true;

                for i in 0..graph[node].edges.len() {
                    if !is_safe(graph, graph[node].edges[i] as usize, explored) {
                        safe = false;
                        break;
                    }
                }

                safe
            };

            graph[node].state = if safe {
                State::Safe
            } else {
                State::Unsafe
            };

            safe
        }
    }
}

/// There is a directed graph of n nodes with each node labeled from 0 to n - 1. The graph is represented by a 0-indexed 2D integer array graph where graph[i] is an integer array of nodes adjacent to node i, meaning there is an edge from node i to each node in graph[i].
/// 
/// A node is a terminal node if there are no outgoing edges. A node is a safe node if every possible path starting from that node leads to a terminal node (or another safe node).
/// 
/// Return an array containing all the safe nodes of the graph. The answer should be sorted in ascending order.
pub fn eventual_safe_nodes(graph: Vec<Vec<i32>>) -> Vec<i32> {
    let mut graph: Graph = graph.into_iter()
        .map(|edges| Node { edges, state: State::Unknown })
        .collect();

    let mut safe = Vec::new();

    for i in 0..graph.len() {
        if is_safe(&mut graph, i, &mut HashSet::new()) {
            safe.push(i as i32);
        }
    }

    safe
}
