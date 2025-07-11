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
                                NOT translates to the exclusive OR operation XORI which implements the negation. Which 
                                then the result is loaded into the destination register. For our result, every zero will
                                become one and every one will become zero."

    // QUESTION #2: Values to contain in register a0: { a. -2037 | b. 4169 | c. 0xD6A | d. 1010110110110000010011_2 }

        "Part A: -2037"

            addi a0, x0, -2037      # Arithmetic Instruction: Load's the value -2037 into register a0 
                                    # Meaning: a0 = x0 + (-2037)
                                        
                                        /* Description of the code instructions
                                            -2037      subtract by value of 2037
                                            x0         register hard-wired to value 0
                                            a0         register storage
                                        */

        "Part B: 4169"

            lui a0, 0x1             # Data Transfer U Format: Loads 20 upper bits (a0 == 0x1000) && 12 lower bits (169)
            addi a0, a0, 169        # Load/Store Instruction: Load's value 4000 by a0 = 0x1000
                                    # Arithmetic Instruction: Load's the value 
                                    # Meaning: a0 = 0x1

                                        /* Description of the code instructions
                                            
                                            a0         register storage
                                        */

        "Part C: 0xD6A = 3434"

            addi a0, x0, 0x6DA      # Arithmetic Instruction: Load's the value 0x6DA or 3434 into register a0
                                    # Meaning: a0 = x0 + 3434

                                        /* Description of the code instructions
                                            3434 or 0x6DA         addition by value of 3434
                                            x0         register hard-wired to value 0
                                            a0         register storage 
                                        */

        "Part D: 1010110110110000010011_2 = 710931"

            lui a0, 0xADB           # Data Transfer U Format: Loads 20 upper bits (a0 == 0xADB) && 12 
            addi a0, a0, 0x13       # Load/Store Instruction: first a0 storage value is 710912
                                    # Arithmetic Instruction: 
                                    # Meaning: a0 = 

                                        /* Description of the code instructions
                                        
                                        */

    // QUESTION #3:        Integer Variables: a, b, c, d, e, f      ||      Registers: t0, t1, t2, t3, t4, t5
                                                                          #Equivalent: x5, x6, x7, x28, x29, x30

        addi t0, t1, imm # t0 = t1 + imm
        
        

    // QUESTION #4:

        reverse_char:
            addi sp, sp, -16         # Allocate stack space for 4 registers
            sw   ra, 12(sp)          # Save return address
            sw   s0, 8(sp)           # Save s0 (base pointer)
            sw   s1, 4(sp)           # Save s1 (end pointer)
            sw   s2, 0(sp)           # Save s2 (temporary register)

            mv   s0, a0              # s0 = base address of array
            add  t0, a0, a1          # t0 = a0 + a1 (byte offset to end, not correct yet!)
            addi t0, t0, -1          # adjust for zero-based indexing
            mv   s1, t0              # s1 = address of last character (end pointer)

        reverse_loop:
            bge  s0, s1, reverse_done  # If start >= end, we're done

            lbu  s2, 0(s0)           # s2 = *start
            lbu  t1, 0(s1)           # t1 = *end
            sb   t1, 0(s0)           # *start = *end
            sb   s2, 0(s1)           # *end = original *start

            addi s0, s0, 1           # Move start forward
            addi s1, s1, -1          # Move end backward
            j    reverse_loop        # Repeat until pointers meet

        reverse_done:
            mv   a0, a0              # Return base address in a0

            lw   ra, 12(sp)          # Restore return address
            lw   s0, 8(sp)           # Restore saved registers
            lw   s1, 4(sp)
            lw   s2, 0(sp)
            addi sp, sp, 16          # Deallocate stack space
            ret                      # Return to caller

    // QUESTION #5:

    // QUESTION #6:
