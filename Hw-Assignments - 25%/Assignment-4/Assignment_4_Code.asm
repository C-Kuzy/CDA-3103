/*
 Author: C-Kuzy
 Description: CDA-3103 Computer Organization 
                    Major Assignment #4
                      RISC-V Assembly
*/

    // Question #1: risc-v-asm-manual.pdf

        "Reference 3.1.1.6 NOT: Given the following syntax statement:'not rd, rs1'"
            "NOT, known as a bit-wise invert operation performs one's complment arithmetic"                     

                "Translation: xori rd, rs1, -1  [-1 = 0xFFFFFFFF]"

                    /* Description of the the code instructions 
                        rs1     source register 1
                        rd      destination register 
                    */

            "Why does it work?: The translation works correctly because NOT instructions flip each bit of the register.
                                NOT translates to the exclusive OR operation XORI which implements the negation. Which 
                                then the result is loaded into the destination register. For our result, every 0 will
                                become 1 and every 1 will become zero."

    // QUESTION #2: Values to contain in register a0: { a. -2037 | b. 4169 | c. 0xD6A | d. 1010110110110000010011_2 }

        "Part A: -2037"

            addi a0, x0, -2037      # Arithmetic Instruction: 

        "Part B: 4169"

            lui a0, 0x1             # Data Transfer U Format: Loads 20-it upper 
            addi a0, a0, 169        # Arithmetic Instruction: 

        "Part C: 3434"

            addi x0, x0, 0x6DA      # Arithmetic Instruction: 

        "Part D: 1010110110110000010011_2"

            lui a0, 0xADB           # Data Transfer U Format: Loads 20-it upper 
            addi a0, a0, 0x13       # Arithmetic Instruction: 

    // QUESTION #3:        Integer Variables: a, b, c, d, e, f      ||      Registers: t0, t1, t2, t3, t4, t5
                                                                          #Equivalent: x5, x6, x7, x28, x29, x30

        add t0, t1, t2 # t0 = t1 + t2
        
        

    // QUESTION #4:

    // QUESTION #5:

    // QUESTION #6:
