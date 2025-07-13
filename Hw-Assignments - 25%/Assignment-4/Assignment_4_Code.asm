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

                                                                                /* PSUEDOCODE INSTRUCTIONS */
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

        Chk_A_Grtr_B:
            blt t1, t0, Chk_C_Grtr_D       # Branch if less than Checks the following """if (t1 < t0 == t0 > t1) move to Chk_C_Grtr_D"""
            j Else_OP                      # 'j' moves directly to else block if 'a' is not greater than 'b'

        Chk_C_Grtr_D:
            blt t3, t2, Then_OP            # Branch if less than Checks the following """if (t3 < t2 == t2 > t3) move to Then_OP"""
            j Else_OP                      # 'j' moves directly to else block if 'c' is not greater than 'd'

        Then_OP:
            srai t4, t4, 2                 # Shift right arithmetic immediate by power of 2^n so 2^2 = 4, then divide
            slli t5, t5, 2                 # Shift left logical immediate by 
            
            j End                          # 'j' moves after completion, jump to End function

        /* TEST "else" with Else_OP */

        Else_OP:
            sub t6, t0, t1                 # Subtract: Solving for variable 'e' ( a - b ) = result stored t6
            sub s0, t2, t3                 # Subtract: Solving for variable 'e' ( c - d ) = result stored s0
            add t4, t6, s0                 # Add: Solving for variable 'e' ( t6 + s0 ) = result stored t4

            add t6, t0, t1                 # Add: Solving for variable 'f' ( a + b ) = result stored t6
            add s1, t2, t3                 # Add: Solving for variable 'f' ( c + d ) = result stored s1
            sub t5, t6, s1                 # Subtract: Solving for variable 'f' ( t6 + s1 ) = result stored t5
            
            j End                          # After completion, jump to End function
        
        End:
                                           # 

        
    // QUESTION #4:







        rev_char:
            addi sp, sp, -16         # Allocate stack space for 4 registers
            sw   ra, 12(sp)          # Save return address
            sw   s0, 8(sp)           # Save s0 (base pointer)
            sw   s1, 4(sp)           # Save s1 (end pointer)
            sw   s2, 0(sp)           # Save s2 (temporary register)

            mv   s0, a0              # s0 = base address of array
            add  t0, a0, a1          # t0 = a0 + a1 (byte offset to end, not correct yet!)
            addi t0, t0, -1          # adjust for zero-based indexing
            mv   s1, t0              # s1 = address of last character (end pointer)

        rev_loop:
            bge  s0, s1, rev_done  # If start >= end, we're done

            lbu  s2, 0(s0)           # s2 = *start
            lbu  t1, 0(s1)           # t1 = *end
            sb   t1, 0(s0)           # *start = *end
            sb   s2, 0(s1)           # *end = original *start

            addi s0, s0, 1           # Move start forward
            addi s1, s1, -1          # Move end backward
            j    rev_loop        # Repeat until pointers meet

        rev_done:
            mv   a0, a0              # Return base address in a0

            lw   ra, 12(sp)          # Restore return address
            lw   s0, 8(sp)           # Restore saved registers
            lw   s1, 4(sp)
            lw   s2, 0(sp)
            addi sp, sp, 16          # Deallocate stack space
            ret                      # Return to caller

    // QUESTION #5:



    // QUESTION #6:
