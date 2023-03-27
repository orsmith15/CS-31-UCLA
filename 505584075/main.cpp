#include <iostream>
#include <string>
#include <cassert>

#include "Kind.h"
#include "Gym.h"
#include "GymMember.h"

using namespace std;

int main()
{
    // Start of Stahl's sample test code
    Gym gym("SportsClub", "1800 Sepulveda Boulevard", PREMIER);
    gym.setFeatures(true, false, true, false);

    GymMember me("Howard", "123456", EXECUTIVE);
    assert(me.workoutsThisMonth() == 0);
    me.startNewMonth();
    me.newWorkout();
    assert(me.workoutsThisMonth() == 1);

    if (gym.canWorkoutHere(me)) gym.checkin(me, true, false, true, false);
    assert(me.workoutsThisMonth() == 2);
    // End of Stahl's sample test code

    //CODE BOARD TESTING
    
    //GymMember Getters
    GymMember m("Pixie", "12345", OTHER);
    assert(m.getName() == "Pixie");
    assert(m.getAccountNumber() == "12345");
    assert(m.getKindAsString() == "Other"||"OTHER");

    //Workout Defaults
    
    assert(m.workoutsThisMonth() == 0);
    m.startNewMonth();
    assert(m.workoutsThisMonth() == 0);

    //New workout

    assert(m.workoutsThisMonth() == 0);
    m.startNewMonth();
    m.newWorkout();
    m.newWorkout();
    m.newWorkout();
    assert(m.workoutsThisMonth() == 3);

    m.startNewMonth();
    m.newWorkout();
    assert(m.workoutsThisMonth() == 1);

    //Gym getters and defaults

    Gym exec("ExecGym", "Los Angeles", EXECUTIVE);
    assert(exec.getName() == "ExecGym");
    assert(exec.getLocation() == "Los Angeles");
    assert(exec.getKindAsString() == "Executive"||"EXECUTIVE");
    assert(exec.hasCardioFeatures() == false);
    assert(exec.hasWeightsFeatures() == false);
    assert(exec.hasPoolFeatures() == false);
    assert(exec.hasTrackFeatures() == false);

    //Gym cardio features

    exec.setFeatures(true, false, false, false);
    assert(exec.hasCardioFeatures() == true);
    assert(exec.hasWeightsFeatures() == false);
    assert(exec.hasPoolFeatures() == false);
    assert(exec.hasTrackFeatures() == false);

    //Gym weights feature
    exec.setFeatures(false, true, false, false);
    assert(exec.hasCardioFeatures() == false);
    assert(exec.hasWeightsFeatures() == true);
    assert(exec.hasPoolFeatures() == false);
    assert(exec.hasTrackFeatures() == false);

    //gym pool functions

    exec.setFeatures(false, false, true, false);
    assert(exec.hasCardioFeatures() == false);
    assert(exec.hasWeightsFeatures() == false);
    assert(exec.hasPoolFeatures() == true);
    assert(exec.hasTrackFeatures() == false);

    //gym track feature
    exec.setFeatures(false, false, false, true);
    assert(exec.hasCardioFeatures() == false);
    assert(exec.hasWeightsFeatures() == false);
    assert(exec.hasPoolFeatures() == false);
    assert(exec.hasTrackFeatures() == true);

    //executive checkin 
    GymMember executive("You", "67890", EXECUTIVE);
    GymMember premier("Me", "11111", PREMIER);
    GymMember regular("Someone Else", "22222", REGULAR);
    assert(exec.canWorkoutHere(executive) == true);
    assert(exec.canWorkoutHere(premier) == false);
    assert(exec.canWorkoutHere(regular) == false);

    //premier checkin 
    Gym prem("PremGym", "Sacramento", PREMIER);
    assert(prem.canWorkoutHere(executive) == true);
    assert(prem.canWorkoutHere(premier) == true);
    assert(prem.canWorkoutHere(regular) == false);

    //regular checkin 
    Gym regu("ReguGym", "San Diego", REGULAR);
    assert(regu.canWorkoutHere(executive) == true);
    assert(regu.canWorkoutHere(premier) == true);
    assert(regu.canWorkoutHere(regular) == true);

    //regular checkin wanting nothing 
    assert(regu.checkin(regular, false, false, false, false) == true);

    //premier wants pool 
    premier.startNewMonth();
    regu.setFeatures(true, true, true, true); assert(regu.checkin(premier, false, false, true, false) == true);
    assert(premier.workoutsThisMonth() == 1);

    //exectuive checkin wants cardio
    regu.setFeatures(true, false, false, false);
    executive.startNewMonth();
    assert(regu.checkin(executive, true, false, false, false) == true);
    assert(regu.checkin(executive, true, false, false, false) == true);
    assert(executive.workoutsThisMonth() == 2);

    //executive wants pool but no pool at gym 
    regu.setFeatures(false, false, false, false);
    executive.startNewMonth();
    assert(regu.checkin(executive, false, true, false, true) == false);
    assert(regu.checkin(executive, true, false, false, true) == false);
    assert(executive.workoutsThisMonth() == 0);

    //Own test case data 
     
    GymMember member_other("Paul", "1", OTHER);
    GymMember member_regular("Pual", "12", REGULAR);
    GymMember member_premier("Plua", "123", PREMIER);
    GymMember member_exec("Plau", "69", EXECUTIVE);
    Gym gym_other("BFit", "UCLA", OTHER);
    Gym gym_regular("BFitFit", "UCLA", REGULAR);
    Gym gym_premier("BFitFitFit", "UCLA", PREMIER);
    Gym gym_exec("Fit", "UCLA", EXECUTIVE);

    /* GymMember methods */

    // workoutsThisMonth()
    for (int i = 0; i < 100; i++) {
        member_other.newWorkout();
    }
    assert(member_other.workoutsThisMonth() == 100);

    // startNewMonth()
    member_other.startNewMonth();
    assert(member_other.workoutsThisMonth() == 0);

    // newWorkout()
    member_regular.newWorkout();
    assert(member_regular.workoutsThisMonth() == 1);

    // getKind()
    assert(member_other.getKind() == OTHER);

    // getKindAsString()
    assert(member_other.getKindAsString() == "OTHER");
    assert(member_regular.getKindAsString() == "REGULAR");
    assert(member_premier.getKindAsString() == "PREMIER");
    assert(member_exec.getKindAsString() == "EXECUTIVE");

    // getName()
    assert(member_other.getName() == "Paul");

    // getAccountNumber()
    assert(member_exec.getAccountNumber() == "69");

    /* Gym methods */

    // setFeatures()
    // hasCardioFeatures()
    // hasWeightsFeatures()
    // hasPoolFeatures()
    // hasTrackFeatures()
    gym_other.setFeatures(true, false, false, false);
    gym_regular.setFeatures(false, true, false, false);
    gym_premier.setFeatures(false, false, true, false);
    gym_exec.setFeatures(false, false, false, true);

    assert(gym_other.hasCardioFeatures());
    assert(!gym_regular.hasCardioFeatures());

    assert(gym_regular.hasWeightsFeatures());
    assert(!gym_premier.hasWeightsFeatures());

    assert(gym_premier.hasPoolFeatures());
    assert(!gym_exec.hasPoolFeatures());

    assert(gym_exec.hasTrackFeatures());
    assert(!gym_other.hasTrackFeatures());

    // canWorkoutHere() 
    //members working out at other gyms. any member can workout at an OTHER gym 
    //no OTHER member can workout at Regular, premier, or executive gyms, but can workout at an other gym
    assert(gym_other.canWorkoutHere(member_other));
    assert(gym_other.canWorkoutHere(member_regular));
    assert(gym_other.canWorkoutHere(member_premier));
    assert(gym_other.canWorkoutHere(member_exec));

    assert(!gym_regular.canWorkoutHere(member_other));
    assert(gym_regular.canWorkoutHere(member_regular));
    assert(gym_regular.canWorkoutHere(member_premier));
    assert(gym_regular.canWorkoutHere(member_exec));

    assert(!gym_premier.canWorkoutHere(member_other));
    assert(!gym_premier.canWorkoutHere(member_regular));
    assert(gym_premier.canWorkoutHere(member_premier));
    assert(gym_premier.canWorkoutHere(member_exec));

    assert(!gym_exec.canWorkoutHere(member_other));
    assert(!gym_exec.canWorkoutHere(member_regular));
    assert(!gym_exec.canWorkoutHere(member_premier));
    assert(gym_exec.canWorkoutHere(member_exec));

    // checkin()
    member_other.startNewMonth();
    member_regular.startNewMonth();
    member_premier.startNewMonth();
    member_exec.startNewMonth();

    assert(gym_other.checkin(member_other, true, false, false, false));
    assert(!gym_other.checkin(member_other, true, true, true, true));
    assert(member_other.workoutsThisMonth() == 1);

    assert(gym_regular.checkin(member_regular, false, true, false, false));
    assert(!gym_regular.checkin(member_regular, true, true, true, true));
    assert(member_regular.workoutsThisMonth() == 1);

    assert(gym_premier.checkin(member_premier, false, false, true, false));
    assert(!gym_premier.checkin(member_premier, true, true, true, true));
    assert(member_premier.workoutsThisMonth() == 1);

    assert(gym_exec.checkin(member_exec, false, false, false, true));
    assert(!gym_exec.checkin(member_exec, true, true, true, true));
    assert(member_exec.workoutsThisMonth() == 1);

    // getKind()
    assert(gym_other.getKind() == OTHER);

    // getKindAsString()
    assert(gym_other.getKindAsString() == "OTHER");
    assert(gym_regular.getKindAsString() == "REGULAR");
    assert(gym_premier.getKindAsString() == "PREMIER");
    assert(gym_exec.getKindAsString() == "EXECUTIVE");

    // getLocation()
    assert(gym_other.getLocation() == "UCLA");

    // getName()
    assert(gym_exec.getName() == "Fit");

    std::cerr << "You're an amazing and valid person, even if you didn't pass "
        "the tests. Btw you passed the tests."
        << std::endl;

    return 0;
}