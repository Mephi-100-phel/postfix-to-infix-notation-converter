
# Postfix to infix notation converter

*This project is a product of a practical task for my algorithms and data structures course at uni*

This program converts math formulas from postfix notation into infix notation using stack (with limitaions - see [Usage And Examples](@usage-and-examples)).

This program has 2 implementations - list-based stack and vector-based stack. But algorithm for both of these implementations is the same.
## Author

- [@Mephi-100-phel](https://github.com/Mephi-100-phel)


## Run Locally

Clone the project

```bash
  git clone https://github.com/Mephi-100-phel/postfix-to-infix-notation-converter
```

Go to the project directory

```bash
cd <directory with downloaded project>
```

Make is used to compile this project.

There are 2 variables for make - **LIB** and **STRUCT**. Next 2 sections contain description of these variables.

**LIB variable:**

This variable is used to set linkage to either *static* or *dynamic*

If you want your library to be dynamically linked - variable LIB should be set to *dynamic* like this:

```bash
make LIB=dynamic
```

If you want your library to be statically linked - don't specify any value for LIB variable, or you may explicitly specify it to be *static* like this:

```bash
make LIB=static
```

**STRUCT variable:**

This variable is used to set the base implementation of stack - using either *list* or *vector*.

If you want the program to use list-based stack - set the value of the STRUCT variable to *list* like this:

```bash
make STRUCT=list
```

If you want the program to use vector-based stack - don't specify any value for STRUCT variable, or you may explicitly specify it to be *vector* like this:

```bash
make STRUCT=vector
```

Every combination of these variables will work correctly. For example if you wanted this program to use list-based stack and have a dynamically linked library you would do it like this:

```bash
make LIB=dynamic STRUCT=list
```

To run the program:

```bash
./lab2.out <size of stack>
```

*Size of stack* - is an integer, which specifies stack size (makes real difference only in vector implementation). By default set to 5.
## Usage And Examples

After you start the program, it will ask you to enter math formula in postfix notation.

In this formula only variables (letters of the English alphabet) and operators '+', '-', '*', '/' can be used. These operations are all equal for the program (have the same mathematical operation priority).

Output formula has brackets added to show mathematical operation priority, which was determined by the program.

If a formula is incorrect or stack is overflowing (can happen if vector-based stack is used and size of base vector is too little to store required data) or any other error occured - program will notify you with a message and end right after that.

**Examples:**

1. **Correct execution:**

Input:

```txt
abc++d*e-
```

Output:

```txt
(((a+(b+c))*d)-e)
```

2. **Only variable:**

*This input is considered valid by the program.*

Input:

```txt
a
```

Output:

```txt
a
```

3. **Invalid syntax:**

Input:

```txt
a+
```

Output:

```txt
INVALID_SYNTAX
```

4. **Stack overflow:**

*This error can occur if vector-based stack is specified to have too little space.*

```bash
make STRUCT=vector
./lab2.out 1
```

Input:

```txt
ab+
```

Output:

```txt
STACK_FULL
```