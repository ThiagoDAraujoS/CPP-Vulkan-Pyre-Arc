#pragma once
#include "Requirements.hpp"

namespace Servo {
//
//	struct QueueIndex {
//	public:
//		uint32_t familyIndex;
//		uint32_t queueIndex;
//	};
//
//	//QueueFamily obj to manage queue family related processes to deliver queues indexes as requested
//	class QueueFamily {
//	private:
//		//queue family index
//		const uint32_t familyQueueIndex;
//
//		//The index of this queue
//		uint32_t iterator = 0;
//
//		//the queue family properties
//		const vk::QueueFamilyProperties properties;
//
//	public:
//		//return the vk family properties for this family
//		inline const vk::QueueFamilyProperties& GetProperties() {
//			return properties;
//		}
//
//		//Checks if the iterator is at the end
//		inline bool IsFinished() {
//			return iterator >= properties.queueCount;
//		}
//		
//		//return if this family iterator has a given flag
//		inline bool HasFlag(vk::QueueFlagBits flag) {
//			return (flag & properties.queueFlags) == flag;
//		}
//
//		//Draws a queue from this family. queueId is a integer with the queue's index, returns if managed to draw a open queue
//		inline QueueIndex Iterate() {
//			return QueueIndex{familyQueueIndex, iterator++};
//		};
//
//		//Reset the used queues back to 0, so the draw system is able to draw repeated queues
//		inline void Reset() {
//			iterator = 0;
//		};
//
//		//ctor for this class
//		inline QueueFamily(const vk::QueueFamilyProperties& prop, const uint32_t index) : familyQueueIndex(index), properties(prop){};
//	};
//
//	//This iterator sort the avaliable queues by type rather then by family
//	class QueueTypeIterator {
//	private:
//		//all families with a given type
//		vector<QueueFamily&> families;
//
//		//iterator to walk through all the families on this object
//		uint32_t iterator = 0;
//
//	public:
//		//Adds a new family to this iterator
//		inline void AddFamily(QueueFamily& newFamily) {
//			families.push_back(newFamily);
//		}
//		
//		//checks if the iterator reached the end
//		inline bool IsFinished() {
//			return TRUE;// iterator >= families.size;
//		}
//
//		//iterates over the avaliable queues and fetch the next suitable one on the vector
//		inline QueueIndex Iterate() {
//			///while the iterator is not at the end OR finds finished families to iterate
//		/*	while (!IsFinished || families[iterator].IsFinished)
//				///steps to the next avaliable family on the vector
//				iterator++;*/
//
//			///at the end, if didnt manage to stop on an unfinished family, resets the finished families
//			if (TRUE/*IsFinished*/) {
//				///set the iterator to 0 again
//				iterator = 0;
//
//				///for each family on the vector
//				for each (QueueFamily& family in families)
//
//					///if that family was fully iterated over
//					if (/*family.IsFinished*/TRUE)
//
//						///resets its iterator
//						family.Reset();
//			}
//
//			///iterate over the selected family to fetch a queue index
//			return families[iterator].Iterate();
//		}
//	};
//
//
//	class QueueManager {
//	public:
//		vk::Queue graphics;
//		vk::Queue presentation;
//		vk::Queue transference;
//
//		inline QueueFamily& GetFlagIndex(vector<QueueFamily> map, function<bool(uint32_t)> predicate) {
//			//Returned index value
//			uint32_t iterator = -1;
//
//			///For each propertyExt
//			for (uint32_t i = 0; i < map.size() && iterator == -1; i++)
//
//				///if the ext's flags contain the requested flag
//				if (predicate(i))
//
//					///save its index
//					iterator = i;
//
//			///if no index was found throw an error
//			if (iterator == -1)
//				throw std::system_error(std::error_code(), "[ERROR] Queue - Required flag not suported.");
//
//			///returns found index, if index == -1 flag was not found
//			return map[iterator];
//		}
//
//		inline map<vk::QueueFlagBits, uint32_t> BuildIndexFamilyMap() {
//
//		}
//
//		inline void InitializeHandlers(const vk::PhysicalDevice& physicalDevice,const vk::Device& device) {
//			//Queue family property map
//		/*	vector<QueueFamily> propMap = QueueFamily::GetExtList(physicalDevice.getQueueFamilyProperties());
//			map<vk::QueueFlagBits, uint32_t> familyIndexMap;
//
//			int32_t presentationQueueId = GetFlagIndex(propMap, [physicalDevice](uint32_t i) {return physicalDevice.getWin32PresentationSupportKHR(i) == VK_TRUE;}).PickLoopQueueId();
//			int32_t graphicsQueueId     = GetFlagIndex(propMap,		   [propMap](uint32_t i) {return (propMap[i].flags & vk::QueueFlagBits::eGraphics) == vk::QueueFlagBits::eGraphics;}).PickLoopQueueId();
//			int32_t transferenceQueueId = GetFlagIndex(propMap,		   [propMap](uint32_t i) {return (propMap[i].flags & vk::QueueFlagBits::eTransfer) == vk::QueueFlagBits::eTransfer;}).PickLoopQueueId();
//		
//
//		*/
//		};
//
//		inline void GetQueueCreationInfoList(const vk::PhysicalDevice& physicalDevice,const vk::Device& device, vector<vk::DeviceQueueCreateInfo>& emptyQueueCreationInfoList) {
//
//		};
//	};
//
//
	
}