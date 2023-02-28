#include<iostream>
#include<fstream>
#include<string>
using namespace std;
struct serverinfo
{
	char _ip[32];
	int _port;
};
struct ConfigManager
{
public:
	ConfigManager(const char* filename)
		:_configfile(filename)
	{

	}
	void writebin(const serverinfo& info)
	{
		ofstream ofs(_configfile);
		ofs.write((char*)&info, sizeof(serverinfo));
	}
	void readbin(const serverinfo& info)
	{
		ifstream ifs(_configfile);
		ifs.read((char*)&info, sizeof(serverinfo));
	}
	void readtext(serverinfo& info)
	{
		ifstream ifs(_configfile);
		ifs >> info._ip;
		ifs >> info._port;
	}
private:
	string _configfile;
};
int main()
{
	serverinfo myinfor = { "192.168.1.1",8080 };
	ConfigManager cm("server.config");
	cm.writebin(myinfor);
	serverinfo infor;
	cm.readbin(infor);
}