#include "ExampleGameObject.h"

ExampleGameObject::ExampleGameObject()
{
}

ExampleGameObject::~ExampleGameObject()
{
}

void ExampleGameObject::Update()
{
	if (oPosition != oTargetPosition)
	{
		glm::vec2 oDirection = glm::normalize(glm::vec2(oTargetPosition - oPosition));
		oPosition += oDirection * 0.5f;
	}
}
