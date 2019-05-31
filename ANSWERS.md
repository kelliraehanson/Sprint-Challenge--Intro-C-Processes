**1. List all of the main states a process may be in at any point in time on a standard Unix system. Briefly explain what each of these states means.**

Answer: The main states a process may be in are:
Start, Ready, Running, Waiting, Terminated.

Start - (created) Is the initial state when the process has first been started.

Ready - Also know as "waiting" is when a process has been loaded to memory and is waiting an execution by a CPU so they can run. The CPU is the brains of the computer where most calculations take place

Running - Running is when the processor executes it. And it is no longer waiting an execution by a CPU.

Waiting - Waiting is when the process is waiting for something like user input to be run.

Terminated- (exit) When the process completes its execution or is terminated.


**2. What is a zombie process?**

Answer: A zombie process is defined as a process that has finished executing but has not yet been cleaned up.


**3. How does a zombie process get created? How does one get destroyed?**

Answer: A zombie process gets created when a child process completes its execution but is not yet cleaned up therefore leaving its details such as the process status behind. This is visible when typing the command "ps al" into the terminal.

A zombie process gets destroyed when the parent executes a wait system call and removes what is left behind in memory from the child. A child process is typically the first to become a zombie and if a process stay a zombie for a long amount of time it is usually an error.


**4. What are some of the benefits of working in a compiled language versus a non-compiled language? More specifically, what benefits are there to be had from taking the extra time to compile our code?**

Answer: Both types of languages have their strengths and weaknesses. Compiled languages are faster than non-compiled. It is also easier to find errors in compiled because it won't run if there are any errors etc. There are reasons for using languages that are compiled and reasons for using non-compiled languages. There is no simple answer as to which language is "better"—it depends on the application. Even within an application we could end up using many different languages. Non-compiled must be parsed, interpreted, and executed each time the program is run, thereby greatly adding to the cost of running the program. For this reason, non-compiled are usually less efficient than compiled programs.