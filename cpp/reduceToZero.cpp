/**
 * Count the number of steps needed to reduce a number to 0.
*/
int numberOfSteps(int num) {
    if (num == 0)
        return 0;
    
    int steps = 0;

    while (num > 0) {
        steps += num & 1 ? 2 : 1;
        num >>= 1;
    }

    return steps - 1;
}