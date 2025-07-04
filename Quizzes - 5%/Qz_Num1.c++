/*
 Author: C-Kuzy
 Description: Quiz #1 Questions w/ Answers & Calculations
              The Quiz features a total of 12 questions

 QUESTION #1 >> The level of the computer heirarchy where an operating system functions is the?
    {A: Machine Level, B: System Software Level, C: Digital Logic Level, D: Control Gate Level}

 QUESTION #2 >> There are _____ megabytes in a terabyte.
    {A: 2^10, B: 2^40, C: 2^20, D: 2^30}

 QUESTION #3 >> The von Neumann Bottleneck ____________.
    {A: Describes the single processor-memory path, B: Is eliminated when multiple processors/cores are used
    , C: Was first invented by John Atanasoff, D: Creates collisions on an I/O bus}

 QUESTION #4 >> The level of computer hierarchy that is composed of gates and wires is the ________________.
    {A: Digital Logic Level, B: System Software Level, C: Control Level, D: Machine Level}

 QUESTION #5 >> A kilobyte represents 2 to the power of what?
    {Input a valid answer: Value}

 QUESTION #6 >> In the von Neumann architecture, the central processing unit (CPU) consists of registers,
                an arithmetic-logic unit (ALU), and a(n)
    {Input a valid answer: Word}

 QUESTION #7 >> In 1965, one of the founders of Intel predicted "The density of transistors in an integrated
                circuit will double every year." This is now known as: __________.
    {Input a valid answer: Word}

 QUESTION #8 >> Expressed as a power of two, there are _________ kilobytes in a megabyte?
    {Input a valid answer: Value}

 QUESTION #9 >> Any task done by software can also be done using computer hardware, and any operation
                performed directly by hardware can be done using system software.
    {A: True, B: False}

 QUESTION #10 >> The fetch-decode-execute cycle is also called the instruction architecture cycle?
    {A: True, B: False}

 QUESTION #11 >> Computer architecture encompasses all physical aspects of computer systems.
    {A: True, B: False}

 QUESTION #12 >> It is evident that multi-core processors have higher computing power than multiple processors?
    {A: True, B: False}

-----------------------------------------------------------------------------------------------------------------
-----------------------------------------------------------------------------------------------------------------
*/

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cctype>
#include <iomanip>
#include <algorithm>

using namespace std;

// Building Quiz Question Structure
struct Question {
   string prompt;          // Prompts Each Question's Text Statement
   vector<string> options; // MC options (Leave the braces "{}" empty for FRQ questions)
   string answer;          // Listed Correct Answer under each question in int main()
   bool isMC;  // Reference: True = MCQ && False = free-response

   void ask(int index) const {
      
      // Prompts Each Question
      std::cout << "\nQUESTION #" << (index + 1)
                << " >> " << prompt << "\n";

      // Building the array input for int main() questions          
      if (isMC) {
         char label = 'A';
         for (size_t i = 0; i < options.size(); ++i) {
            cout << "   {" << label++ << ": " << options[i] << "}\n";
         }
      }
      else { // If invalid characters/answer choices are entered
         cout << "FRQ QUESTION [Read Carefully & Input a Valid Answer]\n";
      }
   }
};

// Using the normalize function helps strips out chars and lowercases input
string normalize(const string &input) {
   string out;
   for (size_t i = 0; i < input.size(); ++i) {
      char c = input[i];
      if (isalnum(static_cast<unsigned char>(c)))
         out += tolower(static_cast<unsigned char>(c));
   }
   return out;
}

// Using void to run quiz questions and accept answer input(s)
void QuizRunner(vector<Question> &quiz) {
   int pts = 0;
   string userInput;
   time_t start = time(NULL);

   // Demonstrating pts assignment following each question
   for (size_t i = 0; i < quiz.size(); ++i) {
      quiz[i].ask(i);
      cout << "Answer Selection: ";
      getline(cin, userInput);

      // Normalize both user input and the correct/incorrect answer for comparison
      if (normalize(userInput) == normalize(quiz[i].answer)) { // User selected the correct answer
         cout << "CORRECT!\n";
         ++pts;
      }
      else { // User selected an incorrect answer
         cout << "The Answer is INCORRECT! ";
         // Show the correct answer for feedback
         if (quiz[i].isMC && !quiz[i].options.empty()) {
            cout << "Correct answer: " << quiz[i].answer << " ("
                 << quiz[i].options[quiz[i].answer[0] - 'A'] << ")\n";
         }
         else {
            cout << "Correct answer: " << quiz[i].answer << "\n";
         }
      }
      cout << endl;
   }

   // AFTER PROGRAM ENDS CALCULATE Time & Grade/Percentage
   time_t End = time(NULL);
   double time_elapsed = difftime(End, start);
   double percentage = 100.0 * pts / quiz.size();

   // Display Final Results!
   cout << "\nCongratulations! You have finished Quiz 1!";
   cout << "\nFinal Grade: " << pts << "/" << quiz.size()
        << " (" << fixed << setprecision(1) << percentage << "%)\n";
   cout << "Time Taken: " << time_elapsed << " seconds\n";
}

int main() { // Main Function Purpose: House ALL Quiz Questions

   /* REFER TO TOP OF PROGRAM FOR QUESTION INPUT */
   /* Define which question is a MCQ or FRQ */
    vector<Question> quiz;

   /* QUESTION #1: MCQ */
   quiz.push_back({"The level of the computer hierarchy where an operating system functions is the?",
                  {"Machine Level", "System Software Level", "Digital Logic Level", "Control Gate Level"},
                  "B", true
               }); // Correct Answer: "System Software Level"

   /* QUESTION #2: MCQ */
   quiz.push_back({"There are _____ megabytes in a terabyte.",
                  {"2^10", "2^40", "2^20", "2^30"},
                  "D", true
               }); // Correct Answer: "2^30"

   /* QUESTION #3: MCQ */
   quiz.push_back({"The von Neumann Bottleneck ____________.", 
                  {"Describes the single processor-memory path", 
                  "Is eliminated when multiple processors/cores are used",
                  "Was first invented by John Atanasoff", 
                  "Creates collisions on an I/O bus"},
                  "A", true
               }); // Correct Answer: "Describes the single processor-memory path"

   /* QUESTION #4: MCQ */
   quiz.push_back({"The level of computer hierarchy that is composed of gates and wires is the ________________.",
                  {"Digital Logic Level", "System Software Level", "Control Level", "Machine Level"},
                  "A", true
               }); // Correct Answer: "Digital Logic Level"

   /* QUESTION #5: FRQ */
   quiz.push_back({"Expressed as a power of two, a kilobyte represents 2 to the power of what?",
                  {"Ex: 2^x"},
                  "2^10", false
               }); // Correct Answer: "2^10"

   /* QUESTION #6: FRQ */
   quiz.push_back({"In the von Neumann architecture, the central processing unit (CPU) consists of registers, an arithmetic-logic unit (ALU), and a(n)",
                  {},
                  "Control Unit", false
               }); // Correct Answer: "Control Unit"

   /* QUESTION #7: FRQ */
   quiz.push_back({"In 1965, one of the founders of Intel predicted \"The density of transistors in an integrated circuit will double every year.\" This is now known as:",
                  {},
                  "Moore's Law", false
               }); // Correct Answer: "Moore's Law"

   /* QUESTION #8: FRQ */
   quiz.push_back({"Expressed as a power of two, there are _________ kilobytes in a megabyte?",
                  {},
                  "2^10", false
               }); // Correct Answer: "2^10"

   /* QUESTION #9: MCQ */
   quiz.push_back({"Any task done by software can also be done using computer hardware, and any operation performed directly by hardware can be done using system software.",
                  {"True", "False"},
                  "A", true
               }); // Correct Answer: "True"

   /* QUESTION #10: MCQ */
   quiz.push_back({"The fetch-decode-execute cycle is also called the instruction architecture cycle?",
                  {"True", "False"},
                  "B", true
               }); // Correct Answer: "False"

   /* QUESTION #11: MCQ */
   quiz.push_back({"Computer architecture encompasses all physical aspects of computer systems.",
                  {"True", "False"},
                  "B", true
               }); // Correct Answer: "False"

   /* QUESTION #12: MCQ*/
   quiz.push_back({"It is evident that multi-core processors have higher computing power than multiple processors?",
                  {"True", "False"},
                  "B", true
               }); // Correct Answer: "False"

   // PROMPT USER WITH GREETING MESSAGE, DESCRIPTION, & QUIZ INITIATION
   cout << "👋 Welcome to CDA-3103 Computer Organization Practice Material\n"; 
   cout << "You will be completing the following: Quiz #1 Computer Architecture Fundamentals\n";
   cout << "Ready to start the quiz? (Y/N): ";

   // Determining Input to Start/Kill the Quiz
   string choice;
   getline(cin, choice);

   if (!choice.empty() && (tolower(choice[0]) == 'y' || toupper(choice[0]) == 'Y')) { // If the user input's "Y" or "y"
      cout << "\nINSTRUCTIONS: 12 Question Mix of MCQ OR FRQ Style\n";
      QuizRunner(quiz);
   }
   else { // If the user input's "N" or "n"
      cout << "\nGOODBYE! Quiz Successfully Terminated...\n";
   }
   return 0;
}
