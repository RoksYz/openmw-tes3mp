//
// Created by koncord on 01.04.17.
//

#ifndef OPENMW_PROCESSORPLAYERSPELLBOOK_HPP
#define OPENMW_PROCESSORPLAYERSPELLBOOK_HPP

#include "../PlayerProcessor.hpp"

namespace mwmp
{
    class ProcessorPlayerSpellbook final: public PlayerProcessor
    {
    public:
        ProcessorPlayerSpellbook()
        {
            BPP_INIT(ID_PLAYER_SPELLBOOK)
        }

        void Do(PlayerPacket &packet, const std::shared_ptr<Player> &player) override
        {
            DEBUG_PRINTF(strPacketID.c_str());

            Networking::get().getState().getEventCtrl().Call<CoreEvent::ON_PLAYER_SPELLBOOK>(player.get());
        }
    };
}


#endif //OPENMW_PROCESSORPLAYERSPELLBOOK_HPP
