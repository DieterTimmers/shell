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

        int pid = fork();

        if (pid == 0) {
            std::vector<char *> args = {};
            args.reserve(command_line.size());
            for (std::string &word : command_line) {
                args.push_back(word.data());
            }
            args.push_back(nullptr);

            execvp(args[0], args.data());
            char *error = strerror(errno);
            int child_error = errno;
            if (child_error == 2) {
                std::cerr << "command not found" << '\n';
                _exit(127);
            }
            std::cerr << error << '\n';
            _exit(126);
        }

        int *result = {};
        int childwait = waitpid(pid, result, 0);
    }

    return 0;
}
