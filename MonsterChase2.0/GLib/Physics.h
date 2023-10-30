#pragma once

#include <vector>
#include <Moveable.h>
class Physics {

public:

	static	Moveable* AddPhysicsObject(Point2D pCoord, Point2D pVelocity, float pMass) noexcept;

	static Moveable* AddPhysicsObject(const SmartPtr<GameObject>& GO, float m);

	static	void		Update(float pDt) noexcept;

	static  void		RemovePhysicsObject(Moveable* pMoveable) noexcept;

	static void ClearAll();

	static std::vector<Moveable*> sMovableObjects;
};
