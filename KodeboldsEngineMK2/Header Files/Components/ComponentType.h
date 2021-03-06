#pragma once
typedef struct {
	enum : int
	{
		COMPONENT_NONE = 0,
		COMPONENT_AI = 1 << 1,
		COMPONENT_AUDIO = 1 << 2,
		COMPONENT_BOXCOLLIDER = 1 << 3,
		COMPONENT_CAMERA = 1 << 4,
		COMPONENT_COLOUR = 1 << 5,
		COMPONENT_GEOMETRY = 1 << 6,
		COMPONENT_GRAVITY = 1 << 7,
		COMPONENT_POINTLIGHT = 1 << 8,
		COMPONENT_DIRECTIONALLIGHT = 1 << 9,
		COMPONENT_RAY = 1 << 10,
		COMPONENT_SHADER = 1 << 11,
		COMPONENT_SPHERECOLLIDER = 1 << 12,
		COMPONENT_TEXTURE = 1 << 13,
		COMPONENT_TRANSFORM = 1 << 14,
		COMPONENT_VELOCITY = 1 << 15,
		COMPONENT_COLLISION = 1 << 16,
		CUSTOM_COMPONENT = 1 << 17,
	};
}ComponentType;