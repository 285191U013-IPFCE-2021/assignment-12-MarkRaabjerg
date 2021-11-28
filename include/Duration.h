#ifndef _DURATION_CLASS_H
#define _DURATION_CLASS_H
#include <assert.h>
#include <stdio.h>

class Duration
{
private:  // Private function is functions the user cant see and touch.
    int time;
    int alarm;
    bool AlarmHasBeenSet;
    void ResetAlarm();
    bool Check();


public:   // Public funktions is function that the user of the program can call and pass arguments to.
    int getDuration();
    // void Tick();
    bool Tick(int dt);
    void SetAlarm(int t);

    Duration();
    Duration(int t);
    // ~Duration();    We dont allocate memorry for anything so we don't have to use a deconstructor.
};

#endif