/**
 * Basically reverse fibonacci.
 */
int climbStairs(int n) {
    if (n == 1)
        return 1;
    
    int count = 2;
    int next = 1;
    int twoNext = 0;

    for (int i = n - 2; i > 0; i--) {
        int waysToClimb = next + twoNext;
        count += waysToClimb;
        twoNext = next;
        next = waysToClimb;
    }

    return count;
}

int main() {

}