#include <vector>
#include <set>
#include <utility>
#include <algorithm>
#include <iterator>

/**
 * You are given an m x n binary matrix mat of 1's (representing soldiers) and 0's (representing civilians). The soldiers are positioned in front of the civilians. That is, all the 1's will appear to the left of all the 0's in each row.
 * 
 * A row i is weaker than a row j if one of the following is true:
 *
 * The number of soldiers in row i is less than the number of soldiers in row j.
 * Both rows have the same number of soldiers and i < j.
 * Return the indices of the k weakest rows in the matrix ordered from weakest to strongest.
 */
std::vector<int> kWeakestRows(std::vector<std::vector<int>> &mat, int k) {
    int n = mat.size();
    std::set<std::pair<int, int>> rows;

    for (int i = 0; i < n; i++) {
        int strength = std::count(mat[i].cbegin(), mat[i].cend(), 1);
        rows.insert(std::make_pair(strength, i));
    }

    auto kth = std::next(rows.cbegin(), k);
    std::vector<int> output;

    for (auto it = rows.cbegin(); it != kth; it++)
        output.push_back(it->second);

    return output;
}

int main() {

}