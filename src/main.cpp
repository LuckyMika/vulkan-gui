#include <stdio.h>
#include <Windows.h>
#include <vulkan\vulkan.h>

#include "window.h"

#define WINDOW_CLASS "Vulkan GUI"
#define WINDOW_NAME "Vulkan GUI"

int main() {
	HINSTANCE module = GetModuleHandleA(nullptr);
	
	WNDCLASS window_class = {};
	window_class.hInstance = module;
	window_class.lpszClassName = WINDOW_CLASS;
	window_class.lpfnWndProc = Wndproc;

	RegisterClass(&window_class);

	HWND window = CreateWindow(WINDOW_CLASS, WINDOW_NAME, WS_OVERLAPPEDWINDOW /* | WS_BORDER | WS_MAXIMIZEBOX */, 400, 200, 800, 600, nullptr, nullptr, module, nullptr);
	
	if (!window) return -1;
	
	ShowWindow(window, SW_SHOW);
	UpdateWindow(window);

	VkApplicationInfo app_info{};
	app_info.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
	app_info.pApplicationName = "Hello Triangle";
	app_info.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
	app_info.pEngineName = "No Engine";
	app_info.engineVersion = VK_MAKE_VERSION(1, 0, 0);
	app_info.apiVersion = VK_API_VERSION_1_0;

	VkInstanceCreateInfo create_info{};
	create_info.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
	create_info.pApplicationInfo = &app_info;

	VkInstance instance;
	VkResult result = vkCreateInstance(&create_info, nullptr, &instance);
	
	if (result != VK_SUCCESS) {
		printf("Failed to create vulkan instance\n");
		return -1;
	}

	MSG msg = {};
	while (GetMessage(&msg, NULL, 0, 0)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return 0;
}