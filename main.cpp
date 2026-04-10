#include "ModuleManager.h"
#include "Events/OnUpdateEvent.h"

class VelocityAssist : public Module {
public:
    VelocityAssist() : Module("VelocityAssist", "Prevents all knockback", Category::COMBAT) {}

    void onEnable() override {
        Logger::Log("Velocity hooked!");
    }

    void onEvent(Event* e) override {
        if (e->GetType() == EventType::PacketReceive) {
            auto* packetEvent = static_cast<PacketReceiveEvent*>(e);
            if (packetEvent->getPacketID() == S12PacketEntityVelocity) {
                packetEvent->cancel(); // Discard knockback packet
            }
        }
    }
};
