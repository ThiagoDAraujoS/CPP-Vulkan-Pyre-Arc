#include "Servo.hpp"

vk::PhysicalDevice Servo::Device::PickPhysicalDevice(const vk::Instance& instance, const vk::SurfaceKHR& surface, const PhysicalDeviceRequestIndexes& requestedFeatures) {
	/// Use an ordered map to automatically sort candidates by increasing score
	std::multimap<int, vk::PhysicalDevice> candidates;

	///sort devices using the device inspector
	for (const vk::PhysicalDevice& device : instance.enumeratePhysicalDevices())
		candidates.insert(std::make_pair(DeviceInspector(device, surface, requestedFeatures).RateFitness(), device));

	/// Check if the best candidate is suitable at all
	if (candidates.rbegin()->first > 0)
		return candidates.rbegin()->second;
	else
		throw std::runtime_error("[ERROR] Failed to find a suitable GPU!");
};

Servo::Device::Device(vk::Instance & instance, vk::SurfaceKHR & surface/*, QueueManager & queue*/) {
	//ADD NEW FEATURES HERE
	//List with all requested indexes
	///make a physical device map from the requested device features
	PhysicalDeviceRequestIndexes requestedFeatureIndexes = vk::PhysicalDeviceFeatures()
		.setGeometryShader(VK_TRUE)
		.setDepthClamp(VK_TRUE);

	//vkPhysicalDevice
	///Build a physical device from a found suitable virtual device.
	vk::PhysicalDevice physicalDevice = PickPhysicalDevice(instance, surface, requestedFeatureIndexes);

	//List with all info related to the queue infos
	vector<vk::DeviceQueueCreateInfo> queueInfoList;
	
	//physicalDevice.createDevice()
	
	//fills queue infos
//	queue.GetQueueCreationInfoList(physicalDevice, resource, queueInfoList);

	/*
	vk::DeviceCreateInfo deviceInfo = vk::DeviceCreateInfo()
		.setPQueueCreateInfos(queueInfoList.data())
		.setQueueCreateInfoCount(queueInfoList.size())
	//	.setEnabledExtensionCount()
	//	.setPpEnabledExtensionNames()
	.setPEnabledFeatures(VK_FALSE);

	device = physicalDevice.createDevice(deviceInfo);
	*/
//	queue.InitializeHandlers(physicalDevice, resource);

	COUT("[DONE] Device")
};

Servo::Device::~Device() {
	resource.destroy();
	COUT("[UNDONE] Device")
};
	