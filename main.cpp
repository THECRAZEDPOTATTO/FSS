#include <stdio.h>
#include <iostream>
#include <Windows.h>
#include <list>
#include <chrono>
#include <sstream>
#include <vector>
#include <windef.h>
#include <regex>
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
	ifstream settingsfile("C:\\Users\\Josep\\OneDrive\\Desktop\\files\\targetfile.eset");
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
		if (mycompiler.find("admin.main") != string::npos) {
			cout << mycompiler << endl;
			string f = mycompiler;
			int posf = f.find(":");
			string subf = f.substr(posf + 1);
			ShellExecuteA(NULL, "runas", subf.c_str(), 0, 0, SW_SHOWNORMAL);
		}
		if (mycompiler.find("mov") != string::npos) {
			cout << mycompiler << endl;
			string f = mycompiler;
			auto start = ":"s;
			auto end = ">"s;
			std::regex base_regex(start + "(.*)" + end);
			auto example = mycompiler;
			std::smatch base_match;
			std::string matched;
			if (std::regex_search(example, base_match, base_regex)) {
				if (base_match.size() == 2) {
					matched = base_match[1].str();
				}
			}
			int posnew = f.find(">");
			string subnew = f.substr(posnew + 1);
			cout << matched+"\n";
			cout << subnew+"\n";
			ifstream infile(matched);
			ofstream outfile(subnew);
			string content = "";
			int i;

			for (i = 0; !infile.eof(); i++)    
				content += infile.get();
			infile.close();

			content.erase(content.end() - 1);  
			i--;

			cout << i << " characters read...\n";

			outfile << content;         
			outfile.close();
		}
		if (mycompiler.find("write") != string::npos) {
			cout << mycompiler << endl;
			string ff = mycompiler;
			auto startff = ":"s;
			auto endff = ">"s;
			std::regex base_regex(startff + "(.*)" + endff);
			auto corewriter = mycompiler;
			std::smatch base_match;
			std::string matched;
			if (std::regex_search(corewriter, base_match, base_regex)) {
				if (base_match.size() == 2) {
					matched = base_match[1].str();
				}
			}
			int posnew = ff.find(">");
			string subnew = ff.substr(posnew + 1);
			cout << matched + "\n";
			cout << subnew + "\n";
			if (subnew == "newline") {
				subnew = "\n";
			}
			ofstream newwriter;
			newwriter.open(matched);
			newwriter << subnew;
			newwriter.close();
		}
		if (mycompiler.find("awrite") != string::npos) {
			cout << mycompiler << endl;
			string ff = mycompiler;
			auto startff = ":"s;
			auto endff = ">"s;
			std::regex base_regex(startff + "(.*)" + endff);
			auto corewriter = mycompiler;
			std::smatch base_match;
			std::string matched;
			if (std::regex_search(corewriter, base_match, base_regex)) {
				if (base_match.size() == 2) {
					matched = base_match[1].str();
				}
			}
			int posnew = ff.find(">");
			string subnew = ff.substr(posnew + 1);
			cout << matched + "\n";
			cout << subnew + "\n";
			if (subnew == "newline") {
				subnew = "\n";
			}
			ofstream newwriter;
			newwriter.open(matched, std::ios_base::app);
			newwriter << subnew;
			newwriter.close();
		}
		if (mycompiler.find("brake") != string::npos) {
			cout << mycompiler << endl;
			this_thread::sleep_for(chrono::milliseconds(10000));
		}
		if (mycompiler.find("make-source") != string::npos) {
			cout << mycompiler << endl;
			string ff = mycompiler;
			auto startff = ":"s;
			auto endff = ">"s;
			std::regex base_regex(startff + "(.*)" + endff);
			auto corewriter = mycompiler;
			std::smatch base_match;
			std::string matched;
			if (std::regex_search(corewriter, base_match, base_regex)) {
				if (base_match.size() == 2) {
					matched = base_match[1].str();
				}
			}
			int posnew = ff.find(">");
			string subnew = ff.substr(posnew + 1);
			cout << matched + "\n";
			cout << subnew + "\n";
			execute("curl "+ subnew, matched);
		}
		if (mycompiler.find("openweb") != string::npos) {
			cout << mycompiler << endl;
		}
		if (mycompiler.find("makefile") != string::npos) {
			cout << mycompiler << endl;
			string makefile = mycompiler;
			int posmakefile = makefile.find(":");
			string submakefile = makefile.substr(posmakefile + 1);
			ofstream newfile(submakefile);
		}
		if (mycompiler.find("del") != string::npos) {//Using same string names becuase I can LOL
			string del = mycompiler;
			int posdel = del.find(":");
			string subdel = del.substr(posdel + 1);
			remove(subdel.c_str());
		}
		if (mycompiler.find("winos") != string::npos) {
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
					MessageBox(NULL, L"Current OS Not Compatible", L"ESS os Error", MB_ICONERROR | MB_OK);
				}

			}
			else if (sub == "win7") {
				cout << "Windows 7\n";
				win7p = IsWindows7OrGreater();
				if (win7p == 1) {
					cout << "True";
				}
				else {
					MessageBox(NULL, L"Current OS Not Compatible", L"ESS os Error", MB_ICONERROR | MB_OK);
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
					MessageBox(NULL, L"Current OS Not Compatible", L"ESS os Error", MB_ICONERROR | MB_OK);
				}
			}
			else if (sub == "winxp") {
				cout << "Windows xp\n";
				winxpp = IsWindowsXPOrGreater();
				if (winxpp == 1) {
					cout << "True";
				}
				else {
					MessageBox(NULL, L"Current OS Not Compatible", L"ESS os Error", MB_ICONERROR | MB_OK);
				}
			}
			else if (sub == "winvista") {
				cout << "Windows Vista\n";
				winvistap = IsWindowsVistaOrGreater();
				if (winvistap == 1) {
					cout << "True";
				}
				else {
					MessageBox(NULL, L"Current OS Not Compatible", L"ESS os Error", MB_ICONERROR | MB_OK);
				}

			}
			else if (sub == "winserver") {
				cout << "Windows Server\n";
				server = IsWindowsServer();
				if (server == 1) {
					cout << "True";
				}
				else {
					MessageBox(NULL, L"Current OS Not Compatible", L"ESS os Error", MB_ICONERROR | MB_OK);
				}
			}
			else if (sub == "win11") {
				cout << "Windows 11\n";
				win7p = IsWindows7OrGreater();
				if (win7p == 1) {
					cout << "True";
				}
				else {
					MessageBox(NULL, L"Current OS Not Compatible ", L"ESS os Error", MB_ICONERROR | MB_OK);
				}

			}
			else {
				MessageBox(NULL, L"Not a Valid Windows OS", L"ESS os Error", MB_ICONERROR | MB_OK);
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
	remove("pip.bat");
	//CLEAN UP
}
