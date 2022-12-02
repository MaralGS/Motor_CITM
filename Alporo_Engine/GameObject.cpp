#include "GameObject.h"
#include "Mesh.h"
#include "Transform.h"
#include "CameraObject.h"
#include<vector>

GameObject::GameObject()
{
	name = "root";
	Parent = nullptr;
	transform = new Transform(this);
	Comp.push_back(transform);
}

GameObject::GameObject(GameObject* parent)
{
	name = "GameObject";
	Parent = parent;

	CamGOGame = new CObject();

	transform = new Transform(this);
	Comp.push_back(transform);
	Comp.push_back(CamGOGame);

	//GOMesh = new Meshes(this);
	if (parent != nullptr)
	{
		parent->child.push_back(this);
	}
}

GameObject::~GameObject()
{


	if (Parent != nullptr)
	{
		for  (size_t i = 0; i < child.size(); i++)
		{
			delete child[i];
			child[i] = nullptr;
		}
	}
	
	//transform = nullptr;
	child.clear();
	for  (size_t i = 0; i < Comp.size(); i++)
	{
		delete Comp[i];
		Comp[i] = nullptr;
	}

	Comp.clear();
	
}

void GameObject::CreateInspector()
{
	if (ImGui::Begin("Inspector")) {
		for (size_t i = 0; i < Comp.size(); i++)
		{
			Comp[i]->Inspector();
		}
	}
	ImGui::End();
}

void GameObject::MoveGameObject(GameObject* P)
{
	P->child.erase(std::find(child.begin(), child.end(), Parent));

	Parent = P;
	Parent->child.push_back(P);
}

void GameObject::CameraGameObject()
{
		for (size_t i = 0; i < Comp.size(); i++)
		{
			Comp[i]->Update();
		}

}

