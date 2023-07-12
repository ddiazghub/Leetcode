#include <vector>
#include <algorithm>
#include <map>

/**
 * Class which allows to manipulate an array an take snapshots of the different array states.
 */
class SnapshotArray {
private:
    /**
     * Array where each elements contains the snapshot history of each element of the array.
     */
    std::vector<std::map<int, int, std::greater<int>>> snapshots;

    /**
     * Current snap id.
     */
    int current;

public:
    SnapshotArray(int length) : snapshots(length), current(0) {
        for (auto &element : this->snapshots)
            element.insert({0, 0});
    }
    
    /**
     * Sets the element at the given index to be equal to val.
     */
    void set(int index, int val) {
        this->snapshots[index][this->current] = val;
    }
    
    /**
     * Takes a snapshot of the array and returns the snap_id
     */
    int snap() {
        int id = this->current;
        this->current++;

        return id;
    }
    
    /**
     * Returns the value at the given index, at the time we took the snapshot with the given snap_id.
     */
    int get(int index, int snap_id) {
        return this->snapshots[index].lower_bound(snap_id)->second;
    }
};

int main() {
    SnapshotArray array(3);
    array.set(0, 5);
    array.snap();
    array.set(0, 6);
    array.get(0, 0);

    /*
    SnapshotArray array(4);
    array.snap();
    array.snap();
    array.get(3, 1);
    array.set(2, 4);
    array.snap();
    array.set(1, 4);
    */
}