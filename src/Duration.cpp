#include "Duration.h"
#include <stdio.h>
#include <assert.h>


// getDuration is the function that tells us the time.
int Duration::getDuration()
{
    return time;
}


// This function is called to initiate and reset the time and alarm.
Duration::Duration()
{
    time=0;
    ResetAlarm();
}


// In this function you can choose the starting time. The time has to be 0 and the alarm is resetting 
Duration::Duration(int t)
{
    assert(t>=0);
    time=t;
    ResetAlarm();
}


// The Tick function is commented out because its the same as if you pass 0 to the next function.
// void Duration::Tick()
// {
//     time++
// }


// This function Ticks the time up by as much you would like. If you pass 0 and 1 to this funktion the time goes up by 1.
bool Duration::Tick(int dt)
{
    time++;
    assert(dt>=0);
    time=time + dt - 1;
    return Check();
}


// This function sets the alarm. The alarm must be greater than the time.
void Duration::SetAlarm(int t)
{
    assert(time<t);

    if (AlarmHasBeenSet == false)
    {
    alarm=t;    
    AlarmHasBeenSet=true;
    }
}


// This function resets the alarm.
void Duration::ResetAlarm()
{
    alarm=time+10000;
    AlarmHasBeenSet=false;
}

// This funktion checks if the alarm has been set and if the time exceeds the time.
bool Duration::Check()
{
    if (AlarmHasBeenSet==true)
    {
        if (time>=alarm)
        {
            ResetAlarm();
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}