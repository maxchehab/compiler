# compiler
This is a WIP weekend project. There is no error handling and very minimal functionality.
This is simply an exercise exploring how a compiler works. View an online demonstration of this project [here](http://104.236.141.69/compiler).

## commands

### `var` :: static variables
All variables are considered static. If one wants to update a variable's property they must create a new variable and assign the old variable plus whatever operation they desire.
A variable must be a positive integer.

### `+` :: operator
The only mathematical operation available is addition of positive numbers. One can add saved variables and integers.

### `print()` :: stdout
The print command is the only way to output variables. The print method only takes variables.

### `;` :: semicolons
All commands must end with a semicolon.

## examples

### creating a variable

```
var a = 10;
```

### adding to a variable

```
var a = 10;
var b = a + 30;
```

### printing a variable

```
var a = 10;
var b = a + 30;
print(b);
```

### semicolons

```
var a = 10;var b = a + 30;print(b);
```
