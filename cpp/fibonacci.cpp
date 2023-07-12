/**
 * Fibonacci series.
 */
int fib(int n) {
    if (n == 0)
        return 0;
    
    int last = 0;
    int current = 1;

    for (int i = 2; i < n; i++) {
        int next = last + current;
        last = current;
        current = next;
    }

    return last + current;
}

int main() {

}