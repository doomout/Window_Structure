#include <stdio.h>
#include <iostream> //C++ 표준 입출력 라이브러리

using namespace std;

int main(int argc, char *argv[])
{
	printf("Hello C\n"); //C언어
	cout << "C/C++" << endl; //C++ 언어

	if (argc > 1)
	{
		for (int i = 0; i < argc; i++)
		{
			printf("Input count : %s Input value : %d \n", argv[i], i);
			cout << "Input count : " << argc << " input value : " << argv[i] << "\n" << endl;
		}
	}
	
	return 0;
}