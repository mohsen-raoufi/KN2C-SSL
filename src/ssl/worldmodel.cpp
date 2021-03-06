#include "worldmodel.h"

WorldModel::WorldModel(OutputBuffer *outputBuffer)
{
    time=0;
    refgs.cmd=0;
    gs = STATE_Null;
    gs_last = STATE_Null;
    isSim = false;
    kn = new Knowledge(this);

    for(int i=0; i<PLAYERS_MAX_NUM; i++)
    {
        ourRobot[i].setID(i);
        ourRobot[i].setOutputBuffer(outputBuffer);
        ourRobot[i].setWorldModel(this);
    }
}
