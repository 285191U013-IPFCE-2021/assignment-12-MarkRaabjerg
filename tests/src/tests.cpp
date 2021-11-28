#define CATCH_CONFIG_MAIN // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "Duration.h"


// See Catch2's documentation: https://github.com/catchorg/Catch2/blob/devel/docs/tutorial.md#scaling-up

TEST_CASE("getDuration")
{

// Testing The getDuration funktion for 3 examples.

    Duration ex1 = Duration();
    Duration ex2 = Duration(3);
    Duration ex3 = Duration (10);

    REQUIRE(ex1.getDuration()==0);
    REQUIRE(ex2.getDuration()==3);
    REQUIRE(ex3.getDuration()==10);
}

TEST_CASE("Tick")
{

// Testing the tick funktion for the 3 examples. 

    Duration ex1 = Duration();
    Duration ex2 = Duration(3);
    Duration ex3 = Duration (10);

    ex1.Tick(0);
    ex2.Tick(3);
    ex3.Tick(21);

    REQUIRE(ex1.getDuration()==0);
    REQUIRE(ex2.getDuration()==6);
    REQUIRE(ex3.getDuration()==31);
}

TEST_CASE("Alarm")
{

// Testing all funktions together to test the alarm funktion that has to reset when the time exceeds the alarm duration.

    Duration ex1 = Duration();
    Duration ex2 = Duration(3);
    Duration ex3 = Duration (10);

    ex1.SetAlarm(3);
    ex1.Tick(2);
    REQUIRE(ex1.Tick(0)==false);
    REQUIRE(ex1.Tick(1)==true);
    REQUIRE(ex1.Tick(2)==false);
    REQUIRE(ex1.getDuration()==5);


    ex2.SetAlarm(9);
    ex2.Tick(3);
    REQUIRE(ex2.Tick(2)==false);
    REQUIRE(ex2.Tick(1)==true);
    REQUIRE(ex2.Tick(2)==false);
    REQUIRE(ex2.getDuration()==11);

    ex3.SetAlarm(20);
    ex3.Tick(5);
    REQUIRE(ex3.Tick(2)==false);
    REQUIRE(ex3.Tick(4)==true);
    REQUIRE(ex3.Tick(2)==false);
    REQUIRE(ex3.getDuration()==23);

}