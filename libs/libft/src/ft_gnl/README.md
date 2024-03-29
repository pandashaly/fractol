
# 📚 Get Next Line (GNL) Project README 📚

Welcome to the Get Next Line (GNL) project, an integral part of the 42 London Core Curriculum, challenging students to develop a deeper understanding of file manipulation and dynamic memory allocation(malloc & free). 

This project is designed to equip students with the skills to write a function that will efficiently read lines from a file descriptor in the C programming language. 







# ❗❗RTFM❗❗

## Dont be lazy. Before looking for tutorials and guides for your projects, read the _project pdfs_!!!

## How This README Can Help
This README serves as a comprehensive guide, providing clear explanations of each function, hints for implementation, and insights into fundamental C programming concepts. 

## ⚠️ Disclaimer / Please Read ⚠️

### Attention Fellow learners

First and foremost, this project is meant to be a *learning resource*, not a *shortcut*. Copying and pasting the code without understanding the underlying concepts is a disservice to your own growth as a developer.

### _Understand, Don't Copy:_

Resist the temptation to copy blindly. Yes, it might save time momentarily, but the real magic happens when you unravel the logic, face the challenges, and truly understand what each line of code does.

### _Learn, Don't Cheat:_

Cheating is not the goal here. You're not here to trick anyone; you're here to become a better programmer. The shortcuts might seem enticing, but the long road of understanding is far more rewarding.
Curiosity is Your Superpower:

### _Be endlessly CURIOUS._

Curiosity is what makes the difference between a good developer and a GREAT developer. Ask "why" at every corner, challenge assumptions, and explore alternatives. Think like a child—constantly questioning. This project is your playground; make the most of it.

#### 💻 In the end, this isn't just about coding; it's about embracing a mindset of perpetual learning. Use this project as a guide, a mentor, and a challenge to hone your skills. Happy coding and, above all, stay curious! 🚀🔍
## ❗ Getting Started

Before diving into the code, make sure you understand the following basic concepts:

### 📖 Memory Allocation (malloc)
**Definition:**
malloc is a function in the C that dynamically allocates a specified number of bytes of memory during program execution.

**Why we use it:** We use malloc when we need memory that persists beyond the scope of the current function, especially for strings or buffers.

**How to Use:**
```
char *ptr = (char *)malloc(size);
if (ptr == NULL) {
    /* Handle allocation failure */
}
/* Use 'ptr' for memory operations */ 
```
**Library:** _<stdlib.h>_

**Manual:** Type _man_ malloc in the terminal for the manual.

### 📖 Memory Deallocation (free)
**Definition:** free is a function in the C releases previously allocated memory.

**Why Use:** We use free to prevent memory leaks, ensuring that allocated memory is returned to the system when no longer needed.

**How to Use:**
```
free(ptr);
ptr = NULL; /* Optional but good practice to avoid using freed memory */
```
**Library:** _<stdlib.h>_

**Manual:** _man free_.

### 📖 File Reading (read)

**Definition:**
read is a system call in Unix-like operating systems that reads data from a file descriptor.

**Why Use:** We use read to read data from files or other input sources, often in chunks to optimize performance.

**How to Use:**
```
ssize_t bytes_read = read(fd, buffer, size);
if (bytes_read == -1) {
    /* Handle read error */
}
/* Process the read data in 'buffer' */
```
**Library:** _<unistd.h>_

**Manual:** _man read_

### 📖 Buffer Size (BUFFER_SIZE)

**Definition:** BUFFER_SIZE is a constant representing the size of the buffer used for reading data, typically defined at the beginning of the program.

**Why it's Important:** The buffer size determines how much data is read at once, impacting the efficiency of reading operations.

**How to Define:** At the top of your program: _#define BUFFER_SIZE 42_ (adjust size as needed).

### 📖 File Descriptor (fd)
**Definition:** A file descriptor (fd) is a non-negative integer representing an open file or input/output resource.

**Why it's Important:** File descriptors are crucial for performing operations on files, sockets, or other input/output devices.

**How to Use:** Obtained through functions like open or socket, and then used in operations like read, write, or close.

**Library:** <fcntl.h> (for functions like open)

**Manual:** _man open_

#### ❗Understanding these basic concepts is fundamental for effective C programming. They allow you to manage memory, interact with files, and ensure efficient data processing in your programs. Always refer to the manual pages for detailed information and guidance. Remember, BE CURIOUS!❗
# 📚 Functions Explained 📚

### get_next_line(int fd)
**Purpose:**
 Reads a line from the specified file descriptor (fd).

**How to Use:**
 Call this function, passing the file descriptor as an argument.

**Return Value:**
Returns the read line as a string, or NULL if there's an error or no more lines.

**Hints:**
```
/* To build this function, consider the following steps: */
/* - Check for valid parameters */
/* - Use a helper function to read data from the file descriptor */
/* - Use a helper function to extract lines from the read data */
/* - Update and manage the memory for any remaining content */
/* - Return the read line or NULL if there's an error or no more lines */
```
### ft_readfd(int fd, char *save)
**Purpose:** Reads data from the file descriptor in chunks, updates the save variable, and ensures lines are complete.

**How to Use:** Called by get_next_line. Manages reading data and updating the save variable.

**Return Value:** Returns the updated save variable containing read data, or NULL in case of an error.

**Hints:**
```
/* To build this function, consider the following steps: */
/* - Allocate memory for a buffer */
/* - Use a loop to read data from the file descriptor in chunks */
/* - Update the save variable with the read data */
/* - Check for newline characters to determine when to stop reading */
/* - Return the updated 'save' variable or NULL if there's an error */
```
### ft_line(char *buff)
**Purpose:** Extracts a line from the given string (buff) until a newline is encountered.

**How to Use:** Called by get_next_line. Extracts lines for further processing.

**Return Value:** Returns the extracted line as a string, or NULL if there's an error or the end of the string is reached.

**Hints:**
```
/* To build this function, consider the following steps: */
/* - Loop through the string until a newline character is encountered */
/* - Allocate memory for the extracted line */
/* - Copy characters to the new line until a newline or the end of the string is reached */
/* - Add a newline character to the end of the line if needed */
/* - Return the extracted line or NULL if there's an error or the end of the string is reached */
```

### ft_afternl(char *str)
**Purpose:** Handles the remaining content of a string after a newline character and updates the save variable.

**How to Use:** Called by get_next_line. Deals with any content left in the buffer after extracting a line.

**Hints:**
```
/* To build this function, consider the following steps: */
/* - Find the position of the newline character in the string */
/* - Allocate memory for the remaining content after the newline character */
/* - Copy the remaining content to the new memory location */
```

### ft_strjoin & ft_strlen
#### _Note:_ No hints will be provided for _ft_strjoin_ or _ft_strlen_. 🙅‍♀️ At this stage, you're expected to be familiar with both. If you're not, then **_RTFM_**!!!❗


🤔 **Why might you need to concatenate two strings for your GNL?**
Consider how combining strings is essential for handling and manipulating line data efficiently.

🤔 **Why might you need to know the length of a string?**
Think about situations where understanding the length of a string is crucial for proper memory allocation and manipulation in GNL.

🤔 Reflect on how ft_strlen and ft_strjoin play a key role in reading lines from a file in GNL.


# Contribution
This README is a collective effort to ease the learning journey for future 42 students. Your contributions, insights, and improvements are welcome. Together, let's make the path to mastering Get Next Line a bit smoother for those who follow.
