# 📚 Libft - Personal C Library

A comprehensive C library containing reimplemented standard library functions and additional utilities, developed as part of the 42 School curriculum.

## 🚀 Features

This library includes custom implementations of standard C library functions, organized into logical modules:

### 📋 Function Categories

#### 🔍 **Character Classification** (`ft_is/`)
- `ft_isalpha` - Check if character is alphabetic
- `ft_isdigit` - Check if character is numeric
- `ft_isalnum` - Check if character is alphanumeric
- `ft_isascii` - Check if character is ASCII
- `ft_isprint` - Check if character is printable

#### 🧠 **Memory Management** (`ft_mem/`)
- `ft_memset` - Fill memory with a constant byte
- `ft_bzero` - Zero out memory
- `ft_memcpy` - Copy memory area
- `ft_memmove` - Copy memory area (handles overlap)
- `ft_memchr` - Scan memory for a character
- `ft_memcmp` - Compare memory areas
- `ft_calloc` - Allocate and zero memory
- **🏟️ Arena Allocator** (`ft_arna.c`)
  - `ft_arnalloc` - Arena-based memory allocation
  - `ft_arna_free` - Free entire arena
  - `ft_arn_calloc` - Arena-based calloc

#### 🔤 **String Manipulation** (`ft_str/`)
- `ft_strlen` - Calculate string length
- `ft_strlcpy` - Size-bounded string copy
- `ft_strlcat` - Size-bounded string concatenation
- `ft_strchr` - Locate character in string
- `ft_strrchr` - Locate character in string (reverse)
- `ft_strncmp` - Compare strings up to n characters
- `ft_strnstr` - Locate substring
- `ft_strdup` - Duplicate string
- `ft_substr` - Extract substring
- `ft_strjoin` - Join two strings
- `ft_strjoin3` - Join three strings
- `ft_strtrim` - Trim characters from string
- `ft_split` - Split string by delimiter
- `ft_strmapi` - Apply function to each character
- `ft_striteri` - Apply function to each character with index

**Arena-based String Functions:**
- `ft_arn_strdup` - Arena-based string duplication
- `ft_arn_strjoin` - Arena-based string joining
- `ft_arn_substr` - Arena-based substring extraction
- `ft_arn_split` - Arena-based string splitting

#### 🔢 **Type Conversion** (`ft_to/`)
- `ft_atoi` - String to integer
- `ft_atol` - String to long
- `ft_itoa` - Integer to string
- `ft_arn_itoa` - Arena-based integer to string
- `ft_toupper` - Convert to uppercase
- `ft_tolower` - Convert to lowercase

#### 📤 **Output Functions** (`ft_put/`)
- `ft_putchar_fd` - Output character to file descriptor
- `ft_putstr_fd` - Output string to file descriptor
- `ft_putendl_fd` - Output string with newline to file descriptor
- `ft_putnbr_fd` - Output number to file descriptor

#### 🔗 **Linked Lists** (`ft_lst/`)
- `ft_lstnew` - Create new list element
- `ft_lstadd_front` - Add element at beginning
- `ft_lstadd_back` - Add element at end
- `ft_lstsize` - Count list elements
- `ft_lstlast` - Get last element
- `ft_lstdelone` - Delete one element
- `ft_lstclear` - Delete and free list
- `ft_lstiter` - Apply function to each element
- `ft_lstmap` - Apply function and create new list
- `ft_arn_lstnew` - Arena-based list creation

#### 📄 **File I/O** (`ft_gnl/`)
- `get_next_line` - Read line from file descriptor
- `arn_get_next_line` - Arena-based get next line

#### 🖨️ **Formatted Output** (`ft_printf/`)
- `ft_printf` - Formatted output to stdout
- `ft_dprintf` - Formatted output to file descriptor
- Support for: `%c`, `%s`, `%p`, `%d`, `%i`, `%u`, `%x`, `%X`, `%%`

#### 🧹 **Memory Cleanup** (`ft_free/`)
- `ft_free_tab` - Free array of strings

## 🏗️ Build System

### Compilation
```bash
make        # Build the library
make clean  # Remove object files
make fclean # Remove object files and library
make re     # Rebuild everything
```

### Testing
```bash
make test   # Compile and run tests
```

## 🔧 Installation & Usage

1. **Clone the repository:**
   ```bash
   git clone <repository-url>
   cd libft
   ```

2. **Build the library:**
   ```bash
   make
   ```

3. **Include in your project:**
   ```c
   #include "libft.h"
   ```

4. **Link during compilation:**
   ```bash
   gcc -Wall -Wextra -Werror your_file.c -L. -lft -o your_program
   ```

## 🎯 Special Features

### 🏟️ Arena Allocator
This library includes a custom arena allocator system that provides:
- **Memory pooling**: Efficient allocation of multiple small objects
- **Automatic cleanup**: Free entire arena at once with `ft_arna_free()`
- **Performance**: Faster allocation for temporary objects
- **Safety**: Reduces memory leaks in complex programs

Example usage:
```c
char *str1 = ft_arn_strdup("Hello");
char *str2 = ft_arn_strjoin(str1, " World");
// ... use strings ...
ft_arna_free(); // Free all arena-allocated memory at once
```

### 📏 Buffer Size Configuration
The `get_next_line` functions use a configurable buffer size:
```c
#define BUFFER_SIZE 10  // Adjustable in libft.h
```

## 📊 Project Structure

```
libft/
├── Makefile           # Build configuration
├── README.md          # This file
├── Sources.mk         # Source file listing
├── include/           
│   └── libft.h        # Main header file
├── src/               # Source files organized by category
│   ├── ft_is/         # Character classification
│   ├── ft_mem/        # Memory management + Arena allocator
│   ├── ft_str/        # String manipulation
│   ├── ft_to/         # Type conversion
│   ├── ft_put/        # Output functions
│   ├── ft_lst/        # Linked list operations
│   ├── ft_gnl/        # Get next line
│   ├── ft_printf/     # Formatted output
│   └── ft_free/       # Memory cleanup
└── tests/             # Test files
```

## 🎨 Code Style

- **Norm compliant**: Follows 42 School coding standards
- **Modular design**: Functions organized by category
- **Consistent naming**: Clear `ft_` prefix for all functions
- **Arena variants**: Special `arn_` functions for arena allocation
- **Error handling**: Robust null pointer and edge case handling

## 🛠️ Compiler Flags

The library is compiled with strict flags:
- `-Wall` - Enable all warnings
- `-Wextra` - Enable extra warnings
- `-Werror` - Treat warnings as errors

## 🏆 42 School Project

This library was developed as part of the 42 School curriculum, demonstrating:
- Deep understanding of C standard library functions
- Memory management expertise
- Custom implementation skills
- Modular programming practices

## 📝 License

This project is part of the 42 School curriculum. Please respect academic integrity guidelines when using this code.

---

*Built with ❤️ for the 42 School community*