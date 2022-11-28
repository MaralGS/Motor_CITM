#include "CameraObject.h"
#include "MathGeoLib.h"

CObject::CObject() : Component(nullptr)
{

}

CObject::CObject(GameObject* CameraObj) : Component(CameraObj)
{
	GObjectSelected = CameraObj;
	type = Type::CamObject;
}

CObject::~CObject()
{
	GObjectSelected = nullptr;
}

void CObject::Update()
{
	float3 newPos(0, 0, 0);
	
}

