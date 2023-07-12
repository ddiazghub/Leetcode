#include <vector>
#include <string>
#include <unordered_map>
#include <utility>
#include <unordered_set>
#include <algorithm>

/**
 * A graph which links together an equation system.
 */
struct EquationGraph {
    /**
     * Variables participating in an equation system.
     * This is basically a weighted adjacency matrix where each cell is the result of dividing the ith variable by the jth variable.
    */
    std::vector<std::vector<double>> variables;

    /**
     * Hashmap which maps each variable name as a string to the variable's index for quick lookup.
    */
    std::unordered_map<std::string, int> indexes;

    /**
     * Creates a new equation graph with the given system of equations.
    */
    EquationGraph(std::vector<std::vector<std::string>> &equations, std::vector<double> &values) {
        int n = equations.size();

        // Adds each equation to the graph.
        for (int i = 0; i < n; i++) {
            this->addEquation(equations[i], values[i]);
        }

        // Makes the adjacency matrix a square matrix.
        int nodes = this->variables.size();

        for (auto &variable : variables)
            variable.resize(nodes, -1);
    }

    /**
     * Adds a new equation to the graph with the given result.
     */
    void addEquation(std::vector<std::string> &equation, double value) {
        unsigned int numerator;
        unsigned int denominator;

        // First add each variable to the graph.
        for (int i = 0; i < 2; i++) {
            std::string &variable = equation[i];
            auto entry = this->indexes.find(variable);
            bool isNumerator = i == 0;
            int index;

            if (entry == this->indexes.end()) {
                index = this->variables.size();
                std::vector<double> relations(index + 1, -1);
                relations[index] = 1.0;
                this->variables.push_back(std::move(relations));
                indexes.insert(std::make_pair(variable, index));
            } else {
                index = entry->second;
            }

            if (isNumerator)
                numerator = index;
            else
                denominator = index;
        }

        // Then add the relations and results to the graph.
        this->addEquation(numerator, denominator, value, this->variables.size());
    }

    /**
     * Adds an equation with the given numerator, denominator and value.
     */
    void addEquation(int numerator, int denominator, double value, size_t newSize) {
        // Resize the matrix if needed.
        if (variables[numerator].size() < newSize)
            this->variables[numerator].resize(newSize, -1);
        
        if (variables[denominator].size() < newSize)
            this->variables[denominator].resize(newSize, -1);

        // Add the results in the respective cells
        this->variables[numerator][denominator] = value;
        this->variables[denominator][numerator] = 1.0 / value;
    }

    /**
     * Evaluates an equation.
     * Starts from the numerator of the equation and uses DFS to traverse the system of equations and find the result of dividing the numerator by the denominator.
     */
    double eval(std::vector<std::string> &query) {
        // Looks up the index of the numerator and denominator.
        auto numeratorIndex = this->indexes.find(query[0]);
        auto denominatorIndex = this->indexes.find(query[1]);

        // If there is any invalid variable in the equation, returns -1
        if (numeratorIndex == indexes.end() || denominatorIndex == indexes.end())
            return -1;
        
        int n = this->variables.size();
        int numerator = numeratorIndex->second;
        int denominator = denominatorIndex->second;
        double val = this->variables[numerator][denominator];
        
        // If there is a direct edge from numerator to denominator, return it's value.
        if (val != -1)
            return val;

        // Defines variables for DFS.
        std::unordered_set<int> traversed{numerator};
        std::vector<std::pair<int, double>> stack;

        // Add all variables that can be reached from numerator to the stack.
        for (int i = 0; i < n; i++) {
            double expressionVal = this->variables[numerator][i];

            if (expressionVal != -1.0) {
                stack.push_back(std::make_pair(i, expressionVal));
            }
        }
        
        while (stack.size() > 0) {
            // Gets next variable and the result.
            auto [next, value] = stack.back();
            stack.pop_back();

            if (traversed.find(next) == traversed.end()) {
                // If the denominator is reachable from the current variable, cache the result and return it.
                double expressionVal = this->variables[next][denominator];

                if (expressionVal != -1) {
                    expressionVal *= value;
                    this->addEquation(numerator, denominator, expressionVal, n);

                    return expressionVal;
                }

                traversed.insert(next);

                // Keep looking for the denominator in all variables we can reach from the current variable.
                // Cache the result to make next evaluations of the same equation a constant time operation.
                for (int i = 0; i < n; i++) {
                    double expressionVal = this->variables[next][i];

                    if (expressionVal != -1.0) {
                        double newValue = value * expressionVal;
                        this->addEquation(numerator, i, newValue, n);
                        stack.push_back(std::make_pair(i, newValue));
                    }
                }
            }
        }

        return -1.0;
    }
};

/**
 * Create an equation graph and calculate the result of the given queries.
 */
std::vector<double> calcEquation(std::vector<std::vector<std::string>> &equations, std::vector<double> &values, std::vector<std::vector<std::string>> &queries) {
    // Create graph.
    EquationGraph graph(equations, values);
    std::vector<double> output;

    // Evaluate queries.
    for (auto &query : queries)
        output.push_back(graph.eval(query));

    return output;
}

int main(){
    std::vector<std::vector<std::string>> equations{{"a","b"},{"b","c"}};
    std::vector<double> values{2.0,3.0};
    std::vector<std::vector<std::string>> queries{{"a","c"},{"b","a"},{"a","e"},{"a","a"},{"x","x"}};
    calcEquation(equations, values, queries);
}