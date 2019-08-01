#include "DeviceInspector.hpp"
/*
Servo::PhysicalDeviceFeaturesUnion::PhysicalDeviceFeaturesUnion(vk::PhysicalDeviceFeatures basefeatures) {
	data = basefeatures;
};

Servo::PhysicalDeviceFeaturesUnion::PhysicalDeviceFeaturesUnion() { };
*/
Servo::PhysicalDeviceRequestIndexes::PhysicalDeviceRequestIndexes(vk::PhysicalDeviceFeatures& base) {
	//gets a pointer to the start of the struct
	vk::Bool32* pointer = (vk::Bool32*)&base;

	//for each element inside the struct
	for (int i = 0; i < PHYSICAL_DEVICE_FEATURES_SIZE; i++)
		//if that element is true
		if (*(pointer + i) == VK_TRUE)
			//push its index into the list
			list.push_back(i);
};

bool Servo::DeviceInspector::CheckFeatureSupport() {
	int32_t size = PHYSICAL_DEVICE_FEATURES_SIZE;
	bool result = true;
	VkBool32* pointerToFeature = (VkBool32*)(&features);
	for (size_t i = 0; i < requests.list.size() && result; i++) 
		result = *(pointerToFeature + requests.list[i]) == VK_TRUE;
	return result;
}


//check if this device is able to process presentation commands
VkBool32 Servo::DeviceInspector::CheckSurfaceSupport() {
	//result variable
	VkBool32 hasSurfaceSupport = VK_FALSE;

	//get how many families this device has
	uint32_t familyCount = 0;
	vkGetPhysicalDeviceQueueFamilyProperties(device, &familyCount, nullptr);

	//check if any of those families suport presentation on this surface
	for (uint32_t i = 0; i < familyCount && !hasSurfaceSupport; i++)
		hasSurfaceSupport = device.getSurfaceSupportKHR(i, surface);

	//return variable
	return hasSurfaceSupport;
};

//check if this device can be used
bool Servo::DeviceInspector::CheckSuitability() {
	return
		//this device supports presentation
		CheckSurfaceSupport() &&

		//this device has all the required features
		CheckFeatureSupport() &&

		//this device supports the minimal required vulkan api
		VK_VERSION_MAJOR(properties.apiVersion) >= VK_VERSION_MAJOR(MINIMAL_API_VERSION);
};

//initialize the device inspector
Servo::DeviceInspector::DeviceInspector(const vk::PhysicalDevice& deviceRef, const vk::SurfaceKHR& surfaceRef, const PhysicalDeviceRequestIndexes& requestsRef) : device(deviceRef), surface(surfaceRef), requests(requestsRef) {
};

//rate this device fitness (0 means this device cant be used at all)
int Servo::DeviceInspector::RateFitness() {
	int score = 0;
	if (CheckSuitability()) {
		if (properties.deviceType == vk::PhysicalDeviceType::eDiscreteGpu)
			score += 1000;
		score += properties.limits.maxImageDimension2D;
	}
	return score;
}
