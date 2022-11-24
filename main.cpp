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
//NEW: Linux optimized
int main()
{
	
	int win10p = IsWindows10OrGreater();
	int win7p = IsWindows7OrGreater();
	int win8p = IsWindows8OrGreater();
	int winvistap = IsWindowsVistaOrGreater();
	int winxpp = IsWindowsXPOrGreater();
	int server = IsWindowsServer();			
	//FILECOMPILER
	bool mycore = false;
	string mycompiler;
	ifstream settingsfile("settings.fss");
	while (getline(settingsfile, mycompiler)) {
		if (mycompiler.find("main") != string::npos) { 
			string f = mycompiler;
			int posf = f.find(":");
			string subf = f.substr(posf + 1);
			string cmd = "start " + subf;
			system(cmd.c_str());
		}
		if (mycompiler.find("pip") != string::npos) {
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
			string commandp = mycompiler;
			int poscommandp = commandp.find(":");
			string subcommandp = commandp.substr(poscommandp + 1);
			string code = subcommandp;
			system(code.c_str());
		}
		if (mycompiler.find("admin.main") != string::npos) {
			string f = mycompiler;
			int posf = f.find(":");
			string subf = f.substr(posf + 1);
			ShellExecuteA(NULL, "runas", subf.c_str(), 0, 0, SW_SHOWNORMAL);
		}
		if (mycompiler.find("mov") != string::npos) {
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
			ifstream infile(matched);
			ofstream outfile(subnew);
			string content = "";
			int i;

			for (i = 0; !infile.eof(); i++)    
				content += infile.get();
			infile.close();

			content.erase(content.end() - 1);  
			i--;
			outfile << content;         
			outfile.close();
		}
		if (mycompiler.find("write") != string::npos) {
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
			if (subnew == "newline") {
				subnew = "\n";
			}
			ofstream newwriter;
			newwriter.open(matched);
			newwriter << subnew;
			newwriter.close();
		}
		if (mycompiler.find("awrite") != string::npos) {
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
			if (subnew == "newline") {
				subnew = "\n";
			}
			ofstream newwriter;
			newwriter.open(matched, std::ios_base::app);
			newwriter << subnew;
			newwriter.close();
		}
		if (mycompiler.find("brake") != string::npos) {
			this_thread::sleep_for(chrono::milliseconds(10000));
		}
		if (mycompiler.find("make-source") != string::npos) {
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
			execute("curl "+ subnew, matched);
		}
		if (mycompiler.find("openweb") != string::npos) {
			cout << mycompiler << endl;
		}
        if (mycompiler.find("sleep") != string::npos) {
            string sleep = mycompiler;
			int possleep = sleep.find(":");
			string subsleep = sleep.substr(possleep + 1);
            int time = stoi(subsleep);
            this_thread::sleep_for(chrono::seconds(time));
		}
		if (mycompiler.find("makefile") != string::npos) {
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
		if (mycompiler.find("showcon") != string::npos) {
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
				cout << "\n";
			}
		}
	}
	remove("pip.bat");
	//CLEAN UP
}
