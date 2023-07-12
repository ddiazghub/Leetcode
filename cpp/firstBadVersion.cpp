bool isBadVersion(int version) {
    return version > 3;
}

/**
 * Find the first bad version in a list of versions where the first bad version causes all next versions to be bad.
 * This is just binary search.
 */
int firstBadVersion(int n) {
    int start = 0;
    int end = n;

    while (start < end) {
        int current = start + (end - start) / 2;

        if (isBadVersion(current))
            end = current;
        else
            start = current + 1;
    }

    return end;
}