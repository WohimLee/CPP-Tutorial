&emsp;
# Appendix - C string

## strcspn
>头文件、声明
```c
#include <string.h>
size_t strcspn(const char *str1, const char *str2)
```
- 描述: 检索字符串 str1 开头连续有几个字符都不含字符串 str2 中的字符
- 参数
    - str1: 要被检索的 C 字符串
    - str2: 该字符串包含了要在 str1 中进行匹配的字符列表
- 返回值: 该函数返回 str1 开头连续都不含字符串 str2 中字符的字符数
>Example
```c++
while (fgets(buffer, BUFFER_SIZE, file)) {
    // Remove trailing newline
    buffer[strcspn(buffer, "\n\r")] = 0;
    ...
}
```
- `buffer[strcspn(buffer, "\n\r")] = 0;`: This line is a clever way to remove the trailing newline character from the buffer.
    - `strcspn(buffer, "\n\r")` is a function that scans buffer for the first occurrence of any of the characters that are in the string "\n\r", which represents both the Unix (\n) and Windows (\r\n) line endings. It returns the number of characters before the first occurrence of any of the characters in the search string.
    - `buffer[strcspn(buffer, "\n\r")]` accesses the position in the buffer where the newline or carriage return character would be located if one is present.
    - `= 0;` sets that position in the buffer to the `null` character `'\0'` (with `0` being equivalent to `'\0'` in this context), effectively truncating the string at that point and removing the newline character.

&emsp;
## strtok
分解字符串为一组字符串。s 为要分解的字符串，delim 为分隔符字符（如果传入字符串，则传入的字符串中每个字符均为分割符）。取第一个片段调用时，s指向要分解的字符串，之后再次调用要把s设成NULL
>头文件、声明
```c
#include <string.h>
char* strtok(char s[], const char* delim)
char* strtok(char* str, const char* delimiters );
```
- 描述: sep 参数是个字符串，定义了用作分隔符的字符集合。第一个参数指定一个字符串，它包含了 0 个或者多个由 sep 字符串中一个或者多个分隔符分割的标记
- 返回值: 返回值为 char* 类型。如果找到标记，则为指向标记开头的指针。否则为空指针。当在正在扫描的字符串中达到字符串的末尾（即空字符）时，始终返回空指针

>Example
```c++
void processCSVRow(char *line, CSVRow *row) {
    char *token;
    int arcIdx = 0;
    
    // Start tokenizing the line by commas
    token = strtok(line, ",");
    if (token != NULL) {
        row->idx = atoi(token);
        token = strtok(NULL, ",");
    }

    if (token != NULL) {
        strncpy(row->roomType, token, sizeof(row->roomType));
        token = strtok(NULL, ",");
    }

    if (token != NULL) {
        strncpy(row->description, token, sizeof(row->description));
        token = strtok(NULL, ",");
    }

    // Tokenize and store the arcs in the arcs array
    while (token != NULL) {
        row->arcs[arcIdx++] = atoi(token);
        token = strtok(NULL, ",");
    }
    row->arcCount = arcIdx;
}
```
- `token = strtok(NULL, ",");`: After processing the first token, token = strtok(NULL, ","); is called. This tells strtok to continue from where it left off in the original string line. The NULL argument signifies that strtok should keep using the string you first gave it. It will find the next token in the string by searching for the next delimiter (,). If found, the delimiter is replaced by a null terminator (\0) in the original string, and strtok returns a pointer to the next token.


&emsp;
## strncpy
strncpy 函数用于将指定长度的字符串复制到字符数组中，是 C 语言的库函数之一，来自 C语言标准库，定义于 string.h。
```c
#include <string.h>
char *strncpy(char *dest, const char *src, int n)
```

- 把 src 所指向的字符串中以 src 地址开始的前 n 个字节复制到 dest 所指的数组中
- 并返回被复制后的des

&emsp;
## strcmp
strcmp 函数是 string compare (字符串比较)的缩写，用于比较两个字符串并根据比较结果返回整数

>声明
```c++
strcmp(str1,str2)
```
- 若 str1 = str2, 则返回零
- 若 str1 < str2, 则返回负数
- 若 str1 > str2, 则返回正数
>Example
```c++
#include <stdio.h>
#include <string.h>

int main() {
    char a[10] = "hello";
    char* b = "World";

    if (strcmp(a, b) == 0) {
        printf("The strings are equal.\n");
    } else {
        printf("The strings are not equal.\n");
    }

    return 0;
}
```


