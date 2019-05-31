#include <stdio.h>
#include <dirent.h> // (You don't need to declare this `struct dirent` type. It's already included in `<dirent.h>`.)
#include <sys/stat.h> // for stat()
#include <stdlib.h> //  for exit()
// C requires importing system / header files
// This is when you import functionalities from other libraries. 
//These could contain functions that you would like to use in  your program so you have to import them. 
//You typically include these at the top of your C file. 
//These could be header files from the standard library or header files that you write.

// ### Accessing Directories
// You will be using functionality included in `<dirent.h>`. This header file holds
// the declarations for `DIR`, `struct dirent`, `opendir()`, `readdir()`, and
// `closedir()`, below.

// * `DIR *opendir(char *path)`: This function opens the directory named in `path`
//   (e.g. `.`) and returns a pointer to a variable of type `DIR` that will be used
//   later. If there is an error, `opendir()` returns `NULL`.
  
//   _You should check for errors. If there is one, print an error message and exit
//   (using the `exit()` function)._

// * `struct dirent *readdir(DIR *d)`: Reads the next directory entry from the
//   `DIR` returned by `opendir()`. Returns the result as a pointer to a `struct
//   dirent` (see below). Returns `NULL` if there are no more directory entires.

// * `closedir(DIR *d)`: Close a directory (opened previously with `opendir()`)
//   when you're done with it.

// The `struct dirent *` returned by `readdir()` has the following fields in it:

// ```c
// struct dirent {
//   ino_t  d_ino       // file serial number
//   char   d_name[]    // file name, a string
// };
// ```

// (You don't need to declare this `struct dirent` type. It's already included in `<dirent.h>`.)

// For output, you should print the field `d_name` from your `struct dirent *`
// variable, e.g.

// ```c
// struct dirent *ent;

// // ... some of your code ...

// ent = readdir(d);

// printf("%s\n", ent->d_name);
// ```
// To parse the command line, you'll have to look at `argc` and `argv` specified in
// your `int main(int argc, char **argv)` function. Example code to print all
// command line arguments can be found in [commandline.c](examples/commandline.c).
// Modify that example to look at the command line parameters, if any, and pass
// those to `opendir()`.

// ### File Sizes

// For each entry in a directory, your program should print its size in bytes. 

// To get the size of entries, you'll need to use the `stat()` call in `<sys/stat.h>`.
//   - `int stat(char *fullpath, struct stat *buf)`: For a given full path to a file
//   (i.e. the path passed to `opendir()` following by a `/` followed by the name
//   of the file in `d_name`), fill the fields of a `struct stat` that you've
//   pointed to. Returns `-1` on error.

//   >**Hint**: Use `%10lld` to print the size in a field of width 10

//   ```c
//   // Example stat() usage

//   struct stat buf;

//   stat("./lsls.c", &buf);

//   printf("file size is %lld\n", buf.st_size);
//   ```

//  > Note: The specification for the `stat` system call does not specify exactly how directories should be treated. This means you might see weird behavior when your `lsls` prints out the sizes of directories, such all their sizes being 0 or all their sizes being 512, or some other such strange behaviors. This is not a mistake on your part, 
//  it was simply just not specified how this should work as part of the spec.


// ### Follow the general approach outlined below to get started on your project:

// 1. Call `opendir()`.
// 2. Then repeatedly call `readdir()`--printing the filenames as you go--until it
//    lets you know there are no more directory entries by returning `NULL`.
// 3. Then call `closedir()`.

//   You don't have to write the three functions, above. They're _system calls_ built into the OS.

// >**Hint** _You are expected to use Google to find examples of how to use these functions._


/**
 * Main
 */

//   You don't have to write the three functions, above. 
// They're _system calls_ built into the OS.
// Use Google!

// Remember!
// gcc -o lsls lsls.c
// ./lsls
// open another terminal window and ps al for a process list command
// S+ ./lsls means is in some form of sleep because it is wainting for keyboard input.

/**
 * Main
 */
int main(int argc, char **argv)
{
  // Parse command line
  // char *dir_path;
  // printf("There are %d command line argument(s):\n", argc);


// A buffer is an area of memory, set aside for temporary storage of data. 
// a data buffer (or just buffer) is a region of a 
// physical memory storage used to temporarily store data while it is being 
// moved from one place to another.
  struct stat buf;
  (argv > 1) ? stat(argv[1], &buf) : stat("./lsls.c", &buf); // Set the file size of directory
//   ```c
//   // Example stat() usage
//   struct stat buf;
//   stat("./lsls.c", &buf);
//   printf("file size is %lld\n", buf.st_size);
//   ```
  printf("\n");
  printf("The file size is: %10lld\n", buf.st_size); // Print the file size
  // Use `%10lld` to print the size in a field of width 10
  printf("\n");

  int i;
  for (i = 0; i < argc; i++)
  {
    printf("\n");
    printf("Name of directory: %s\n", argv[i]);
    printf("\n");
  }

  DIR *d;
  struct dirent *directory;

  // Open directory
  d = (argc > 1) ? opendir(argv[1]) : opendir("."); // The opendir() function opens a directory stream 
  // corresponding to the directory name, and returns a pointer to the directory stream. 
  // The stream is positioned at the first entry in the directory.
  if (d)
  {
    // Repeatly read and print entries
    while ((directory = readdir(d)) != NULL) // 2. Then repeatedly call `readdir()`--printing the filenames as you go--until it
    // lets you know there are no more directory entries by returning `NULL`.
    {
      printf("Size and names of all entries in directory: Name: %s / Size: %10lld\n", directory->d_name, buf.st_size);
      // struct dirent has field `d_name` in it. 
      // You should print the field `d_name` from your `struct dirent
      // (You don't need to declare this `struct dirent` type. It's already included in `<dirent.h>`.)
      printf("\n");
    }
    // ```c
    // struct dirent *ent;
    // // ... some of your code ...
    // ent = readdir(d);
    // printf("%s\n", ent->d_name);
    // ```

    // Close directory
   closedir(d); // 3. Then call `closedir()`.

  return 0;
  }
}