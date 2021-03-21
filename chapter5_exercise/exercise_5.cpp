#include<iostream>
#include<cctype>
#include <algorithm>
#include<string>
#include<fstream>
#include<vector>
#include<array>

namespace ex5_1 {
	int inputFromUser() {
		int number{};
		std::cout << "\n Enter a number";
		std::cin >> number;
		return number;
	}
	void run() {
		std::cout << "\nExample 1";

		int limit = std::move(inputFromUser());
		for (size_t i = 1; i < limit; i=i+2)
		{
			std::cout << "\n Number = " << i << " square = " << i*i;
		}
	}
}

namespace ex5_2 {
	void calc() {
		int sum{}, totalNumbers{};
		std::string yOrN(1,'n');
		while (1) {

			std::cout << "\n Want to enter a number, press 'y'?";
			std::cin >> yOrN;
			std::transform(yOrN.begin(), yOrN.end(), yOrN.begin(), [](unsigned char C) {return std::tolower(C); });
			if (yOrN == "y") {
				int value;
				std::cout << "\nEnter number:";
				std::cin >> value;
				totalNumbers++;
				sum += value;
			}
			else {
				break;
			}
		}
		if (totalNumbers > 0) {
			std::cout << "\n SUM = " << sum;
			std::cout << "\n AVERAGE = " << static_cast<float>(sum / static_cast<float>(totalNumbers));
		}
		else {
			std::cout << "\n SUM = 0";
			std::cout << "\n AVERAGE =0";
		}
	}
	void run() {
		std::cout << "Example 2";
		calc();
	}
}

namespace ex5_3 {
	void calc() {
		std::string inputLine{}, terminateChar{};
		do
		{
			std::cout << "\nEnter something\n";
			std::getline(std::cin, inputLine, '\n');
			std::cout << "\n You entered " << std::endl << inputLine;

			size_t count1{};
			for (size_t i = 0; i < inputLine.length(); i++)
				if (std::isalpha(inputLine.at(i))) count1++;
			std::cout << "\n It has " << count1 << " non whitespaces";

			std::cout << "\n Enter '#' to stop else any other key to continue" << std::endl;
			// solution 1 - use getline and get rid of the issue of cin and getline combination.
			std::getline(std::cin, terminateChar);			
			// solution 2 - std::cin  doesn't pick the remaining \n from input stream, use a dummy getline to pick it.
			//std::cin >> terminateChar;
			//std::getline(std::cin, inputLine);
		} while (terminateChar != "#");
	}
	void readFromFile() {
		std::ifstream input("Text.txt");
		std::string intoString;
		std::cout << "\nPrinting the contents of file: Text.txt" << std::endl;
		while (std::getline(input, intoString, '\n')) {
			std::cout << intoString << std::endl;
		}
	}
	void run() {
		std::cout << "\n Example 3";
		calc();
		readFromFile();
	}
}
namespace ex5_4 {
	void calc() {
		constexpr size_t MAX_VALUE = 1000;
		char cstring[MAX_VALUE];
		size_t count{};
		std::cin.getline(cstring, MAX_VALUE, '\n');	// c style string API.
		for (size_t i = 0; cstring[i] != '\0' ; i++)
		{
			count++;
		}
		std::cout << std::endl << "The string is" << std::endl << cstring;
		std::cout << std::endl << "\nCount of words : " << count;

		while (count != 0) {
			std::cout << "\n " << cstring[count-1];
			count--;
		}
		// for loop when using size_t goes into infinite loop.
	}
	void run() {
		std::cout << "\n Example 4";
		calc();
	}
}
namespace ex5_5 {
	void calc() {
		constexpr size_t MAX_VALUE = 1000;
		char cstring[MAX_VALUE];
		std::cin.getline(cstring, MAX_VALUE, '\n');	// c style string API.
		int count{};
		while (cstring[count] != 0) {
			count++;
		}

		std::cout << std::endl << "The string is" << std::endl << cstring;
		std::cout << std::endl << "\nCount of words with whitespace: " << count;
		// --real work
		int start{ 0 };
		int end{ count - 1 };
		while (start < end) {
			auto temp = cstring[start];
			cstring[start] = cstring[end];
			cstring[end] = temp;

			start++;
			end--;
		}
		//--
		std::cout << "\nReverse c style string = " << std::endl << cstring;
		for (size_t i = 0; i < count/2; i++)
		{
			std::swap(cstring[i], cstring[static_cast<unsigned long long>(count) - 1 - i]);
		}
		std::cout << "\nAgain reverse c style string = " << std::endl << cstring;
	}
	void run() {
		std::cout << "\n Example 5";
		calc();
	}
}
namespace ex5_6 {

	void calc() {
		size_t vecCnt{};
		std::cout << "\nTell me a count of vector";
		std::cin >> vecCnt;
		int number{};
		std::vector<int> vec;

		for (auto i{ 0 }; i <vecCnt ; i++) {
			std::cout << std::endl << "Enter number";
			std::cin >> number;
			vec.push_back(number);
		}
		std::cout << "\nNon multiples of 7/13" << std::endl;
		for (auto elem : vec) {
			if (!(elem % 7 == 0 || elem % 13 == 0))
				std::cout << elem << " ";
		}
	}
	void run() {
		std::cout << "\n Example 6";
		calc();
	}
}

namespace ex5_7 {
	void calc() {
		struct record {
			int productNumber, quantity, unitPrice;
		};
		std::vector<record> products;
		char exitval;
		int pid{}, pquantity{}, punitprice{};
		do{
			std::cout << "\n Enter values : ";
			std::cout << "\n Enter product no : ";
			std::cin >> pid;
			std::cout << "\n Enter quantity no : ";
			std::cin >> pquantity;
			std::cout << "\n Enter unitprice no : ";
			std::cin >> punitprice;
			products.push_back({ pid, pquantity, punitprice});
			std::cout << "\nExit(y/n) ";
			std::cin >> exitval;
		} while (exitval == 'n');

		// printing
		std::cout << "\n Printing products";
		for (const auto elem : products) {
			std::cout << std::endl << elem.productNumber << " " << elem.quantity << " "<< elem.unitPrice << " " << elem.quantity*elem.unitPrice;
		}

	}
	void run() {
		std::cout << "\n Example 7";
		calc();
	}
}
namespace ex5_8 {
	void calc() {
		std::array<unsigned long long, 93> fibarrayholder{};
		unsigned long long initvalue{}; // 0 inisitally
		fibarrayholder[0] = 1;
		fibarrayholder[1] = fibarrayholder[0] + initvalue;

		for (size_t i{ 2 }; i < fibarrayholder.size(); i++) {
			fibarrayholder[i] = fibarrayholder[i - 1] + fibarrayholder[i - 2];
		}

		std::cout << "\n Printing array with fibonacci values " << std::endl;
		for (auto elem : fibarrayholder) {
			std::cout << elem << " ";
		}
	}
	void run() {
		std::cout << "\n Example 8";
		calc();
	}
}
int main() {
//	ex5_1::run();
//	ex5_2::run();
//	ex5_3::run();
//	ex5_4::run();
//	ex5_5::run();
//	ex5_6::run();
	ex5_7::run();
//	ex5_8::run();
}