#include "window.h"

LRESULT CALLBACK Wndproc(HWND window, UINT message, WPARAM wParam, LPARAM lParam) {
    switch (message) {
    case WM_CLOSE:
        DestroyWindow(window);  // Properly destroys the window
        return 0;

    case WM_DESTROY:
        PostQuitMessage(0);  // Ends the message loop
        return 0;
    }

	return DefWindowProc(window, message, wParam, lParam);
}