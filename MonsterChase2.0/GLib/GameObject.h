#pragma once
#include "Point2D.h"
#include <vector>
#include "GLib.h"
#include"SmartPtr.h"
#include "WeakPtr.h"

class GameObject
{
public:

	static inline SmartPtr<GameObject> CreateNewGO();
	static inline SmartPtr<GameObject> CreateNewGO(Point2D coord, Point2D prevCoord);
	static inline void ClearAll();

	inline ~GameObject();

	inline void SetCoord(Point2D pCoord);
	inline void SetPrevCoord(Point2D pVel);
	inline void SetGameObject(Point2D pCoord, Point2D pVel);

	inline Point2D GetCoord() const;
	inline GLib::Point2D GetCoordAsPoint2D() const;
	inline Point2D GetPrevCoord() const;

	static std::vector<SmartPtr<GameObject>> AllGameObjects;

private:
	inline GameObject();
	inline GameObject(Point2D pCoord, Point2D pVel);

protected:

	Point2D vCoord;
	Point2D vPrevCoord;
};

/* GameObject */

SmartPtr<GameObject>
GameObject::CreateNewGO()
{
	GameObject* gameobj;

	gameobj = new GameObject();

	SmartPtr<GameObject> smartptr(gameobj);

	AllGameObjects.push_back(smartptr);

	return smartptr;
}

SmartPtr<GameObject>
GameObject::CreateNewGO(Point2D pCoord, Point2D pPrevCoord)
{
	GameObject* gameobj;

	gameobj = new GameObject(pCoord, pPrevCoord);

	SmartPtr<GameObject> smartptr(gameobj);

	AllGameObjects.push_back(smartptr);

	return smartptr;
}

void
GameObject::ClearAll()
{
	size_t size;
	size_t ndx = 0;

	size = AllGameObjects.size();

	for (std::vector<SmartPtr<GameObject>>::iterator it = AllGameObjects.begin(); size > ndx;) {

		AllGameObjects.erase(it);

		++ndx;

		if (size > ndx) {

			++it;
		}
	}

	AllGameObjects.clear();
}
// constructor

GameObject::GameObject()
{
	Point2D zero{ 0, 0 };

	vCoord = zero;
	vPrevCoord = zero;
}

// parameterized constructor

GameObject::GameObject(Point2D pCoord, Point2D pVel)
{
	SetGameObject(pCoord, pVel);
}

GameObject::~GameObject()
{

}

void
GameObject::SetCoord(Point2D pCoord)
{
	vCoord = pCoord;
}

void
GameObject::SetPrevCoord(Point2D pVel)
{
	vPrevCoord = pVel;
}

void
GameObject::SetGameObject(Point2D pCoord, Point2D pVel )
{
	SetCoord(pCoord);
}

Point2D
GameObject::GetCoord() const
{
	return vCoord;
}

GLib::Point2D 
GameObject::GetCoordAsPoint2D() const
{
	GLib::Point2D coord;

	coord.x = vCoord.GetX();
	coord.y = vCoord.GetY();

	return coord;
}

Point2D
GameObject::GetPrevCoord() const
{
	return vPrevCoord;
}