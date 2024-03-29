# 📚 Printf Project README 📚

Welcome to the ft_Printf project from the 42 London Core Curriculum! I had so much fun recreating the wonderful yet _forbidden_ function printf! Now we can finally add it to our Libft library to use for the rest of our studies at 42!
This project aims to enhance your understanding of string formatting and handling variable arguments in the C programming language.

## ❗❗RTFM❗❗

### Dont be lazy. Before looking for tutorials and guides for your projects, read the _project pdfs_!!!

## How This README Can Help

This README serves as a comprehensive guide, offering clear explanations of each function, hints for implementation, and insights into fundamental C programming concepts related to the Printf project.

## ⚠️ Disclaimer / Please Read ⚠️

### Attention Fellow learners

This project is designed to be a *learning resource*, not a *shortcut*. Copying without understanding the underlying concepts is a disservice to your own growth as a developer.

### _Understand, Don't Copy:_

Copying is easy; understanding is invaluable. How does diving into the code with a curious mind transform your learning experience?

### _Learn, Don't Cheat:_

Cheating is not the goal here. You're not here to trick anyone; you're here to become a better programmer. The shortcuts might seem enticing, but the long road of understanding is far more rewarding. Curiosity is Your Superpower:

### _Be endlessly CURIOUS._

Curiosity is what makes the difference between a good developer and a GREAT developer. Ask "why" at every corner, challenge assumptions, and explore alternatives. This project is your playground; make the most of it.

#### 💻 In the end, this isn't just about coding; it's about embracing a mindset of perpetual learning. Use this project as a guide, a mentor, and a challenge to hone your skills. Happy coding and, above all, stay curious! 🚀🔍

## ❗ Getting Started

Before diving into the code, make sure you understand the following basic concepts:

### Format Specifier Table:
| Specifier | Meaning                                      |
|-----------|----------------------------------------------|
| %c        | Character                                    |
| %s        | String                                       |
| %p        | Pointer address                              |
| %d, %i    | Signed decimal integer                       |
| %u        | Unsigned decimal integer                     |
| %x, %X    | Unsigned hexadecimal integer (lower/uppercase)|
| %%        | Percent symbol                               |

### 💭 Thinking Tip

**Question:** Ever wondered how a pointer address is displayed when using %p in your format specifier? 🤔 

**%d vs %i:** They are both an `int`, but there is a difference! _Do you know what it is? (hint: scanf)_ 
Why do you think we might need both for our printf project?
Consider scenarios where both `%d` and `%i` are used. Additionally, think about how *scanf* treats these format specifiers and what consequences a mismatch might have.

## Return Value of Printf (int)

The prototype of the `printf` function is constructed as follows:
```
int ft_printf(const char *format, ...);
```
The _printf_ function returns a value of type _int_. **But why?**

## Variadic Functions and stdarg.h

It's crucial to grasp the concept of **variadic functions**, which are essential in this project and understanding printf. 
The `stdarg` library introduces a new type of variable, `va_list`, along with three very important macros: `va_start`, `va_arg`, and `va_end`.

### 📖 Variadic Functions

A variadic function is a function that can accept a variable number of arguments. In the context of the Printf project, the `printf` function itself is a classic example of a variadic function. Variadic functions provide flexibility by allowing different numbers of arguments to be passed to the function.

### 📚 stdarg.h Library

The `stdarg.h` library provides a set of macros and functions to work with variadic functions. Here are the key components:

### va_list

- **Definition:** A type representing a variable-length argument list.
- **Usage:** Declare a `va_list` variable to access the arguments.

```c
#include <stdarg.h>
va_list args;
```

### va_start

- **Definition:** Initializes the `va_list` to point to the first unnamed argument.
- **Usage:** Call `va_start` before accessing the variable arguments.
```c
va_start(args, last_named_arg);
```
`args`: The `va_list` variable.
`last_named_arg`: The last named parameter before the variable arguments.

### va_arg

- **Definition:** Retrieves the next argument from the `va_list`.
- **Usage:** Call `va_arg` to get the value of the next argument.

```c
type value = va_arg(args, type);
```
`args`: The `va_list` variable.
`type`: The type of the next argument.

### va_end

- **Definition:** Cleans up the `va_list` after variable argument processing.
- **Usage:** Call `va_end` when finished using the variable arguments.
```c
va_end(args);
```
`args`: The `va_list` variable.

### How to use them:

```c
#include <stdarg.h>

void example_function(int num, ...) {
    va_list args;
    va_start(args, num);
    int value = va_arg(args, int);
    va_end(args);
}
```

## Printf Project Overview

Now that you understand variadic functions a little better, let's break down *printf*. The `printf` function is designed to output each character of the initial string sequentially. When it encounters a `%`, it signals the beginning of a format specifier, indicating the type of the next variable argument.

### 🚀 Process Breakdown

1. **Print Characters:** Iterate through the string, printing each character until a `%` is encountered.

2. **Identify Format Specifier:** Identify the type of the next variable argument based on the character following `%`.

3. **Display Variable Argument:** Call a corresponding method to display the argument, depending on its type.
   - For example, if it's an `s`, display a string; if it's a `d`, display a number, and so on.

4. **Repeat Steps:** Repeat steps 1-3 until the entire string is processed (i.e., until a null character `\0` is encountered).

5. **Count Characters:** Keep track of the number of characters printed at each step to return the total count at the end of the function.

Understanding this sequential process is crucial for developing an efficient `printf` function. It guides us in creating the necessary logic to handle different format specifiers and variable argument types.

# 📚 Functions Explained 📚

## ft_printf(const char *arg, ...)
**Purpose:**
Formats and prints data according to a format specifier.

**How to Use:**
Call this function, passing the format string and any required arguments.

**Return Value:**
Returns the number of characters printed (excluding the null byte).

**Hints:**
```c
/* To build this function, consider the following steps: */
/* - Use va_list to handle variable arguments */
/* - Loop through the format string */
/* - Identify format specifiers and call corresponding functions to handle each case */
/* - Print characters as needed and keep track of the count */
/* - Return the total count of characters printed */
```

## ft_format(const char *str, va_list args)
**Purpose:**
Handles the formatting of specific format specifiers.

**How to Use:**
Called by ft_printf. Processes the format string and delegates the printing of each specifier.

**Return Value:**
Returns the number of characters printed for the specific format specifier.

**Hints:**

```c
/* To build this function, consider the following steps: */
/* - Use a switch or if-else statements to identify and handle each format specifier */
/* - Delegate the printing of each specifier to corresponding functions */
/* - Return the count of characters printed for the specific specifier */
```
## If this guide was helpful, consider starring the repository! ⭐️

# Contribution
This README is written to ease the learning journey for future 42 students. Your contributions, insights, and improvements are welcome. 
Together, let's make the path to completing 42 Common Core a bit smoother for those who follow.
