#include <iostream>
#include <string>
#include <vector>

std::vector<std::string> read_command() {
    std::vector<std::string> command;
    std::string word;

    char c;
    while (true) {
        std::cin.get(c);

        if (c == ' ') {
            if (word.empty()) {
                continue;
            }
            command.push_back(word);
            word.clear();
            continue;
        }

        if (c == '\n') {
            command.push_back(word);
            break;
        }

        word.push_back(c);
    }
    return command;
}

int main() {
    std::cout << "> ";

    std::vector<std::string> command = read_command();

    return 0;
}
