#include <iostream> 
#include <vector> 
#include <string>
#include <cstdlib>
#include <ctime>
#include <stdlib.h>
#include <Windows.h> 
#include <chrono>
#include <psapi.h>
#include <stdio.h>
#include <iostream>

void Execution() 
{ 
  // Idk I have no clue, some google stuff.
  SHELLEXECUTEINFO sei;
  TCHAR szModule [MAX_PATH],
  szComspec[MAX_PATH],
  szParams [MAX_PATH];
 
  if((GetModuleFileName(0,szModule,MAX_PATH)!=0) && (GetShortPathName(szModule,szModule,MAX_PATH)!=0) && (GetEnvironmentVariable("COMSPEC",szComspec,MAX_PATH)!=0))
  {
  lstrcpy(szParams,"/c del ");
  lstrcat(szParams, szModule);
  lstrcat(szParams, " > nul");
  //sei
  sei.cbSize = sizeof(sei);
  sei.hwnd = 0;
  sei.lpVerb = "Open";
  sei.lpFile = szComspec;
  sei.lpParameters = szParams;
  sei.lpDirectory = 0;
  sei.nShow = SW_HIDE;
  sei.fMask = SEE_MASK_NOCLOSEPROCESS;
  //shellexecute
  if(ShellExecuteEx(&sei))
  {
   SetPriorityClass(sei.hProcess,IDLE_PRIORITY_CLASS); //removing process stops
   SetPriorityClass(GetCurrentProcess(),REALTIME_PRIORITY_CLASS); //accelerate our process
   SetThreadPriority(GetCurrentThread(),THREAD_PRIORITY_TIME_CRITICAL); //accelerate our thread
  }
  }
}
// String of classes, used for scanning of words.
const std::vector<std::string> vWindowClasses = {
    "OLLYDBG",
    "WinDbgFrameClass", // WinDbg
    "ID",               // Immunity Debugger
    "Zeta Debugger",
    "Rock Debugger",
    "ObsidianGUI",
	"Jinx",
	"Arm Forge Client",
	"dbx",
	"LLDB",
	"GDB",
	"IDA", 
	"Valgrind",

};
// Scans for classes above, if they're found. Return will be true, if there has been none found in the list, return false.
bool IsDebuggedClasses()
{
    for (auto &sWndClass : vWindowClasses)
    {
        if (NULL != FindWindowA(sWndClass.c_str(), NULL))
            return true;
    }
    return false;
}
// This function will check if there is any debuggers present.
bool IsDebugged()
{
    CONTEXT ctx;
    ZeroMemory(&ctx, sizeof(CONTEXT)); 
    ctx.ContextFlags = CONTEXT_DEBUG_REGISTERS; 
    if(!GetThreadContext(GetCurrentThread(), &ctx))
        return false;
    return ctx.Dr0 || ctx.Dr1 || ctx.Dr2 || ctx.Dr3;
}
// Checking for OLLYDBG via memory allocation.
void MemoryPointCheck()
{
    void *addr = __builtin_extract_return_addr (__builtin_return_address (0));
    if (*(PBYTE)addr == 0xCC)
    {
        DWORD dwOldProtect;
        if (VirtualProtect(addr, 1, PAGE_EXECUTE_READWRITE, &dwOldProtect))
        {
            *(PBYTE)addr = 0x90;
            VirtualProtect(addr, 1, dwOldProtect, &dwOldProtect);
        }
    }
}
// According to where I got this from, it was a heap overload. But this looks like a heap anti dumping?
bool Check()
{
    PROCESS_HEAP_ENTRY HeapEntry = { 0 };
    do
    {
        if (!HeapWalk(GetProcessHeap(), &HeapEntry))
            return false;
    } while (HeapEntry.wFlags != PROCESS_HEAP_ENTRY_BUSY);
    PVOID pOverlapped = (PBYTE)HeapEntry.lpData + HeapEntry.cbData;
    return ((DWORD)(*(PDWORD)pOverlapped) == 0xABABABAB);
}
void ErasePEHeaderFromMemory()
{
// This function will erase the current images
// PE header from memory preventing a successful image
// if dumped
    DWORD OldProtect = 0;
    // Get base address of module
    char *pBaseAddr = (char*)GetModuleHandle(NULL);
    // Change memory protection
    VirtualProtect(pBaseAddr, 4096, // Assume x86 page size
            PAGE_READWRITE, &OldProtect);
    // Erase the header
    ZeroMemory(pBaseAddr, 4096);
}