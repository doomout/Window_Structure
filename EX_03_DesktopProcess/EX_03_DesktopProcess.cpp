// EX_03_DesktopProcess.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"

using namespace std;

int main()
{
    STARTUPINFO si = {0};
    PROCESS_INFORMATION pi = { 0 };
    
    //현재 데스크탑 정보 기억
    HDESK currentdesktop = GetThreadDesktop(GetCurrentThreadId());

    //새로운 데스크탑 생성
    HDESK hiddendesktop = CreateDesktop(L"Hidden", NULL, NULL, 0, GENERIC_ALL, NULL);

    //STARTUPINFOD의 시작할 데스크탑 정보 넣어주기
    si.lpDesktop = (LPWSTR)"Hidden";

    //메모장 실행을 위한 값을 넣어주기
    wstring command = L"notepad.exe";

    CreateProcess(NULL, &command[0], NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi);

    //자식 프로세스를 생성하고 새로 만들어진 데스크탑으로 이동
    SetThreadDesktop(hiddendesktop);
    SwitchDesktop(hiddendesktop);

    //생성된 메모장이 종료되는지 확인
    while (WaitForSingleObject(pi.hProcess, 500) == WAIT_TIMEOUT)
    {
        cout << "Waiting:" << pi.hProcess << " still run.\n" << endl;
    }

    //메모장이 종료되면 다시 기존 데스크탑으로 복귀한다.
    SetThreadDesktop(currentdesktop);
    SwitchDesktop(currentdesktop);

    system("pause");

    return 0;
}

// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
