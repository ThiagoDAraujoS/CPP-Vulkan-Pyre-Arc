#pragma once
#define VK_USE_PLATFORM_WIN32_KHR
#define SDL_MAIN_HANDLED

//VK related libraries
#include <glm/glm.hpp>
#include <SDL2/SDL.h>
#include <SDL2/SDL_syswm.h>
#include <vulkan/vulkan.hpp>

//Useful libraries
#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <string.h>
#include <array>
#include <memory>
#include <functional>
#include <set>
#include <map>

//usings
using namespace std;

//debug macros
#ifdef _DEBUG
#define COUT(message) cout<<message<<endl;
#define _CRTDBG_MAP_ALLOC  
#include <stdlib.h>  
#include <crtdbg.h>  
#else
#define COUT(message)
#endif


/*
struct QueueGroupSpecification {
	VkQueueFlagBits type;
	int32_t quantity;
	float priority;
};*/

//App Definition Macros
#define WINDOW_WIDTH 1280
#define WINDOW_HEIGHT 720
#define MINIMAL_API_VERSION VK_API_VERSION_1_0

//Rendering Queues Definition Macros
#define GRAPHICS_QUEUE_DEF	   { VK_QUEUE_GRAPHICS_BIT, 1, 0.5f }
#define TRANSFERENCE_QUEUE_DEF { VK_QUEUE_TRANSFER_BIT, 1, 1.0f }
#define PRESENTATION_QUEUE_DEF { VK_QUEUE_GRAPHICS_BIT, 1, 1.0f }
