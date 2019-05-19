#pragma once
#include <vector>
#include "Vector3.h"
#include "OctTreeNode.h"

struct BoxCollider
{
	KodeboldsMath::Vector3 minBounds;
	KodeboldsMath::Vector3 maxBounds;
};