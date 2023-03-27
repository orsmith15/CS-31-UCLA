#include "Kind.h"
#include "GymMember.h"
#include "Gym.h"
#include <iostream>
#include <string>
using namespace std;

Gym::Gym(string name, string location, Kind kind) {
	mName = name;
	mLocation = location;
	mKind = kind;

	hasCardio = false;
	hasWeights = false;
	hasPool = false;
	hasTrack = false;
}
void Gym::setFeatures(bool cardio, bool weights, bool pool, bool track) {
	
	hasCardio = cardio;
	hasWeights = weights;
	hasPool = pool;
	hasTrack = track;
}

bool Gym::canWorkoutHere(GymMember m) {

	if (m.getKind() < Gym::getKind()) {
		return false;
	}
	else if (m.getKind() >= Gym::getKind()) {
		return true;
	}
	else return false;
	
}
bool Gym::checkin(GymMember& m, bool wantsCardio, bool wantsWeights, bool wantsPool, bool wantsTrack) {
	if (canWorkoutHere(m) == false) {//need to figure out what the importance of the & is
		return false;
	}
	else if ((wantsCardio == true&&hasCardio==false)||(wantsWeights==true &&hasWeights==false)||(wantsPool == true && hasPool == false)||(wantsTrack == true && hasTrack == false)) {
		return false;
	}
	else {
		m.newWorkout();
		return true;
	}
	
}

bool Gym::hasCardioFeatures() {
	return hasCardio;
}
bool Gym::hasWeightsFeatures() {
	return hasWeights;
}
bool Gym::hasPoolFeatures() {
	return hasPool;
}
bool Gym::hasTrackFeatures() {
	return hasTrack;
}

Kind Gym::getKind() {
	return mKind;
}
string Gym::getKindAsString() {
	switch (mKind) {
	case OTHER:
		return "OTHER";
	case REGULAR:
		return "REGULAR";
	case PREMIER:
		return "PREMIER";
	case EXECUTIVE:
		return "EXECUTIVE";
	default:
		return "invalid Kind";
	}
}
string Gym::getLocation() {
	return mLocation;
}
string Gym::getName() {
	return mName;
}
