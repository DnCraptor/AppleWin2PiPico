#pragma once

#include "Video.h"

class FrameBase
{
public:
	FrameBase();

	virtual ~FrameBase();

	HINSTANCE  g_hInstance;
	HWND       g_hFrameWindow;
	BOOL       g_bConfirmReboot; // saved PageConfig REGSAVE
	BOOL       g_bMultiMon;
	bool       g_bFreshReset;

	virtual void Initialize(void) = 0;
	virtual void Destroy(void) = 0;

	virtual void FrameDrawDiskLEDS(HDC hdc) = 0;
	virtual void FrameDrawDiskStatus(HDC hdc) = 0;
	virtual void FrameRefreshStatus(int, bool bUpdateDiskStatus = true) = 0;
	virtual void FrameUpdateApple2Type() = 0;
	virtual void FrameSetCursorPosByMousePos() = 0;

	virtual void SetFullScreenShowSubunitStatus(bool bShow) = 0;
	virtual bool GetBestDisplayResolutionForFullScreen(UINT& bestWidth, UINT& bestHeight, UINT userSpecifiedHeight = 0) = 0;
	virtual int SetViewportScale(int nNewScale, bool bForce = false) = 0;
	virtual void SetAltEnterToggleFullScreen(bool mode) = 0;

	virtual void SetLoadedSaveStateFlag(const bool bFlag) = 0;

	virtual void VideoPresentScreen(void) = 0;
	virtual void ChooseMonochromeColor(void) = 0;
	virtual void Benchmark(void) = 0;
	virtual void DisplayLogo(void) = 0;

	void VideoRefreshScreen(uint32_t uRedrawWholeScreenVideoMode, bool bRedrawWholeScreen);
	void VideoRedrawScreen(void);
	void VideoRedrawScreenDuringFullSpeed(DWORD dwCyclesThisFrame, bool bInit = false);
	void VideoRedrawScreenAfterFullSpeed(DWORD dwCyclesThisFrame);
	void Video_RedrawAndTakeScreenShot(const char* pScreenshotFilename);

	void Video_TakeScreenShot(const Video::VideoScreenShot_e ScreenShotType);
	void Video_SaveScreenShot(const Video::VideoScreenShot_e ScreenShotType, const TCHAR* pScreenShotFileName);
	void SetDisplayPrintScreenFileName(bool state) { g_bDisplayPrintScreenFileName = state; }
	void Video_ResetScreenshotCounter(const std::string& pDiskImageFileName);

	bool GetShowPrintScreenWarningDialog(void) { return g_bShowPrintScreenWarningDialog; }
	void SetShowPrintScreenWarningDialog(bool state) { g_bShowPrintScreenWarningDialog = state; }

private:
	void Util_MakeScreenShotFileName(TCHAR* pFinalFileName_, DWORD chars);
	bool Util_TestScreenShotFileName(const TCHAR* pFileName);

	bool g_bShowPrintScreenWarningDialog;

	DWORD dwFullSpeedStartTime;
	bool g_bDisplayPrintScreenFileName;

	int g_nLastScreenShot;
	std::string g_pLastDiskImageName;
	static const int nMaxScreenShot = 999999999;
};
