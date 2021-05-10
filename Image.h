#include <string>

using namespace std;

#pragma once
class Image
{
private:
	string name;
	string path;
public:
	Image();
	Image(string name, string path);
	~Image();

	string getName();
	void setName(string name);
	string getPath();
	void setPath(string path);
};

