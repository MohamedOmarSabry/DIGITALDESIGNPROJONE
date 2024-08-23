# Logic Table & Prime Implicant Printer
> Simple command line C++ program that takes boolean algebraic expressions and prints the truth table, the primary implicants, essential prime implicants, and canonical min and max terms.
## Description
A command line C++ program that takes in alphabetical boolean terms made up of a max of 10 different characters in terms of their sum or products or product of sums form and validates them before turning them into a binary string and creating a truth table before deriving the canonical min and max terms before the prime and essential prime implicants are evaluated.
## How to Run the Program:
Run the C++ file.
## Features
- Takes the input as a sum of products or product of sums in the following format: `abc + ad'c` or `(a + b + c)(c + d + e')`.
- Validates the number of variables to be less than 10.
- Creates a binary string from the input.
- Builds a correct truth table for the boolean expressions provided.
- Prints the canonical min and max terms in their boolean form.
- Prints the prime implicants correctly, but not the essential prime implicants due to a faulty understanding of the project requirements that would have needed code redesigns that were not possible with the allotted time.
