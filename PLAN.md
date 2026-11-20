# Shell Roadmap

Build a simple shell in C++ in four steps. Steps 1 to 3 handle a single command per line; step 4 adds operators that combine commands.

## Step 1: Read input

- Read characters from the user, like an existing shell.
- Enter ends the line; the shell then shows a new prompt.

## Step 2: Turn text into a command

- Turn one line of text into one program that runs.
- Find out how the shell asks the kernel to start a program.

## Step 3: Output and errors

- Find out how stdout and stderr of the program reach the terminal.
- Get the exit status of the program.

## Step 4: Special characters

- `;`: run commands one after another.
- `&&`: run the next command only if the previous one exited with status 0. Uses the exit status from step 3.
- `|`: the stdout of the left command becomes the stdin of the right command.
- Heredoc (`<<EOF`): read more lines as input until the delimiter. Reuses the input reading from step 1.

## Open questions

- How does the shell stop (for example Ctrl-D or `exit`)? Decide later.
- Do both sides of a `|` run one after another, or at the same time?
