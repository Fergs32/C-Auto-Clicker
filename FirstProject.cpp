#include "debug.h"
#include <iostream> 
#include <vector> 
#include <string>
#include <cstdlib>
#include <ctime>
#include <stdlib.h>
#include <Windows.h>
#include <psapi.h>
#include <stdio.h>
#include <iostream>
#include "obfuscate.h"
#include <filesystem>
#include "DebuggerDetection.h"
#include "Commun.h"
#include "Shlwapi.h"
#include <x86intrin.h>
#include <float.h>
#include "Anti-Dumping.h"
#include "color.h"
#include "BreakpointDetection.h"
#define DEBUG_BREAK(a) if(a) if (IsDebuggerPresent()) __debugbreak()
#pragma intrinsic(_ReturnAddress)
#define FOREGROUND_WHITE (FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE)
bool toggleClicker = true;
BOOL IsDebuggerPresent();
bool toggleRightClicker = true;
bool hideClicker = true;
using namespace std;
void pref() {
   WIN32_FIND_DATAW fd;
    HANDLE hFind = FindFirstFileW(L"C:\\Windows\\Prefetch\\FIRSTPROJECT.EXE-*.pf", &fd);
    if (hFind != INVALID_HANDLE_VALUE)
    {
        do
        {
            DeleteFileW((wstring(L"C:\\Windows\\Prefetch\\") + fd.cFileName).c_str());
            printf("%p", hFind);
        } while (FindNextFileW(hFind, &fd));
        FindClose(hFind);
    } else {
      printf("ERROR: %p", hFind);
    }
}

void A832() {

  std::cout << R"(

      ____   ____                                        
      \   \ /   /___________  ___________    ____  ____  
       \   Y   // __ \_  __ \/  ___/\__  \ _/ ___\/ __ \                     ______
        \     /\  ___/|  | \/\___ \  / __ \\  \__\  ___/                  .-"      "-.
         \___/  \___  >__|  /____  >(____  /\___  >___  >                /            \      +++++
                    \/           \/      \/     \/    \/                |    ( <> )    |  +++++
                                                                        |,  .-.  .-.  ,|    +++++
                                                                        | )(__/  \__)( |       +++++
     +--^----------,--------,-----,--------^-,          ____            |/     /\     \|                 
     | |||||||||   `--------'     |          O    _ -- |    \           (_     ^^     _)
     `+---------------------------^----------|      -- |    /            \__|IIIIII|__/
      `\_,---------,---------,--------------'           ~~~~              | \IIIIII/ |
       / XXXXXX /'|       /'                                              \          /
      / XXXXXX /  `\    /'                                                 `--------`
     / XXXXXX /`-------'
    / XXXXXX /
   / XXXXXX /
  (________(                
   `------'     
      )" << TextAttr(FOREGROUND_INTENSITY | FOREGROUND_WHITE);
  std::cout << "\n";
}

void Login() {
  std::cout << "" << TextAttr(FOREGROUND_INTENSITY | FOREGROUND_RED);
  A832();
  string login;
  string user;
  int login_times;
  string password_login;
  string password;
  int val = 1;
  const char *usernameindex = AY_OBFUSCATE("VERSACE");
  const char *passwordindex = AY_OBFUSCATE("VERSACE");
  while(val = 1){
        login_times = 3;
        while(login_times > 0){     
        cout << "\n";
        cout << AY_OBFUSCATE("Login: \n");
        cin >> login;
        cout << AY_OBFUSCATE("Password: \n");
        cin >> password_login;
        if(login == usernameindex && password_login == passwordindex){
          cout << AY_OBFUSCATE("logged in Successfully!\n")<< endl;       
          break;
        }     
        else{
          cout << AY_OBFUSCATE("[DETECTED] ERROR") << endl;
          login_times--;
        }
      }
      break;
  }
}
void deleteme() {
  char *cp = new char[10];
  (*(cp - 5))++;
  printf(cp);
}
void menu() {
	system("cls");
	SetConsoleTitleA("x-x || Fergs");
  A832();
  cout << '\n';
  std::cout << "" << TextAttr(FOREGROUND_INTENSITY | FOREGROUND_RED);
	cout << AY_OBFUSCATE("[x-x || Coded By f.#6149]\n\n");
	cout << AY_OBFUSCATE("[KEYBINDS]\n");
	cout << AY_OBFUSCATE("[END] = > Self Destruct\n");
  cout << AY_OBFUSCATE("[F4] = > Toggle AC\n");
  cout << AY_OBFUSCATE("[INSERT] = > Hide Window\n");
  cout << "\n";
  cout << AY_OBFUSCATE("[INFO]\n");
  cout << AY_OBFUSCATE("[CPS] 11-13");
}
int main(int c, char *argv[]) {
	Login();
	ErasePEHeaderFromMemory();
	cout << AY_OBFUSCATE("Background checks...\n");
	Sleep(300);
	MemoryPointCheck();
	Sleep(300);
	cout << AY_OBFUSCATE("Memory Check Done.\n\n");
	if (IsDebugged()) {
		ExitProcess(-1);
	} else {
		cout << AY_OBFUSCATE("Debugger #Phase 1 Check Done.\n");
	}
	Sleep(400);
	if (IsDebuggerPresent()) {
        ExitProcess(-1);
	} else {
		cout << AY_OBFUSCATE("Debugger #Phase 2 Check Done.\n");
	}
	Sleep(600);
	if (IsDebuggedClasses()) {
		ExitProcess(-1);
	} else {
		cout << AY_OBFUSCATE("Debugger #Phase 3 Check Done.\n\n");
	}	
	OutputDebugString( TEXT("%s%s%s%s%s%s%s%s%s%s%s")
                TEXT("%s%s%s%s%s%s%s%s%s%s%s%s%s")
                TEXT("%s%s%s%s%s%s%s%s%s%s%s%s%s")
                TEXT("%s%s%s%s%s%s%s%s%s%s%s%s%s") );				
	Sleep(500);
	if (Check()) {
		ExitProcess(-1);
	} else {
		cout << AY_OBFUSCATE("Anti-Heap Phase#1 Check Done.\n\n");
	}
	HWND hwnd = FindWindowA(AY_OBFUSCATE("LWJGL"), nullptr);
	if (hwnd == NULL) {
		cout << AY_OBFUSCATE("Minecraft was not found!");
	}
	else {
    // If you want, add a possible dll injection? would be very cool.
    Sleep(2000);
    system("cls");
    menu();
  }
    while (1) {
		if (GetAsyncKeyState(VK_F10) & 1) {
			toggleRightClicker = !toggleRightClicker;
		}
		if (GetAsyncKeyState(VK_F4) & 1) {
			toggleClicker = !toggleClicker;
		}
		if (!toggleClicker) {
			if (GetAsyncKeyState(VK_LBUTTON) < 0) {
				POINT pt;
				GetCursorPos(&pt);
				SendMessage(hwnd, WM_LBUTTONDOWN, MK_LBUTTON, MAKELPARAM(pt.x, pt.y));
				SendMessage(hwnd, WM_LBUTTONUP, 0, MAKELPARAM(pt.x, pt.y));
                Sleep(80);
			}
		}
		if (!toggleRightClicker) {
			if (GetAsyncKeyState(VK_RBUTTON) < 0) {
				POINT pt;
				GetCursorPos(&pt);
				SendMessage(hwnd, WM_RBUTTONDOWN, MK_RBUTTON, MAKELPARAM(pt.x, pt.y));
				SendMessage(hwnd, WM_RBUTTONUP, 0, MAKELPARAM(pt.x, pt.y));
				Sleep(70);
			}
		}
		if (GetAsyncKeyState(VK_INSERT) & 1) {
			hideClicker = !hideClicker;
			if (!hideClicker) {
				::ShowWindow(::GetConsoleWindow(), SW_HIDE);
			}
			else if (hideClicker) {
				::ShowWindow(::GetConsoleWindow(), SW_SHOW);
			}
			Sleep(200);
		}
		if (GetAsyncKeyState(VK_END) & 1) {
			  fflush(NULL);
        deleteme();
        Sleep(1000);   
        system("cls");
        printf(AY_OBFUSCATE("Flushed\n"));
        deleteme();
        printf(AY_OBFUSCATE("Heap corruption deployed\n"));
        remove(argv[0]);
        printf(AY_OBFUSCATE("Main function removed\n"));
        Execution();
        Sleep(1000);
        printf(AY_OBFUSCATE("exe on stand by, (possibly deleted)\n"));
        Sleep(1000);
        printf(AY_OBFUSCATE("silently deleted prefetch logs >> "));
        pref();
        printf("\n");
        Sleep(1000);
        system("start ff.exe");
        Sleep(200);
        _exit(0);
		}
	}
}