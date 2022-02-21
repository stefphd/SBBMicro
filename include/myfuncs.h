
#ifndef __MYFUNCS_H__ //skip if __MYFUNCS_H__ already defined
#define __MYFUNCS_H__

//variables declaration
unsigned int time0; //initialize initial time

//functions
void initTimer() {
    #ifndef MATLAB_MEX_FILE //do nothing if matlab mexing
    time0 = micros();
    #endif
}

float getTimer() {
    #ifndef MATLAB_MEX_FILE //do nothing if matlab mexing
    return (((float) (micros()-time0))/1.0e6);
    #else
    return 0;
    #endif
}


#endif //end #ifndef MYFUNCS_H 
