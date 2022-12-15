// EX_04_CreateThread.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"

using namespace std;

void ThreadSpeed(); //식별자 선언

#pragma comment(lib, "winmm.lib") 

const int sumcount = 100;

struct ThreadSUM
{
    int count = 0;
};

int main()
{
    bool cont = true; //while 문을 실행할지 정지할지를 결정
    int maxthread = 1; //생성하는 최대 스레드 갯수
    int whilecount = 1; //마지막 결과 값을 저장하는 변수
    ThreadSUM data[sumcount]; //ThreadSUM 구조체를 이용
    
    while (cont == true)
    {
        HANDLE thread[sumcount]; //여러개의 핸들을 하나로 관리하기 위해 배열로 선언
        DWORD start = timeGetTime(); //시작하는 시간을 기록

        //스레드 생성 갯수를 1씩 올려가며 생성하도록 구성
        for  (int numthread = 0; maxthread > numthread ; numthread++)
        {
            //스레드를 생성한다.
            thread[numthread] = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)ThreadSpeed, NULL, 0, NULL);
        }
        //객체 여러 개가 종료되기를 기다린다.
        WaitForMultipleObjects(maxthread, thread, true, INFINITE);
       
        //작업을 마쳤을 때의 시간을 계산하여 차이를 구한다.
        DWORD sum = timeGetTime() - start;
        
        CloseHandle(thread);
 
        //만약 0보다 오래 걸렸다면, 지연되는 것으로 판단하여 결과를 보여준다.
        if (sum > 0) 
        {
            //마지막으로 생성된 스레드 갯수
            cout << "Create Thread Done: " << maxthread << endl;

            //생성에 걸린 시간
            cout << "Current Create Time: " << sum << endl;
            for (int i = 0; i < sumcount; i++)
            {
                if (i == maxthread)
                {
                    data[i].count = data[i].count + 1;
                }
            }
            maxthread = 1; //지연되었다면 다시 처음부터 진행한다.
        }
        else //최대 생성 개수를 증가시켜 다시 생성하도록 한다.
        {
            maxthread++ ;
        }
        maxthread++;
        
        if (whilecount == sumcount)
        {
            cont = false; //while 문 종료
        }
        else
        {
            whilecount++;
        }
    }
    system("pause");
    for (int i = 0; i < sumcount; i++)
    {
        //저장이 안된 데이터는 표시 하지 않는다.
        if (data[i].count != 0)
        {
            cout << "Create Thread: " << i << endl;
            cout << "Result Count: " << data[i].count << endl;
        }
    }
    system("pause");

    return 0;
}

void ThreadSpeed()
{
    return;
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
