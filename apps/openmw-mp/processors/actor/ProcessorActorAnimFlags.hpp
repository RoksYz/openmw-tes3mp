#ifndef OPENMW_PROCESSORACTORANIMFLAGS_HPP
#define OPENMW_PROCESSORACTORANIMFLAGS_HPP

#include "../ActorProcessor.hpp"

namespace mwmp
{
    class ProcessorActorAnimFlags final: public ActorProcessor
    {
    public:
        ProcessorActorAnimFlags()
        {
            BPP_INIT(ID_ACTOR_ANIM_FLAGS)
        }

        void Do(ActorPacket &packet, const std::shared_ptr<Player> &player, BaseActorList &actorList) override
        {
            // Send only to players who have the cell loaded
            Cell *serverCell = CellController::get().getCell(actorList.cell);

            if (serverCell != nullptr && *serverCell->getAuthority() == actorList.guid)
                serverCell->sendToLoaded(&packet, &actorList);
        }
    };
}

#endif //OPENMW_PROCESSORACTORANIMFLAGS_HPP
