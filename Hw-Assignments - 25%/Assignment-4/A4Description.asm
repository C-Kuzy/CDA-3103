/*
 Author: C-Kuzy
 Description: Assignment #4 Points/Question Description

Part #1. Complete the following 6 Questions: Reference from Chapter #4 in the textbook
    
    |  Total Pts:  |   Question #   |                                 Description of Question Task/Work Needed                                   |

        3 Points      Question #1:     The NOT in an assembly operator that can be used in RISC-V assembly programs. However, NOT is not listed
                                       as a RV32I operator on page 104 of the 'risc-v-isa-spec.pdf' on Canvas. This means that the NOT operator
                                       is translated into a different statement. What is the translation of 'not rd, rs1' in RISC-V ISA? Justify
                                       why the translation works correctly. (Hint: look for 'NOT' in 'risc-v-asm-manual.pdf' on Canvas.)

       12 Points      Question #2:     Write RISC-V assembly code for placing the following immediate constants in register a0. Use a minimum of
                                       number of instructions. Comment each line of assembly code. 
                                                         { a. -2037 | b. 4169 | c. 0xD6A | d. 1010110110110000010011_2 }

       15 Points      Question #3:     Convert the following high-level code into RISC-V assembly code. Assume that the signed integer variables
                                       a, b, c, d, e and f are in registers t0, t1, t2, t3, t4, and t5. Use only RV321 operators. Comment each
                                       line of assembly code.                  Assignment code below!

                                                                            if (( a > b ) && ( c > d )) {
                                                                                e = e / 4;
                                                                                f = f * 4;
                                                                            }
                                                                            else {
                                                                                e = ( a - b ) + ( c - d );
                                                                                f = ( a + b ) - ( c + d );
                                                                            }

       20 Points      Question #4:     Write a RISC-V assembly function called 'reverse_char()' to reverse an array of characters. The function
                                       takes the base address of the array and the number of elements as arguments. It should return the base
                                       address of the array as the return value. Comment each line of assembly code.

       20 Points      Question #5:     Convert the following 'fibonacci()' function, which calculates the Fibonacci number recursively, into 
                                       RISC-V assembly code. The function takes a number as an argument. Comment each line of assembly code.
                                                                               Assignment code below!

                                                                            int fibonacci ( int num ) {
                                                                                if ( n <= 1 )
                                                                                    return n;
                                                                                else
                                                                                    return ( fibonacci ( n - 1 ) + fibonacci ( n - 2 ));
                                                                            }

       30 Points      Question #6:     Convert the following 'high-level' code into RISC-V assembly code. Comment each line of assembly code.
                                                                               Assignment code below!

                                                                            int sum_number( int ) {
                                                                                int result = 0;
                                                                                // Calculate n + ( n - 1 ) + ... + 1
                                                                                while ( n >= 1 ) {
                                                                                    result += n;
                                                                                    n--;
                                                                                }
                                                                                return result;
                                                                            } 
                                                                                            
                                                                            int swap_sum ( int * x, int *y ) {
                                                                                // swap the numbers
                                                                                int temp;
                                                                                temp = *y;
                                                                                *y = *x;
                                                                                *x = temp;

                                                                                // return the sum of number
                                                                                int sum_x = sum_number( *x );
                                                                                int sum_y = sum_number( *y );
                                                                                return sum_x + sum_y;
                                                                            }

       Total Pts: 100
    
 Part #2: Create a .pdf file once completing all the questions 

 Part #3: Submit work to Canvas Submission
*/
