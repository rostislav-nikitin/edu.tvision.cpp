#include "TInterior.h"


TInterior::TInterior(const TRect &bounds, TScrollBar *aHScrollBar, TScrollBar *aVScrollBar, TFileContent *fileContent) : 
		TScroller{bounds, aHScrollBar, aVScrollBar},
		_fileContent{fileContent}
{
	growMode = gfGrowHiX | gfGrowHiY;
	options = options | ofFramed;
	setLimit(_fileContent->get_maxLineLength(), _fileContent->get_maxLines());
}

void TInterior::draw()
{
	//TStringView hstr {"Hello World!"};
	ushort color = getColor(0x0301);
	TView::draw();
	//TDrawBuffer b{};
	//b.moveStr(0, hstr, color);
	//writeLine(4, 2, 12, 1, b);
	//std::cout << lineCount; 
	for(int idx_line = 0; idx_line < size.y; idx_line++)
	{
//		TDrawBuffer b{};
//		b.moveCStr(0, lines[idx_line], color);
		//writeCStr(0, idx_line, lines[idx_line], 1);
//		writeStr(2, idx_line + 2, lines[idx_line], color);
		//std::cout << idx_line << ":" << lines[idx_line] << std::endl;
		//
		TDrawBuffer b{};
		b.moveChar(0, ' ', color, size.x);
		int idx_line_visible = idx_line + delta.y;
		if(idx_line_visible < _fileContent->get_lineCount() &&  _fileContent->get_lines()[idx_line_visible])
		{
			char s[_fileContent->get_maxLineLength()];
			if(delta.x > strlen(_fileContent->get_lines()[idx_line_visible]))
			{
				s[0] = EOS;
			}
			else
			{
				int length = _fileContent->get_maxLineLength() - delta.x;
				strncpy(s, _fileContent->get_lines()[idx_line_visible] + delta.x, length);
				s[length - 1] = EOS;
			}
			b.moveStr(0, s, color);
		}
		writeLine(0, idx_line, size.x, 1, b);
	}
}

TInterior::~TInterior()
{
}
