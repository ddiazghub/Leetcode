#include <vector>

double new21Game(int n, int k, int maxPts) {
    if (k == 0 || n > k + maxPts)
        return 1.0;

    std::vector<double> probabilities(n + 1);
    probabilities[0] = 1.0;
    double sum = 1.0;
    double probability = 0.0;

    for (int i = 1; i <= n; i++) {
        probabilities[i] = sum / maxPts;

        if (i < k)
            sum += probabilities[i];
        else
            probability += probabilities[i];

        if (i >= maxPts)
            sum -= probabilities[i - maxPts];
    }

    return probability;
}

int main() {

}