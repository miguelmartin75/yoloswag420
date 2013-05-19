- [1 Introduction](#1)
	- [1.1 Disclaimer](#1.1)
- [2 Source Files](#2)
	- [2.1 Standard Extension](#2.1)
- [3 Syntax](#3)
	- [3.1 Structure of a Program](#3.1)
    - [3.2 Statements](#3.2)
	- [3.3 Whitespace](#3.3)
	- [3.4 Comments](#3.4)
		- [3.4.1 Single-line Comments](#3.4.1)
		- [3.4.2 Multi-line Comments](#3.4.2)
	- [3.5 Variables](#3.5)
		- [3.5.1 Generalised Syntax](#3.5.1)
		- [3.5.2 Types](#3.5.2)
            - [3.5.2.1 txt](#3.5.2.1)
            - [3.5.2.2 #](#3.5.2.2)
	- [3.6 Tokens](#3.6)
		- [3.6.1 Keywords](#3.6.1)
		- [3.6.2 Literals](#3.6.2)
            - [3.6.2.1 String Literals](#3.6.2.1)
            - [3.6.2.2 Number Literals](#3.6.2.2)
	- [3.7 In-built Commands](#3.7)
		- [3.7.1 prnt](#3.7.1)
		- [3.7.2 inpt](#3.7.2)
- [4 Design Decisions](#4)
	- [4.1 Design History](#4.1)
        - [4.1.1 V0.1](#4.1.1)
        - [4.1.2 V0.2](#4.1.2)
	- [4.2 Reasons for Design](#4.2)
- [5 Feature TODO List](#5)

---

# <a href="#1" id="1">1 Introduction</a>

This document is the official reference manual for the yoloswag420 programming language. 
It is assumed you have prior knowledge in programming. This document contains:

1. General structure of a yoloswag420 program
2. Syntax of the language
3. Available commands of the language
4. Tips and hints

---
## <a href="#1.1" id="1.1">1.1 Disclaimer</a>

yoloswag420 is currently being developed, so things may drastically change during the development stage. Please be aware of this, so the site may not have updated information at the time you are reading this. However, I will try my best to keep this page updated, if any changes/additions occur.

# <a href="#2" id="2">2 Source Files</a>
This section discusses source file standards for the yoloswag420 language.

## <a href="#2.1" id="2.1">2.1 Standard Extension</a>
The standard extension for the yoloswag420 language is `*.ys`. The official interpreter doesn't care what extension you use, however it is suggested you use the extension so you (and other people) can recognise it is yoloswag420 code.

# <a href="#3" id="3">3 Syntax</a>
This section describes the syntax of the language, including how to structure a program and possbily some hints and tips.

## <a href="#3.1" id="3.1">3.1 Structure of a Program</a>
This section describes the structure of a program.

A typical program written in yoloswag420 has the following structure:

	#yoloswag
	
	#420

Where the keywords `#yoloswag` resembles the beginning of the program and `#420` resembles the end of the program. Anything in-between those two keywords describe the program itself.

Here is the equavilent code in other languages:

### C and C++

	int main(int argc, char* argv[]) 
	{
		return 0;
	}
	
### Java
	
	class Program
	{
		static void main(String[] args)
		{
		}
	}
	
### C#

	class Program
	{
		static void Main(string[] args)
		{
		}
	}

## <a href="#3.2" id="3.2">3.2 Statements</a>
A statement has the following syntax:

    <statement> plz

Where `plz` is required, as it is the keyword to describe that it is the end of the statement. And, where `<statement>` is a valid statement of the program. What you can write in the statement is dicussed further down.


## <a href="#3.3" id="3.3">3.3 Whitespace</a>

The yoloswag420 program is whitespace insensitive, like most languages. This means that, the following code:

	#yoloswag
	
	#420
	
Is equivalent to:

	#yoloswag#420
	
## <a href="#3.4" id="3.4">3.4 Comments</a>
Comments are notes for the programmer to read whilst reading code 

There are only single line comments (so far). Multi-line comments may be added in the future.

### <a href="#3.4.1" id="3.4.1">3.4.1 Single-line Comments</a>
`<3` starts a single line comment.

#### EXAMPLE

	<3 This is a single line comment #swag

## <a href="#3.4.2" id="3.4.2">3.4.1 Multi-line comments</a>
Multi-line comments are not currently not supported.

## <a href="#3.5" id="3.5">3.5 Variables</a>

Variables are declared by their type explicitly, as yoloswag420 is statically typed. I may add dynamic typed variables in the future, but as for now, there is none.

### <a href="#3.5.1" id="3.5.1"> 3.5.1 Generalised Syntax</a>

The syntax for declaring a variable is as follows:

	<type> <name> [= value] plz
	
Where `<type>` is the type of your variable, and where `<name>` is the name of your variable. And where `[= value]` is an optional value you may assign your variable to.

### <a href="#3.5.2" id="3.5.2">3.5.2 Types</a>
As of currently, there are no way to define your own type of variables (i.e. no classes).

### <a href="#3.5.2.1" id="3.5.2.1">3.5.2.1 txt</a>
`txt` resembles a string of text.

#### For Example

	txt example = "This is an example" plz

### <a href="#3.5.2.2" id="3.5.2.2">3.5.2.2 #</a>

`#` represents a decimal number. It is implemented as a double floating point in C++, which is 64 bits on most systems.

#### For Example

	# example = 42.5 plz

# <a href="#3.6" id="3.6">3.6 Tokens</a>

This section discusses the tokens of the language. A token is a single element in the source code of a programming language, which describes the syntax of it. 

Read more about tokens on [Wikipedia](https://en.wikipedia.org/wiki/Lexical_analysis#Token).

#### For Example:

	#yoloswag
	
	#420

Where `#yoloswag` and `#420` are keyword tokens.

## <a href="#3.6.1" id="3.6.1">3.6.1 Keywords</a>

Here is a list of all reserved keywords and their equivalent meaning in other programming languages:

| Keyword | C 						| C++                 | C#              | Java
|--------|----------------------|---------------------|----------------|----
| `#yoloswag`* | N/A | N/A | N/A | N/A
| `#420`* | N/A | N/A | N/A | N/A
| `txt`  | `char*` | `std::string`      | `string`      | `String` 
| `#` | `double` | `double` | `double` | `double`
| `prnt` | `printf()` | `std::cout` | `Console.Write()` | `System.out.print()`
| `inpt` | `gets()` | `std::cin` | `Console.ReadLine()` | `Scanner.next()`

*These keywords do have an alternative in other languages, however the direct meaning doesn't translate to another keyword.

## <a href="#3.6.2" id="3.6.2">3.6.2 Literals</a>

Constants and literals are un-mutable, they are used to assign variables to values (see [section 3.5](#3.5)).

### <a href="#3.6.2.1" id="3.6.2.1">3.6.2.1 String Literals</a>
A string literal is described in-between enclosing double quotation marks. A string literal describes an un-mutable string. You may refer to a string literal as you would with a `txt` variable, but you may not change the value of a string literal.

#### i.e.

The following snippets of code are equivalent:

	txt message = "Hello World" plz
	print message plz
	
and

	prnt "Hello World" plz
	
The following code is illegal:

	"Hello World" = "Cheese" plz

### <a href="#3.6.2.2" id="3.6.2.2">3.6.2.2 Number Literals</a>
A number literal (constant) is described as a decimal number, there are no prefixes or suffixes for number literals. You may refer to a number constant as you would with a `#` variable, but you may not change the value of a number literal.

i.e.

The following snippets of code are equivalent:

	# threePointFive = 3.5 plz
	print threePointFive plz
	
and

	prnt 3.5 plz

The following code is illegal:

	3.5 = 42 plz

## <a href="#3.7" id="3.7">3.7 In-built Commands</a>
This sections describes the in-built commands in yoloswag420.

### <a href="#3.7.1" id="3.7.1">3.7.1 prnt</a>

The prnt command stands for "print".

Here is the syntax of the usage:

    prnt <message> plz

Where <message> is a `txt` or `#` variable or constant.

### <a href="#3.7.2" id="3.7.2">3.7.2 inpt</a>

The inpt command stands for "input". This command simply gets user input from the console, and returns a `txt` variable.

# <a href="#4" id="4">4 Design Decisions</a>

This section describes design decisions for the yoloswag420 language.

## <a href="#4.1" id="4.1">4.1 Design History</a>
This section describes all previous designs of the yoloswag420 language.

### <a href="#4.1.1" id="4.1.1.">4.1.1 V0.1</a>

The initial design for the yoloswag420 language had support for functions and slight differences in the syntax.

Initially, the language looked some-what like this:

    #swag yolo

    #420

Where `#swag` would define a function, and `yolo` was the name of the function, `#420` ended the function body. `yolo` was equivalent to `main` in C-like languages; the function that gets called on the start of the program. 

### <a href="#4.1.2" id="4.1.2">4.1.2 V0.2</a>

Version 0.2 is the current design that you see. The reason for the function removal was because it would take a lot more time to implement functions. 

## <a href="#4.2" id="4.2">4.2 Reasons for Design</a>

The programming language concept was made up for my research project, in year 12. The idea of the language came to me whilst I was trying to think of a programming language design that would be easy/fun to implement and wouldn't seem to take that long compared to traditonal programming languages.

See above for feature specific reasons on design.

# <a href="#5" id="5">5 Feature TODO List</a>

Here is a list of what I would like the language to have in the future, after a stable version of interpreter is implemented:

- Functions (a.k.a. user commands)
- More primitive types
    - integers
    - booleans
    - character type
- File I/O
