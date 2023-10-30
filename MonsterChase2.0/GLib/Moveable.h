#pragma once

#include "GameObject.h"
#include "SmartPtr.h"
#include "WeakPtr.h"

class Moveable {

public:

	inline Moveable(Point2D pCoord, Point2D pVelocity, float pMass) noexcept;

	inline Moveable(const SmartPtr<GameObject>& GO, float m);

	inline ~Moveable() noexcept;

	inline void	UpdateForce(Point2D pForce) noexcept;

	inline void	AddForce(Point2D pForce) noexcept;

	inline GameObject* GetGameObject() noexcept;

private:

	friend class Physics;

	float  vMass;			// mass of the gameobject
	Point2D vForce;		    // force acting on this gameobject
	SmartPtr<GameObject> vGameObject;		// reference to the gameobject
};


inline
Moveable::Moveable(Point2D pCoord, Point2D pVelocity, float pMass) noexcept
{
	vGameObject = GameObject::CreateNewGO(pCoord, pVelocity);
	vMass = pMass;
}

inline
Moveable::Moveable(const SmartPtr<GameObject>& pGameObject, float pMass)  : vGameObject(pGameObject), vMass(pMass)
{
}

inline Moveable::~Moveable() noexcept
{
	//delete vGameObject;
}

inline void
Moveable::UpdateForce(Point2D pForce) noexcept
{
	vForce = pForce;
}

inline void
Moveable::AddForce(Point2D pForce) noexcept
{
	vForce += pForce;
}

inline GameObject*
Moveable::GetGameObject() noexcept
{
	return vGameObject.GetData();
}
