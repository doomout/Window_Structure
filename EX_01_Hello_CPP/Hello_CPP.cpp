#include <stdio.h>
#include <iostream> //C++ ǥ�� ����� ���̺귯��

using namespace std;

int main(int argc, char *argv[])
{
	printf("Hello C\n"); //C���
	cout << "C/C++" << endl; //C++ ���

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