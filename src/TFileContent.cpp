#include "TFileContent.h"

TFileContent::TFileContent(std::string fileName, const int maxViewWidth):_fileName{fileName}, _maxLineLength{maxViewWidth + 1}, _lineCount{0}
{
	read();
}
      
std::string TFileContent::get_fileName() const
{
	return _fileName;
}

int TFileContent::get_maxLineLength() const
{
	return _maxLineLength;
}
int TFileContent::get_maxLines() const
{
	return MAX_LINES;
}
int TFileContent::get_lineCount() const
{
	return _lineCount;
}
char **TFileContent::get_lines()
{
	return _lines;
}

void TFileContent::read()
{
	const int TAB_SIZE = 4;

	int idx_pos = 0;
	int idx_line = 0;
	char *currentLine;// = new char[maxLineLength];
	std::ifstream i_stream(_fileName);

	char c = i_stream.get();
 
	while(i_stream.good())
	{
		if(idx_pos == 0)
 		{
			currentLine = new char[_maxLineLength];
 		}
 
		if(c == '\t')
		{
			for(int i = 0; i < TAB_SIZE; i++)
			{
				currentLine[idx_pos++] = ' ';
			}
		}
		else if(c != '\n' && c != '\r')
		{
			currentLine[idx_pos++] = c;
		}

		if(idx_pos == _maxLineLength - 2)
 		{
 			currentLine[_maxLineLength - 1] = '\0';
 			_lines[idx_line++] = currentLine;
 			idx_pos = 0;
 		}
		else if (c == '\n')
		{
			currentLine[idx_pos] = '\0';
			_lines[idx_line++] = currentLine;
			idx_pos = 0;
		}

		if(idx_line >= MAX_LINES - 1)
			break;

		//std::cout << c;
		c = i_stream.get();
	}

	if(idx_pos != 0)
	{
		currentLine[idx_pos] = '\0';
		_lines[idx_line++] = currentLine;
		idx_pos = 0;
	}

	_lineCount = idx_line;
	//std::cout << _lineCount << std::endl;

	i_stream.close();
}

TFileContent::~TFileContent()
{
	//std::cout << __PRETTY_FUNCTION__ << std::endl;
	//return;
	for(int idx_line = 0; idx_line < _lineCount; idx_line++)
	{
		char *str = _lines[idx_line];
		delete[] str;
	}
}


