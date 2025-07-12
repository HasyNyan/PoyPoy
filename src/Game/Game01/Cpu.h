#pragma once
#include <System/Scene.h>
#include <System/Component/ComponentModel.h>
#include <System/Component/ComponentCollisionModel.h>
#include <System/Component/ComponentCollisionCapsule.h>
#include <System/Component/ComponentObjectController.h>
#include <System/Component/ComponentCollisionSphere.h>
namespace Game01 {

USING_PTR(Cpu);

class Cpu : public Object
{
public:
    BP_OBJECT_DECL(Cpu, u8"Game01のCpu");

    bool Init() override;

    //! @brief 更新
    void Update() override;
    void Draw() override;
    void OnHit(const ComponentCollision::HitInfo& hit_info) override;

    void SetDirection(const float3& dir) { direction_ = dir; }
    void SetIsFlying(bool flying) { isFlying_ = flying; }

private:
    float                   jumpPower_  = 0.5f;
    bool                    isJump_     = false;
    bool                    takeMode_   = false;
    bool                    throwMode_  = false;
    std::shared_ptr<Object> takenStone_ = nullptr;

    float3 direction_ = {};
    float  speed_     = 0.2f;
    bool   isFlying_  = false;
};

}    // namespace Game01
