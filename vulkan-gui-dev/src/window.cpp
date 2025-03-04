#include "window.h"

LRESULT CALLBACK Wndproc(HWND window, UINT message, WPARAM wParam, LPARAM lParam) {
    switch (message) {
    case WM_CLOSE:
        DestroyWindow(window);
        return 0;

    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;

    case WM_ERASEBKGND: {
        HDC hdc = (HDC)wParam;
        RECT rect;
        GetClientRect(window, &rect);
        HBRUSH blackBrush = CreateSolidBrush(RGB(0, 0, 0));
        FillRect(hdc, &rect, blackBrush);
        DeleteObject(blackBrush);
        return 1;
    }

    case WM_PAINT: {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(window, &ps);
        RECT clientRect;
        GetClientRect(window, &clientRect);

        int rectWidth = clientRect.right * 0.5;
        int rectHeight = clientRect.bottom * 0.59;
        int rectLeft = (clientRect.right - rectWidth) / 2.5;
        int rectTop = (clientRect.bottom - rectHeight) / 2;

        RECT rect = { rectLeft, rectTop, rectLeft + rectWidth, rectTop + rectHeight };

        Rectangle(hdc, rect.left, rect.top, rect.right, rect.bottom);

        EndPaint(window, &ps);
        return 0;
    }

    case WM_NCHITTEST: {
        LRESULT hit = DefWindowProc(window, message, wParam, lParam);
        if (hit == HTCLIENT) {
            return HTCAPTION;
        }
        return hit;
    }

    case WM_KEYDOWN: {
        if (wParam == VK_F10) {

            BOOL isVisible = IsWindowVisible(window);
            ShowWindow(window, isVisible ? SW_HIDE : SW_SHOW);
        }
        return 0;
    }
    }

    return DefWindowProc(window, message, wParam, lParam);
}