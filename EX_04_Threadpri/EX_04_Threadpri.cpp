// EX_04_Threadpri.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"
using namespace std;

int main()
{
    //현재 우선순위 확인
    cout << "Current Process Priority: " << hex << GetPriorityClass(GetCurrentProcess()) << endl;
    cout << "Current Thread Priority: " << GetThreadPriority(GetCurrentThread()) << endl;

    //프로세스 우선순위를 13으로 변경, 스레드는 높은 우선순위로 변경
    cout << "Let's Change Process PRI: HIGH_PRIORITY_CLASS" << endl;
    cout << "Let's Change Thread PRI: THREAD_PRIORITY_HIGHEST" << endl;
    system("pause");
    SetPriorityClass(GetCurrentProcess(), HIGH_PRIORITY_CLASS);
    SetThreadPriority(GetCurrentThread(), THREAD_PRIORITY_HIGHEST);

    cout << "Current Process Priority: " << hex << GetPriorityClass(GetCurrentProcess()) << endl;
    cout << "Current Thread Priority: " << GetThreadPriority(GetCurrentThread()) << endl;

    //프로세스 우선순위를 24으로 변경, 스레드는 높은 우선 순위로 유지
    cout << "Let's Chandge Process PRI : REALTIME_PRIORITY_CLASS" << endl;
    SetPriorityClass(GetCurrentProcess(), REALTIME_PRIORITY_CLASS);
    system("pause");

    cout << "Current Process Priority: " << hex << GetPriorityClass(GetCurrentProcess()) << endl;
    cout << "Current Thread Priority: " << GetThreadPriority(GetCurrentThread()) << endl;

    //프로세스 우선순위를 4로 변경, 스레드는 보통보다 낮은 우선순위로 변경
    cout << "Let's Change Process PRI: IDLE_PRIORITY_CLASS" << endl;
    cout << "Let's Change Thread PRI: THREAD_PRIORITY_BELOW_NORMAL" << endl;
    system("pause");
    SetPriorityClass(GetCurrentProcess(), IDLE_PRIORITY_CLASS);
    SetThreadPriority(GetCurrentThread(), THREAD_PRIORITY_BELOW_NORMAL);

    cout << "Current Process Priority: " << hex << GetPriorityClass(GetCurrentProcess()) << endl;
    cout << "Current Thread Priority: " << GetThreadPriority(GetCurrentThread()) << endl;
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
