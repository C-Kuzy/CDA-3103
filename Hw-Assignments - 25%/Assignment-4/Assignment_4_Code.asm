/*
 Author: C-Kuzy
 Description: CDA-3103 Computer Organization 
                    Major Assignment #4
                      RISC-V Assembly
*/

    // QUESTION #1: risc-v-asm-manual.pdf

        "Reference 3.1.1.6 NOT: Given the following syntax statement:'not rd, rs1'"
            "NOT, known as a bit-wise invert operation performs one's complement arithmetic"                     

                "Translation: xori rd, rs1, -1  [-1 = 0xFFFFFFFF]"

                    /* Description of the the code instructions 
                        -1      subtract by value of 1
                        rs1     source register 1
                        rd      destination register 
                    */

            "Why does it work?: The translation works correctly because NOT instructions flip each bit of the register.
                                NOT translates to the exclusive OR operation XORI which implements a negation. Which 
                                then the result is loaded into the destination register. For our result, every zero will
                                become one and every one will become zero."

    // QUESTION #2: Values to contain in register a0: { a. -2037 | b. 4169 | c. 0xD6A | d. 1010110110110000010011_2 }
                                    "VALUE RANGE: [-2048, 2047]"

        a0_reg:

        "Part A: -2037"

            addi a0, zero, -2037    # Arithmetic Instruction: Load's x0 and add value -2037 into register a0 
                                    # Meaning: a0 = x0 + (-2037) = -2037
                                        
                                        /* Description of the code instructions
                                            -2037      subtract by value of 2037
                                            zero/x0    register hard-wired to value 0
                                            a0         register storage
                                        */

        "Part B: 4169"

            lui a0, 0x1             # Load Upper Immediate: Loads 20 upper bits (a0 == 0x1) && 12 bits to the left
            addi a0, a0, 73         # Load/Store Instruction: Load's value 4096 to register a0 (1*2^12)
                                    # Arithmetic Instruction: Addition operation to load stored in a0 plus 73 to a0
                                    # Meaning: a0 = 4096 + 73 = 4169

                                        /* Description of the code instructions
                                            0x1        calculates value after shifting left 12 bits = 4096
                                            73         value left over to be added
                                            a0         register storage
                                        */

        "Part C: 0xD6A = 3434"       

            lui a0, 0x1             # Load Upper Immediate: Loads 20 upper bits (a0 == 0x1) && 12 bits to the left
            addi a0, a0, 0xD6A      # Load/Store Instruction: Load's value 4096 to register a0 (1*2^12)
                                    # Arithmetic Instruction: Addition operation to load stored in a0 plus -662 to a0
                                    # Meaning: a0 = 4096 + (-662) = 3434

                                        /* Description of the code instructions
                                            0x1        calculates value after shifting left 12 bits = 4096
                                            -662 or 0x6DA     subtraction by value of 662
                                            a0         register storage 
                                        */

        "Part D: 1010110110110000010011_2 = 2845715"   // CONVERT BINARY TO HEXADECIMAL: 2B6C13 >> Make 8-Bit: 002B6C13
                                                       // >> Count 5 From Left && + 1: 002B7C13 

            lui a0, 0x2B7           # Load Upper Immediate: Loads 20 upper bits (a0 == 0x2B7) && 12 bits to the left 2B7
            addi a0, a0, 0xC13      # Load/Store Instruction: Load's value 2846720 to register a0
                                    # Arithmetic Instruction: Addition operation to load stored in a0 plus -1005 to a0
                                    # Meaning: a0 = 2846720 + (-1005) = 2845715

                                        /* Description of the code instructions
                                            0x2B7      addition by value = 2846720
                                            0xC13      subtraction by value = -1005
                                            a0         register storage
                                        */

    // QUESTION #3:        Integer Variables: a, b, c, d, e, f      ||      Registers: t0, t1, t2, t3, t4, t5

                                                                                /* PSEUDOCODE INSTRUCTIONS */
                    """     if (( a > b ) && ( c > d )) {               IF A is greater than B and C is greater than D    
                                e = e / 4;                              then, compute e = (e / 4)
                                f = f * 4;                              then, compute f = (f * 4)
                            }
                            else {                                      IF A is not greater than B or C is not greater than D
                                e = ( a - b ) + ( c - d );              then, compute e = ( a - b ) + ( c - d )
                                f = ( a + b ) - ( c + d );              then, compute f = ( a + b ) - ( c + d )
                            }
                    """

        /* TEST "if (( a > b ) && ( c > d ))" with Chk_A_Grtr_B: && Chk_C_Grtr_D: && Then_OP */
    Main_OP:
        j       Chk_A_Grtr_B         # Main Operation jumps directly to check the if statement

        Chk_A_Grtr_B:
            blt t1, t0, Chk_C_Grtr_D # Branch if less than Checks the following """if (t1 < t0 == t0 > t1) move to Chk_C_Grtr_D"""
            j       Else_OP          # 'j' moves directly to else block if 'a' is not greater than 'b'

        Chk_C_Grtr_D:
            blt t3, t2, Then_OP      # Branch if less than Checks the following """if (t3 < t2 == t2 > t3) move to Then_OP"""
            j       Else_OP          # 'j' moves directly to else block if 'c' is not greater than 'd'

        Then_OP:
            srai t4, t4, 2           # Shift right arithmetic immediate by power of 2^n so 2^2 = 4, then divide by 4 | e = e / 4 |
            slli t5, t5, 2           # Shift left logical immediate by power of 2^n so 2^2 = 4, then multiply by 4 | f = f * 4 | 
            j       End              # 'j' moves after completion, jump to End function

        /* TEST "else" with Else_OP */
        Else_OP:
            sub t6, t0, t1           # Subtract: Solving for variable 'e' ( a - b ) = result stored t6
            sub s0, t2, t3           # Subtract: Solving for variable 'e' ( c - d ) = result stored s0
            add t4, t6, s0           # Add: Solving for variable 'e' ( t6 + s0 ) = result stored t4
            add t6, t0, t1           # Add: Solving for variable 'f' ( a + b ) = result stored t6
            add s1, t2, t3           # Add: Solving for variable 'f' ( c + d ) = result stored s1
            sub t5, t6, s1           # Subtract: Solving for variable 'f' ( t6 + s1 ) = result stored t5
            j       End              # 'j' moves after completion, jump to End function
        
        End:
            jr ra                    # Acts as a termination statement to end the RISC-V program

    // QUESTION #4:

    Main_OP:
        j       Rev_Char             # Jumps straight to Rev_Char function

        Rev_Char:
            addi a0, a2, 0           # Addition Immediate: a0 = Original Base Pointer of the character array
            addi t0, a2, 0           # Addition Immediate: t0 = Base Case == Start Pointer
            addi t1, a1, -1          # Addition Immediate: t1 = (char_length) - 1 
            add  t1, a0, t1          # Addition: t1 = base + (char_length - 1) == End Pointer
        
        Rev_Loop:
            bge  t0, t1, Rev_Done    # IF start >= end, then move to 'Rev_Done'
            lbu  t3, 0(t0)           # Load Byte Unsigned: t3 = *t0 
            lbu  t4, 0(t1)           # Load Byte Unsigned: t4 = *t1
            sb   t4, 0(t0)           # Store Byte: *t0 = t4
            sb   t3, 0(t1)           # Store Byte: *t1 = t3
            addi t0, t0, 1           # Addition Immediate: t0 -> increment t0++
            addi t1, s1, -1          # Addition Immediate: t1 -> decrement t1--
            j       Rev_Loop         # 'j' jumps after completion, back to top of 'Rev_Loop'

        Rev_Done:
            jr ra                    # Function returns to caller as base address within a0

    // QUESTION #5:

                    """     int fibonacci ( int num ) {
                                if ( n <= 1 )
                                    return n;
                                else
                                    return ( fibonacci ( n - 1 ) + fibonacci ( n - 2 ) );
                                }
                    """
        
    Main_OP:
        j       Fib_Main             # Jumps directly to Fib_Main, executing the program

        Fib_Main:
            addi sp, sp, -20         # Addition Immediate: Stack allocation for 20 bytes of the stack (ra, a0, and s1)
            sw ra, 16(sp)            # Store Word: ra saves our return address
            sw s0, 12(sp)            # Store Word: s0 is saved for our arguments
            sw s1, 8(sp)             # Store Word: s1 is saved for the fibonacci result
            
            addi t0, zero, 1         # Addition Immediate: Used as the base case constant t0 = 1
            blt a0, t0, Base_OP      # Branch If Less Than: IF n < 1, then move onto Base_OP
            beq a0, t0, Base_OP      # Branch If Equal: IF n == 1 then move onto Base_OP

            /* fibonacci( n - 1 ) */
            addi s0, a0, -1          # Addition Immediate: Defines fibonacci argument s0 = n - 1
            addi a0, s0, 0           # Addition Immediate: Changes set argument a0 = s0
            jal Fib_Main             # Jump & Link: Calls the function Fib_Main( n - 1 )
            addi s1, a0, 0           # Addition Immediate: Upon completion, s1 stores the result of the function call

            /* fibonacci( n - 2 ) */
            addi s0, s0, -1          # Addition Immediate: Defines fibonacci argument s0 = n - 2
            addi a0, s0, 0           # Addition Immediate: Changes set argument a0 = s0
            jal Fib_Main             # Jump & Link: Calls the function Fib_Main( n - 2 )
            
            /* Find Sum of fibonacci */
            add a0, s1, a0           # Addition: TOTAL VAL = fibonacci ( n - 1 ) + fibonacci ( n - 2 )
            j       Fib_End          # 'j' jumps after completion to branch function 'Fib_End', skipping Base_OP

        Base_OP:
            addi a0, a0, 0           # Addition Immediate: Returns 'n' value (0 or 1) from IF statement

        Fib_End:
            lw ra, 16(sp)            # Load Word: Responsible for restoring the return address
            lw s0, 12(sp)            # Load Word: Responsible for restoring argument(s) s0
            lw s1, 8(sp)             # Load Word: Responsible for restoring results s1
            addi sp, sp, 20          # Addition Immediate: Stack is deallocated from program function space
            jr ra                    # Function returns directly to the caller

    // QUESTION #6:

                    """     int sum_number( int ) {
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
                    """
    Main_OP:
        j       Sum_Main             # 'j' jumps  

        Sum_Main:
            addi sp, sp, -24         # Addition Immediate:
            sw a0, 20(sp)            # t1 = result = 0
            sw ra, 16(sp)            # 
            sw a1, 8(sp)             #
            sw a2, 4(sp)             #
            sw t1, 0(sp)             # Temp Storage Usage for While Loop

        Sum_Num:
            addi t2, t2, 1           # Addition Immediate: Assigned temp t2 = 1
        
        While_Sum:

            add a0, a0, t1
            addi
            j 

        Swap_Sum:


        Sum_End:
