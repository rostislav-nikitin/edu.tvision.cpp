#include <string>
#include <iostream>
#include <fstream>

#ifndef __TFileContent_h
#define __TFileContent_h

const int MAX_LINES = 100;

class TFileContent
{
public:
	TFileContent(std::string fileName, int maxViewWidth);

	std::string get_fileName() const;
	int get_maxLineLength() const;
	int get_maxLines() const;
	int get_lineCount() const;
	char **get_lines();

	~TFileContent();
private:
	std::string _fileName;
	int _maxLineLength;
	int _lineCount;
	char *_lines[MAX_LINES];

	void read();

};

#endif
