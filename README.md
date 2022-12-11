# C++로 풀어보는 윈도우 구조

윈도우 os 구조를 C++로 공부한다.
도서명 : 구조를 알아야 개발이 보인다.

[1]윈도우 구조 기본 요소 5가지

1. 유저 모드와 커널 모드  
	(1)유저 모드  
	-운영체제의 시스템 영역을 제외한 데이터 영역에 접근 가능  
	-하드웨어를 엑세스 할 수 없음  
	-유저 모드에서 실행되는 개별 프로그램으로 인한 시스템 동작 불가 오류를 막는다.  
	(2)커널 모드  
	-커널과 디바이스 드라이버들만 사용  
	-모든 시스템 자원에 접근 가능  
	-오류 발생시 시스템 동작이 불가능 할 수 있다.  
	(3) 권한  
	-Ring 0 : 커널 모드  
	-Ring 3 : 유저 모드  
2. 프로세스  
	(1)프로세스란? : 하나의 프로그램을 실행하기 위한 자원의 집합  
	(2) PID : 프로세스를 구별할 수 있도록 만들어진 고유 식별 번호  
	(3) 프로세스의 내부 동작 상황을 세부적으로 보려면 Process Explorer을 사용한다.  
		다운로드 링크 : https://learn.microsoft.com/en-us/sysinternals/downloads/  
3. 스레드  
	(1)스레드란? : 프로그램의 실행 코드를 커널에서 처리하는 역할을 담당  
	(2)TID : 스레드 고유 번호  
4. 가상 메모리  
	(1)가상 메모리란? : 물리 메모리와 디스크를 이용한 메모르를 모두 통합하여 관리 해주는 역할  
	(2)VMMap로 메모리 분석을 할 수 있다.  
5. 객체와 핸들  
	(1)객체란? 변수들과 연관된 함수들로 이루어진 하나의 묶음, 윈도우에서 객체들은 커널 메모리 공간에 존재  
	(2)커널 메모리에 위치한 이유는 직접 접근하지 못하고 윈도우의 관리하에 접근하도록 하기 위해  
	(3)객체에 접근하기 위해서 필요한 것이 핸들(Handle)  
	(4)유저 모드에서 동작하는 프로그램은 모두 핸들을 통해서 객체에 접근해야 함  
	(5)커널 모드에서 동작하는 프로그램은 바로 객체에 접근.  

[2]멀티프로세싱(Multiprocessing)  
1. 다수의 프로세서가 하나의 메모리 영역과 하드웨어 자원들을 공유해서 사용하는 대칭형 다중 처리(SMP)를 지원  
2. SMP는 CPU에서 데이터가 어느 위치에 있든 각 프로세스를 지원  

[3]서브 시스템  
1. 서브 시스템이란? 실행 중인 응용 프로그램들의 환경을 지원해주는 기능  
2. PE : 윈도우에서 사용하는 실행 파일 구조  
3. 서브 시스템 DLL  
	(1)Kernel32.dll : 파일 생성과 같은 하드웨어 요청에 주로 사용  
	(2)Advapi32.dll : 보안 구성이나 확인 등 추가적으로  윈도우에서 제공하는 기능적인 부분에 사용  
	(3)User32.dll : 사용자에게 제공하는 창이나 메뉴 등의 화면을 생성하는데 필요한 요소를 요청 할 때 사용  
	(4)Gdi32.dll : 직접 그림을 그릴수 있는 부분에 사용  
	(5)Ntdll.dll : 유저 모드에서 커널 모드의 요청을 대신 처리한 후 결과 값을 반환해주는 역할  
