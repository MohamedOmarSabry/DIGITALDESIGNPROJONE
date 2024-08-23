# DIGITALDESIGNPROJONE
## How to Build the Program:
Take the cpp file in the DIGITALDESIGNPROJONE file and open it any C++ compiler.
## How our program works:
1)	Takes input as POS or SOP. 
2)	Does validation on the format. "abc + ad'c" or "(a + b + c)(c + d + e')". 
3)	SoPValidation1() -Takes the SoP and checks for brackets.
4)	SoPValidation2() and PoSValidation() Validate that the number of variables is not more than 10.
5)	 SoPCleanUp() or PoSCleanUp() take the input string and divide it into parts using the functions and stores it in vectors. 
6)	We then take the vectors and turn the strings into binary strings. SoPtoBinaryString() or PoStoBinaryString(). 
7)	Take the binary string to the TTableBuild() or TTableBuild2() functions to build the truth table. 
8)	After the table is built, the final column is filled according to the function provided. FTTColFillSOP() or FTTColFillPOS() 
9)	The PrintMinMaxterms() function is then used to derive the canonical min and max terms in boolean form. 
10)	It then calls the SoPtoBinaryString2() or PoStoBinaryString2() to turn the boolean terms into their binary string form and then into their binary string form.
11)	The binary strings are then given to the GroupByOnes() to group them according to the number of ones. 
12)	The ImplicantGroupComparison() function derives the prime implicants and the essential prime implicants by comparing each group with the ones underneath it. The process is repeated until all essential prime implicants are derived it uses the GroupByOnesIMP() function as well.
