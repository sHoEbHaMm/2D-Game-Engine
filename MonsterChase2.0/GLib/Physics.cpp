#include "Physics.h"

std::vector<Moveable*>  Physics::sMovableObjects{};
std::vector<SmartPtr<GameObject>> GameObject::AllGameObjects{};

static const float kMinVelocityMagnitude{ 0.001f };

Moveable*
Physics::AddPhysicsObject(Point2D pCoord, Point2D pVelocity, float pMass) noexcept
{
    Moveable* moveable = new Moveable(pCoord, pVelocity, pMass);
    sMovableObjects.push_back(moveable);

    return moveable;
}

Moveable*
Physics::AddPhysicsObject(const SmartPtr<GameObject>& GO, float m) 
{
    Moveable* moveable = new Moveable(GO, m);
    sMovableObjects.push_back(moveable);

    return moveable;
}

void
Physics::Update(float pDt) noexcept
{
    Point2D  acceleration;
    Point2D  temp;
    Moveable* movObj;
    Point2D  prevVel;
    Point2D  newVel;
    Point2D newPosition;

    pDt = 10;

    // Iterate through all movable objects
    for (auto it = sMovableObjects.begin(); it != sMovableObjects.end(); ++it)
    {
        movObj = *it;

        // Calculate acceleration
        acceleration = (movObj->vForce) / movObj->vMass;

        if (acceleration != Point2D(0, 0)) {

            newPosition = (2 * movObj->vGameObject->GetCoord()) - movObj->vGameObject->GetPrevCoord() + (acceleration * pDt * pDt);

            // Update object position
            movObj->vGameObject->SetPrevCoord(movObj->vGameObject->GetCoord());
            movObj->vGameObject->SetCoord(newPosition);

        }
        else {

            movObj->vGameObject->SetPrevCoord(movObj->vGameObject->GetCoord());
            movObj->vGameObject->SetCoord(movObj->vGameObject->GetCoord());
        }
    }
}

void
Physics::RemovePhysicsObject(Moveable* pMoveable) noexcept
{
    for (std::vector<Moveable*>::iterator it = sMovableObjects.begin(); it != sMovableObjects.end();)
    {
        if (*it == pMoveable) {

            sMovableObjects.erase(it);
            break;
        }
        else
            ++it;
    }
}

void
Physics::ClearAll() noexcept
{
    int size;
    int ndx = 0;

    size = (int)sMovableObjects.size();

    for (std::vector<Moveable*>::iterator it = sMovableObjects.begin(); size > ndx;) {

        delete (*it);

        sMovableObjects.erase(it);

        ++ndx;

        if (size > ndx) {

            ++it;
        }
    }
    //sMovableObjects.clear();
}