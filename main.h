#define Uses_TKeys
#define Uses_TApplication
#define Uses_TEvent
#define Uses_TRect
#define Uses_TDialog
#define Uses_TStaticText
#define Uses_TButton
#define Uses_TMenuBar
#define Uses_TSubMenu
#define Uses_TMenuItem
#define Uses_TStatusLine
#define Uses_TStatusItem
#define Uses_TStatusDef
#define Uses_TDeskTop

#include <tvision/tv.h>
#include "TDemoWindow.h"


class THelloApp : public TApplication
{
	public:
		THelloApp();

		static TMenuBar * initMenuBar(TRect r);
		static TStatusLine * initStatusLine(TRect r);
		void myNewWindow();
		virtual void handleEvent(TEvent &event);
	private:
		void greetingBox();
};
