#include "pch.h"

using namespace std;
void ThreadLock();

mutex m;

int i = 0;

int main()
{
	HANDLE thread1 = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)ThreadLock, NULL, 0, NULL); //공유 객체 i에 접근하는 스레드 1
	HANDLE thread2 = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)ThreadLock, NULL, 0, NULL); //공유 객체 i에 접근하는 스레드 2
	HANDLE thread3 = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)ThreadLock, NULL, 0, NULL); //공유 객체 i에 접근하는 스레드 3
	HANDLE thread4 = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)ThreadLock, NULL, 0, NULL); //공유 객체 i에 접근하는 스레드 4

	system("pause");

	return 0;
}

void ThreadLock()
{
	while (i < 10)
	{
		m.lock(); //뮤텍스를 이용해 사용하고자 하는 객체를 lock 시킨다.
			cout << GetCurrentThreadId() << " Thread : " << i << endl;
			i++;
		m.unlock(); //객체 사용이 완료 되면 unlock를 통해 다른 스레드에서 접근할 수  있도록 한다.
	}
	return;
}

