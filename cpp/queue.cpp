#include <vector>
#include <iostream>

class MyQueue {
private:
    std::vector<int> inputStack;
    std::vector<int> outputStack;

    void moveToOutput() {
        while (this->inputStack.size() > 0) {
            outputStack.push_back(inputStack.back());
            inputStack.pop_back();
        }
    }

public:
    MyQueue() {}
    
    void push(int x) {
        this->inputStack.push_back(x);
    }
    
    int pop() {
        if (this->outputStack.empty())
            this->moveToOutput();
        
        int element = outputStack.back();
        outputStack.pop_back();

        return element;
    }
    
    int peek() {
        if (this->outputStack.empty())
            this->moveToOutput();

        return outputStack.back();
    }
    
    bool empty() {
        return this->inputStack.empty() && this->outputStack.empty();
    }
};

int main() {
    MyQueue queue;
    queue.push(1);
    queue.push(2);
    std::cout << queue.peek() << '\n';
    std::cout << queue.pop() << '\n';
    std::cout << queue.empty() << '\n';
}