#include "boxCollider.h"

physics::BoxCollider::BoxCollider()
  : Collider()
{

}

physics::AABB physics::BoxCollider::computeAABB()
{

  double tempRotation = std::abs(static_cast<int>(rotation)) % 180;
  double width = 2 * boxSize.x;
  double height = 2 * boxSize.y;

  double xPos = parentObject->transform.getPosition().x + offset.x;
  double yPos = parentObject->transform.getPosition().y + offset.y;

  double xProjection;
  double yProjection;

  if (tempRotation < 90)
  {
    xProjection = height * cos((90 - tempRotation) * (3.14 / 180)) + width * cos((tempRotation) * (3.14 / 180));
    yProjection = height * cos((tempRotation) * (3.14 / 180)) + width * cos((90 - tempRotation) * (3.14 / 180));
  }
  else
  {
    xProjection = height * -cos((90 + tempRotation) * (3.14 / 180)) + width * -cos((tempRotation) * (3.14 / 180));
    yProjection = height * -cos((tempRotation) * (3.14 / 180)) + width * -cos((90 + tempRotation) * (3.14 / 180));
  }

  boundingBox.min = rune::Vec2(xPos - 0.5 * xProjection, yPos - 0.5 * yProjection);
  boundingBox.max = rune::Vec2(xPos + 0.5 * xProjection, yPos + 0.5 * yProjection);

  return boundingBox;

}
