/**
 * Counting odd numbers in a range.
 */
int countOdds(int low, int high) {
    int rangeSize = (high - low) + 1;

    if (rangeSize % 2 == 0 || low % 2 == 0)
        return rangeSize / 2;

    return (rangeSize / 2) + 1;
}

int main() {
    
}