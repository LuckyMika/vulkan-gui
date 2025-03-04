#include <stdio.h>
#include <Windows.h>

#include "window.h"

#define WINDOW_CLASS "Vulkan GUI"
#define WINDOW_NAME "Vulkan GUI"

int main() {
	HINSTANCE instance = GetModuleHandleA(nullptr);
	
	WNDCLASS window_class = {};
	window_class.hInstance = instance;
	window_class.lpszClassName = WINDOW_CLASS;
	window_class.lpfnWndProc = Wndproc;

	RegisterClass(&window_class);

	HWND window = CreateWindow(WINDOW_CLASS, WINDOW_NAME, WS_OVERLAPPEDWINDOW /* | WS_BORDER | WS_MAXIMIZEBOX */, 400, 200, 800, 600, nullptr, nullptr, instance, nullptr);
	
	if (!window) return 0xF0C;
	
	ShowWindow(window, SW_SHOW);
	UpdateWindow(window);

	MSG msg = {};
	while (GetMessage(&msg, NULL, 0, 0)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return 0;
}