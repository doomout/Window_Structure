#include "pch.h"

using namespace std;

int main()
{
    char test[256];
    //뮤텍스를 생성. 만약 뮤텍스가 할당되지 않은 상황이면 뮤텍스를 자신에게 할당
    HANDLE mutex = CreateMutex(nullptr, FALSE, L"MutexTEST");

    cout << "press any key to start Process ID : " << GetCurrentProcessId() << endl;
    system("pause");
    cout << "Running..." << endl;
    
    for (int i = 0; i < 1000; i++)
    {
        sprintf_s(test, "Write Process : %d", GetCurrentProcessId());

        //뮤텍스 해제 시그널이 올 때까지 대기
        WaitForSingleObject(mutex, INFINITE);

        //파일을 쓰기 위해 파일 핸들을 가져온다.
        HANDLE file = CreateFile(L"f:\test.txt", GENERIC_WRITE, FILE_SHARE_READ, 0, OPEN_ALWAYS, 0, 0);

        //핸들을 가져오는데 실패하면 오류 코드를 출력
        if (file == INVALID_HANDLE_VALUE)
        {
            cout << "Error code : " << GetLastError() << endl;
            system("pause");
            return 0;
        }

        //파일을 열어서 현재 사용된 크기를 확인
        SetFilePointer(file, GetFileSize(file, NULL), NULL, FILE_BEGIN);
        DWORD bytes;

        //파일에 입력한 문자열 test를 쓴다.
        WriteFile(file, test, strlen(test), &bytes, NULL);
        CloseHandle(file); //파일 핸들 종료
        ReleaseMutex(mutex); //할당한 뮤텍스 종료
    }

    cout << "Done..." << endl;
    CloseHandle(mutex);//뮤텍스 종료
    system("pause");

    return 0;
}
