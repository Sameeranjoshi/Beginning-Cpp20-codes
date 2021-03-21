#include<iostream>
#include<string>

namespace playingwithstrings {
	void printstringwithnewline(const std::string& strtoprint) {
		std::cout << std::endl << strtoprint;
	}
	void initialization() {
		std::cout << std::endl << " WAYS TO INITIALIZE STRINGS\n";
		std::string str_empty;
		std::string str_emptybrace{};
		std::string str_stringliteral{ "This has a cosntant string literal but the std::string is still non-const compared to C-style strings" };
		std::string str_stringvariable{ str_stringliteral };
		std::string str_curlyandround{ ("this should not") };
		std::string str_roundbrace("Ok this is different from above");
		std::string str_roundandcurly({ "Ok how about this" });
		
		printstringwithnewline(str_empty);
		printstringwithnewline(str_emptybrace);
		printstringwithnewline(str_stringliteral);
		printstringwithnewline(str_stringvariable);
		printstringwithnewline(str_curlyandround);
		printstringwithnewline(str_roundbrace);
		printstringwithnewline(str_roundandcurly);
		
	}
	void highleveloverviewofstringlibrary() {
		// There is 
		// std::string
			//	- This has different ways in which the lower level stuff is represented.
			//  - std::string -> char
			//						- type used(char_t, wchar_t)
			//						- encoding (UTF-8,UTF-16,UTF-32)
			// Hence total 5 ways.

		std::string thisisnormal{"Type = char, encoding = UTF-8"};
		std::wstring thisiswide{L"Type = char, encoding = UTF-8"};
		std::u32string u32encodedstring{U"Type = char, encoding = UTF-32"};
		std::u16string u16encodedstring{u"Type = char, encoding = UTF-16"};
		//std::u8string u8encodedstring{"Type = char, encoding = UTF-8"};
		// std::string_view
			// will discuss as a part of vocabulary types
			// performance, cpp17

		// null terminated strings(maybe can call C-style strings)
		printstringwithnewline(thisisnormal);

	}
	void run() {
		highleveloverviewofstringlibrary();
		//initialization();
	}
}
int main() {
	std::cout << "\n WORKING WITH STRINGS\n";
	playingwithstrings::run();
}