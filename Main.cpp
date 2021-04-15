#include <locale>
#include "Stack.h"

#define PATH_FOR_FILE_DBL "C:\\outDBL.txt"
#define PATH_FOR_FILE_INT "C:\\outINT.txt"
#define PATH_FOR_FILE_CHAR "C:\\outCHAR.txt"


int main()
{
	setlocale(LC_ALL, "RUS");
	
	// DOUBLE
	Stack<double> s1;
	int countElements = 8;
	srand(time(NULL));
	for (int i = 0; i < countElements; i++)
	{
		double num = (double)(rand() % (100 - (-100) + 1) + (-100)) / 10;	// -10...10
		s1.push(num);
		std::cout << num << " ";
	}
	std::cout << std::endl;

	s1.print();

	std::cout << "\nMin: " << s1.FindMin();
	std::cout << "\nMax: " << s1.FindMax() << std::endl;

	s1.OutputFile(PATH_FOR_FILE_DBL);
	std::cout << std::endl;

	// INT
	Stack<int> s2;
	countElements = 8;
	srand(time(NULL));
	for (int i = 0; i < countElements; i++)
	{
		int num = -5 + rand() % 30;
		s2.push(num);
		std::cout << num << " ";
	}
	std::cout << std::endl;

	s2.print();
	
	std::cout << "\nMin: " << s2.FindMin();
	std::cout << "\nMax: " << s2.FindMax() << std::endl;

	s2.OutputFile(PATH_FOR_FILE_INT);

	Stack<int> s22;
	s22.FromFile(PATH_FOR_FILE_INT);
	std::cout << "ѕосле прочтени€ из файла: ";
	s22.print();
	std::cout << std::endl << std::endl;

	//CHAR
	Stack<char> s3;
	countElements = 8;
	srand(time(NULL));
	for (int i = 0; i < countElements; i++)
	{
		char letter = 'A' + rand() % ('Z' - 'A');
		s3.push(letter);
		std::cout << letter << " ";
	}
	std::cout << std::endl;

	s3.print();

	std::cout << "\nMin: " << s3.FindMin();
	std::cout << "\nMax: " << s3.FindMax() << std::endl;

	s3.OutputFile(PATH_FOR_FILE_CHAR);
	std::cout << std::endl;

	//Tests
	Stack<int> s_t1;
	std::cout << "ѕустой стек: " << s_t1.empty() << std::endl;	// 1 - pustoi, 0 - ectb element
	
	s_t1.push(5);
	s_t1.push(22);
	s_t1.push(-3);

	s_t1.pop(); 
	s_t1.pop();
	s_t1.pop();

	std::cout << "Pop из пустого стека: ";
	try
	{
		s_t1.pop();
	}
	catch (std::logic_error err)
	{
		std::cout << err.what();
	}
	std::cout << std::endl;

	std::cout << "Top из пустого стека: ";
	try
	{
		s_t1.Top();
	}
	catch (std::logic_error err)
	{
		std::cout << err.what();
	}
	std::cout << std::endl;

	std::cout << "FindMax из пустого стека: ";
	try
	{
		s_t1.FindMax();
	}
	catch (std::logic_error err)
	{
		std::cout << err.what();
	}
	std::cout << std::endl;

	std::cout << "FindMin из пустого стека: ";
	try
	{
		s_t1.FindMin();
	}
	catch (std::logic_error err)
	{
		std::cout << err.what();
	}
	std::cout << std::endl;

	std::cout << "OutputFile из пустого стека: ";
	try
	{
		s_t1.OutputFile(PATH_FOR_FILE_INT);
	}
	catch (std::logic_error err)
	{
		std::cout << err.what();
	}
	std::cout << std::endl;

	std::cout << "Print из пустого стека: ";
	try
	{
		s_t1.print();
	}
	catch (std::logic_error err)
	{
		std::cout << err.what();
	}
	std::cout << std::endl;

	system("pause");
	return 0;
}