// EX_02_WindowStation.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h" 
/*
#include <iostream>, #include <Windows.h>를 #include "pch.h" 에 넣어놨음
*/
using namespace std;

int main()
{
    cout << "Current Window Station is:" << GetProcessWindowStation() << "\n" << endl;

    HANDLE hClipboard1 = NULL; //클립보드 내용을 요청하기 위한 핸들을 생성

    //클립보드를 현재 프로그램이 사용할 수 있다면.
    if (OpenClipboard(NULL))
    {
        hClipboard1 = GetClipboardData(CF_UNICODETEXT); //클립보드 내용을 요청하기 우한 핸들 생성
        cout << "Current hClipboard is : " << hClipboard1 << "\n" << endl;
    }
    else
    {
        cout << "Clipboard Get failed, error" << GetLastError() << "\n" << endl;
    }
    cout << "Check Clipboard!\n" << endl;
    //CloseClipboard()를 호출하지 않으면 메모장의 복사/붙이기시 클립보드가 어떤 상태가 되는지 확인
    
    system("pause");
  
    if (hClipboard1 != NULL)
    {
        cout << "Close Clipboard!\n" << endl;
        CloseClipboard(); //만약 값이 있으면 클립 보드는 닫음.
    }
    cout << "Change WindowStation.\n" << endl;

    HWINSTA beforWinsta = GetProcessWindowStation();
    HWINSTA AfterWinsta = CreateWindowStation(L"hiddenWinSta", 0, 0, NULL);
    
    if (AfterWinsta == NULL)
        cout << "CreateWindowStation failed, error" << GetLastError() << "\n" << endl;
    else
        cout << "CreateWindowStation is OK!\n" << endl;
    SetProcessWindowStation(AfterWinsta);
    cout << "Current Window Station is:" << GetProcessWindowStation() << "\n" << endl;

    //Window Station 이 변경되었을 때 클립보드를 가져올 수 있는지 확인
    HANDLE hClipboard2 = NULL;
    if (OpenClipboard(NULL))
    {
        hClipboard2 = GetClipboardData(CF_UNICODETEXT);
        cout << "Current hClipboard is : " << hClipboard2 << "\n" << endl;
    }
    else
    {
        cout << "Clipboard Get failed, error" << GetLastError() << "\n" << endl;
    }
    cout << "Check Clipboard!\n" << endl;

    //CloseClipboard()를 호출하지 않으면 메모장의 복사/붙이기시 클립보드가 어떤 상태가 되는지 확인
    system("pause");
    if (hClipboard2 != NULL)
    {
        cout << "Close Clipboard!\n" << endl;
        CloseClipboard();
    }
    //다시 기존 Window Station으로 변경 후 클립보드를 불러올 수 있는지 확인
    SetProcessWindowStation(beforWinsta);
    cout << "Current Window Station is :" << GetProcessWindowStation() << "\n" << endl;

    HANDLE hClipboard3 = NULL;
    if (OpenClipboard(NULL))
    {
        hClipboard3 = GetClipboardData(CF_UNICODETEXT);
        cout << "Current hClipboard is : " << hClipboard3 << "\n" << endl;
    }
    else
    {
        cout << "Clipboard Get failed, error" << GetLastError() << "\n" << endl;
    }
    cout << "Check Clipboard!\n" << endl;

    //CloseClipboard()를 호출하지 않으면 메모장의 복사/붙이기시 클립보드가 어떤 상태가 되는지 확인
    system("pause");
    if (hClipboard3 != NULL)
    {
        cout << "Close Clipboard!\n" << endl;
        CloseClipboard();
    }

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
