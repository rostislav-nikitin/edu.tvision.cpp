#include "main.h"

static short winNumber = 0;
const int cmNewWin = 199;


THelloApp::THelloApp():TProgInit( &THelloApp::initStatusLine,
	&THelloApp::initMenuBar,
	&THelloApp::initDeskTop
)
{
}

TMenuBar * THelloApp::initMenuBar(TRect r)
{
	r.b.y = r.a.y + 1;

	return new TMenuBar 
	{	r,
		*new TSubMenu{"~F~ile", kbAltF} +
			*new TMenuItem{"~N~ew", cmNewWin, kbF4, hcNoContext, "F4"} +
			*new TMenuItem{"~O~pen", cmFileOpen, kbF3, hcNoContext, "F3"} +
			newLine() +
			*new TMenuItem{"E~x~it", cmQuit, kbAltX, hcNoContext, "Alt-X"} +
		*new TSubMenu{"~W~indow", kbAltW} +
			*new TMenuItem{"~N~ext", cmNext, kbF6, hcNoContext, "F6"} +
			*new TMenuItem{"~Z~oom", cmZoom, kbF5, hcNoContext, "F5"}
	};
}

TStatusLine * THelloApp::initStatusLine(TRect r)
{
	r.a.y = r.b.y - 1;
	return new TStatusLine
	{
		r, 
		*new TStatusDef{0, 0xFFFF} + 
		*new TStatusItem{"~Alt-X~ Exit", kbAltX, cmQuit} + 
		*new TStatusItem{"~F4~ New", kbF4, cmNewWin} +
		*new TStatusItem{"~Alt-F3~ Close", kbAltF3, cmClose} +
		*new TStatusItem{"", kbF10, cmMenu}
	};
}

void THelloApp::handleEvent(TEvent &event)
{
	TApplication::handleEvent(event);
	if(event.what == evCommand)
	{
		switch(event.message.command)
		{
			case cmNewWin:
				myNewWindow();
				break;
			default:
				return;
		}
		clearEvent(event);
	}
}

void THelloApp::myNewWindow()
{
	TRect r {5, 5, 72, 17};
	//r.move(random(), random());
	TDemoWindow *window = new TDemoWindow {r, "Demo Window", ++winNumber};
	deskTop->insert(window);
}


void THelloApp::greetingBox()
{
}

int main()
{
	THelloApp app;
	app.run();

	return 0;
}
