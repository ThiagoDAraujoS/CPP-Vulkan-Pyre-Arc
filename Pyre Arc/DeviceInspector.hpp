#include "Requirements.hpp"

namespace Servo {

#define PHYSICAL_DEVICE_FEATURES_SIZE sizeof(vk::PhysicalDeviceFeatures) / sizeof(vk::Bool32)
	//Union, physicaldevicefeatures with a bool32 list of the same size (this enables me to use the indexer of the list on the physical device features struct
	/*union PhysicalDeviceFeaturesUnion {
		//array interface for the data stored in this container
		vk::Bool32 iterator[PHYSICAL_DEVICE_FEATURES_SIZE];

		//physical device features stored in this container
		vk::PhysicalDeviceFeatures data;

		//ctor
		PhysicalDeviceFeaturesUnion(vk::PhysicalDeviceFeatures basefeatures);

		//ctor
		PhysicalDeviceFeaturesUnion();
	};*/

	//this struct contains a list of indexes related to the requested features
	struct PhysicalDeviceRequestIndexes {
		//list with all indexes
		vector<int> list;

		//initializer
		PhysicalDeviceRequestIndexes(vk::PhysicalDeviceFeatures& base);

	};

	class DeviceInspector {
	private:
		//Reference to the inspected physical device
		const vk::PhysicalDevice& device;

		//Reference to the surface used for rendering (used on some checks)
		const vk::SurfaceKHR& surface;

		//Reference to the feature request list
		const PhysicalDeviceRequestIndexes& requests;
		
		//Device properties
		const vk::PhysicalDeviceProperties properties = device.getProperties();

		//Device features
		const vk::PhysicalDeviceFeatures features = device.getFeatures();

		//Check if all the features requested are present in this device
		bool CheckFeatureSupport();
		
		//check if this device is able to process presentation commands
		VkBool32 CheckSurfaceSupport();

		//check if this device can be used
		bool CheckSuitability();

	public:
		//initialize the device inspector
		DeviceInspector(const vk::PhysicalDevice& deviceRef, const vk::SurfaceKHR& surfaceRef, const PhysicalDeviceRequestIndexes& requestsRef);
		
		//rate this device fitness (0 means this device cant be used at all)
		int RateFitness();
	};
}