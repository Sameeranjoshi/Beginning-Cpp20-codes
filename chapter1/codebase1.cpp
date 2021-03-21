#include<iostream>
#include <iterator>
#include<algorithm>
#include<cstddef>
#include<array>
#include<vector>
#include<numbers>
namespace sample5stdvector {

	template<typename T>
	void printstdVec(T vec) {
		std::cout << "\n printing std::vector" << std::endl;
		if (!vec.empty()) {
			for (auto elem : vec) {
				std::cout << elem << " ";
			}
		}
		else {
			std::cout << std::endl << "Vector has 0 elements";
		}
		std::cout << std::endl;
	}

	void define() {
		std::vector<int> v1{};
		std::vector<int> v2 = { 1, 2, 3 };
		std::vector<int> v3(10);
		std::cout << "\nPrint " << v3.capacity() << v3.size();
		std::vector<int> v4(10,200);
		std::cout << "\nPrint " << v4.capacity() << v4.size();

		printstdVec(v1);
		printstdVec(v2);
		printstdVec(v3);
		printstdVec(v4);
	}
	void vectorOperators() {
		std::vector<int> v1(10);
		std::vector<int> v2(10, 20);
		printstdVec(v1);
		printstdVec(v2);
		std::cout << "\n < " << std::boolalpha << (v1 < v2);
		std::cout << "\n > " << std::boolalpha << (v1 > v2);
		std::cout << "\n <= " << std::boolalpha << (v1 <= v2);
		std::cout << "\n >= " << std::boolalpha << (v1 >= v2);
		std::cout << "\n == " << std::boolalpha << (v1 == v2);
		std::cout << "\n != " << std::boolalpha << (v1 != v2);
	}
	void vectorCheckers() {
		std::cout << "\n Vector checkers";

		std::vector<int> v1{1, 2, 3, 4};
		std::cout << std::boolalpha << "\n .empty() : " << v1.empty();
		std::cout << "\n .size() : " << v1.size();
		std::cout << "\n .capacity() : " << v1.capacity();
		std::cout << "\n .max_size() : " << v1.max_size();
		std::cout << std::endl;
	}
	template<typename T>
	void printcapacity(T vec) {
		std::cout << "\n Capacity = " << vec.capacity();
	}
	void run() {
		std::cout << "\n In vectors";
		define();
		vectorCheckers();
		vectorOperators();
	}
}

namespace sample4stdarray {
	template<typename T>
	void printstdarraycapacity(T arr) {
		std::cout << "\n printing std::array capacity" << std::endl;
		std::cout << "\n .empty() : " << arr.empty();
		std::cout << "\n .size() : " << arr.size();
		std::cout << "\n .max_size() : " << arr.max_size();
		std::cout << std::endl;
	}

	template<typename T>
	void printstdarray(T arr) {
		std::cout << "\n printing std::array" << std::endl;
		for (auto elem : arr) {
			std::cout << elem << " ";
		}
		std::cout << std::endl;
	}
	void defining() {
		std::array<int, 10> a1 = {1,2,3};
		std::array<int, 10> a2 = { };
		std::array<int, 10> a6;

		//std::array<int, 10> a5;	// must be initialized.

		std::array a3 { 1,2,3 };
		//std::array a4{ 1,2,3.3, 3.3 }; // Compiler error: needs same data types.

		a6.fill(100);

		printstdarray(a1);
		printstdarray(a2);
		printstdarray(a3);
		printstdarray(a6);

		printstdarraycapacity(a1);	
	}
	void operationsonarray() {
//define
		std::array<int, 10> a1 = { 1,2,3 };
		std::array<int, 10> a2 = { };

//fill
		a2.fill(20);

// swap		
		std::cout << "\n Before";
		printstdarray(a1);
		printstdarray(a2);
		a1.swap(a2);
		std::cout << "\n After";
		printstdarray(a1);
		printstdarray(a2);

// other functions		
		std::cout << "\n .front() :" << a2.front();
		std::cout << "\n .back() :" << a2.back();
		std::cout << "\n .data() :" << a2.data();
		std::cout << "\n .operator[2] :" << a2[2];
		std::cout << "\n .at(2) :" << a2.at(2);
	}

	void run() {
		std::cout << "\n Inside namespace sample4stdarray\n";
		defining();
		operationsonarray();
	}
}
namespace sample3chararray {
	void chararrayBasics() {
		char somearray[] = { 'a', 'b', 'c' };		
		char somestring[10] = { "the" };
		std::cout << "\n Enter the string with space";
		std::cin.getline(somestring, 10);
		std::cout << "\n string with space" << std::endl << somestring << std::endl;
		std::cout << somearray << std::endl ;
	}
	void multiDimension() {
		int mat[3][4] = {};
		auto printLambda = [=](const int (&mat)[3][4]) {
			for (size_t i = 0; i < std::size(mat); i++)
			{
				for (size_t j = 0; j < std::size(mat[i]); j++)
				{
					std::cout << " " << mat[i][j];
				}
				std::cout << std::endl;
			}
		};
		printLambda(mat);
	}
	void charArray() {
		char charr[][20] = { 
			"okgoogle", 
			"this", 
			"that", 
			"no", 
			"bad" 
		};
		std::cout << "\n SIZE OF CHAR ARRAY:  " << std::size(charr);
	}

	// variable length arrays are at least not allowed on this compiler.
	// use vector instead.
	void variableLenghtArray() {
		const int arrsize{ 10 };
		//size_t count{};
		//std::cin >> count;
		int arr[arrsize];
		std::cout << "\n Printing variable size- array ";
		for (auto i : arr) {
			std::cout << std::endl << i;
		}
	}
	void initmat() {
//		int mat1[][3] = {};
//		int mat2[][2] = { {1,2}, {3} };

	}
	void run() {
		std::cout << "\n Inside namespace sample3chararray\n";
		//chararrayBasics();
		//multiDimension();
		charArray();
		variableLenghtArray();
	}
}
namespace sample2 {
	void dowhile() {
		std::cout << "\n Printing do while";
		int i{};
		do {
			std::cout << "\n I:" << i;
			i++;	
		} while (i < 10);
	}
	void rangeBasedFor() {
		std::cout << "\n Printing range based for loops: \n";
		int values[] = { 1,2,34,4,5,6,7,8,9,0 };
		for (const auto &var : values){
			std::cout << var << std::endl;
		}
	}
	void usingstdformat() { // c++20 not supported.
		auto radius{ 10 };
		double floatval{ 10.3333 };
		//std::format();
	}
	void emptyLoops() {
		for (size_t i{}; i < 10; i++);
	}
	void uniquepointer() {
		std::unique_ptr<int[]> uptr = std::make_unique<int[]>(5);
		uptr[0] = 60;
		uptr[1] = 50;
		uptr[2] = 40;
		uptr[3] = 30;
		uptr[4] = 20;
		std::cout << "\n Printing address of uptr : \n" << uptr;
		std::cout << "\n Printing value of uptr : \n" << uptr[0];
	}
	void stdsizecpp17() {
		int array[] = { 1,2,3,34,555,5,2303 };
		std::cout << "\n Printing using std::size() c++17 \n" << std::size(array);
	}
	void run() {
		std::cout << "\n Inside namespace sample2\n";
		stdsizecpp17();
		uniquepointer();
		emptyLoops();
		rangeBasedFor();
		dowhile();
	}
}

namespace sample1 {
	const size_t size{ 6 };

	class playwithArray
	{
	public:
		playwithArray(std::initializer_list<int> initList) {
			arraySize = initList.size();
			int j = 0;
			for (auto i{ initList.begin() }; i != initList.end(); i++) {
				array[j++] = *i;
			}
		}
		~playwithArray();
		void printArray() {
			std::cout << "\n Printing array";
			for (auto i = 0; i < arraySize; i++)
			{
				std::cout << "\n ELEMENT[" << i + 1 << "] = " << array[i];
			}
		}
		int* getArray() {
			return array;
		}
		/*void operator=(playwithArray &assignFrom) {
			std::copy(std::begin(assignFrom.getArray()), std::end(assignFrom.getArray()), std::begin(this->array));
		}*/
	private:
		int array[size];
		int arraySize;
	};

	playwithArray::~playwithArray()
	{
	}
	void run() { // equivalent to main, but only that the you can't use 2 mains in VS.
		std::cout << "\n SIZEOF(size_t) " << sizeof(sample1::size);
		sample1::playwithArray somearrayObj{};
		sample1::playwithArray somearrayObj2{ 1222,2,3,422,5,638 };
		somearrayObj.printArray();
		somearrayObj2.printArray();
		//somearrayObj = somearrayObj2;*/
		//	int a[3], b[3] = { 1,2,3 };

		//	std::cout << "\n some array";
		//	std::cout << a[0] << a[1] << a[2];
	}
}

int	 main() {
	sample1::run();
	sample2::run();
	sample3chararray::run();
	sample4stdarray::run();
	sample5stdvector::run();
}
