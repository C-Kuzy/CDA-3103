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

*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cctype>
#include <iomanip>
#include <random>

using namespace std;

// ------------------
// QUESTION STRUCT
// ------------------
struct Question
{
   string prompt;        // The question text
   vector<string> options; // MC options (empty for FR questions)
   string answer;          // Correct answer key or text
   bool isMultipleChoice;  // True = MCQ, False = free-response

   void ask(int index) const
   {
      cout << "\nQUESTION #" << (index + 1)
           << " >> " << prompt << "\n";

      if (isMultipleChoice)
      {
         char label = 'A';
         for (const auto &opt : options)
         {
            cout << "   {" << label++ << ": " << opt << "}\n";
         }
      }
      else
      {
         cout << "   [Input a valid answer below]\n";
      }
   }
};

// ------------------
// NORMALIZE FUNCTION
// ------------------
// Strips out non-alphanumeric chars and lowercases input
string normalize(const string &input)
{
   string out;
   for (char c : input)
   {
      if (isalnum(static_cast<unsigned char>(c)))
         out += tolower(static_cast<unsigned char>(c));
   }
   return out;
}

// ------------------
// QUIZ RUNNER
// ------------------
void QuizRunner(vector<Question> &quiz)
{
   // Shuffle questions
   random_device rd;
   mt19937 gen(rd());
   std::shuffle(quiz.begin(), quiz.end(), gen);

   int score = 0;
   string userInput;
   time_t start = time(NULL);

   // Iterate through each question
   for (size_t i = 0; i < quiz.size(); ++i)
   {
      quiz[i].ask(i);
      cout << "Your answer: ";
      getline(cin, userInput);

      // Compare normalized answers
      if (normalize(userInput) == normalize(quiz[i].answer))
      {
         ++score;
      }
   }

   // Compute time & percentage
   time_t end = time(NULL);
   double elapsed = difftime(end, start);
   double percent = 100.0 * score / quiz.size();

   // Display final results
   cout << "\n🎯 Final Score: " << score << "/" << quiz.size()
        << " (" << fixed << setprecision(1) << percent << "%)\n";
   cout << "⏱️ Time Taken: " << elapsed << " seconds\n";
}

// ------------------
// MAIN FUNCTION
// ------------------
int main()
{
   // Input all Quiz Questions Below in Braces
   // Define which question is a MCQ or FRQ
   vector<Question> quiz = {
       // Question #1: (Multiple Choice Question)
       {"The level of the computer hierarchy where an operating system functions is the?",
           {"Machine Level", "System Software Level", "Digital Logic Level", "Control Gate Level"}, "B", true
       },
       // Q2 (MCQ)
       {
           "There are _____ megabytes in a terabyte.",
           {"2^10", "2^40", "2^20", "2^30"}, "D", true
       },
       // Q3 (MCQ)F
       {
           "The von Neumann Bottleneck ____________.",
           {"Describes the single processor-memory path",
            "Is eliminated when multiple processors/cores are used",
            "Was first invented by John Atanasoff",
            "Creates collisions on an I/O bus"},
           "A",
           true},
       // Q4 (MCQ)
       {
           "The level of computer hierarchy that is composed of gates and wires is the ________________.",
           {"Digital Logic Level",
            "System Software Level",
            "Control Level",
            "Machine Level"},
           "A",
           true},
       // Q5 (Free Response)
       {
           "A kilobyte represents 2 to the power of what?",
           {},
           "10",
           false},
       // Q6 (Free Response)
       {
           "In the von Neumann architecture, the central processing unit (CPU) consists of registers, an arithmetic-logic unit (ALU), and a(n)",
           {},
           "control unit",
           false},
       // Q7 (Free Response)
       {
           "In 1965, one of the founders of Intel predicted \"The density of transistors in an integrated circuit will double every year.\" This is now known as:",
           {},
           "moore's law",
           false},
       // Q8 (Free Response)
       {
           "Expressed as a power of two, there are _________ kilobytes in a megabyte?",
           {},
           "10",
           false},
       // Q9 (MCQ)
       {
           "Any task done by software can also be done using computer hardware, and any operation performed directly by hardware can be done using system software.",
           {"True", "False"},
           "A",
           true},
       // Q10 (MCQ)
       {
           "The fetch-decode-execute cycle is also called the instruction architecture cycle?",
           {"True", "False"},
           "B",
           true},
       // Q11 (MCQ)
       {
           "Computer architecture encompasses all physical aspects of computer systems.",
           {"True", "False"},
           "B",
           true},
       // Q12 (MCQ)
       {
           "It is evident that multi-core processors have higher computing power than multiple processors?",
           {"True", "False"},
           "B",
           true}};

   cout << "👋 Welcome to Quiz #1: Computer Architecture Fundamentals\n\n";
   cout << "Start quiz? (Y/N): ";

   string choice;
   getline(cin, choice);

   if (!choice.empty() && tolower(choice[0]) == 'y')
   {
      QuizRunner(quiz);
   }
   else
   {
      cout << "Quiz aborted. Have a great day!\n";
   }

   return 0;
}