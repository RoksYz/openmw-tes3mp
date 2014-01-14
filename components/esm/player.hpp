#ifndef OPENMW_ESM_PLAYER_H
#define OPENMW_ESM_PLAYER_H

#include <string>

#include "objectstate.hpp"
#include "cellid.hpp"
#include "defs.hpp"

namespace ESM
{
    class ESMReader;
    class ESMWriter;

    // format 0, saved games only

    struct Player
    {
        ObjectState mObject;
        CellId mCellId;
        float mLastKnownExteriorPosition[3];
        unsigned char mHasMark;
        ESM::Position mMarkedPosition;
        CellId mMarkedCell;
        unsigned char mAutoMove;

        void load (ESMReader &esm);
        void save (ESMWriter &esm) const;
    };
}

#endif