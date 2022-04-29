#include"mfc.h"
MyApp app;
BOOL MyApp::InitInstance()
{
	MyFrame* frame = new MyFrame;

	frame->ShowWindow(SW_SHOWNORMAL);
	frame->UpdateWindow();

	m_pMainWnd = frame;

	return true;
}

MyFrame::MyFrame()
{
	Create(NULL, TEXT("mfc"));
}