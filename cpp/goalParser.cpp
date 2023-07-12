#include <string>

std::string interpret(std::string command) {
    std::string output;
    int size = command.size();
    int i = 0;

    while (i < size) {
        switch (command[i]) {
        case 'G':
            output.push_back('G');
            i++;
            break;
        case '(':
            switch (command[i + 1]) {
            case 'a':
                output.append("al");
                i += 4;
                break;
            case ')':
                output.push_back('o');
                i += 2;
            default:
                break;
            }
        default:
            break;
        }
    }

    return output;
}

int main() {

}