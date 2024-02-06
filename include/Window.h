#pragma once
#include "Prerequisites.h"


/// <summary>
/// This class is in charge of generatting new window
/// </summary>
class Window
{
public:
	Window();
	~Window();

	/// <summary>
	/// The method is in charge of generate a window
	/// </summary>
	/// <param name="hInstance"> A single ID for the window / Copy of the resource </param>
	/// <param name="nCmdShow"> Command list window </param>
	/// <param name="wndproc"> Input Bridge </param>
	/// <returns></returns>
	HRESULT
		init(HINSTANCE hInstance, int nCmdShow, WNDPROC wndproc);

	void
		update();

	void
		render();

	void
		destroy();

public:
	// This is in charge to close the window
	HWND m_hWnd = nullptr;
	// m_width is a parameter to control the width of the screen
	unsigned int m_width;
	// m_height is a parameter to control the height of the screen
	unsigned int m_height;
private:
	HINSTANCE m_hInst = nullptr;
	// IDK
	RECT m_rect;
	// Declare the window name 
	std::string m_WindowName = "Direct3D 11 Tutorial 7";
};


