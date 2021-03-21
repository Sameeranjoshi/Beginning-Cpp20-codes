#include<iostream>
#include<array>
#include<vector>
#include<memory>
// There were a few cavets here, I might not be following the question correctly.

namespace ex6_6 {
	void calc() {
		int n{};
		std::cout << "\nEnter size of vector\n";
		std::cin >> n;

		long float sum{};

		// 100 float values all initialized to `0`.
		std::vector<float> oddnumbersvector(n);
		for (size_t i{ 0 }; i < n; i++)
			oddnumbersvector[i] = 1.0 / ((i + 1) * (i + 1));

		std::cout << "\nPrinting the vector\n";
		for (const auto &elem : oddnumbersvector) {
			sum += elem;
		}

		std::cout << "\n SUM= " << sum;
		std::cout << "\n SUM*6= " << sum * 6;
		std::cout << "\n sqrt(SUM*6)= " << sqrt(sum * 6);
	}
	void run() {
		std::cout << "\n EXERCISE -6.6\n";
		calc();
	}
}

namespace ex6_5 {
	void calc() {
		int n{};
		std::cout << "\nEnter size of vector\n";
		std::cin >> n;

		auto uptrtoarray = std::make_unique<float[]>(n);
		

		float sum{};
		for (size_t i{ 0 }; i < n; i++) {
			*(uptrtoarray.get() + i) = 1.0 / ((i + 1) * (i + 1));
			sum += *(uptrtoarray.get() + i);
		}
		
		std::cout << "\nPrinting the vector\n";

		std::cout << "\n SUM= " << sum;
		std::cout << "\n SUM*6= " << sum * 6;
		std::cout << "\n sqrt(SUM*6)= " << sqrt(sum * 6);
	}
	void run() {
		std::cout << "\n EXERCISE -6.5\n";
		calc();
	}
}


namespace ex6_4 {
	void calc() {
		int n{};
		std::cout << "\nEnter size of vector\n";
		std::cin >> n;
		auto *ptrtovec = new std::vector<float>(n);
		
		long float sum{};
		std::cout << "\n OK GOOGLE\n";
		for (size_t i{ 0 }; i < n; i++) {
			ptrtovec->at(i) = 1.0 / ((i + 1) * (i + 1));
			sum += ptrtovec->at(i);
		}
		/*
		for (size_t i = 0; i < n; i++)
		{
			std::cout << " " << (ptrtovec->at(i));
		}

		// 100 float values all initialized to `0`.
		std::vector<float> oddnumbersvector(n);
		for (size_t i{ 0 }; i < n; i++)
			oddnumbersvector[i] = 1.0 / ((i + 1) * (i + 1));

		std::cout << "\nPrinting the vector\n";
		long float sum{};
		for (const auto &elem : oddnumbersvector) {
			sum += elem;
		}
		*/
		delete ptrtovec;
		std::cout << "\n SUM= " << sum;
		std::cout << "\n SUM*6= " << sum * 6;
		std::cout << "\n sqrt(SUM*6)= " << sqrt(sum * 6);
	}
	void run() {
		std::cout << "\n EXERCISE -6.3\n";
		calc();
	}
}

namespace ex6_3 {
	void calc() {
		int a = 10;
		
		const int sizeofarray{10};
		// variable length arrays are a compiler dependent thing.
		// c++ standard doesn't support that.
//		std::cout << "\nEnter size of array\n";
//		std::cin >> sizeofarray;
		float oddnumbersarrayp[sizeofarray];
		auto* ptrtoarray{ oddnumbersarrayp };
		for (size_t i = 0; i < std::size(oddnumbersarrayp); i++)
		{
			ptrtoarray[i] = static_cast<float>(1/static_cast<float>(std::pow((i+1),2)));
		}
		std::cout << "\nPrinting the array\n";
		int i{};
		long float sum{};
		for (auto elem : oddnumbersarrayp) {
			if (i % 5 == 0)
				std::cout << std::endl;
			std::cout << " " << elem;
			sum += elem;
			i++;
		}

		std::cout << "\n SUM= " << sum;
		std::cout << "\n SUM*6= " << sum*6;
		std::cout << "\n sqrt(SUM*6)= " << sqrt( sum * 6);

	}
	void run() {
		std::cout << "\n EXERCISE -6.3\n";
		calc();
	}
}

namespace ex6_2 {
	void calc() {
		std::array<int, 50> oddnumbersarray{};
		size_t i{ 1 }, count{1};
		while (count!=51)
		{
			oddnumbersarray.at(count-1) = i;
			i = i + 2;
			count++;
		}
		auto* ptr{ &oddnumbersarray[0] };
		auto sizeofarray{ std::size(oddnumbersarray) };
		std::cout << "\n Printing using pointer notation\n";
		for (size_t i = 1; i <= sizeofarray; i++)
		{
			if (i % 10 == 1) {
				std::cout << std::endl;
			}
			std::cout << " " << *ptr;
			ptr++;
		}

		ptr = &oddnumbersarray[sizeofarray-1];
		std::cout << "\n Printing reverse using pointer notation\n";
		for (size_t i = 1; i <= sizeofarray; i++)
		{
			if (i % 10 == 1) {
				std::cout << std::endl;
			}
			std::cout << " " << *ptr;
			ptr--;
		}
	}
	void run() {
		std::cout << "\n EXERCISE -6.2\n";
		calc();
	}
}

namespace ex6_1 {
	void calc() {
		std::array<int, 50> oddnumbersarray{};
		size_t i{ 1 }, count{ 1 };
		// filling values
		while (count != 51)
		{
			oddnumbersarray.at(count - 1) = i;
			i = i + 2;
			count++;
		}
		auto* ptr{ &oddnumbersarray[0] };
		auto sizeofarray{ std::size(oddnumbersarray) };
		std::cout << "\n Printing using index and loop notation\n";
		for (size_t i = 0; i < sizeofarray; i++)
		{
			if ((i) % 10 == 0) {
				std::cout << std::endl;
			}
			std::cout << " " << ptr[i];
		}

		ptr = &oddnumbersarray[0];
		std::cout << "\n Printing reverse using index notation\n";
		for (signed int i = sizeofarray; i > 0; i--)
		{
			if ((i) % 10 == 0) {
				std::cout << std::endl;
			}
			std::cout << " " << *(ptr+i-1);
		}
	}
	void run() {
		std::cout << "\n EXERCISE -6.1\n";
		calc();
	}
}
int main() {
	ex6_1::run();
	ex6_2::run();
	ex6_3::run();
	ex6_4::run();
	ex6_5::run();
	ex6_6::run();
}