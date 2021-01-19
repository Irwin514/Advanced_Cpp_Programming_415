
// review example #1: variable types, etc.

#include <iostream> // allow use of cout

using namespace std; // use definitions for standard C++ library

// a "global variable" is declared outside a function
// -> all functions in a file can access the global variable.
// normally you should avoid using globals except for constants.
int ig,jg;

// the const modifier makes the variable constant
const double PI = 3.14159;

// alternative not as good -- not actually a variable
// so less type checking is involved, etc.
// #define is an example of a "preprocessor directive"
// (statments that begin with #) -> more on that later
// #define does a straight substitution of the constant 
// (eg PI2) with the value which comes after it (eg 3.14)
#define PI2 3.14159 

int main()
{ 
	// a variable declaration inside a function
	// indicates a "local variable" -- can't be accessed 
	// outside the function (encapsulated inside the function)
	int i=7,j,k; 
	
	// int is normally a signed 4 bytes (32 bit) integer
	// on 32 bit or more CPUs such as PCs.
	
	// on 8 bit microcontrollers like Arduino it's normally 2 bytes
	
	// note that integer varibles will roll when they go out of range
	// the range is about +/- 2 billion for 4 byte int
	// and +/- 32,000 for 2 byte int
	
	// variable sizes depends on CPU type so in C++ the sizeof()
	// function is provided to tell the program the size
	// of a variable in bytes.
	cout << "\nsizeof(int) = " << sizeof(int);

	// double represent real numbers 
	// normally 16 significant digits (8 bytes).
	// floats are half -- 8 significant digits.
	
	// doubles have less round off error in numerical calculations.	
	
	// normally we use doubles except maybe for network communication
	// where we want to minimize data rate.

	// note that 8 bit microcontrollers such as standard Arduino 
	// boards only have floats because doubles are too computationally
	// difficult for small processors.
	
	double x=2,y,z;
	float f1;
	cout << "\nsizeof(double) = " << sizeof(double);

	// note that floats and double will normally go to Inf
	// (an exception value) when they go out of range.
	// the range is about +/-1.7e308 for doubles
	// and +/- 3.4e38 for floats.
	
	// \n - new line
	// \t - tab
	cout << "\ni = " << i << " \t x = " << x; 

	// input a number from keyboard
	cout << "\nz = ? ";
	cin >> z; // make sure you input the expected type of variable
	// z from the keyboard or the program could have an error
	cout << "\nz = " << z;

	char c1 = 'w';

	cout << "\n" << c1 << "\n";
	cout << "\nsizeof(char) = " << sizeof(char);

	// characters are almost always 1 byte in most CPUs

	// the "unsigned char" is VERY useful because it is a one byte 
	// positive integer ranging from 0 to 255
	// -> very useful for accessing and manipulating one byte
	// at a time or communication (typically in arrays of bytes).
	unsigned char c2 = 97;
	
	// note: a normal / signed char goes from -128 to 127
	// and 1 byte = 8 bits

	j = c2;
	cout << "\n(int)'a' = " << (int)'a';
	cout <<"\nc2 = " << c2; // will print out the character
	cout <<"\nc2 = " << (int)c2; // will print out the equivalent number	
	// (int) is a cast -- ie a forced conversion
	cout <<"\nj = " << j;

	// a big 64 bit / 8 byte int is declared as follows
	__int64 i64 = 7777774334453532324;

	// pointers
	
	double *p; // holds the memory location of a variable
	// in this case a double -- we will use this with dynamic arrays.
	// note this is just a very brief introduction -> more later

	// expressions and operators
	// +, -, *, /, ++, --, +=, -=, -

	// +, -, * are normally trouble free
	// the main pitfall is if the variable goes out of range ->
	// can't hold the result because the number is too large
	// -> overflow / roll / wrap around for ints, or Inf for doubles

	// however division / has two other pitfalls:
	
	// 1. integer division eg
	// double x = 1/3*5.5; --> x = 0 -> error
	// double x = 1.0/3*5.5;
	// integer division always rounds down
	// -> more on this in review2
	
	// 2. divide by zero
	// double x = 1.0/0.0; // mathematical exception
	// this can crash your program, result in Inf, etc. depending
	// on the CPU and compiler
	
	// note: you should always check the denomenator of your
	// mathematical expressions to make sure it doesn't go to
	// zero.  
	
	// if it does go to zero -- stop program or perform
	// some approxiation, eg
	// fg = G*m1*m2/r^2 -> if abs(r) < eps then set r = eps

	double x7 = 1.0, x8 = 0.0;
	int i7=1, i8=0;

	cout << "\nx7 = " << x7/x8;
//	cout << "\ni7 = " << i7/i8; // maybe a crash ?

	// cast - converts one data type into another,
	// especially needed for unusual conversions
	// such as chars to double, doubles to chars,
	// pointers, etc.
	c2 = (unsigned char)z; // truncation occurs -- takes the 1st byte of z

	cout << "\nc2(remix) = " << c2;

	// logical operators &&, ||, ! - not, 
	// && - logical AND
	// || - logical OR
	// == equality test, = assignment opeator
	// != not equal, etc.
	// >= , etc.
	if( ( (z < 3.4) && (x > 1.0) ) || (z < 1.2) ) cout << "\ntrue";

	// arrays and strings
	double A[3]; // 1D array starts at zero A[0] to A[2] -- zero offset
	// array is default

	// note: it is a big error to use the array out of bounds
	// eg A[-1] or A[4] -- like a wild pointer -- could cause memory
	// problems -- this is the most common / deadly error with arrays

	// A[4] = 3; // big error -- could overwrite the program or variables	

	// note: if you want to have a 3 component array that begins
	// at [1] (ie a one offset array) you can simply write
	double A1[3+1]; // we leave A1[0] unused so we can do A1[1], A1[3]
	
	double A2[] = {1.0,2.0,3.0}; // the size of A2 will be set
	// automatically to fit the init data
	// the compiler puts in 3 in the above based on the initialization list
		
	// -- in general I recommend don't using [] with arrays
	// it's a bit confusing and programmers have a tendency
	// to use it when it doesn't work
	
	// NOTE: [] doesn't work well with 2D or more arrays
	// or in any situation other than the above and 1D 
	// array function arguments.
	
	// for 3 component vector starting at one we can use
	double B[4]; // in this case B[1] to B[3]

	// 2D arrays
	// Name[nrows][ncols]
	double C[4][4]; // use to store a 3x3 matrix

	// the array starts at C[0][0]
	// don't use empty brackets

	// stings are 1D arrays of characters starting at 0
	// and at the null/termination character '\0'
	char s2[5]="1234"; // note the 5th character is '\0'

	s2[0] = 'x';

//	s2 = "1234"; // error -> only for initialization of a string

	cout << "\ns2 = " << s2;

	// note for multiple characters you use "" -- for strings
	// for single characters you use single quotes '' -- for chars
	// note "" only works for string initialization -- can't
	// use it later in the program.

	// note: in this course we use C-strings, ie strings composed 
	// of arrays of characters with '\0' at the end.
	// we don't use string objects or string library functions

	char s3[3];

	// manual initialization of a string
	s3[0] = '1';
	s3[1] = '2';
//	s3[2] = '\0'; // termination character / null character

	// note: without the teminator the program doesn't know
	// when the string ends --> eg if you print it out
	// the computer just keeps printing until it finds a 
	// terminator in memory

	cout << "\ns3 = " << s3;	

	cout <<"\n\ndone.\n";

	// note the normal convention for returning ints
	// from a function is that you are returning an error message/level
	// 0 - OK no error
	// 1 - error level/type 1
	// 2 - error level/type 2
	// ...

	return 0; // indicate return status of function (0=OK)
} 

