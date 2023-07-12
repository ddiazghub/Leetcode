#include <vector>

char nextGreatestLetter(std::vector<char> &letters, char target) {
    if (letters.back() <= target)
        return letters[0];

    int start = 0;
    int end = letters.size() - 1;
    int mid = start + (end - start) / 2;

    while (start < end) {
        mid = start + (end - start) / 2;

        if (letters[mid] < target)
            start = mid + 1;
        else if (letters[end] > target)
            end = mid;
        else
            break;
    }

    while (letters[mid] <= target)
        mid++;

    return letters[mid];
}

int main() {

}