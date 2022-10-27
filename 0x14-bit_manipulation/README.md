Bit manipulation is the act of algorithmically manipulating bits or other pieces of data shorter than a word.

Computer programming tasks that require bit manipulation include low-level device control, error detection and correction algorithms, data compression, encryption algorithms, and optimization. For most other tasks, modern programming languages allow the programmer to work directly with abstractions instead of bits that represent those abstractions.

Source code that does bit manipulation makes use of the bitwise operations: AND, OR, XOR, NOT, and possibly other operations analogous to the boolean operators; there are also bit shifts and operations to count ones and zeros, find high and low one or zero, set, reset and test bits, extract and insert fields, mask and zero fields, gather and scatter bits to and from specified bit positions or fields. Integer arithmetic operators can also effect bit-operations in conjunction with the other operators.

Example of bit manipulation
To determine if a number is a power of two, conceptually we may repeatedly do integer divide by two until the number won't divide by 2 evenly; if the only factor left is 1, the original number was a power of 2. Using bit and logical operators, there is a simple expression which will return true (1) or false (0):

 bool isPowerOfTwo = (x != 0) && ((x & (x - 1)) == 0);
The second method uses the fact that powers of two have one and only one bit set in their binary representation:

x         == 0...010...0
x-1       == 0...001...1
x & (x-1) == 0...000...0
If the number is neither zero nor a power of two, it will have '1' in more than one place:

x         == 0...1...010...0
x-1       == 0...1...001...1
x & (x-1) == 0...1...000...0
If inline assembly language code is used, then an instruction that counts the number of 1's or 0's in the operand might be available; an operand with exactly one '1' bit is a power of 2. However, such an instruction may have greater latency than the bitwise method above.