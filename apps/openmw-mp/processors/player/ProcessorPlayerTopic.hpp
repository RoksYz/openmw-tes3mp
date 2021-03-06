#ifndef OPENMW_PROCESSORPLAYERTOPIC_HPP
#define OPENMW_PROCESSORPLAYERTOPIC_HPP

#include "../PlayerProcessor.hpp"

namespace mwmp
{
    class ProcessorPlayerTopic final: public PlayerProcessor
    {
    public:
        ProcessorPlayerTopic()
        {
            BPP_INIT(ID_PLAYER_TOPIC)
        }

        void Do(PlayerPacket &packet, const std::shared_ptr<Player> &player) override
        {
            DEBUG_PRINTF(strPacketID.c_str());

            //Todo: Script::Call<Script::CallbackIdentity("OnPlayerTopic")>(player.getId());
            Networking::get().getState().getEventCtrl().Call<CoreEvent::ON_PLAYER_TOPIC>(player.get());
        }
    };
}

#endif //OPENMW_PROCESSORPLAYERTOPIC_HPP
