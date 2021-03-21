#include<iostream>
#include<typeinfo>
#include<vector>
#include<memory>
#include<array>

namespace sample1 {
	void pointersyntax_seman(){
		long long* p{};
		double* doubleptr{}, doublevar = 0.0;
		int* q = nullptr, avar = 0;

		int a1{ 10 };
		int* pa1 = &a1;
		std::cout << std::endl;
		std::cout << "\n a1 = " << a1;
		std::cout << "\n &a1 = " << &a1;
		std::cout << "\n pa1 = " << pa1;
		std::cout << "\n &pa1 = " << &pa1;
		std::cout << "\n *pa1 = " << *pa1;

		std::cout << "\n Programming with pointers ";
		std::cout << "p = " << p;
		std::cout << "&p = " << &p;
		//std::cout << "*p = " << *p;	// derefencing a nullptr is runtime failure.


		std::cout << "\n You know what the sizeof a pointer is constant and is machine dependent: ";
		std::cout << "\n sizeof(pa1)= " << sizeof(pa1) << sizeof pa1 ;
	}

	void charpoitnerTheMystery() {
		const char* charp = { "Why on this earth" };
		const char* charq = { "Why on this \0earth" };
		std::cout << "\n charp = " << charp;
		std::cout << "\n *charp = " << *charp;
		std::cout << "\n charq(has \\0 explicitely) = " << charq;

		std::cout << std::endl << "printing strlen() of pointers";
		std::cout << std::endl << std::strlen(charp);
		std::cout << std::endl << std::strlen(charq);

		// remember changing char pointer is not allowed.
		//charp[0] = "O";
	}
	void arrayofpoitners() {
		const char* arrptr[] = { "this is one", "then two", "nOW WE ARE THREE" };
		std::cout << "\n Printing array of char pointers\n";
		std::cout << *arrptr;
		std::cout << arrptr[0] << std::endl;
		std::cout << arrptr[1] << std::endl;
		std::cout << arrptr[2] << std::endl;
		std::cout << &arrptr;

		int a{ 10 }, b{ 20 }, c{ 30 };
		int* p[] = { &a, &b, &c };
		std::cout << "\n Printing int* array\n";
		std::cout << p[0] << std::endl;
		std::cout << p[1] << std::endl;
		std::cout << p[2] << std::endl;
		std::cout << *p[0] << std::endl;
		std::cout << *p[1] << std::endl;
		std::cout << *p[2] << std::endl;
	}
	void pointerandconstness() {
		const int* p{};
		int* const p1{};
		const int* const p2{};
	}
	void pointerandarray() {
		int p[4]{ 10, 11, 12, 13 };
		int a1{ 10 }, b1{ 20 };
		int* q{ p };
		int* pa1{ &a1 };
		int* qa1{ &b1 };
		std::cout << "\n Printing array with pointer\n";
		std::cout << p << std::endl;
		std::cout << q;
		std::cout << "\n DIFF(qa1-pa1)\n" << qa1 - pa1 << std::endl << pa1 << std::endl << qa1 ;
	}
	void ptrdiff() {
		std::cout << "\n PTRDIFF_T - \n";
		int* p{};
		int* q{};
		std::cout << p - q;
		std::cout << "\n Printing typeid(p) = " << typeid(p-q).name();
	}
	void freestoreandpointers() {
		double* ptr{};
		ptr = new double;
		if (!ptr) {
			std::cout << "\n free store full\n";
			exit (-1);
		}
		*ptr = 10;
		std::cout << "\n *ptr= " << *ptr;
		std::cout << "\n ptr= " << ptr;

		double* ptrint{ new double(3.421) };
		double* ptrnullptr{ new double{} };
		double* pp{};
		std::cout << "\n *ptr= " << *ptrint;
		std::cout << "\n *ptrnullptr= " << *ptrnullptr;

		// let's delete something.
		delete ptrint;
		ptrint = nullptr;
//		std::cout << "\n Printing the dandling memory\n" << *ptrint;
	}
	void arraysandfreestore() {
		std::cout << "\n Arrays and free store";
		int* ptrarr{new int[]{1,2}};

		for (size_t i = 0; i < 10; i++)
		{
			std::cout << std::endl << ptrarr[i];
		}

		delete[] ptrarr;
		ptrarr = nullptr;
	}
	void vectorandfreestore() {
		std::vector<int> v1{ 1,2,3 };
		std::vector<int>* pvec = &v1;
		pvec->push_back(10);
		std::cout << "\n pvec = " << pvec;
		std::cout << "\n *pvec = " << (*pvec).at(0);
		std::cout << "\n &pvec = " << &pvec;
		//std::cout << "\n pvec[0] = " << pvec[0];
		//std::cout << "\n pvec[2] = " << pvec[2];

		std::cout << "\nPrinting using for each";
		for (auto elem : *pvec) {
			std::cout << elem;
		}
	}
	void smartpointers() {
		std::unique_ptr<int> ptr1{ new int{10} };
		auto ptr2{ std::make_unique<int>(20) };
		auto ptr3{ std::make_unique<int[]>(3) };
/*		std::shared_ptr<int> p1= &addr1;
		std::shared_ptr<int> p2 = &addr1;
		std::shared_ptr<int> p3 = &addr1;
		*/
		std::cout << "\n unique_ptr \n";
		std::cout << *ptr1  << ptr1.get();
		std::cout << std::endl << " ptr = " << ptr1;
		std::cout << std::endl << " *ptr = " << *ptr1 << "  " << *ptr2 ;
		std::cout << std::endl << " &ptr = " << &ptr1;
	}
	void uniqueptr() {
		std::cout << "\n Playing with unique pointer - ";
		std::unique_ptr<int> uptr{ std::make_unique<int>(10) };
		std::cout << "\n uptr = " << uptr;
		std::cout << "\n uptr.get() = " << uptr.get();
		std::cout << "\n *uptr = " << *uptr;
		std::cout << "\n uptr.operator*() = " << uptr.operator*();
		std::cout << "\n uptr.release() = ";
		auto* stackptr{ &uptr};
		auto* saveheapptr{ uptr.release() };
		std::cout << "\n *uptr = " << *saveheapptr << std::endl << uptr << std::endl << "*stackptr = " << *stackptr; 
	}
	void references() {
		std::cout << "\n Playing with references\n";

		std::cout << "\nSimple variables \n";
		// This is not allowed, a reference can be to only variables/pointers.
		//int& aref{10};
		const int someveryconstantvariable{ 20 };
		const int& aref{ someveryconstantvariable };
		std::cout << "someveryconstantvariable = " << someveryconstantvariable;
		std::cout << "\naref to above const = " << aref;

		std::cout << "\n pointers and references\n";
		auto avariable{ 20.3 };
		auto* apointer{ &avariable };
		auto& areftopointer{ apointer };
		auto& areftothevalueinthepointer{ *apointer };
		std::cout << "\n avariable = " << avariable;
		std::cout << "\n areftopointer = " << areftopointer;
		std::cout << "\n areftothevalueinthepointer = " << areftothevalueinthepointer ;

		auto& acopyref{ aref };
		std::cout << "\n acopyref = " << acopyref;

		std::array<int,10> anarray{ 1,2,3,4,5,6,7,8 };
		std::cout << std::endl;
		for (auto& elembyref : anarray) {
			std::cout << " " << elembyref++;
		}
		std::cout << std::endl << "\n Now printing the above array after changes using references\n";
		for (auto& elembyref : anarray) {
			std::cout << " " << elembyref;
		}
	}
	void run() {
		std::cout << "\n Inside Sample1 play with pointer syntax ";
		pointersyntax_seman();
		charpoitnerTheMystery();
		arrayofpoitners();
		pointerandarray();
		ptrdiff();
		freestoreandpointers();
		arraysandfreestore();
		vectorandfreestore();
		smartpointers();
		uniqueptr();
		references();
		int p = 10;
		std::cout << "\n typeid(p).name() = " << typeid(p).name();
	}
}
int	 main() {
	sample1::run();
}
