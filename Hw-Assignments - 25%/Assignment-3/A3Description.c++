/*
 Author: C-Kuzy
 Description: Assignment #3 Points/Question Description

 Part #1. Complete the following 12 Questions: Reference from page #369 in textbook
    
    |  Total Pts:  |   Question #   | Exercise Value |                                 Description of Question Task/Work Needed                                    |
 
        9 Points      Question #1:         3.41         Construct the XOR operator using only NAND gates. (Hint: x XOR y = ((x^i * y)^i)

        9 Points      Question #2:         3.42         Draw a half-adder using only NAND gates.

        9 Points      Question #3:         3.44         Design a circuit with three inputs x, y, z representing the bits in a binary number. When the input is 0, 1,
                                                        6, or 7, the binary output will be the compliment of the input. When the binary input is 2, 3, 4, or 5, the
                                                        output is the input shifted left with rotation. (Ex: 3 = 011_2 output is 110; 4 = 100_2 outputs 001)
                                                        Show your truth table, all computations for simplification, and the final circuit.

        9 Points      Question #4:         3.47         Draw the combination circuit that directly implements the following Boolean Expression:
                                                        F(x, y, z) = (x ( y XOR z )) + (xz)^i

        9 Points      Question #5:         3.49         Find the truth table that describes the following circuit:
                                                        ***REFER TO TEXTBOOK FOR QUESTION REFERENCE***

        5 Points      Question #6:         3.51         How many inputs does a decoder have if it has 64 outputs?

        5 Points      Question #7:         3.52         How many control lines does a multiplexer have if it has 32 inputs?

        9 Points      Question #8:         3.58         Describe how each of the following circuits works and indicate typical inputs and outputs. Also provide a
                                                        carefully labeled "black box" diagram for each. 1. a) Decoder and 2. b) Multiplexer

        9 Points      Question #9:         3.63         Complete the truth table for the following sequential circuit
                                                        ***REFER TO TEXTBOOK FOR QUESTION REFERENCE***

        9 Points      Question #10:        3.67         A sequential circuit has one flip-flop; two inputs, X and Y; and one output, S. It consists of a full-adder
                                                        circuit connected to a JK flip-flop, as shown. Fill in the truth table for this sequential circuit by
                                                        completing the Next State and Output columns.
                                                        ***REFER TO TEXTBOOK FOR QUESTION REFERENCE***

        9 Points      Question #11:        N/A          Construct a Moore Machine and a Mealy machine which recognize strings over the alphabet {a,b,c} and output 1
                                                        if the string contains the substring "abc", and 0 otherwise. For example, the input "abbcabacba" outputs 0,
                                                        while the input of "ababaababc" outputs 1.

        9 Points      Question #12:        N/A          Simplify a function, F(w, x, y, z), with the following truth table. Then Justify your answer...

                                                        TRUTH TABLE USED:         |    W    |    X    |    Y    |    Z    |    F    |
                                                                                  |    0    |    0    |    0    |    0    |    0    |
                                                                                  |    0    |    0    |    0    |    1    |    0    |
                                                                                  |    0    |    0    |    1    |    0    |    0    |
                                                                                  |    0    |    0    |    1    |    1    |    0    |
                                                                                  |    0    |    1    |    0    |    0    |    0    |
                                                                                  |    0    |    1    |    0    |    1    |    0    |
                                                                                  |    0    |    1    |    1    |    0    |    0    |
                                                                                  |    0    |    1    |    1    |    1    |    0    |
                                                                                  |    1    |    0    |    0    |    0    |    0    |
                                                                                  |    1    |    0    |    0    |    1    |    0    |
                                                                                  |    1    |    0    |    1    |    0    |    1    |
                                                                                  |    1    |    0    |    1    |    1    |    1    |
                                                                                  |    1    |    1    |    0    |    0    |    1    |
                                                                                  |    1    |    1    |    0    |    1    |    1    |
                                                                                  |    1    |    1    |    1    |    0    |    1    |
                                                                                  |    1    |    1    |    1    |    1    |    1    |

        Total Pts: 100

 Part #2: Submit work to Canvas Submission
*/
