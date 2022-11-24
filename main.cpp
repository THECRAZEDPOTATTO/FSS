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
#include <filesystem>
using namespace std; 
using namespace filesystem;
int main(int count,char* arg[])
{
	int counter;
	int win10p = IsWindows10OrGreater();
	int win7p = IsWindows7OrGreater();
	int win8p = IsWindows8OrGreater();
	int winvistap = IsWindowsVistaOrGreater();
	int winxpp = IsWindowsXPOrGreater();
	int server = IsWindowsServer();			
	//FILECOMPILER
	bool mycore = false;
	string mycompiler;
	 if(count>=2)
    {
        for(counter=0;counter<count;counter++)
            cout << "";
    }else{
		cout << "Error: Invalid Command Line Arguments" << endl;
		exit(1);
	}
	ifstream checksum;
	checksum.open(arg[1]);
	if(checksum){
	cout<<"";
	} else {
		cout << arg[1] <<" doesn't exist!" << endl;
		exit(1);
	}
	path filePath = arg[1];
    if (filePath.extension() == ".fss") 
    {
        cout  << ""; 
    }
    else
    {
        cout << filePath.filename() << " is not an FSS file!" << endl; 
    }
	ifstream settingsfile(arg[1]);
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
		if (mycompiler.find("title") != string::npos) {
			string title = mycompiler;
			int postitle = title.find(":");
			string subtitle = title.substr(postitle + 1);
            SetConsoleTitle(subtitle.c_str());
		}
	    if (mycompiler.find("print") != string::npos) {
			string x = mycompiler;
			int pos = x.find(":");//*BASE LINE READER
			string sub = x.substr(pos + 1);
			cout << sub << endl;
		}//create_directories("sandbox/1/2/a");
	    if (mycompiler.find("mkdir") != string::npos) {
			string x = mycompiler;
			int pos = x.find(":");//*BASE LINE READER
			string sub = x.substr(pos + 1);
			create_directories(sub);
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
 //TODO: Add ESCEL Script to FSS
 //TODO: Add Let function 
 //TODO: Update/Push new exe to github
 
