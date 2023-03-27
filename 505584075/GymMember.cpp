#include "Kind.h"
#include "GymMember.h"
#include <iostream>
#include <string>
#include "Gym.h"
using namespace std;

	GymMember::GymMember(string name, string accountnumber, Kind kind)
	{
		mName = name;
		mAccountNumber = accountnumber;
		mKind = kind;
		mWorkOutCount = 0;
	}

	int GymMember::workoutsThisMonth() {

		//public accessor for data member
		cerr << "Work Out This Month: " << mWorkOutCount << endl;
		return mWorkOutCount;
	}
	void GymMember::startNewMonth() {

		//workout count set to 0
		mWorkOutCount = 0;
	}
	void GymMember::newWorkout() {
		
			mWorkOutCount++;
			cerr << "New Work Out Count This Month: " << mWorkOutCount << endl;

	}

	Kind GymMember::getKind() const {

		cerr << "Kind of membership enum: " << mKind << endl;
		return mKind;
	}
	string GymMember::getKindAsString()const {

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
	string GymMember::getName()const {

		cerr << "Name of Gymmember: " << mName << endl;
		return mName;
	}
	string GymMember::getAccountNumber()const {
		cerr << "Account number: " << mAccountNumber << endl;
		return mAccountNumber;
	}

