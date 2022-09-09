//PRJ - RPG Hills of Darkness - MFC GUI Game - 2006 - C. S. Germany
//File 4 of 7: MFCSleep (multi-threading to prevent GUI lockout in game sequences)

//---------------------------------------------------------------------------------------------------------------------------

struct XSleep_Structure
{
int duration;
HANDLE eventHandle;
};

DWORD WINAPI XSleepThread(LPVOID pWaitTime)
{
XSleep_Structure *sleep = (XSleep_Structure *)pWaitTime;

Sleep(sleep->duration);
SetEvent(sleep->eventHandle);

return 0;
}

void XSleep(int nWaitInMSecs)
{
XSleep_Structure sleep;

sleep.duration = nWaitInMSecs;
sleep.eventHandle = CreateEvent(NULL, TRUE, FALSE, NULL);

DWORD threadId;
CreateThread(NULL, 0, &XSleepThread, &sleep, 0, &threadId);

MSG msg;

while(::WaitForSingleObject(sleep.eventHandle, 0) == WAIT_TIMEOUT)
{
//get and dispatch messages
if(::PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
{
::TranslateMessage(&msg);
::DispatchMessage(&msg);
}
}

CloseHandle(sleep.eventHandle);
}

//---------------------------------------------------------------------------------------------------------------------------










