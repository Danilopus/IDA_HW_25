#include <iostream>
#include <string>
#include <windows.h>
#include <time.h>
#include <algorithm>
//#include <array>

// Service functions prototypes ------------------------------------
int Get_Int_SA();			// String-analysis вариант фильтра INTEGER
int Get_Int_Positive();		// String-Analysis вариант проверки ввода INTEGER_POSITIVE		
int Get_Int_PG();			// peek&get вариант проверки ввода INTEGER	
double Get_Dbl_SA();		// String-analysis вариант фильтра DOUBLE.
double Get_Dbl_Positive();	// String-analysis вариант фильтра DOUBLE_POSITIVE
double Get_Dbl_PG();		// peek&get вариант проверки ввода DOUBLE	
int Get_Random(int Range_min, int Range_max);
double Get_Random(double Range_min, double Range_max);
template <typename ANY> void Fill_Array_with_Random(ANY arr[], int Size, ANY Range_min, ANY Range_max);
template <typename ANY> void Array_Console_Out(ANY arr[], int Size);

// Homework 25 ----------------------------------------------------	

//Task 1 / Solved with string instead of char because of avoiding std::cin and using std::getline, that works with strings only
std::string Finding_matches_in_string(std::string Original, std::string str_Search)
{
	int i = 0, offset = -1, final_offset = Original.rfind(str_Search);
	std::string  Final_string;
	if (final_offset == -1)
	{
		std::cout << "\n" << "No matches found";
		return "";
	}
	else if (str_Search == "")
	{
		std::cout << "\n" << "Searching with empty char";
		return "";
	}
	else
	{
		while (offset != final_offset)
		{
			offset++;
			offset = Original.find(str_Search, offset);
			Final_string += str_Search;
		}
	}	
	return Final_string;
}
void Finding_matches_in_string()
{
	std::string Original_string = { "Hello world! Please come and see what I can!" };
	std::cout << "Original string: \"" << Original_string << "\"";
	std::cout << "\n\n"<<"Enter a symbol to search ammount of matches\n -> ";
	std::string str_for_search;
	std::getline(std::cin, str_for_search);	
	std::cout << "\n" << "Final string: " << Finding_matches_in_string(Original_string, str_for_search);
}

//Task 2
bool Palindrome_investigation(std::string String_1)
{
	int String_Length = String_1.length();
	if (String_Length > 1)
	{
		for (int i = 0; i < String_Length / 2; i++)
			if (String_1[i] != String_1[String_Length - i - 1])
				return false;
		return true;
	}
	return false;
}
void Palindrome_investigation()
{
	std::string String_1;
	std::cout << "Enter a word\n\n";
	std::getline(std::cin, String_1);
	for (int i=0;i< String_1.length(); i++)
		String_1[i]=std::toupper(String_1[i]);
	if (Palindrome_investigation(String_1))
	std::cout << "\n" << "PALINDROME CONFIRMED";
	else 
		std::cout << "\n" << "NOT A PALINDROME ";
}

//Task 3
int Punctuation_marks_counter(std::string Frase_String)
{
	int Punctuation_marks_counter = 0;
	for (int i = 0; i < Frase_String.length(); i++)
	{
		std::cout << char(Frase_String[i]);
	 	//std::cout << int(char(Frase_String[i]));
		if ((char(Frase_String[i]) > 31 && char(Frase_String[i]) < 48) || (char(Frase_String[i]) > 57 && char(Frase_String[i]) < 65) || char(Frase_String[i]) > 90 && char(Frase_String[i]) < 97 || char(Frase_String[i])<0)
		Punctuation_marks_counter++;
	}
	return Punctuation_marks_counter;
}
void Punctuation_marks_counter()
{
	std::string Frase_String = { "“First, you’ve gotta know — not fear, know — that someday, you’re gonna die.” – Tyler Durden, Fight Club" };
	std::cout <<"\n\nPunctuation marks quantity = " << Punctuation_marks_counter(Frase_String);
}

//Task 4
std::string String_Rfind(std::string Original_str, char symbol)
{
	int Last_Index = Original_str.rfind(symbol);
	if (Last_Index == -1) return "";
	return  Original_str.substr(Last_Index);
}
void String_Rfind()
{
	std::string Original_str = { "Some people give and forgive and some people get and forget…"};
	//std::string Original_str = { "“First, you’ve gotta know — not fear, know — that someday, you’re gonna die.” – Tyler Durden, Fight Club" };

	char symbol;
	std::cout << "Original string:\n" << Original_str;
	std::cout << "\n\nEnter a symbol to search\n";
	std::string CIN_str;
	std::getline(std::cin, CIN_str);
	symbol = CIN_str[0];
	std::cout << "Result string:\n" << String_Rfind(Original_str, symbol);
}

// MAIN ------- MAIN ------- MAIN ------- MAIN ------- MAIN --------
int main()
{
	setlocale(LC_CTYPE, "Russian");
	system("mode con cols=110 lines=40"); // ??? текст основного меню не входит в окно консоли по умолчанию. При небольшом увеличении окна (lines < 85) пропадает полоса прокрутки, что не здорово. Как ee оставить и не делать (lines > 85)?
	std::string Name_of_Work = { "Home Work 25: Strings" };
	std::string Menu_Element_1 = { "Finding matches in string" };
	std::string Menu_Element_2 = { "Palindrome investigation" };
	std::string Menu_Element_3 = { "Punctuation marks counter" };
	std::string Menu_Element_4 = { "String Rfind and return" };

	do {		
		system("cls");
		std::cout << "\n\t***\t" << Name_of_Work << "\t***\n\n\t\n\nChoose an opion: \n";
		std::cout << "\n 1. " << Menu_Element_1;
		std::cout << "\n 2. " << Menu_Element_2;
		std::cout << "\n 3. " << Menu_Element_3;
		std::cout << "\n 4. " << Menu_Element_4;
		std::cout << "\n\n 0. Exit\n";
		int choice = 0;
		std::cout << "\nYour choice: ";
		choice = Get_Int_Positive();		
		std::cout << "\n";
		// Обработка выбора пользователя
		if (choice == 0) { std::cout << "\nGood By"; for (int j = 0; j < 50; j++) { Sleep(50 - j); std::cout << "y"; } std::cout << "e!"; Sleep(850);  return 0; }
		else if (choice == 1) Finding_matches_in_string();
		else if (choice == 2) Palindrome_investigation();
		else if (choice == 3) Punctuation_marks_counter();
		else if (choice == 4) String_Rfind();
			
		else { std::cout << "\nSuch choice does not exist yet\n"; Sleep(1000); }
		std::cout << "\n\n";
		system("pause");
		} while (true);
		
	//system("pause");
	return 0;
}

// Service functions -----------------------------------------
int Get_Int_SA() {
	std::string a;
	std::cin.sync(); 
	std::cin.clear(); 
	getline(std::cin, a);
	if (a != "")
	{

		if ((a.find_first_not_of("-0123456789") == -1))
		{
			for (int i = 1; i < a.size(); i++) // определяем есть ли минусы кроме первого символа
			{
				if (a[i] == '-') 
				{
					std::cout << "Input Error: Minus misstanding. [INTEGER] expected.\n";
					return Get_Int_SA();
				}
			}
			try
			{
				return stoi(a);
			}
			catch (std::out_of_range)
			{
				std::cout << "Input Error: Data type overflow. [INTEGER] expected.\n";
				return Get_Int_SA();
			}


		}
		else
		{
			std::cout << "Input Error: Incorrect symbol. [INTEGER] expected.\n";
			return Get_Int_SA();
		}
	}
	else
	{
		std::cout << "Input Error: NULL input. [INTEGER] expected.\n";
		return Get_Int_SA();
	}
}
int Get_Int_Positive()
{
	std::string a;
	std::cin.sync();
	std::cin.clear();
	getline(std::cin, a);
	if (a != "") 
	{

		if ((a.find_first_not_of("0123456789") == -1))
		{
			try{
				return stoi(a);
			}
			catch (std::out_of_range){
				std::cout << "Input Error: overflow. Positive [INTEGER] expected.\n";
			}
		}
		else
		{
			std::cout << "Input Error: Positive [INTEGER] expected.\n";
			return Get_Int_Positive();
		}		
	}
	else
		std::cout << "Input Error: NULL input. Positive [INTEGER] expected.\n";
	return Get_Int_Positive();
}
int Get_Int_PG()
{
	int a;
	while (!(std::cin >> a) || (std::cin.peek() != '\n'))
	{
		std::cin.clear();
		while (std::cin.get() != '\n');
		std::cout << "Input error! [INTEGER] expected. Repeat please...\n";
	}
	return a;
}
double Get_Dbl_SA(){
	std::string a;
	std::cin.sync();
	getline(std::cin, a);
	if (a == "") { std::cout << "\nInput Error : NULL input\n"; return Get_Dbl_SA(); }
	if ((a.find_first_not_of("-.0123456789") == -1))
	{
		for (int i = 1; i < a.size(); i++) // Проверяем отсутсвие лишних минусов
		{
			if (a[i] == '-')
			{
				std::cout << "\nInput Error: Minus misstanding. [DOUBLE] expected.\n";
				return Get_Dbl_SA();
			}

		}
		bool Dot_Flag = 0;
		for (int i = 0; i < a.size(); i++) // проверяем отсутсвие лишних точек
		{
			if (a[i] == '.')
			{
				if (Dot_Flag == 1)
				{
					std::cout << "\nInput Error: Dot misstandig. [DOUBLE] expected.\n";
					return Get_Dbl_SA();
				}
				Dot_Flag = 1;
			}

		}		 	
				try{
					return stod(a);
				}
				catch (std::out_of_range) {
					std::cout << "Input Error: overflow. [DOUBLE] expected.\n";
					return Get_Dbl_SA();					
				}						
	}
	else {		
		std::cout << "Incorrect symbols: [DOUBLE] expected.\nUse dot instead of coma. Example 50.64\n";
		return Get_Dbl_SA();
	}
}
double Get_Dbl_Positive(){
	std::string a, dot = ".";
	std::cin.sync();
	std::cin.clear();
	getline(std::cin, a);
	if (a != "")
	{
		if ((a.find_first_not_of(".0123456789") == -1))
		{
			bool One_Dot_already = false;
			for (int i = 0; i < a.size(); i++)
			{				
				if (a[i] == dot[0] && One_Dot_already == true) //проверяем количество разделителей
				{
					std::cout << "Input Error: Dot misstandig. Positive [DOUBLE] expected.\n";
					return Get_Dbl_Positive();
				}
				if (a[i] == dot[0])	One_Dot_already = true;
			}
			try
			{				
				return stod(a);
			}
			catch (std::out_of_range)
			{
				std::cout << "Input Error: Data type overflow. Positive [DOUBLE] expected.\n";
				return Get_Dbl_Positive();
			}
		}
		else
		{
			//std::cout << "Incorrect symbols: positive REAL expected.\nUse coma instead of dot. Example 50,64\n"; // да точно говорю вот даже сообщение такое было, а теперь наоборот wtf*2?!
			std::cout << "Incorrect symbols: Positive [DOUBLE] expected.\nUse dot instead of coma. Example 50.64\n";
			return Get_Dbl_Positive();
		}
	}
	else
	{
		std::cout << "Input Error: NULL input. Positive [DOUBLE] expected.\n";
		return Get_Dbl_Positive();
	}
	return Get_Dbl_Positive();
}
double Get_Dbl_PG()
{
	double a;
	while (!(std::cin >> a) || (std::cin.peek() != '\n'))
	{
		std::cin.clear();
		while (std::cin.get() != '\n');
		std::cout << "Input error! [DOUBLE] expected. Repeat please...\n";
	}
	return a;
}
int Get_Random(int Range_min=-999, int Range_max=999)
{
	if (Range_min > Range_max) 
	{ 
		std::cout << "\nError: Range_min > Range_max. New range: [Range_max..Range_min]\n";
		std::swap(Range_min, Range_max);
	}
	//return (Range_min + rand() % (Range_max - Range_min + 1));
	double K_random = double((rand() % RAND_MAX)) / RAND_MAX;
	int random = Range_min + ((Range_max - Range_min) * K_random);
	//return Range_min + (Range_max - Range_min) * (rand() % RAND_MAX) / RAND_MAX;
	return random;
}
double Get_Random(double Range_min=-9999.0, double Range_max=9999.0)
{
	if (Range_min > Range_max)
	{
		std::cout << "\nError: Range_min > Range_max. New range: [Range_max..Range_min]\n";
		std::swap(Range_min, Range_max);
	}
	return 	Range_min + (Range_max - Range_min) * double(rand() % RAND_MAX) / RAND_MAX;	
}
template <typename ANY> void Array_Console_Out(ANY arr[], int Size)
{
	std::cout << "\n[";
	for (int i = 0; i < Size; i++)
		std::cout << arr[i] << ", ";
	std::cout << "\b\b]\n";
}
template <typename ANY> void Fill_Array_with_Random(ANY arr[], int Size, ANY Range_min, ANY Range_max)
{
	for (int i = 0; i < Size; i++)
	{
		arr[i] = Get_Random(Range_min, Range_max);		
	}
}
