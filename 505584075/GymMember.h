#ifndef GYMMEMBER_H
#define GYMMEMBER_H
#include <string>
#include "Kind.h"


	class GymMember {

	private:
		std::string mName;
		std::string mAccountNumber;
		Kind mKind;
		int mWorkOutCount;

	public:
		//constructor 
		//int??
		//GymMember();//take out
		GymMember();
		GymMember(std::string name, std::string accountnumber, Kind kind);

		int workoutsThisMonth();
		void startNewMonth();
		void newWorkout();

		Kind getKind() const;
		std::string getKindAsString() const;
		std::string getName() const;
		std::string getAccountNumber() const;

	};

# endif
