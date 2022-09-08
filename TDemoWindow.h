//#define Uses_TKeys
//#define Uses_TApplication
//#define Uses_TEvent
#define Uses_TRect
//#define Uses_TDialog
#define Uses_TStaticText
//#define Uses_TButton
//#define Uses_TMenuBar
//#define Uses_TSubMenu
//#define Uses_TMenuItem
//#define Uses_TStatusLine
//#define Uses_TStatusItem
//#define Uses_TStatusDef
#define Uses_TDeskTop
#define Uses_TWindow
#define Uses_TScrollBar

#include <tvision/tv.h>
#include "TFileContent.h"
#include "TInterior.h"


class TDemoWindow : public TWindow
{
public:
	TDemoWindow(const TRect &bounds, TStringView aTitle, short aNumber);
	virtual void sizeLimits(TPoint &minP, TPoint &maxP);
private:
	TFileContent main_cpp;
	TFileContent main_h;
	TInterior *lInterior;
	TInterior *rInterior;

	//void makeInterior();
	TInterior *makeInterior(TFileContent *fileContent, TRect &bounds, bool left);

};
