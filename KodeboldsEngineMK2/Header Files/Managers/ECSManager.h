#pragma once
#include <memory>
#include <vector>
#include "Components.h"
#include "ISystem.h"
#include <algorithm>
#include <string>

struct Entity
{
	std::string mName;
	int mID;
	ComponentType mComponentMask;
};

class ECSManager final
{
private:
	static std::shared_ptr<ECSManager> mInstance;

	std::vector<Entity> mEntities;
	std::vector<std::pair<std::string, int>> mEntityNames;
	std::vector<std::pair<int, Transform>> mTransforms;
	std::vector<std::pair<int, Velocity>> mVelocities;
	std::vector<std::pair<int, BoxCollider>> mBoxColliders;
	std::vector<std::pair<int, SphereCollider>> mSphereColliders;
	std::vector<std::pair<int, Geometry>> mGeometries;
	std::vector<std::pair<int, Texture>> mTextures;
	std::vector<std::pair<int, Shader>> mShaders;
	std::vector<std::pair<int, Camera>> mCameras;
	std::vector<std::pair<int, Light>> mLights;
	std::vector<std::pair<int, Gravity>> mGravities;
	std::vector<std::pair<int, Audio>> mAudios;
	std::vector<std::pair<int, AI>> mAIs;
	std::vector<std::shared_ptr<ISystem>> mRenderSystems;
	std::vector<std::shared_ptr<ISystem>> mUpdateSystems;

	void AssignEntity(const Entity& pEntity);
	void RemoveEntity(const Entity& pEntity);

public:
	ECSManager();
	~ECSManager();
	
	static std::shared_ptr<ECSManager> Instance();

	void CreateEntity(const std::string& pEntityName);
	void DestroyEntity(const std::string& pEntityName);
	void AddComponent(const ComponentType& pComponentType, const std::shared_ptr<const IComponent> pComponent, const std::string& pEntityName);
	void RemoveComponent(const ComponentType& pComponentType, const std::string& pEntityName);
	void AddUpdateSystem(const std::shared_ptr<const ISystem> pSystem);
	void AddRenderSystem(const std::shared_ptr<const ISystem> pSystem);
	void ProcessSystems();
	const std::shared_ptr<const IComponent> GetComponent(const ComponentType& pComponentType, const std::string& pEntityName) const;
	void SetComponent(const ComponentType& pComponentType, const std::shared_ptr<const IComponent> pComponent);
	const std::shared_ptr<const IComponent> GetComponent(const ComponentType& pComponentType, const int& pEntityID) const;
	void SetComponent(const ComponentType& pComponentType, const int& pEntityID);

};
