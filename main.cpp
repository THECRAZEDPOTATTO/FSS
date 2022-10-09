#include <stdio.h>
#include <iostream>
#include <Windows.h>
#include <list>
#include <sstream>
#include <vector>
#include <windef.h>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include "reader.h"
using namespace std; 

int main()
{
	//os:HERE cmd
	int win10p = IsWindows10OrGreater();
	int win7p = IsWindows7OrGreater();
	int win8p = IsWindows8OrGreater();
	int winvistap = IsWindowsVistaOrGreater();
	int winxpp = IsWindowsXPOrGreater();
	int server = IsWindowsServer();
	string s = "os:win11";
	int pos = s.find(":");
	string sub = s.substr(pos + 1);
	if (sub == "win10") {
		cout << "Windows 10\n";
		win10p = IsWindows10OrGreater();
		if (win10p == 1) {
			cout << "True";
		}
		else {
			cout << "False";
		}

	}
	else if (sub == "win7") {
		cout << "Windows 7\n";
		win7p = IsWindows7OrGreater();
		if (win7p == 1) {
			cout << "True";
		}
		else {
			cout << "False";
		}
	}
	else if (sub == "all") {
		cout << "All";
	}
	else if (sub == "win8") {
		cout << "Windows 8\n";
		win8p = IsWindows8OrGreater();
		if (win8p == 1) {
			cout << "True";
		}
		else {
			cout << "False";
		}
	}
	else if (sub == "winxp") {
		cout << "Windows xp\n";
		winxpp = IsWindowsXPOrGreater();
		if (winxpp == 1) {
			cout << "True";
		}
		else {
			cout << "False";
		}
	}
	else if (sub == "winvista") {
		cout << "Windows Vista\n";
		winvistap = IsWindowsVistaOrGreater();
		if (winvistap == 1) {
			cout << "True";
		}
		else {
			cout << "False";
		}

	}
	else if (sub == "winserver") {
		cout << "Windows Server\n";
		server = IsWindowsServer();
		if (server == 1) {
			cout << "True";
		}
		else {
			cout << "False";
		}
	}
	else if (sub == "win11") {
		cout << "Windows 11\n";
		win7p = IsWindows7OrGreater();
		if (win7p == 1) {
			cout << "True";
		}
		else {
			cout << "False";
		}

	}
	else {
		cout << "Not Valid Windows Type\n";
	}														//PYTHON\\
	//FILECOMPILER
	bool mycore = false;
	string mycompiler;
	ifstream settingsfile("settings.fss");
	while (getline(settingsfile, mycompiler)) {
		if (mycompiler.find("main") != string::npos) { 
			cout << mycompiler << endl;
			string f = mycompiler;
			int posf = f.find(":");
			string subf = f.substr(posf + 1);
			string cmd = "start " + subf;
			system(cmd.c_str());
		}
		if (mycompiler.find("pip") != string::npos) {
			cout << mycompiler << endl;
			string pip = mycompiler;
			int pospip = pip.find(":");
			string subpip = pip.substr(pospip + 1);
			std::string ss = subpip;
			std::string delimiter = ",";
			size_t poss = 0;
			std::string token;
			ofstream batch("pip.bat");
			while ((poss = ss.find(delimiter)) != std::string::npos) {
				token = ss.substr(0, poss);
				batch << "py -m pip install " + token + "\n";
				ss.erase(0, poss + delimiter.length());
			}
			batch.close();
			system("pip.bat");
			remove("pip.bat");
		}
		if (mycompiler.find("cmd") != string::npos) {
			cout << mycompiler << endl;
			string commandp = mycompiler;
			int poscommandp = commandp.find(":");
			string subcommandp = commandp.substr(poscommandp + 1);
			string code = subcommandp;
			system(code.c_str());
		}
		if (mycompiler.find("run.admin") != string::npos) {
			cout << mycompiler << endl;
			string f = mycompiler;
			int posf = f.find(":");
			string subf = f.substr(posf + 1);
			ShellExecuteA(NULL, "runas", subf.c_str(), 0, 0, SW_SHOWNORMAL);
		}
		if (mycompiler.find("openweb") != string::npos) {
			cout << mycompiler << endl;
		}
		if (mycompiler.find("os") != string::npos) {
			cout << mycompiler << endl;
			string s = mycompiler;
			int pos = s.find(":");
			string sub = s.substr(pos + 1);
			if (sub == "win10") {
				cout << "Windows 10\n";
				win10p = IsWindows10OrGreater();
				if (win10p == 1) {
					cout << "True";
				}
				else {
					MessageBox(NULL, L"Current OS Not Compatible", L"FSS os Error", MB_ICONERROR | MB_OK);
				}

			}
			else if (sub == "win7") {
				cout << "Windows 7\n";
				win7p = IsWindows7OrGreater();
				if (win7p == 1) {
					cout << "True";
				}
				else {
					MessageBox(NULL, L"Current OS Not Compatible", L"FSS os Error", MB_ICONERROR | MB_OK);
				}
			}
			else if (sub == "all") {
				cout << "All";
			}
			else if (sub == "win8") {
				cout << "Windows 8\n";
				win8p = IsWindows8OrGreater();
				if (win8p == 1) {
					cout << "True";
				}
				else {
					MessageBox(NULL, L"Current OS Not Compatible", L"FSS os Error", MB_ICONERROR | MB_OK);
				}
			}
			else if (sub == "winxp") {
				cout << "Windows xp\n";
				winxpp = IsWindowsXPOrGreater();
				if (winxpp == 1) {
					cout << "True";
				}
				else {
					MessageBox(NULL, L"Current OS Not Compatible", L"FSS os Error", MB_ICONERROR | MB_OK);
				}
			}
			else if (sub == "winvista") {
				cout << "Windows Vista\n";
				winvistap = IsWindowsVistaOrGreater();
				if (winvistap == 1) {
					cout << "True";
				}
				else {
					MessageBox(NULL, L"Current OS Not Compatible", L"FSS os Error", MB_ICONERROR | MB_OK);
				}

			}
			else if (sub == "winserver") {
				cout << "Windows Server\n";
				server = IsWindowsServer();
				if (server == 1) {
					cout << "True";
				}
				else {
					MessageBox(NULL, L"Current OS Not Compatible", L"FSS os Error", MB_ICONERROR | MB_OK);
				}
			}
			else if (sub == "win11") {
				cout << "Windows 11\n";
				win7p = IsWindows7OrGreater();
				if (win7p == 1) {
					cout << "True";
				}
				else {
					MessageBox(NULL, L"Current OS Not Compatible ", L"FSS os Error", MB_ICONERROR | MB_OK);
				}

			}
			else {
				MessageBox(NULL, L"Not a Valid Windows OS", L"FSS os Error", MB_ICONERROR | MB_OK);
			}
		}
		if (mycompiler.find("showcon") != string::npos) {
			cout << mycompiler << endl;
			string hide = mycompiler;
			int poshide = hide.find(":");
			string subhide = hide.substr(poshide + 1);
			if (subhide == "True") {
				HWND Stealth;
				AllocConsole();
				Stealth = FindWindowA("ConsoleWindowClass", NULL);
				ShowWindow(Stealth, 0);
			}
			else {
				cout << "False\n";
			}
		}
	}
	//CLEAN UP
	remove("pip.bat");
}
