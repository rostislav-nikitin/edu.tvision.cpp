#include "main.h"

static short winNumber = 0;
const int cmNewWin = 199;
const int cmNewDialog = 200;

struct DialogData
{
	ushort cheeses;
	ushort consistency;
	char instructions[128];
};

DialogData *_dialogData;


THelloApp::THelloApp():TProgInit( &THelloApp::initStatusLine,
	&THelloApp::initMenuBar,
	&THelloApp::initDeskTop
)
{
	_dialogData = new DialogData{1, 1, "Call Mom!"};
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
			*new TMenuItem{"~Z~oom", cmZoom, kbF5, hcNoContext, "F5"} +
		*new TSubMenu{"~C~ustom", kbAltC} +
			*new TMenuItem{"~D~ailog", cmNewDialog, kbF2, hcNoContext, "F2"}
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
			case cmNewDialog:
				showNewDialog();
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

void THelloApp::showNewDialog()
{
	TRect r{10, 10, 50, 24};
	//deskTop->insert(new TDialog{r, "Demo Dialog"});
	//deskTop->execView(new TDialog{r, "Demo Dialog"});
	
	TDialog *dialog = new TDialog{r, "Demo Dialog"};
	if(dialog)
	{
		TView *cbView = new TCheckBoxes{TRect{3, 3, 18, 6},
			new TSItem{"~H~varti",
			new TSItem{"~T~ilset",
			new TSItem{"~J~arlsberg", 0}}}};

		dialog->insert(cbView);
		dialog->insert(new TLabel{TRect{2, 2, 18, 3}, "Ch~e~eses", cbView});
		
		TView *rbView = new TRadioButtons{TRect{22, 3, 34, 6},
			new TSItem{"~S~olid",
			new TSItem{"~R~unney",
			new TSItem{"~M~elted", 0}}}};

		dialog->insert(rbView);
		dialog->insert(new TLabel{TRect{21, 2, 34, 3}, "Co~n~sistency", rbView});

		TView *ilView = new TInputLine{TRect{3, 8 , 37, 9}, 128};
		dialog->insert(ilView);
		dialog->insert(new TLabel{TRect{2, 7, 12, 8}, "~I~nstructions", ilView});

		TButton *okButton = new TButton{TRect{15, 10, 25, 12}, "~O~K", cmOK, bfDefault};
		dialog->insert(okButton);
		dialog->insert(new TButton{TRect{28, 10, 38, 12}, "~C~ancel", cmCancel, bfNormal});

		//okButton->select();
		
		dialog->setData(_dialogData);
		

		int result = deskTop->execView(dialog);
		if(result == cmOK)
		{
			dialog->getData(_dialogData);
		}

	}
	destroy(dialog);
}


void THelloApp::greetingBox()
{
}

THelloApp::~THelloApp()
{
	delete _dialogData;
}

int main()
{
	THelloApp app;
	app.run();

	return 0;
}
