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
struct Question
{
   string prompt;          // Prompts Each Question's Text Statement
   vector<string> options; // MC options (empty for FR questions)
   string answer;          // Correct answer key or text
   bool isMultipleChoice;  // True = MCQ, False = free-response

   void ask(int index) const
   {
      std::cout << "\nQUESTION #" << (index + 1)
                << " >> " << prompt << "\n";

      if (isMultipleChoice)
      {
         char label = 'A';
         for (size_t i = 0; i < options.size(); ++i)
         {
            cout << "   {" << label++ << ": " << options[i] << "}\n";
         }
      }
      else
      {
         cout << "[Read Carefully & Input a Valid Answer]\n";
      }
   }
};

// NORMALIZE FUNCTION
// Strips out non-alphanumeric chars and lowercases input
string normalize(const string &input)
{
   string out;
   for (size_t i = 0; i < input.size(); ++i)
   {
      char c = input[i];
      if (isalnum(static_cast<unsigned char>(c)))
         out += tolower(static_cast<unsigned char>(c));
   }
   return out;
}

// Using void to run quiz questions and accept answer input(s)
void QuizRunner(vector<Question> &quiz)
{
   int score = 0;
   string userInput;
   time_t start = time(NULL);

   // Iterate through each question
   for (size_t i = 0; i < quiz.size(); ++i)
   {
      quiz[i].ask(i);
      cout << "Your answer: ";
      getline(cin, userInput);

      // Normalize both user input and the correct answer for comparison
      if (normalize(userInput) == normalize(quiz[i].answer))
      {
         cout << "CORRECT!\n";
         ++score;
      }
      else
      {
         cout << "The Answer is INCORRECT! ";
         // Show the correct answer for feedback
         if (quiz[i].isMultipleChoice && !quiz[i].options.empty())
         {
            cout << "Correct answer: " << quiz[i].answer << " ("
                 << quiz[i].options[quiz[i].answer[0] - 'A'] << ")\n";
         }
         else
         {
            cout << "Correct answer: " << quiz[i].answer << "\n";
         }
      }
      cout << endl;
   }

   // Compute time & percentage
   time_t end = time(NULL);
   double elapsed = difftime(end, start);
   double percent = 100.0 * score / quiz.size();

   // Display final results
   cout << "\nCongratulations! You have finished Quiz 1!";
   cout << "\nFinal Grade: " << score << "/" << quiz.size()
        << " (" << fixed << setprecision(1) << percent << "%)\n";
   cout << "Time Taken: " << elapsed << " seconds\n";
}

// MAIN FUNCTION
int main() {
   // Input all Quiz Questions Below in Braces
   // Define which question is a MCQ or FRQ
   vector<Question> quiz;

   quiz.push_back({"The level of the computer hierarchy where an operating system functions is the?",
                   {"Machine Level", "System Software Level", "Digital Logic Level", "Control Gate Level"},
                   "B", // Correct Answer: "System Software Level"
                   true});

   quiz.push_back({"There are _____ megabytes in a terabyte.",
                   {"2^10", "2^40", "2^20", "2^30"},
                   3, true // Correct Answer: "2^30" 
                  });

   quiz.push_back({"The von Neumann Bottleneck ____________.",
                   {"Describes the single processor-memory path", "Is eliminated when multiple processors/cores are used",
                    "Was first invented by John Atanasoff", "Creates collisions on an I/O bus"},
                   "A",
                   true});

   quiz.push_back({"The level of computer hierarchy that is composed of gates and wires is the ________________.",
                   {"Digital Logic Level", "System Software Level", "Control Level", "Machine Level"},
                   "A",
                   true});

   quiz.push_back({"A kilobyte represents 2 to the power of what?",
                   {},
                   "10",
                   false});

   quiz.push_back({"In the von Neumann architecture, the central processing unit (CPU) consists of registers, an arithmetic-logic unit (ALU), and a(n)",
                   {},
                   "control unit",
                   false});

   quiz.push_back({"In 1965, one of the founders of Intel predicted \"The density of transistors in an integrated circuit will double every year.\" This is now known as:",
                   {},
                   "Moore's law",
                   false});

   quiz.push_back({"Expressed as a power of two, there are _________ kilobytes in a megabyte?",
                   {},
                   "10",
                   false});

   quiz.push_back({"Any task done by software can also be done using computer hardware, and any operation performed directly by hardware can be done using system software.",
                   {"True", "False"},
                   "A",
                   true});

   quiz.push_back({"The fetch-decode-execute cycle is also called the instruction architecture cycle?",
                   {"True", "False"},
                   "B",
                   true});

   quiz.push_back({"Computer architecture encompasses all physical aspects of computer systems.",
                   {"True", "False"},
                   "B",
                   true});

   quiz.push_back({"It is evident that multi-core processors have higher computing power than multiple processors?",
                   {"True", "False"},
                   "B",
                   true});

   cout << "👋 Welcome to CDA-3103 Computer Organization Practice Material\n"; 
   cout << "You will be completing the following: Quiz #1 Computer Architecture Fundamentals\n";
   cout << "Ready to start the quiz? (Y/N): \n";

   string choice;
   getline(cin, choice);

   if (!choice.empty() && (tolower(choice[0]) == 'y' || toupper(choice[0]) == 'Y'))
   {
      cout << "INSTRUCTIONS: ";
      QuizRunner(quiz);
   }
   else
   {
      cout << "Successfully Terminated the Quiz!\n";
   }

   return 0;
}
