#include "TDemoWindow.h"

TDemoWindow::TDemoWindow(const TRect &bounds, TStringView aTitle, short aNumber): TWindow{bounds, aTitle, aNumber}, TWindowInit{&TDemoWindow::initFrame}, 
		main_cpp{"main.cpp", maxViewWidth}, main_h{"main.h", maxViewWidth}
{
	TRect eBounds = getExtent();
	TRect r {eBounds.a.x, eBounds.a.y, eBounds.b.x/2, eBounds.b.y};
	TInterior *lInterior = makeInterior(&main_h, r, true);
	lInterior->growMode = gfGrowHiY;
	insert(lInterior);

	r = {eBounds.b.x/2 - 1, eBounds.a.y, eBounds.b.x, eBounds.b.y};
	TInterior *rInterior = makeInterior(&main_cpp, r, false);
	rInterior->growMode = (gfGrowHiX | gfGrowHiY);
	insert(rInterior);
};

TInterior *TDemoWindow::makeInterior(TFileContent *fileContent, TRect &bounds, bool left)
{
	//TScrollBar *vScrollBar = standardScrollBar(sbVertical | sbHandleKeyboard);
	//TScrollBar *hScrollBar = standardScrollBar(sbHorizontal | sbHandleKeyboard);
	//TRect r = getClipRect();
	//bounds.grow(-1, -1);
	TRect r {bounds.b.x - 1, bounds.a.y + 1, bounds.b.x, bounds.b.y - 1};
	TScrollBar *vScrollBar = new TScrollBar {r};
	vScrollBar->options |= ofPostProcess;
	if(left)
		vScrollBar->growMode = gfGrowHiY;

	insert(vScrollBar);

	r = {bounds.a.x + 2, bounds.b.y - 1, bounds.b.x - 2, bounds.b.y};
	TScrollBar *hScrollBar = new TScrollBar {r};
	hScrollBar->options |= ofPostProcess;
	if(left)
		hScrollBar->growMode = (gfGrowHiY | gfGrowLoY);

	insert(hScrollBar);

	r = bounds;
	r.grow(-1, -1);
	
	return new TInterior {r, hScrollBar, vScrollBar, fileContent};
	

}

