#define Uses_TRect
#define Uses_TView
#define Uses_TScroller

#include "TFileContent.h"
#include <tvision/tv.h>

class TInterior : public TScroller
{
public:
	TInterior(const TRect &bounds, TScrollBar *aHScrollBar, TScrollBar *aVScrollBar, TFileContent *fileContent);

	virtual void draw();

	~TInterior();

private:
	TFileContent *_fileContent;

	void readFile(const std::string& fileName);

};
