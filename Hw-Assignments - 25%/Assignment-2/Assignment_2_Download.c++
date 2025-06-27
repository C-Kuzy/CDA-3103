/*
  Online version:   https://www.onlinegdb.com/edit/qMfaC1J0-#
  Use this tool for data representation practice
   11. convert unsigned decimal numbers to binary numbers
   12. convert unsigned binary numbers to decimal numbers
   13. convert unsigned decimal numbers to octal numbers
   14. convert unsigned octal numbers to decimal numbers
   15. convert unsigned decimal numbers to hexdecimal numbers
   16. convert unsigned hexdecimal numbers to decimal numbers
   17. convert signed decimal numbers to sign-magnitude binary numbers
   18. convert signed decimal numbers to 1's complementary binary numbers
   19. convert signed decimal numbers to 2's complementary binary numbers
   20. convert sign-magnitude binary numbers to decimal numbers
   21. convert 1's complementary binary numbers to decimal numbers
   22. convert 2's complementary binary numbers to decimal numbers
   23. 1's complement arithmetic operation
   24. 2's complement arithmetic operation
*/

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <limits>
#include <algorithm>
#include <cmath>

// Containing above code to fix issues with "to_string" function in some compilers
#include <sstream>
template<typename T>
std::string to_string(const T& value) {
	std::ostringstream oss;
	oss << value;
	return oss.str();
}
// Fixed Issue #1 ^^^^^^^^^^^

using namespace std;

int generate_random_int(int length, int format = 0); // 0: unsigned int; 1: Sign Magnitude; 2: 1's complement; 3: 2's complement
string Repeat_Division(unsigned int rand_val, int base);
bool check_integer_input_base(string input, int base);
void unsign_decimalI_to_base(std::string name, int base, unsigned int len = 0);

std::string generate_random_base(int base, int len);
int weighted_sum(string pattern, int base);
void unsign_base_to_decimal(std::string name, int base, unsigned int len);

string signed_D2B(int value, int format, unsigned int len);
void signed_decimal_to_binary(std::string name, int format, unsigned int len);

void signed_binary_to_decimal(std::string name, int format, unsigned int len);

bool binary_addition(string datax, string datay, string& sum, string& carry, unsigned int length);

void arithmetic_practice(unsigned int length, unsigned int format);

enum format { unsigned_int, sign_magnitude, ones_complement, twos_complement };
int main()
{
	int elapsed = time(NULL);
	srand(elapsed);

	char choice = 'y';
	string name;

	std::cout << "Welcome to CDA 3103 (Summer 2025) Data Representation Practice" << endl << endl;

	while (tolower(choice) == 'y')
	{
		if (tolower(choice) == 'y')
			std::cout << "Practice Menu\n\n"
			<< "11. Convert unsigned decimal numbers to binary numbers (8 bits)" << endl
			<< "12. Convert unsigned binary numbers to decimal numbers" << endl
			<< "13. Convert unsigned decimal numbers to octal numbers" << endl
			<< "14. Convert unsigned octal numbers to decimal numbers" << endl
			<< "15. Convert unsigned decimal numbers to hexdecimal numbers" << endl
			<< "16. Convert unsigned hexdecimal numbers to decimal numbers" << endl
			<< "17. Convert signed decimal numbers to sign - magnitude binary numbers" << endl
			<< "18. Convert signed decimal numbers to 1's complementary binary numbers" << endl
			<< "19. Convert signed decimal numbers to 2's complementary binary numbers" << endl
			<< "20. Convert sign - magnitude binary numbers to decimal numbers" << endl
			<< "21. Convert 1's complementary binary numbers to decimal numbers" << endl
			<< "22. Convert 2's complementary binary numbers to decimal numbers" << endl
			<< "23. 1's complement arithmetic operation" << endl
			<< "24. 2's complement arithmetic operation" << endl << endl;

		if (name.length() == 0)
		{
			std::cout << "State Your Full Name ('First' + 'Last'): ";
			getline(cin, name);
		}

		int menu_item = 0;
		while (menu_item < 11 || menu_item > 24)
		{
			cout << "\nPlease select from the following practice items in the table above!: ";
			cin >> menu_item;
			if (cin.good())
			{
				if (menu_item < 11 || menu_item > 24)
					cout << "Menu item must be within [11-24], please try again!" << endl;
				else
					break;
			}
			else if (cin.fail())
				std::cout << "That's not a valid number! Try again." << endl;
			else if (cin.bad())
			{
				std::cout << "An unrecoverable error has occurred. Bye!" << endl;
				return 0;
			}
		}

		switch (menu_item) {
		case 11:
			unsign_decimalI_to_base(name, 2, 8);
			break;
		case 12:
			unsign_base_to_decimal(name, 2, 8);
			break;
		case 13:
			unsign_decimalI_to_base(name, 8);
			break;
		case 14:
			unsign_base_to_decimal(name, 8, 5);
			break;
		case 15:
			unsign_decimalI_to_base(name, 16);
			break;
		case 16:
			unsign_base_to_decimal(name, 16, 4);
			break;
		case 17:
			signed_decimal_to_binary(name, sign_magnitude, 8);
			break;
		case 18:
			signed_decimal_to_binary(name, ones_complement, 8);
			break;
		case 19:
			signed_decimal_to_binary(name, twos_complement, 8);
			break;
		case 20:
			signed_binary_to_decimal(name, sign_magnitude, 8);
			break;
		case 21:
			signed_binary_to_decimal(name, ones_complement, 8);
			break;
		case 22:
			signed_binary_to_decimal(name, twos_complement, 8);
			break;
		case 23:
			std::cout << endl << "User: " << name << endl;
			arithmetic_practice(8, ones_complement);
			break;
		case 24:
			std::cout << endl << "User: " << name << endl;
			arithmetic_practice(8, twos_complement);
			break;
		default:
			cout << "Invalid practice item!\n\n";
		};

		std::cout << "Want to practice another item? (y/n): ";
		std::cin >> choice;
		std::cin.ignore(numeric_limits<streamsize>::max(), '\n');
		std::cout << endl;
	}

	return 0;
}

int generate_random_int(int length, int format)
{
	//int elapsed = time(nullptr);
	//srand(elapsed);

	int maxim = pow(2, length);
	int rand_val = rand() % (maxim);  //obtain scaled 0...255

	if (format == 1 || format  == 2)
		rand_val = rand() % (maxim-1) - (maxim/2 - 1);  //obtain scaled -127...127
	
	if (format == 3)
		rand_val = rand() % maxim - maxim/2;  //obtain scaled -128...127
	
	return rand_val;
}


string Repeat_Division(unsigned int rand_val, int base)
{
	int reminder;
	string converted_rep;

	while (rand_val > 0)
	{
		reminder = rand_val % base;
		if (reminder < 10)
			converted_rep = to_string(reminder) + converted_rep;
		else
		{
			if (base == 16)
			{
				converted_rep = static_cast<char>(reminder + 55) + converted_rep;
			}
		}
		rand_val = rand_val / base;
	}
	return converted_rep;
}

bool check_integer_input_base(string input, int base)
{
	bool valid_input = true;

	unsigned int len = input.length();
	for (unsigned int i = 0; i < len; i++)
	{
		//if (isdigit(input[i]))
		//	if (input[i] - '0' >= base)
		//		valid_input = false;
	}

	return valid_input;
}

void unsign_decimalI_to_base(string name, int base, unsigned int len)
{
	int count = 0;
	int correct = 0;
	string converted_rep;
	string converted_input;
	char choice = 'y';

	int elapsed = time(NULL);
	srand(elapsed);

	int rand_val;

	while (tolower(choice) == 'y')
	{
		count++;
		rand_val = generate_random_int(8, 0);

		// convert the decimal to other base
		converted_rep = Repeat_Division(rand_val, base);
		while (converted_rep.length() < len)
		{
			converted_rep = '0' + converted_rep;
		}

		// get converted result from users.
		std::cout << "Please convert "	<< rand_val	<< " to unsigned ";
		switch (base)
		{
		case 2:
			std::cout << "8 - bit binary representation : ";
			break;
		case 8:
			std::cout << "octal representation : ";
			break;
		case 16:
			std::cout << "hexdecimal representation: ";
		}
		
		while (true)
		{
			if (std::cin >> converted_input)
			{

				std::cin.ignore(numeric_limits<streamsize>::max(), '\n');
				break;
			}
			else if(std::cin.fail())
			{
				std::cout << "That's not a valid number! Try again!" << endl;
				std::cin.clear();
				std::cin.ignore(numeric_limits<streamsize>::max(), '\n');
				continue;
			}
		}

		std::transform(converted_input.begin(), converted_input.end(), converted_input.begin(), ::toupper);

		// Check the input
		if (converted_rep.compare(converted_input) == 0)
		{
			correct++;
			std::cout << "\t Exellent!\n";
		}
		else
		{
			std::cout << "\t The converted unsigned data representation should be " << converted_rep << endl;
		}
		std::cout << "Continue? (y/n): ";
		std::cin >> choice;
		std::cin.ignore(numeric_limits<streamsize>::max(), '\n');
		std::cout << endl;
	}

	std::cout << "Name: " << name << endl;
	std::cout << "You have completed " << count << " conversions of unsigned decimal integers to ";
	switch (base)
	{
	case 2:
		std::cout << "binary." << endl;
		break;
	case 8:
		std::cout << "octal." << endl;
		break;
	case 16:
		std::cout << "hexdecimal." << endl;
	}
	std::cout << "You have done " << correct << " correctly." << endl << endl;
}

string generate_random_base(int base, int len)
{
	int rand_val;

	//int elapsed = time(nullptr);
	//srand(elapsed);

	string rand_pattern;
	for (int i = len - 1; i >= 0; i--)
	{
		rand_val = rand() % base;
		if (rand_val < 10)
		{
			rand_pattern = to_string(rand_val) + rand_pattern;
		}
		else
		{
			if (base == 16)
			{
				rand_pattern = static_cast<char>(rand_val + 55) + rand_pattern;
			}
		}
	}
	return rand_pattern;
}

int weighted_sum(string pattern, int base)
{
	int decimal_rep = 0;
	int weight = 1;
	for (int i = pattern.length() - 1; i >= 0; i--)
	{
		if (isdigit(pattern[i]))
			decimal_rep += (pattern[i] - '0') * weight;
		else
			decimal_rep += (pattern[i] - 'A' + 10) * weight;
		weight = weight * base;
	}
	return decimal_rep;
}

// This function converts unsigned binary/oct/hex to decimal
void unsign_base_to_decimal(string name, int base, unsigned int len)
{
	int count = 0;
	int correct = 0;

	int decimal_input;
	int decimal_rep;
	char choice = 'y';


	while (tolower(choice) == 'y')
	{
		count++;

		// generate a 8-bit binary data
		string rand_pattern = generate_random_base(base, len);

		decimal_rep = weighted_sum(rand_pattern, base);

		std::cout << "Please convert " << rand_pattern << " to unsigned decimal representation: ";

		while (true)
		{
			if (std::cin >> decimal_input)
			{
				std::cin.ignore(numeric_limits<streamsize>::max(), '\n');
				break;
			}
			else if (std::cin.fail())
			{
				std::cout << "That's not a valid number! Try again!" << endl;
				std::cin.clear();
				std::cin.ignore(numeric_limits<streamsize>::max(), '\n');
				continue;
			}
		}

		//std::cin >> decimal_input;
		//std::cin.ignore(numeric_limits<streamsize>::max(), '\n');

		if (decimal_rep == decimal_input)
		{
			correct++;
			std::cout << "\t Exellent!\n";
		}
		else
		{
			std::cout << "\t The converted unsigned decimal data representation should be " << decimal_rep << endl;
		}

		std::cout << "Continue? (y/n): ";
		std::cin >> choice;
		std::cin.ignore(numeric_limits<streamsize>::max(), '\n');
		std::cout << endl;
	}

	std::cout << "Name: " << name << endl;
	std::cout << "You have completed " << count << " conversions of unsigned ";
	switch (base)
	{
	case 2:
		std::cout << "Binary";
		break;
	case 8:
		std::cout << "Octal";
		break;
	case 16:
		std::cout << "Hexdecimal";
	}
	std::cout << " to decimal." << endl
		<< "You have done " << correct << " correctly." << endl << endl;
}

string signed_D2B(int value, int format, unsigned int len)
{
	string converted_rep = Repeat_Division(abs(value), 2);

	while (converted_rep.length() < len)
	{
		converted_rep = '0' + converted_rep;
	}

	switch (format)
	{
	case 1:			// Sign-magnitued
		if (value < 0)
			converted_rep[0] = '1';
		break;
	case 2:			// 1's complement
		if (value < 0)
		{
			for (int i = 0; i < len; i++)
				if (converted_rep[i] == '0')
					converted_rep[i] = '1';
				else
					converted_rep[i] = '0';
		}
		break;
	case 3:			// 2's complement
		if (value < 0)
		{
			int i;
			for (i = len - 1; i >= 0; i--)
			{
				if (converted_rep[i] == '1')
					break;
			}
			i--;
			for (; i >= 0; i--)
				if (converted_rep[i] == '0')
					converted_rep[i] = '1';
				else
					converted_rep[i] = '0';
		}
	}

	return converted_rep;
}

void signed_decimal_to_binary(string name, int format, unsigned int len)
{
	int count = 0;
	int correct = 0;
	string converted_rep;
	string converted_input;
	char choice = 'y';

	//int elapsed = time(nullptr);
	//srand(elapsed);

	int rand_val;

	while (tolower(choice) == 'y')
	{
		count++;
		rand_val = generate_random_int(len, format);

		converted_rep = signed_D2B(rand_val, format, len);
		//if (format == 1 || format == 2)
		//	rand_val = rand() % 255 - 127;  //obtain scaled -127...127
		//else
		//	rand_val = rand() % 256 - 128;  //obtain scaled -128...127

		std::cout << "Please convert "
			<< rand_val
			<< " to signed decimal to 8-bit binary representation with ";
		switch (format)
		{
		case 1:			// Sign-magnitued
			std::cout << "sign-magnitude : ";
			break;
		case 2:			// 1's complement
			std::cout << "1's complement: ";
			break;
		case 3:			// 2's complement
			std::cout << "2's complement: ";
		}

		// get the converted input from the user.
		while (true)
		{
			if (std::cin >> converted_input)
			{
				std::cin.ignore(numeric_limits<streamsize>::max(), '\n');
				break;
			}
			else if (std::cin.fail())
			{
				std::cout << "That's not a valid number! Try again!" << endl;
				std::cin.clear();
				std::cin.ignore(numeric_limits<streamsize>::max(), '\n');
				continue;
			}
		}
		//std::cin >> converted_input;
		//std::cin.ignore(numeric_limits<streamsize>::max(), '\n');

		//converted_rep = Repeat_Division(abs(rand_val), 2);
		//while (converted_rep.length() < len)
		//{
		//	converted_rep = '0' + converted_rep;
		//}
		//
		//switch (format)
		//{
		//case 1:			// Sign-magnitued
		//	if (rand_val < 0)
		//		converted_rep[0] = '1';
		//	break;
		//case 2:			// 1's complement
		//	if (rand_val < 0)
		//	{
		//		for (int i = 0; i < len; i++)
		//			if (converted_rep[i] == '0')
		//				converted_rep[i] = '1';
		//			else
		//				converted_rep[i] = '0';
		//	}
		//	break;
		//case 3:			// 2's complement
		//	if (rand_val < 0)
		//	{
		//		int i;
		//		for (i = len - 1; i >= 0; i--)
		//		{
		//			if (converted_rep[i] == '1')
		//				break;
		//		}
		//		i--;
		//		for (; i >= 0; i--)
		//			if (converted_rep[i] == '0')
		//				converted_rep[i] = '1';
		//			else
		//				converted_rep[i] = '0';
		//	}
		//}

		if (converted_rep.compare(converted_input) == 0)
		{
			correct++;
			std::cout << "\t Exellent!\n";
		}
		else
		{
			std::cout << "\t The converted signed data representation should be " << converted_rep << endl;
		}
		std::cout << "Continue? (y/n): ";
		std::cin >> choice;
		std::cin.ignore(numeric_limits<streamsize>::max(), '\n');
		std::cout << endl;
	}

	std::cout << "Name: " << name << endl;
	std::cout << "You have completed " << count << " conversions of signed decimal integers to binary with ";
	switch (format)
	{
	case 1:
		std::cout << "sign magnitude." << endl;
		break;
	case 2:
		std::cout << "1's complement." << endl;
		break;
	case 3:
		std::cout << "2's complement." << endl;
	}
	std::cout << "You have done " << correct << " correctly." << endl << endl;
}

int signed_B2D(string pattern, int format, unsigned int len)
{
	int decimal_rep = 0;
	int weight = 1;

	for (int i = len - 1; i >= 0; i--)
	{
		if (isdigit(pattern[i]))
			decimal_rep += (pattern[i] - '0') * weight;
		else
			decimal_rep += (pattern[i] - 'A' + 10) * weight;
		weight = weight * 2;
	}

	if (pattern[0] == '1')
	{
		switch (format)
		{
		case 1:			// Sign-magnitued
			decimal_rep = -(decimal_rep - weight / 2);
			break;
		case 2:			// 1's complement
			decimal_rep = decimal_rep - weight + 1;
			break;
		case 3:			// 2's complement
			decimal_rep = decimal_rep - weight;
			break;
		}
	}
	return decimal_rep;
}

void signed_binary_to_decimal(string name, int format, unsigned int len)
{
	int count = 0;
	int correct = 0;
	int decimal_input;
	int decimal_rep;
	char choice = 'y';

	while (tolower(choice) == 'y')
	{
		count++;

		// generate a 8-bit binary data
		string rand_pattern = generate_random_base(2, len);
		decimal_rep = signed_B2D(rand_pattern, format, len);

		std::cout << "Please convert signed binary pattern " << rand_pattern << " of ";
		switch (format)
		{
		case 1:			// Sign-magnitued
			std::cout << "sign-magnitude ";
			break;
		case 2:			// 1's complement
			std::cout << "1's complement ";
			break;
		case 3:			// 2's complement
			std::cout << "2's complement ";
		}
		std::cout << "to decimal representation: ";
		while (true)
		{
			if (std::cin >> decimal_input)
			{
				std::cin.ignore(numeric_limits<streamsize>::max(), '\n');
				break;
			}
			else if (std::cin.fail())
			{
				std::cout << "That's not a valid number! Try again!" << endl;
				std::cin.clear();
				std::cin.ignore(numeric_limits<streamsize>::max(), '\n');
				continue;
			}
		}
		//std::cin >> decimal_input;
		//std::cin.ignore(numeric_limits<streamsize>::max(), '\n');

		//for (int i = len - 1; i >= 0; i--)
		//{
		//	if (isdigit(rand_pattern[i]))
		//		decimal_rep += (rand_pattern[i] - '0') * weight;
		//	else
		//		decimal_rep += (rand_pattern[i] - 'A' + 10) * weight;
		//	weight = weight * 2;
		//}

		//if (rand_pattern[0] == '1')
		//{
		//	switch (format)
		//	{
		//	case 1:			// Sign-magnitued
		//		decimal_rep = -(decimal_rep - weight / 2);
		//		break;
		//	case 2:			// 1's complement
		//		decimal_rep = decimal_rep - weight + 1;
		//		break;
		//	case 3:			// 2's complement
		//		decimal_rep = decimal_rep - weight;
		//		break;
		//	}
		//}

		if (decimal_rep == decimal_input)
		{
			correct++;
			std::cout << "\t Exellent!\n";
		}
		else
		{
			std::cout << "\t The converted signed decimal data representation should be " << decimal_rep << endl;
		}

		std::cout << "Continue? (y/n): ";
		std::cin >> choice;
		std::cin.ignore(numeric_limits<streamsize>::max(), '\n');
		std::cout << endl;
	}

	std::cout << "Name: " << name << endl;
	std::cout << "You have completed " << count << " conversions of signed binary of ";
	switch (format)
	{
	case 1:			// Sign-magnitued
		std::cout << "sign-magnitude ";
		break;
	case 2:			// 1's complement
		std::cout << "1's complement ";
		break;
	case 3:			// 2's complement
		std::cout << "2's complement ";
	}
	std::cout << " to decimal." << endl
		<< "You have done " << correct << " correctly." << endl << endl;
}

// This function performs binary addition.
bool binary_addition(string datax, string datay, string& sum, string& carry, unsigned int length)
{
	int i;
	char carry_in = '0', carry_out = '0';
	bool overflow = false;
	sum = "";
	carry = "";

	for (i = length - 1; i >= 0; i--)
	{
		carry_in = carry_out;

		if (carry_in == '0')
		{
			if (datax[i] == '1' && datay[i] == '1')
				carry_out = '1';
			else
				carry_out = '0';

			if (datax[i] == datay[i])
				sum = '0' + sum;
			else
				sum = '1' + sum;

		}
		else
		{
			if (datax[i] == '0' && datay[i] == '0')
				carry_out = '0';
			else
				carry_out = '1';

			if (datax[i] == datay[i])
				sum = '1' + sum;
			else
				sum = '0' + sum;
		}
		carry = carry_out + carry;
	}

	if (carry_in != carry_out)
		overflow = true;

	return overflow;
}

void display_binary_addition(string datax, string datay, string sum, string carry)
{
	unsigned int length = datax.length();

	std::cout << "   ";
	for (unsigned int i = 0; i < length; i++)
		std::cout << datax[i] << ' ';
	std::cout << endl;

	std::cout << " + ";
	for (unsigned int i = 0; i < length; i++)
		std::cout << datay[i] << ' ';
	std::cout << endl;

	std::cout << "---";
	for (unsigned int i = 0; i < length; i++)
		std::cout << "--";
	std::cout << endl;

	std::cout << "   ";
	for (unsigned int i = 0; i < length; i++)
		std::cout << sum[i] << ' ';
	std::cout << endl;
}

void display_binary_addition_no_result(string datax, string datay)
{
	unsigned int length = datax.length();

	std::cout << "          ";
	for (unsigned int i = 0; i < length; i++)
		std::cout << datax[i] << ' ';
	std::cout << endl;

	std::cout << "        + ";
	for (unsigned int i = 0; i < length; i++)
		std::cout << datay[i] << ' ';
	std::cout << endl;

	std::cout << "       ---";
	for (unsigned int i = 0; i < length; i++)
		std::cout << "--";
	std::cout << endl;

}

void display_sum(char carry, string sum)
{
	unsigned int length = sum.length();

	if (carry == '1')
		std::cout << "        1 ";
	else
		std::cout << "          ";

	for (unsigned int i = 0; i < length; i++)
		std::cout << sum[i] << ' ';
	std::cout << endl;

	return;
}
void addition_1_complement(string datax, string datay, unsigned int length)
{
//	char carry;
	string sum;
	string carry;
	string second_y = "";
	string second_sum;
	string second_carry;

	bool overflow = binary_addition(datax, datay, sum, carry, 8);

	display_binary_addition(datax, datay, sum, carry);

	if (carry[0] == '1')
	{
		std::cout << "End Round Carry:" << endl;
		for (unsigned int i = 0; i < length - 1; i++)
		{
			second_y += '0';
		}
		second_y += '1';
	}
	//	bool overflow = binary_addition(sum, second_y, second_sum, second_carry, 8);



	if (overflow)
		std::cout << "Overflow occurs!" << endl << endl;
	else
		std::cout << "The result is correct and no overflow." << endl << endl;
}

string get_user_input(int rand_val, unsigned int format)
{
	string converted_input;

	switch (format)
	{
	case 1:			// Sign-magnitued
		std::cout << "sign-magnitude : ";
		break;
	case 2:			// 1's complement
		std::cout << "1's complement: ";
		break;
	case 3:			// 2's complement
		std::cout << "2's complement: ";
	}

	// get the converted input from the user.
	while (true)
	{
		if (std::cin >> converted_input)
		{
			std::cin.ignore(numeric_limits<streamsize>::max(), '\n');
			break;
		}
		else if (std::cin.fail())
		{
			std::cout << "That's not a valid number! Try again!" << endl;
			std::cin.clear();
			std::cin.ignore(numeric_limits<streamsize>::max(), '\n');
			continue;
		}
	}
	//std::cin >> converted_input;
	//std::cin.ignore(numeric_limits<streamsize>::max(), '\n');

	return converted_input;
}

void arithmetic_practice(unsigned int length, unsigned int format)
{
	int data1, data2, result_input, result;
	string datax_rep, datay_rep;
	string datax_input, datay_input;
	string sum_rep, sum_input;
	string carry;
	char carry_input;
	bool overflow, overflow_result;
	char overflow_input;
	char end_round_carry_input;
    int count = 0;
	int correct = 0;

	data1 = generate_random_int(length, format);
	data2 = generate_random_int(length, format);

	datax_rep = signed_D2B(data1, format, length);
	datay_rep = signed_D2B(data2, format, length);

	std::cout << "In this exercise, you need to compute ";
	if (data1 < 0)
		std::cout << '(';
	std::cout << data1; 
	if (data1 < 0)
		std::cout << ')';
	std::cout << " + ";

	if (data2 < 0)
		std::cout << '(';
	std::cout << data2;
	if (data2 < 0)
		std::cout << ')';
	std::cout << " using 8 - bit ";
	if (format == ones_complement)
		std::cout << "1's complement operation. ";
	if (format == twos_complement)
		std::cout << "2's complement operation. ";
	std::cout<<"Verify if the result is correct." << endl << endl;

	std::cout << "Step 1: Convert decimal data to binary" << endl;
	std::cout << "Please convert " << data1	<< " to signed decimal to 8-bit binary representation with ";

	datax_input = get_user_input(data1, format);

	if (datax_input.compare(datax_rep) != 0)
	{
		std::cout << "\t The converted signed data representation should be " << datax_rep << endl;
		std::cout << "The end of this practice" << endl;
		return;
	}

	std::cout << "Please convert " << data2 << " to signed decimal to 8-bit binary representation with ";
	datay_input = get_user_input(data2, format);
	if (datay_input.compare(datay_rep) != 0)
	{
		std::cout << "\t The converted signed data representation should be " << datay_rep << endl;
		std::cout << "The end of this practice" << endl;
		return;
	}

	if (format == ones_complement)
		std::cout << endl << "Step 2a: Perform binary addition" << endl;
	else
		std::cout << endl << "Step 2: Perform binary addition" << endl;

	display_binary_addition_no_result(datax_rep, datay_rep);

	std::cout << "Please input the final carry bit (0 or 1)?: ";
	std::cin >> carry_input;
	std::cin.ignore(numeric_limits<streamsize>::max(), '\n');

	std::cout << "Please input the above binary addition result: ";
	getline(cin, sum_input);

	overflow = binary_addition(datax_rep, datay_rep, sum_rep, carry, length);

	display_binary_addition_no_result(datax_rep, datay_rep);
	display_sum(carry_input, sum_input);

	if (sum_input.compare(sum_rep) != 0 || carry[0] != carry_input)
	{
		std::cout << "The calculated binary addition result should be " << sum_rep << endl;
		std::cout << "The carry bit is " << carry[0] << endl << endl;
		std::cout << "The end of this practice" << endl;
		return;
	}

	if (format == ones_complement)
	{
		std::cout << endl << "Step 2b: End-Round Carry?" << endl;

		std::cout << "End-round carry operation is required for this binary addition? (y/n): ";
		std::cin >> end_round_carry_input;
		std::cin.ignore(numeric_limits<streamsize>::max(), '\n');

		//&& tolower(end_round_carry_input) == 'y')

		if (carry[0] == '1' && tolower(end_round_carry_input) == 'n')
		{
			std::cout << "The End Round Carry is required when the carry bit is set." << endl;
			std::cout << "The end of this practice" << endl << endl;
			return;
		}

		if (carry[0] == '0' && tolower(end_round_carry_input) == 'y')
		{
			std::cout << "The End Round Carry is not required when the carry bit is not set." << endl;
			std::cout << "The end of this practice" << endl << endl;
			return;
		}

		if (carry[0] == '1')
		{
			string erc_sum;
			string erc_datay = "";
			string erc_carry;
			for (unsigned int i = 0; i < length - 1; i++)
			{
				erc_datay += '0';
			}
			erc_datay += '1';

			display_binary_addition_no_result(sum_rep, erc_datay);

			std::cout << "Please input the final carry bit (0 or 1)?: ";
			std::cin >> carry_input;
			std::cin.ignore(numeric_limits<streamsize>::max(), '\n');

			std::cout << "Please input the above binary addition result: ";
			getline(cin, sum_input);

			bool erc_overflow = binary_addition(sum_rep, erc_datay, erc_sum, erc_carry, length);

			display_binary_addition_no_result(sum_input, erc_datay);
			display_sum(carry_input, sum_input);

			if (sum_input.compare(erc_sum) != 0 || erc_carry[0] != carry_input)
			{
				std::cout << "The calculated binary addition result should be " << erc_sum << endl;
				std::cout << "The carry bit is " << erc_carry[0] << endl << endl;
				std::cout << "The end of this practice" << endl;
				return;
			}
			
			sum_rep = erc_sum;
			carry = erc_carry;
			if (overflow || erc_overflow)
				overflow = true;
			else
				overflow = false;

		}
	}

	std::cout << endl << "Step 3: Verify the result." << endl;
	std::cout << "Please convert the result binary sum to decimal value: ";
	while (true)
	{
		if (std::cin >> result_input)
		{
			std::cin.ignore(numeric_limits<streamsize>::max(), '\n');
			break;
		}
		else if (std::cin.fail())
		{
			std::cout << "That's not a valid number! Try again!" << endl;
			std::cin.clear();
			std::cin.ignore(numeric_limits<streamsize>::max(), '\n');
			continue;
		}
	}

	//std::cin >> result_input;
	//std::cin.ignore(numeric_limits<streamsize>::max(), '\n');

	std::cout << "Overflow occurs or not (y/n)?: " ;
	std::cin >> overflow_input;
	std::cin.ignore(numeric_limits<streamsize>::max(), '\n');

	std::cout << endl;

	result = signed_B2D(sum_rep, format, length);

	if (result != result_input)
	{
		std::cout << "The resulted decimal value should be " << result << endl;
		std::cout << "The end of this practice" << endl << endl;
		return;
	}
	else if (tolower(overflow_input) == 'y' && overflow == false) 
	{ 
		std::cout << "Overfow does not occur!" << endl;
		std::cout << "The end of this practice" << endl << endl;
		return;
	}
	else if (tolower(overflow_input) == 'n' && overflow == true)
	{
		std::cout << "Overfow does occur!" << endl;
		std::cout << "The end of this practice" << endl << endl;
		return;
	}
	else
	{
		if (tolower(overflow_input) == 'y')
			std::cout << "Overflow occurs and the final result is wrong." << endl;
		else
			std::cout << "The final result is correct and no overflow occurs." << endl;
		
		std::cout << "Well done!" << endl << endl;
	}

	return;
}
