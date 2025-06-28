#include "ExampleGameObject.h"

ExampleGameObject::ExampleGameObject()
{
}

ExampleGameObject::~ExampleGameObject()
{
}

void ExampleGameObject::Update(IN const WCCEngine::GameTime& oGameTime)
{
	if (oPosition != oTargetPosition)
	{
		glm::vec2 oDirection = glm::normalize(glm::vec2(oTargetPosition - oPosition));
		//oPosition += oDirection * static_cast<float>(oGameTime.GetDeltaTtime()) * 0.5f;
	}
}
