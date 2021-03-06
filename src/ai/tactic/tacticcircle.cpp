#include "tacticcircle.h"

TacticCircle::TacticCircle(WorldModel *worldmodel, QObject *parent) :
    Tactic(worldmodel, parent)
{
}

RobotCommand TacticCircle::getCommand()
{
    RobotCommand rc;
    if(!wm->ourRobot[id].isValid) return rc;
    Vector2D vc;
    vc = wm->ourRobot[id].pos.loc;
    vc.setLength(radius);
    vc.rotate(10);
    rc.fin_pos.loc = vc;
    rc.fin_pos.dir = (wm->ball.pos.loc - wm->ourRobot[id].pos.loc).dir().radian();
    return rc;
}
