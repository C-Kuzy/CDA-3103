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
                                then the result is loaded into the destination register.
            "

    // QUESTION #2:



    // QUESTION #3:

    // QUESTION #4:

    // QUESTION #5:

    // QUESTION #6:
