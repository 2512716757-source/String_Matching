==================================================================================================================
CSC10004 - STRING MATCHING PROJECT
Data Structures & Algorithms | Spring 2026
==================================================================================================================

------------------------------------------------------------------------------------------------------------------
1. PREREQUISITES
------------------------------------------------------------------------------------------------------------------

Before running this program, you must have the GNU g++ compiler installed on your machine with support for the
C++17 standard.

You could check by open your terminal and run: 

	g++ --version

If you see a version number (e.g. "g++ (GCC) 15.x.x"), you are ready to go.
If the command is not recognized, you will need to install g++ first by following online instruction.



------------------------------------------------------------------------------------------------------------------
2. TERMINAL SETUP
------------------------------------------------------------------------------------------------------------------

Open your OS terminal application:
Window: Command Prompt (cmd) or PowerShell
macOS/Linux: Terminal

Navigate your project folder and use the "cd" (change directory) command to move into your project folder, the
command should be:

	cd path\to\your\project		(Windows)
	cd path/to/your/project		(macOS/Linux)

If your project is on a different drive, usually on Windows (e.g. D: or E:), you must switch to that drive by 
adding "/d" to the command:

	cd /d path\to\your\project	(Windows only)



------------------------------------------------------------------------------------------------------------------
3. COMPILING THE PROGRAM
------------------------------------------------------------------------------------------------------------------

Run the following command to compile all source files into a single executable:

	g++ main.cpp match.h bf.h rk.h kmp.h bm.h ac.h bf.cpp rk.cpp kmp.cpp bm.cpp ac.cpp -o crossword -std=c++17

If compilation succeeds, no output will be printed and your prompt will return immediately. This is expected 
behavior and means it worked correctly. A new file named "crossword.exe" (Windows) or "crossword" (macOS/Linux) 
will appear in your project folder.



------------------------------------------------------------------------------------------------------------------
4. RUNNING THE PROGRAM
------------------------------------------------------------------------------------------------------------------

The program is run from the terminal using the following format:

	crossword.exe -a [algorithm] -i [input_file] -o [output_file]		(Windows)
	./crossword   -a [algorithm] -i [input_file] -o [output_file]		(macOS/Linux)


All three flags (-a, -i, -o) are required. The program will not run if any flag is missing.

The output file will be created automatically if it does not already exist. If it does exist, it will be 
overwritten with the new results.



------------------------------------------------------------------------------------------------------------------
5. FLAGS AND OPTIONS
------------------------------------------------------------------------------------------------------------------

Flag			Description
------------------------------------------------------------------------------------------
-a [algorithm]  	Selects the string-matching algorithm to use.
                  	Must be one of the following values:
 
                      	  bf   Brute-Force (Naive) algorithm
                      	  rk   Rabin-Karp algorithm
                      	  kmp  Knuth-Morris-Pratt (KMP) algorithm
                      	  bm   Boyer-Moore algorithm
                      	  ac   Aho-Corasick algorithm
 
                  	The value is case-sensitive. (e.g. "KMP" will not be accepted)
 

-i [input_file] 	Path to the input file following the format below. 
			Can be a relative path or absolute path.
 

-o [output_file] 	Path to the output file where results will be written.
                  	The file will be created if it does not exist.
                  	Can be a relative or absolute path.



------------------------------------------------------------------------------------------------------------------
6. INPUT FORMAT
------------------------------------------------------------------------------------------------------------------

The input file must follow this exact structure:

	Line 1:			Two integers R = number of rows and C = number of columns separated by a space
				(1 <= R, C <= 1000)

	
	Line 2 to R+1:		Each line contains C lowercase English characters separated by a single space

	Line R+2:		A single integer K = the number of keywords
				(1 <= K <= 100)

	Line R+3 to R+2+K:	Each line contains one keyword string



------------------------------------------------------------------------------------------------------------------
7. EXAMPLE
------------------------------------------------------------------------------------------------------------------

Sample Input File (tests\puzzle_sample.txt)
-------------------------------------------
4 4
t e s t
e a b c
s d e f
t g h i
2
test
bug


Example Algorithm Run (Using KMP):
	
	crossword.exe -a kmp -i tests\puzzle_sample.txt -o tests\solution.txt		(Windows)
	./crossword -a kmp -i tests/puzzle_sample.txt -o tests/solution.txt		(macOS/Linux)


Expected Output File (tests\solution.txt)
-------------------------------------------
test: (0, 0) -> (0, 3); (0, 0) -> (3, 0);
bug: not found
----------------------------------------
Algorithm: KMP
Comparisons: 68
Execution Time: 0.0056 ms


To print the output directly in the terminal without opening the file, use command:

	type tests\solution_kmp.txt	(Windows)
	cat tests/solution_kmp.txt	(macOS/Linux)


















