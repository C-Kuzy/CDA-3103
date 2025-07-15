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
            
            j       End              # After completion, jump to End function
        
        End:
            jr ra                    # Acts as a termination statement to end the RISC-V program

    // QUESTION #4:

    Main_OP:
        j       Rev_Char             # Jumps straight to Rev_Char function

        Rev_Char:
            addi a0, a2, 0           # Addition Immediate: a0 = Original Base Pointer stored
            addi t0, a2, 0           # Addition Immediate: t0 = Base Case == *Start Pointer*
            addi t1, a1, -1          # Addition Immediate: t1 = (char_length) - 1
            add  t1, a0, t1          # Addition
        
        Rev_Loop:
            bge  t0, t1, Rev_Done    # IF start >= end, 
            lbu  t3, 0(t0)           # t3 = *t0 which prompts 
            lbu  t4, 0(t1)           # t4 = *t1
            sb   t1, 0(t0)           # *start = *end
            sb   s2, 0(t1)           # *end = original *start
            addi t0, t0, 1           # Addition Immediate: t0 -> increment t0++
            addi t1, s1, -1          # Addition Immediate: t1 -> decrement t1--
            j       Rev_Loop         # 'j' jumps back to the top of the 'Rev_Loop'

        Rev_Done:
            addi a2, a0, 0           # Returns the base address within register a0
            jr ra                    # Return to caller

    // QUESTION #5:

                    """     int fibonacci ( int num ) {
                                if ( n <= 1 )
                                    return n;
                                else
                                    return ( fibonacci ( n - 1 ) + fibonacci ( n - 2 ) );
                                }
                    """
        
    Main_OP:
        j       Fib_Main             # Jumps directly to main 

        Fib_Main:
            addi sp, sp, -20         # Stack allocation for ra, s0, and s1
            sw ra, 16(sp)            # 
            sw s0, 12(sp)            # 
            sw s1, 8(sp)             # 
            
            addi t0, zero, 1         # 
            blt t0, a0, recursive    # 
            j       Base_OP          # IF value is less than or equal to one, jump to branch "Base_OP"

        recursive:
            /* Fibonacci( n - 1 ) */
                addi s0, a0, -1      # Stores s0 = n - 1
                mv a0, s0            # 
                jal Fib_Main         # 
                mv s1, a0            # 

            /* Fibonacci( n - 2 ) */
                addi s0, s0, -1      # 
                mv a0, s0            # 
                jal Fib_Main         # 
                add a0, s1, a0       # 
                j       Fib_End      # Jump to branch function "Fib_End" upon recursive loop completion

        Base_OP:
            addi a0, a0, 0           # Returns 'n' value (0 or 1) from if statement

        Fib_End:
            lw ra, 16(sp)            #
            lw s0, 12(sp)            # 
            lw s1, 8(sp)             #
            addi sp, sp, 20          # Stack is deallocated from program function call
            jr ra                    # Return directly to the caller

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
    SUM_NUMBER:
      addi t0, a0, 0          # t0 = n
      addi t1, x0, 0          # t1 = result = 0
    WHILE:
      blt  t0, 1, END_WHILE   # while(n >= 1)
      add  t1, t1, t0         # result += n
      addi t0, t0, -1         # n--
      j    WHILE              # jump back to loop
    END_WHILE:
      addi a0, t1, 0          # return result
      jr   ra                 # jump back to caller

    SWAP_SUM:
      lw   t0, 0(a0)          # t0 = *x
      lw   t1, 0(a1)          # t1 = *y

      sw   t0, 0(a1)          # *y = *x
      sw   t1, 0(a0)          # *x = temp

      lw   a0, 0(a0)          # a0 = *x
      addi sp, sp, -8         # allocate space on the stack
      sw   ra, 4(sp)          # return address
      sw   a1, 0(sp)          # save y pointer for later
      jal  ra, SUM_NUMBER     # call function 
      addi t2, a0, 0          # t2 = sum_x
      jal  ra, SUM_NUMBER     # call function

      lw   a1, 0(sp)          # restore y pointer
      lw   a0, 0(a1)          # a0 = *y
      jal  ra, SUM_NUMBER     # call function
      addi t3, a0, 0          # t3 = sum_y

      lw   ra, 4(sp)          # restore initial return address
      addi sp, sp, 8          # deallocate stack space

      add  a0, t2, t3         # add results, return in a0
      jr   ra                 # jump back to caller
