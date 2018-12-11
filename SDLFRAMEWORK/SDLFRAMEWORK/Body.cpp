#include "Body.h" 

Body::Body(char* imageName, float mass_, float radius_, Vec3 pos_, Vec3 vel_, Vec3 accel_, Vec3 gravity_, bool movable_) {
	mass = mass_;
	radius = radius_;
	pos.x = pos_.x;
	pos.y = pos_.y;
	pos.z = pos_.z;

	vel.x = vel_.x;
	vel.y = vel_.y;
	vel.z = vel_.z;

	accel.x = accel_.x;
	accel.y = accel_.y;
	accel.z = accel_.z;

	gravity.x = gravity_.x;
	gravity.y = gravity_.y;
	gravity.z = gravity_.z;

	movable = movable_;

	IMG_Init(IMG_INIT_PNG);
	bodyImage = IMG_Load(imageName);
	if (bodyImage == nullptr) {
		/// What should we do?
	}

}

Body::~Body() {} /// There is really nothing to do here - yet!


void Body::Update(const float deltaTime) {
	pos.x += vel.x * deltaTime + 0.5f * accel.x * deltaTime * deltaTime + 0.5 * gravity.x * deltaTime * deltaTime;
	pos.y += vel.y * deltaTime + 0.5f * accel.y * deltaTime * deltaTime + 0.5 * gravity.y * deltaTime * deltaTime;
	pos.z += vel.z * deltaTime + 0.5f * accel.z * deltaTime * deltaTime + 0.5 * gravity.z * deltaTime * deltaTime;

	vel.x += accel.x * deltaTime;
	vel.y += accel.y * deltaTime;
	vel.z += accel.z * deltaTime;


	/// Assuming all acceleration comes from an applied force - maybe not in the future - gravity!!
	accel.x = 0.0f;
	accel.y = 0.0f;
	accel.z = 0.0f;


}

void Body::ApplyForce(Vec3 force) {
	accel.x = force.x / mass;
	accel.y = force.y / mass;
	accel.z = force.z / mass;
}


SDL_Surface* Body::getImage() {
	return bodyImage;
}

SDL_Texture* Body::getTexture() {
	return bodyTexture = SDL_CreateTextureFromSurface(bodyRender, bodyImage);
}