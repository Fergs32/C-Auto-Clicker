# C-Auto-Clicker
C++ Auto Clicker, with self destruct, hide window, left &amp; right clicker (11-13) CPS and Toggle (ON/OFF). 
It also calls a C# exe which contains code that removes HKEY recent exe's (MUICache &amp; Store Data).


**[Debug.c]** [C++]
- This header file contains anti debugger mechanisms.
- Memory Checking Allocation 
- Searching for Debuggers currently running
- Heap Protection
- Erase PE Header Memory
- Put exe on standby and reallocate until reboot. (Doesn't work I think)

**[Color.h]** [C++]

- Class that will display different colours when called in [main.cpp]

**[Main.cpp]** [C++]

- Right & Left clicker (Can toggle)
- Hide Window Option
- Self Destuct (Beta)
- Average CPS (11-13)
- Simple Login Menu
- Using adamyaxley Obfuscator (AY_OBFUSCATE) | [GitHub Pages](https://github.com/adamyaxley/Obfuscate)
- Some anti debugging techniques
- Ascii Art
- Delete recent prefetch data
- Potential DLL injection (findwindow) [Not ADDED]

**[ff.exe]** [C#]

- Register key deletion (MUICache and Store)
- Self destruct

**[List to do]**
- [ ] Add DLL injection
- [ ] Better login system
- [ ] Improved Self Destruct

