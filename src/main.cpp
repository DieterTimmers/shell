#include <cerrno>
#include <cstring>
#include <iostream>
#include <string>
#include <sys/wait.h>
#include <unistd.h>
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
    while (true) {
        std::cout << "> ";
        std::vector<std::string> command_line = read_command();

        // std::cout << "> I got: ";

        // for (const std::string& word : command_line) {
        //     std::cout << word << ' ';
        // }

        std::cout << '\n';

        int pid = fork();

        if (pid == 0) {
            std::vector<char *> args = {};
            args.reserve(command_line.size());
            for (std::string &word : command_line) {
                args.push_back(word.data());
            }
            args.push_back(nullptr);

            int result = execve(args[0], args.data(), nullptr);
            char *error = strerror(errno);
            std::cerr << error << '\n';
            _exit(126);
        }

        int *result = {};
        int childwait = waitpid(pid, result, 0);
    }

    return 0;
}
